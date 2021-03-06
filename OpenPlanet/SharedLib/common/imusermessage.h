#ifndef IMUSERMESSAGE_H
#define IMUSERMESSAGE_H

#include <QObject>

enum MessageState
{
	MESSAGE_STATE_WAITSEND = 0, //待发送
	MESSAGE_STATE_PRESEND,      //预发送
	MESSAGE_STATE_SENDING,      //发送中
	MESSAGE_STATE_DELIVER,      //已投递
	MESSAGE_STATE_SEND,         //已发送
	MESSAGE_STATE_RECEIVE,      //已送达
	MESSAGE_STATE_READ,         //已查看
	MESSAGE_STATE_UNREAD,       //未查看
	//	MESSAGE_STATE_DELETE,   //删除
	MESSAGE_STATE_FAILURE     //发送失败
};

enum MessageType
{
	Message_TEXT = 0,        //文本消息
	Message_PIC = 1,         //图片消息
	Message_AUDIO=2,         //音频消息
	Message_VEDIO=3,         //视频消息
	Message_FILE = 5,        //文件消息
	Message_COMMON = 62,     //通用消息
	Message_ROBOT=85,        //机器人消息
	Message_SYSTEM = 100,    //系统消息
	Message_RECEIPT = 101,    //已送达消息
	Message_VIEW = 102,       //已查看消息
	MessageRecordAll = 1000  //全部消息
};

/*消息体*/
typedef struct Message :QObjectUserData
{
	short version;         //版本号
	int nFromUserID;       //发送者ID
	int nToUserID;         //接收者ID
	qlonglong ClientTime;       //客户端时间
	qlonglong ServerTime;       //服务器时间
	int nMsgOrder;         //int 随机数
	unsigned char MsgDeliverType;   //消息投递类型
	short MessageChildType; //消息子类型
	QString strMsg;       //消息内容
	unsigned char isHavePMsgId;    //是否有PMsgID
	QByteArray PMSGID;
	int nUserID;
	unsigned char PerByte[10];
	QByteArray msgID;
	int MessageState;     //消息状态
	unsigned long long SendTime;  //发送时间
	unsigned char offLineFlag;    //离线消息标志
	unsigned char interalTypeMain;    //积分主类型
	unsigned char interalTypeVice;    //积分副类型
	short integral;                 //积分
}MessageInfo;
Q_DECLARE_METATYPE(MessageInfo);

#endif // IMUSERMESSAGE_H
