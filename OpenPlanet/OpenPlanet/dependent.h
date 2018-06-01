#ifndef DEPENDENT_H
#define DEPENDENT_H

#ifdef Q_OS_WIN
#ifdef _DEBUG
#pragma comment(lib,"HttpNetWorkShareLibD.lib")          //Http请求lib库
#pragma comment(lib,"SqlLiteShareLibD.lib")              //数据库基础类
#pragma comment(lib,"IMDataManagerShareLibD.lib")        //数据暂存类
#pragma comment(lib,"LoginDatabaseOperaShareLibD.lib")    //登陆界面操作数据库
#pragma comment(lib,"ScanQRLoginShareLibD.lib")				//扫码登陆窗口
#pragma comment(lib,"IMRequestBuddyInfoD.lib")           //请求好友信息lib
#pragma comment(lib,"ReadAppConfigD.lib")				 //读取配置界面
#pragma comment(lib,"OPObjectManagerD.lib")              //对象管理类
#pragma comment(lib,"AlphabeticalSortSharedLibD.lib")          //拼音库
#pragma comment(lib,"IMDataBaseOperaInfoD.lib")          //数据库操作lib
#pragma comment(lib,"IMSocketNetWorkShareLibD.lib")        //网络socket
#pragma comment(lib,"IMSocketDataBaseShareLibD.lib")       //网络socket数据库
#pragma comment(lib,"SocketNetWorkShareLibD.lib")          //socket基础类
#pragma comment(lib,"OPWindowsManagerShareLibD.lib")       //窗口对象管理类
#pragma comment(lib,"BaseUIShareLibD.lib")                 //UI基础类
#pragma comment(lib,"ContactsWidgetShareLibD.lib")         //联系人窗口类
#pragma comment(lib,"libcef.lib")                          //CEF
#pragma comment(lib,"libcef_dll_wrapper.lib")              //CEF
#pragma comment(lib,"CefWidgetShareLibD.lib")              //CEF框架类
#pragma comment(lib,"ChatWidgetShareLibD.lib")             //聊天窗口类
#pragma comment(lib,"OPMainWidgetShareLibD.lib")           //主窗口类
#pragma comment(lib,"OPMainManagerShareLibD.lib")          //主对象管理类
#pragma comment(lib,"IMDownLoadHeaderImgD.lib")           //下载头像lib
#pragma comment(lib,"VideoPlayShareLibD.lib")             //视频播放类
#pragma comment(lib,"libzvc125.lib")                      //zlib压缩
#pragma comment(lib,"shlwapi.lib")       
#pragma comment(lib,"UpdateShareLibD.lib")                //升级管理类
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
#pragma comment(lib,"HttpNetWorkShareLib.lib")          //Http请求lib库
#pragma comment(lib,"SqlLiteShareLib.lib") 
#pragma comment(lib,"IMDataManagerShareLib.lib") 
#pragma comment(lib,"LoginDatabaseOperaShareLib.lib")   //登陆界面操作数据库
#pragma comment(lib,"IMRequestBuddyInfo.lib")          //Http请求lib库
#pragma comment(lib,"ReadAppConfig.lib")				 //读取配置界面
#pragma comment(lib,"OPObjectManager.lib")          //Http请求lib库
#pragma comment(lib,"AlphabeticalSortSharedLib.lib")          //Http请求lib库
#pragma comment(lib,"IMDataBaseOperaInfo.lib")          //数据库操作lib
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
#pragma comment(lib,"VideoPlayShareLib.lib")             //视频播放类
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