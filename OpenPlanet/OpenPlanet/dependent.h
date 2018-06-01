#ifndef DEPENDENT_H
#define DEPENDENT_H

#ifdef Q_OS_WIN
#ifdef _DEBUG
#pragma comment(lib,"HttpNetWorkShareLibD.lib")          //Http����lib��
#pragma comment(lib,"SqlLiteShareLibD.lib")              //���ݿ������
#pragma comment(lib,"IMDataManagerShareLibD.lib")        //�����ݴ���
#pragma comment(lib,"LoginDatabaseOperaShareLibD.lib")    //��½����������ݿ�
#pragma comment(lib,"ScanQRLoginShareLibD.lib")				//ɨ���½����
#pragma comment(lib,"IMRequestBuddyInfoD.lib")           //���������Ϣlib
#pragma comment(lib,"ReadAppConfigD.lib")				 //��ȡ���ý���
#pragma comment(lib,"OPObjectManagerD.lib")              //���������
#pragma comment(lib,"AlphabeticalSortSharedLibD.lib")          //ƴ����
#pragma comment(lib,"IMDataBaseOperaInfoD.lib")          //���ݿ����lib
#pragma comment(lib,"IMSocketNetWorkShareLibD.lib")        //����socket
#pragma comment(lib,"IMSocketDataBaseShareLibD.lib")       //����socket���ݿ�
#pragma comment(lib,"SocketNetWorkShareLibD.lib")          //socket������
#pragma comment(lib,"OPWindowsManagerShareLibD.lib")       //���ڶ��������
#pragma comment(lib,"BaseUIShareLibD.lib")                 //UI������
#pragma comment(lib,"ContactsWidgetShareLibD.lib")         //��ϵ�˴�����
#pragma comment(lib,"libcef.lib")                          //CEF
#pragma comment(lib,"libcef_dll_wrapper.lib")              //CEF
#pragma comment(lib,"CefWidgetShareLibD.lib")              //CEF�����
#pragma comment(lib,"ChatWidgetShareLibD.lib")             //���촰����
#pragma comment(lib,"OPMainWidgetShareLibD.lib")           //��������
#pragma comment(lib,"OPMainManagerShareLibD.lib")          //�����������
#pragma comment(lib,"IMDownLoadHeaderImgD.lib")           //����ͷ��lib
#pragma comment(lib,"VideoPlayShareLibD.lib")             //��Ƶ������
#pragma comment(lib,"libzvc125.lib")                      //zlibѹ��
#pragma comment(lib,"shlwapi.lib")       
#pragma comment(lib,"UpdateShareLibD.lib")                //����������
#pragma comment(lib,"libzbar-0.lib")
#pragma comment(lib,"eWalletLibD.lib")
#pragma comment(lib,"QRenCodeShareLibD.lib")
#pragma comment(lib,"libqrencodeD.lib")
#pragma comment(lib,"OPRecoveryWalletShareLibD.lib")
#pragma comment(lib,"CreateAddWidgetShareLibD.lib")
#pragma comment(lib,"OPDatebaseShareLibD.lib")
#pragma comment(lib,"OPDataManagerD.lib")
#pragma comment(lib,"OPRequestShareLibD.lib")
#pragma comment(lib,"ContactsProfileShareLibD.lib")
#else
#pragma comment(lib,"HttpNetWorkShareLib.lib")          //Http����lib��
#pragma comment(lib,"SqlLiteShareLib.lib") 
#pragma comment(lib,"IMDataManagerShareLib.lib") 
#pragma comment(lib,"LoginDatabaseOperaShareLib.lib")   //��½����������ݿ�
#pragma comment(lib,"IMRequestBuddyInfo.lib")          //Http����lib��
#pragma comment(lib,"ReadAppConfig.lib")				 //��ȡ���ý���
#pragma comment(lib,"OPObjectManager.lib")          //Http����lib��
#pragma comment(lib,"AlphabeticalSortSharedLib.lib")          //Http����lib��
#pragma comment(lib,"IMDataBaseOperaInfo.lib")          //���ݿ����lib
#pragma comment(lib,"IMSocketNetWorkShareLib.lib")        
#pragma comment(lib,"IMSocketDataBaseShareLib.lib")       
#pragma comment(lib,"SocketNetWorkShareLib.lib")  
#pragma comment(lib,"OPWindowsManagerShareLib.lib") 
#pragma comment(lib,"BaseUIShareLib.lib") 
#pragma comment(lib,"ContactsWidgetShareLib.lib") 
#pragma comment(lib,"libcef.lib")
#pragma comment(lib,"libcef_dll_wrapper.lib")
#pragma comment(lib,"CefWidgetShareLib.lib")
#pragma comment(lib,"ChatWidgetShareLib.lib")
#pragma comment(lib,"OPMainWidgetShareLib.lib") 
#pragma comment(lib,"OPMainManagerShareLib.lib") 
#pragma comment(lib,"IMDownLoadHeaderImg.lib") 
#pragma comment(lib,"VideoPlayShareLib.lib")             //��Ƶ������
#pragma comment(lib,"libzvc125.lib")
#pragma comment(lib,"UpdateShareLib.lib")
#pragma comment(lib,"shlwapi.lib")       
#pragma comment(lib,"libzbar-0.lib")
#pragma comment(lib,"eWalletLib.lib")
#pragma comment(lib,"ScanQRLoginShareLib.lib")
#pragma comment(lib,"QRenCodeShareLib.lib")
#pragma comment(lib,"libqrencode.lib")
#pragma comment(lib,"OPRecoveryWalletShareLib.lib")
#pragma comment(lib,"CreateAddWidgetShareLib.lib")
#pragma comment(lib,"OPDatebaseShareLib.lib")
#pragma comment(lib,"OPDataManager.lib")
#pragma comment(lib,"OPRequestShareLib.lib")
#pragma comment(lib,"ContactsProfileShareLib.lib")
#endif
#endif

#endif // DEPENDENT_H