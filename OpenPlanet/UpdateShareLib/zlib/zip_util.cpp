#include "zip_util.h"
#include "unzip.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>

#include "zip.h"
#include "ioapi.h"
#include "iowin32.h"
#include "wrap_object.h"

using namespace std;

#define CASESENSITIVITY (0)
#define WRITEBUFFERSIZE (8192)
#define MAXFILENAME (256)

unzFile ZipUtil::UnzOpen64(const wchar_t* path)
{
	zlib_filefunc64_def ffunc;  
    fill_win32_filefunc64W(&ffunc);  
    unzFile zf = unzOpen2_64(path,&ffunc);
	return zf;
}

char* ConvertUnicodeToUtf8(const wchar_t* unicode)  
{  
	if(unicode == NULL)
	{
		return strdup("\0");
	}

    int len;  
    len = WideCharToMultiByte(CP_UTF8, 0,unicode, -1, NULL, 0, NULL, NULL);  
    char *szUtf8 = (char*)malloc(len + 1);  
    memset(szUtf8, 0, len + 1);  
    WideCharToMultiByte(CP_UTF8, 0,unicode, -1, szUtf8, len, NULL,NULL);  
    return szUtf8;  
}

wchar_t* ConvertUtf8ToUnicode(const char* utf8)
{
	if(!utf8)
	{
		wchar_t* buf = (wchar_t*)malloc(2);
		memset(buf,0,2);
		return buf;
	}
	int nLen = ::MultiByteToWideChar(CP_UTF8,MB_ERR_INVALID_CHARS,(LPCSTR)utf8,-1,NULL,0);
	//返回需要的unicode长度  
	WCHAR * wszUNICODE = new WCHAR[nLen+1];  
	memset(wszUNICODE, 0, nLen * 2 + 2);  
	nLen = MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)utf8, -1, wszUNICODE, nLen);    //把utf8转成unicode
	return wszUNICODE;
}

void change_file_date( const char *filename,uLong dosdate,tm_unz tmu_date)
{
  HANDLE hFile;
  FILETIME ftm,ftLocal,ftCreate,ftLastAcc,ftLastWrite;

  wchar_t* filenamew = ConvertUtf8ToUnicode(filename);
  hFile = CreateFile(filenamew,GENERIC_READ | GENERIC_WRITE,
                      0,NULL,OPEN_EXISTING,0,NULL);
  GetFileTime(hFile,&ftCreate,&ftLastAcc,&ftLastWrite);
  DosDateTimeToFileTime((WORD)(dosdate>>16),(WORD)dosdate,&ftLocal);
  LocalFileTimeToFileTime(&ftLocal,&ftm);
  SetFileTime(hFile,&ftm,&ftLastAcc,&ftm);
  CloseHandle(hFile);
  free(filenamew);

}

int mymkdir(const char* dirname)
{
	wchar_t* dirnamew = ConvertUtf8ToUnicode(dirname);
	int res = CreateDirectory(dirnamew,NULL);
	free(dirnamew);
    return res;
}

int makedir (const char *newdir)
{
	char *buffer ;
	char *p;
	int  len = (int)strlen(newdir);

	if (len <= 0)
		return 0;

	buffer = (char*)malloc(len+1);
	memset(buffer,0,len+1);

	if (buffer==NULL)
	{
		printf("Error allocating memory\n");
		return UNZ_INTERNALERROR;
	}
	strcpy(buffer,newdir);

	if (buffer[len-1] == '/' || buffer[len-1] == '\\') {
		buffer[len-1] = '\0';
	}
	if (mymkdir(buffer) == 0)
	{
		free(buffer);
		return 1;
	}

	p = buffer+1;
	while (1)
	{
		char hold;

		while(*p && *p != '\\' && *p != '/')
			p++;
		hold = *p;
		*p = 0;
		if ((mymkdir(buffer) == -1) && (errno == ENOENT))
		{
			printf("couldn't create directory %s\n",buffer);
			free(buffer);
			return 0;
		}
		if (hold == 0)
			break;
		*p++ = hold;
	}
	free(buffer);
	return 1;
}

