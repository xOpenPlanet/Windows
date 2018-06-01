#include "TAesClass.h"

Aes::~Aes()
{

}
Aes::Aes()
{

}
////////////////////////////////////////////////////////////////////////////////////////////////
//���캯��
Aes::Aes(int keysize, unsigned char* keyBytes)
{
	SetNbNkNr(keysize);                         //������Կ���������� 
	memcpy(key, keyBytes, keysize);                //�ַ���������������keyBytes��keysize���ַ����Ƶ�key��
	KeyExpansion();                                //��Կ��չ��������ǰ���ĳ�ʼ��
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Aes::SetNbNkNr(int keySize)
{
	Nb = 4;
	if (keySize == Bits128)
	{
		Nk = 4;    //4*4�ֽڣ�128λ��Կ��10�ּ���
		Nr = 10;
	}
	else if (keySize == Bits192)
	{
		Nk = 6;    //6*4�ֽڣ�192λ��Կ��12�ּ���
		Nr = 12;
	}
	else if (keySize == Bits256)
	{
		Nk = 8;    //8*4�ֽڣ�256λ��Կ��14�ּ���
		Nr = 14;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Aes::KeyExpansion()
{

	memset(w, 0, 16 * 15);
	for (int row = 0; row<Nk; row++)       //����seed ��Կ
	{
		w[4 * row + 0] = key[4 * row];
		w[4 * row + 1] = key[4 * row + 1];
		w[4 * row + 2] = key[4 * row + 2];
		w[4 * row + 3] = key[4 * row + 3];
	}
	byte* temp = new byte[4];
	for (int row = Nk; row<4 * (Nr + 1); row++)
	{
		temp[0] = w[4 * row - 4];     //��ǰ�е�ǰһ��  
		temp[1] = w[4 * row - 3];
		temp[2] = w[4 * row - 2];
		temp[3] = w[4 * row - 1];
		if (row%Nk == 0)           //��nkʱ���Ե�ǰ�е�ǰһ�������⴦��
		{
			temp = SubWord(RotWord(temp));   //����λ���ٴ����������ֳ������
			temp[0] = (byte)((int)temp[0] ^ (int)AesRcon[4 * (row / Nk) + 0]);
			temp[1] = (byte)((int)temp[1] ^ (int)AesRcon[4 * (row / Nk) + 1]);
			temp[2] = (byte)((int)temp[2] ^ (int)AesRcon[4 * (row / Nk) + 2]);
			temp[3] = (byte)((int)temp[3] ^ (int)AesRcon[4 * (row / Nk) + 3]);
		}
		else if (Nk > 6 && (row % Nk == 4))  //�����û�и����
		{
			temp = SubWord(temp);
		}

		// w[row] = w[row-Nk] xor temp
		w[4 * row + 0] = (byte)((int)w[4 * (row - Nk) + 0] ^ (int)temp[0]);
		w[4 * row + 1] = (byte)((int)w[4 * (row - Nk) + 1] ^ (int)temp[1]);
		w[4 * row + 2] = (byte)((int)w[4 * (row - Nk) + 2] ^ (int)temp[2]);
		w[4 * row + 3] = (byte)((int)w[4 * (row - Nk) + 3] ^ (int)temp[3]);
	}  // for loop

}
////////////////////////////////////////////////////////////////////////////////////////////////
//��Կ��λ����
unsigned char* Aes::RotWord(unsigned char* word)
{
	byte* temp = new byte[4];
	temp[0] = word[1];
	temp[1] = word[2];
	temp[2] = word[3];
	temp[3] = word[0];
	return temp;
}
////////////////////////////////////////////////////////////////////////////////////////////////
//��Կ�ִ�������
unsigned char* Aes::SubWord(unsigned char* word)
{
	byte* temp = new byte[4];
	for (int j = 0; j<4; j++)
	{
		temp[j] = AesSbox[16 * (word[j] >> 4) + (word[j] & 0x0f)];  //ʵ����Ҳ����д��AesSbox[[j]];��Ϊ�������
	}
	return temp;

}
////////////////////////////////////////////////////////////////////////////////////////////////
//Aes���ܺ���
void Aes::Cipher(unsigned char* input, unsigned char* output)
{
	memset(&State[0][0], 0, 16);
	for (int i = 0; i<4 * Nb; i++)                        //��������д�к�д�еģ���������һ��һ�еĽ�����
	{
		State[i % 4][i / 4] = input[i];                    //������д�к�д��Ҳ�ǿ��Եģ�ֻҪ�����ʱҲ�������Ϳ�����
	}
	AddRoundKey(0);                                    //����Կ��

	for (int round = 1; round <= (Nr - 1); round++)  // main round loop
	{
		SubBytes();                                    //�ֽڴ���
		ShiftRows();                                //����λ
		MixColumns();                                //�л���
		AddRoundKey(round);                            //����Կ��
	}  // main round loop

	SubBytes();                                        //�ֽڴ���
	ShiftRows();                                    //����λ
	AddRoundKey(Nr);                                //����Կ��

	// output = state
	for (int i = 0; i < (4 * Nb); i++)
	{
		output[i] = State[i % 4][i / 4];
	}

}
////////////////////////////////////////////////////////////////////////////////////////////////
//Aes���ܺ���
void Aes::InvCipher(unsigned char* input, unsigned char* output)
{
	memset(&State[0][0], 0, 16);
	for (int i = 0; i < (4 * Nb); i++)
	{
		State[i % 4][i / 4] = input[i];
	}

	AddRoundKey(Nr);

	for (int round = Nr - 1; round >= 1; round--)  // main round loop
	{
		InvShiftRows();
		InvSubBytes();
		AddRoundKey(round);
		InvMixColumns();
	}  // end main round loop for InvCipher

	InvShiftRows();
	InvSubBytes();
	AddRoundKey(0);

	// output = state
	for (int i = 0; i < (4 * Nb); i++)
	{
		output[i] = State[i % 4][i / 4];
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////
//����Կ��
void Aes::AddRoundKey(int round)
{
	int i, j;  //i�� j��           //��Ϊ��Կw��һ��һ�����еģ��� k0 k4 k8 k12
	for (j = 0; j<4; j++)              //                              k1 k5 k9 k13
	{                              //                              k2 k6 k10k14
		for (i = 0; i<4; i++)          //                              k3 k7 k11k15
		{                          // ����i��j�е��±���4*((round*4)+j)+i��16*round+4*j+i
			State[i][j] = (unsigned char)((int)State[i][j] ^ (int)w[4 * ((round * 4) + j) + i]);
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////
//�ֽڴ�������
void Aes::SubBytes()                              //Page 103
{
	int i, j;
	for (j = 0; j<4; j++)
	{
		for (i = 0; i<4; i++)
		{
			State[i][j] = AesSbox[State[i][j]];
			//��Ϊ 16*(State[i][j]>>4)+State[i][j]&0x0f=State[i][j]


		}
	}
}

void Aes::InvSubBytes()
{
	int i, j;
	for (j = 0; j<4; j++)
	{
		for (i = 0; i<4; i++)
		{
			State[i][j] = AesiSbox[State[i][j]]; //��Ϊ 16*(State[i][j]>>4)+State[i][j]&0x0f=State[i][j]
		}
	}

}
////////////////////////////////////////////////////////////////////////////////////////////////
void Aes::ShiftRows()
{
	unsigned char temp[4 * 4];                                        //Page105
	int i, j;
	for (j = 0; j<4; j++)
	{
		for (i = 0; i<4; i++)
		{
			temp[4 * i + j] = State[i][j];
		}
	}
	for (i = 1; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			if (i == 1)State[i][j] = temp[4 * i + (j + 1) % 4];                    //��һ������1λ
			else if (i == 2)State[i][j] = temp[4 * i + (j + 2) % 4];                //�ڶ�������2λ
			else if (i == 3)State[i][j] = temp[4 * i + (j + 3) % 4];                //����������3λ
		}
	}

}
void Aes::InvShiftRows()
{
	unsigned char temp[4 * 4];
	int i, j;
	for (j = 0; j<4; j++)
	{
		for (i = 0; i<4; i++)
		{
			temp[4 * i + j] = State[i][j];
		}
	}
	for (i = 1; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			//if(i==1)State[i][j]=temp[4*i+(j-1)%4];    �ڴ˷���һ������ -1%4=-1 ������3�����Բ����������ټ�һ��4������
			if (i == 1)State[i][j] = temp[4 * i + (j + 3) % 4];            //��һ������1λ j-1+4=j+3
			else if (i == 2)State[i][j] = temp[4 * i + (j + 2) % 4];        //�ڶ�������2λ j-2+4=j+2
			else if (i == 3)State[i][j] = temp[4 * i + (j + 1) % 4];        //����������3λ j-3+4=j+2
		}
	}

}
////////////////////////////////////////////////////////////////////////////////////////////////
void Aes::MixColumns()
{
	unsigned char temp[4 * 4];
	int i, j;
	for (j = 0; j<4; j++)                                    //2 3 1 1  �л�������  Page107
	{                                                    //1 2 3 1
		for (i = 0; i<4; i++)                                //1 1 2 3
		{                                                //3 1 1 2
			temp[4 * i + j] = State[i][j];
		}
	}
	for (j = 0; j<4; j++)
	{
		State[0][j] = (unsigned char)((int)gfmultby02(temp[0 + j]) ^ (int)gfmultby03(temp[4 * 1 + j]) ^
			(int)gfmultby01(temp[4 * 2 + j]) ^ (int)gfmultby01(temp[4 * 3 + j]));
		State[1][j] = (unsigned char)((int)gfmultby01(temp[0 + j]) ^ (int)gfmultby02(temp[4 * 1 + j]) ^
			(int)gfmultby03(temp[4 * 2 + j]) ^ (int)gfmultby01(temp[4 * 3 + j]));
		State[2][j] = (unsigned char)((int)gfmultby01(temp[0 + j]) ^ (int)gfmultby01(temp[4 * 1 + j]) ^
			(int)gfmultby02(temp[4 * 2 + j]) ^ (int)gfmultby03(temp[4 * 3 + j]));
		State[3][j] = (unsigned char)((int)gfmultby03(temp[0 + j]) ^ (int)gfmultby01(temp[4 * 1 + j]) ^
			(int)gfmultby01(temp[4 * 2 + j]) ^ (int)gfmultby02(temp[4 * 3 + j]));
	}

}
void Aes::InvMixColumns()
{
	unsigned char temp[4 * 4];
	int i, j;
	for (i = 0; i < 4; i++)  // copy State into temp[]
	{
		for (j = 0; j < 4; j++)                         //0e 0b 0d 09   ��任���� Page108
		{                                                //09 0e 0b 0d
			temp[4 * i + j] = State[i][j];                    //0d 09 0e 0b
		}                                                //0b 0d 09 0e
	}

	for (j = 0; j < 4; j++)
	{
		State[0][j] = (unsigned char)((int)gfmultby0e(temp[j]) ^ (int)gfmultby0b(temp[4 + j]) ^
			(int)gfmultby0d(temp[4 * 2 + j]) ^ (int)gfmultby09(temp[4 * 3 + j]));
		State[1][j] = (unsigned char)((int)gfmultby09(temp[j]) ^ (int)gfmultby0e(temp[4 + j]) ^
			(int)gfmultby0b(temp[4 * 2 + j]) ^ (int)gfmultby0d(temp[4 * 3 + j]));
		State[2][j] = (unsigned char)((int)gfmultby0d(temp[j]) ^ (int)gfmultby09(temp[4 + j]) ^
			(int)gfmultby0e(temp[4 * 2 + j]) ^ (int)gfmultby0b(temp[4 * 3 + j]));
		State[3][j] = (unsigned char)((int)gfmultby0b(temp[j]) ^ (int)gfmultby0d(temp[4 + j]) ^
			(int)gfmultby09(temp[4 * 2 + j]) ^ (int)gfmultby0e(temp[4 * 3 + j]));
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////
unsigned char Aes::gfmultby01(unsigned char b)
{
	return b;
}
unsigned char Aes::gfmultby02(unsigned char b)
{
	if (b < 0x80)
		return (unsigned char)(int)(b << 1);
	else
		return (unsigned char)((int)(b << 1) ^ (int)(0x1b));
}

unsigned char Aes::gfmultby03(unsigned char b)
{
	return (unsigned char)((int)gfmultby02(b) ^ (int)b);
}

unsigned char Aes::gfmultby09(unsigned char b)
{
	return (unsigned char)((int)gfmultby02(gfmultby02(gfmultby02(b))) ^ (int)b);
}

unsigned char Aes::gfmultby0b(unsigned char b)
{
	return (unsigned char)((int)gfmultby02(gfmultby02(gfmultby02(b))) ^
		(int)gfmultby02(b) ^ (int)b);
}

unsigned char Aes::gfmultby0d(unsigned char b)
{
	return (unsigned char)((int)gfmultby02(gfmultby02(gfmultby02(b))) ^
		(int)gfmultby02(gfmultby02(b)) ^ (int)(b));
}

unsigned char Aes::gfmultby0e(unsigned char b)
{
	return (unsigned char)((int)gfmultby02(gfmultby02(gfmultby02(b))) ^
		(int)gfmultby02(gfmultby02(b)) ^ (int)gfmultby02(b));
}

TAesClass::TAesClass()
{
	m_lpAes = NULL;
}

TAesClass::~TAesClass()
{
	if (m_lpAes != NULL)
	{
		delete m_lpAes;
	}
}
//------------------------------------------------------------------------------------------------------------
// ��д��Ա��wfnhddd
//
// �������ƣ�InitializeAes
//
// ������������ʼ��AES ��Կ����Կ���ڼ��ܽ���
//
// ���ò�������ϸ˵���ο� MSDN �е������������صĿ����ĵ�
//
// ������ֵ����
//
// ����޸ģ�2009 �� 08 �� 07 ��
//------------------------------------------------------------------------------------------------------------


VOID TAesClass::InitializePrivateKey(UCHAR *KeyBytes)
{
	if (m_lpAes)
	{
		delete m_lpAes;
		m_lpAes = NULL;
	}
	m_lpAes = new Aes(Bits256, KeyBytes);

}

//------------------------------------------------------------------------------------------------------------
// ��д��Ա��wfnhddd
//
// �������ƣ�OnAesEncrypt
//
// ������������AES�����㷨��������
//
// ���ò�������ϸ˵���ο� MSDN �е������������صĿ����ĵ�
//
// ������ֵ�����ܺ�����ݴ�С �����󷵻�ֵ  0
//
// ����޸ģ�2009 �� 08 �� 07 ��
//------------------------------------------------------------------------------------------------------------

DWORD TAesClass::OnAesEncrypt(LPVOID InBuffer, DWORD InLength, LPVOID OutBuffer)
{
	DWORD OutLength = 0;
	if (m_lpAes == NULL || OutBuffer == NULL)
	{
		return 0;
	}

	UCHAR *lpCurInBuff = (UCHAR *)InBuffer;
	UCHAR *lpCurOutBuff = (UCHAR *)OutBuffer;
	long blocknum = InLength / 16;
	long leftnum = InLength % 16;
	for (long i = 0; i<blocknum; i++)
	{
		m_lpAes->Cipher(lpCurInBuff, lpCurOutBuff);
		lpCurInBuff += 16;
		lpCurOutBuff += 16;
		OutLength += 16;
	}
	if (leftnum)                   //�����leftnum �ֽ�  �����ʱ ���16-leftnum ���ֽ�
	{
		UCHAR inbuff[16];
		memset(inbuff, 0, 16);
		memcpy(inbuff, lpCurInBuff, leftnum);
		m_lpAes->Cipher(inbuff, lpCurOutBuff);
		lpCurOutBuff += 16;
		OutLength += 16;
	}
	//����16���ֽڣ�����ȷ�����ӵ��ֽ���
	UCHAR extrabuff[16];
	memset(extrabuff, 0, 16);
	*((LPDWORD)extrabuff) = 16 + (16 - leftnum) % 16;      //���16+(16-leftnum)%16���ֽ�
	m_lpAes->Cipher(extrabuff, lpCurOutBuff);
	OutLength += 16;
	return OutLength;

}


//------------------------------------------------------------------------------------------------------------
// ��д��Ա��wfnhddd
//
// �������ƣ�OnAesUncrypt
//
// ������������AES�����㷨��������
//
// ���ò�������ϸ˵���ο� MSDN �е������������صĿ����ĵ�
//
// ������ֵ�����ܺ�����ݴ�С �����󷵻�ֵ  0
//
// ����޸ģ�2009 �� 08 �� 07 ��
//------------------------------------------------------------------------------------------------------------
QString TAesClass::OnAesUncrypt(LPVOID InBuffer, DWORD InLength)
{
	DWORD OutLength = 0;
	if (m_lpAes == NULL)
	{
		return 0;
	}

	char OutBuffer[AesLength];

	UCHAR *lpCurInBuff = (UCHAR *)InBuffer;
	UCHAR *lpCurOutBuff = (UCHAR *)OutBuffer;
	long blocknum = InLength / 16;
	long leftnum = InLength % 16;
	if (leftnum)
	{
		return 0;
	}
	for (long i = 0; i<blocknum; i++)
	{
		m_lpAes->InvCipher(lpCurInBuff, lpCurOutBuff);
		lpCurInBuff += 16;
		lpCurOutBuff += 16;
		OutLength += 16;
	}

	//UCHAR *lpExtraInBuff = lpCurOutBuff - 16;
	//DWORD  dwExtraBytes = *((LPDWORD)lpExtraInBuff);

	char *OutChar = (char *)OutBuffer;
	QString string = QString(QLatin1String(OutChar));

	return string;

}

void TAesClass::initKey(QString strKey)
{
	QByteArray array = strKey.toLatin1();
	UCHAR key[1024] = "";
	for (int i = 0; i < array.count(); i++)
		key[i] = array.at(i);

	UCHAR *p = key;

	InitializePrivateKey(p); //���г�ʼ��
}