int do_extract_currentfile(unzFile uf,const int* popt_extract_without_path,
	int* popt_overwrite,const char* password,const char* dir)
{
	char filename_inzip[256];
	char* filename_withoutpath;
	char* p;
	int err=UNZ_OK;
	FILE *fout=NULL;
	void* buf;
	uInt size_buf;

	unz_file_info64 file_info;
	uLong ratio=0;
	err = unzGetCurrentFileInfo64(uf,&file_info,filename_inzip,sizeof(filename_inzip),NULL,0,NULL,0);

	if (err!=UNZ_OK)
	{
		printf("error %d with zipfile in unzGetCurrentFileInfo\n",err);
		return err;
	}

	size_buf = WRITEBUFFERSIZE;
	buf = (void*)malloc(size_buf);
	if (buf==NULL)
	{
		printf("Error allocating memory\n");
		return UNZ_INTERNALERROR;
	}

	std::string dir1(dir);
	dir1.append(filename_inzip);
	strncpy(filename_inzip,dir1.c_str(),sizeof(filename_inzip));

	p = filename_withoutpath = filename_inzip;
	while ((*p) != '\0')
	{
		if (((*p)=='/') || ((*p)=='\\'))
			filename_withoutpath = p+1;
		p++;
	}

	if ((*filename_withoutpath)=='\0')
	{
		if ((*popt_extract_without_path)==0)
		{
			printf("creating directory: %s\n",filename_inzip);
			mymkdir(filename_inzip);
		}
	}
	else
	{
		const char* write_filename;
		int skip=0;

		if ((*popt_extract_without_path)==0)
			write_filename = filename_inzip;
		else
			write_filename = filename_withoutpath;

		wchar_t* write_filenamew = ConvertUtf8ToUnicode(write_filename);
		WrapMalloc wm_filename(write_filenamew);
		err = unzOpenCurrentFilePassword(uf,password);
		if (err!=UNZ_OK)
		{
			printf("error %d with zipfile in unzOpenCurrentFilePassword\n",err);
		}

		if ((skip==0) && (err==UNZ_OK))
		{
			fout=_wfopen(write_filenamew,L"wb");

			/* some zipfile don't contain directory alone before file */
			if ((fout==NULL) && ((*popt_extract_without_path)==0) &&
				(filename_withoutpath!=(char*)filename_inzip))
			{
				char c=*(filename_withoutpath-1);
				*(filename_withoutpath-1)='\0';
				makedir(write_filename);
				*(filename_withoutpath-1)=c;
				fout = _wfopen(write_filenamew,L"wb");
			}

			if (fout==NULL)
			{
				printf("error opening %s\n",write_filename);
			}
		}

		if (fout!=NULL)
		{
			printf(" extracting: %s\n",write_filename);

			do
			{
				err = unzReadCurrentFile(uf,buf,size_buf);
				if (err<0)
				{
					printf("error %d with zipfile in unzReadCurrentFile\n",err);
					break;
				}
				if (err>0)
					if (fwrite(buf,err,1,fout)!=1)
					{
						printf("error in writing extracted file\n");
						err=UNZ_ERRNO;
						break;
					}
			}
			while (err>0);
			if (fout)
				fclose(fout);

			if (err==0)
				change_file_date(write_filename,file_info.dosDate,
				file_info.tmu_date);
		}

		if (err==UNZ_OK)
		{
			err = unzCloseCurrentFile (uf);
			if (err!=UNZ_OK)
			{
				printf("error %d with zipfile in unzCloseCurrentFile\n",err);
			}
		}
		else
			unzCloseCurrentFile(uf); /* don't lose the error */
	}

	free(buf);
	return err;
}


int do_extract(	unzFile uf,
int opt_extract_without_path,
int opt_overwrite,const char* password,const char* dir)
{
	uLong i;
	unz_global_info64 gi;
	int err;
	FILE* fout=NULL;

	err = unzGetGlobalInfo64(uf,&gi);
	if (err!=UNZ_OK)
		printf("error %d with zipfile in unzGetGlobalInfo \n",err);

	for (i=0;i<gi.number_entry;i++)
	{
		if (do_extract_currentfile(uf,&opt_extract_without_path,
			&opt_overwrite,
			password,dir) != UNZ_OK)
			return 0;

		if ((i+1)<gi.number_entry)
		{
			err = unzGoToNextFile(uf);
			if (err!=UNZ_OK)
			{
				printf("error %d with zipfile in unzGoToNextFile\n",err);
				return 0;
			}
		}
	}

	return 1;
}

bool ZipUtil::UnzipFile(std::wstring zip_file,std::wstring unzip_dir)
{
	if(unzip_dir[unzip_dir.size()-1] != L'\\')
	{
		unzip_dir.append(L"\\");
	}
	int err = UNZ_OK;                 // error status
    uInt size_buf = WRITEBUFFERSIZE;  // byte size of buffer to store raw csv data
    void* buf;                        // the buffer
    string sout;                      // output strings
    char filename_inzip[256];         // for unzGetCurrentFileInfo
    unz_file_info file_info;          // for unzGetCurrentFileInfo
    
    unzFile uf = UnzOpen64(zip_file.c_str()); // open zipfile stream
    if (uf==NULL) {
        wcerr << "Cannot open " << zip_file << endl;
        return false;
    } // file is open
	CreateDirectory(unzip_dir.c_str(),NULL);
	char* utf8 = ConvertUnicodeToUtf8(unzip_dir.c_str());
    int ret_value = do_extract(uf,0,0,NULL,utf8);
	unzClose(uf);
	free(utf8);
	return ret_value;
}

