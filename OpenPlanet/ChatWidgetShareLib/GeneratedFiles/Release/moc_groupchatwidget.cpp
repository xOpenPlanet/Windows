/****************************************************************************
** Meta object code from reading C++ file 'groupchatwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../groupchatwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'groupchatwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GroupChatWidget_t {
    QByteArrayData data[70];
    char stringdata0[1129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GroupChatWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GroupChatWidget_t qt_meta_stringdata_GroupChatWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "GroupChatWidget"
QT_MOC_LITERAL(1, 16, 8), // "sigClose"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "sigShowPerChat"
QT_MOC_LITERAL(4, 41, 9), // "strUserID"
QT_MOC_LITERAL(5, 51, 19), // "sigBtnCloseWClicked"
QT_MOC_LITERAL(6, 71, 12), // "sigKeyUpDown"
QT_MOC_LITERAL(7, 84, 10), // "QKeyEvent*"
QT_MOC_LITERAL(8, 95, 20), // "sigGroupBuddyPerChat"
QT_MOC_LITERAL(9, 116, 9), // "sigCancle"
QT_MOC_LITERAL(10, 126, 20), // "sigShowWindowMinsize"
QT_MOC_LITERAL(11, 147, 19), // "sigShowNormalWindow"
QT_MOC_LITERAL(12, 167, 17), // "sigOpenMessageLog"
QT_MOC_LITERAL(13, 185, 16), // "slotClickedClose"
QT_MOC_LITERAL(14, 202, 17), // "slotClickedCutPic"
QT_MOC_LITERAL(15, 220, 18), // "slotClickedExpress"
QT_MOC_LITERAL(16, 239, 15), // "slotClickedFont"
QT_MOC_LITERAL(17, 255, 18), // "slotClickedPicture"
QT_MOC_LITERAL(18, 274, 15), // "slotClickedSend"
QT_MOC_LITERAL(19, 290, 16), // "slotClickedShake"
QT_MOC_LITERAL(20, 307, 20), // "slotClickedVoiceChat"
QT_MOC_LITERAL(21, 328, 26), // "slotExpressNormalImagePath"
QT_MOC_LITERAL(22, 355, 7), // "strPath"
QT_MOC_LITERAL(23, 363, 21), // "slotClickedDoubleItem"
QT_MOC_LITERAL(24, 385, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(25, 402, 4), // "item"
QT_MOC_LITERAL(26, 407, 22), // "slotOnBtnCloseWClicked"
QT_MOC_LITERAL(27, 430, 13), // "slotGroupFile"
QT_MOC_LITERAL(28, 444, 20), // "doUpLoadFileProgress"
QT_MOC_LITERAL(29, 465, 7), // "sendnum"
QT_MOC_LITERAL(30, 473, 5), // "total"
QT_MOC_LITERAL(31, 479, 24), // "slotDownLoadFileProgress"
QT_MOC_LITERAL(32, 504, 22), // "slotUpPicReplyFinished"
QT_MOC_LITERAL(33, 527, 6), // "result"
QT_MOC_LITERAL(34, 534, 9), // "strResult"
QT_MOC_LITERAL(35, 544, 24), // "slotStartGroupUserThread"
QT_MOC_LITERAL(36, 569, 21), // "slotGroupUserInfoLoad"
QT_MOC_LITERAL(37, 591, 27), // "slotThreadLoadGroupUserInfo"
QT_MOC_LITERAL(38, 619, 9), // "BuddyInfo"
QT_MOC_LITERAL(39, 629, 9), // "buddyInfo"
QT_MOC_LITERAL(40, 639, 23), // "slotReLoadGroupUserList"
QT_MOC_LITERAL(41, 663, 25), // "slotUpdateGroupBuddyImage"
QT_MOC_LITERAL(42, 689, 12), // "slotCefDrags"
QT_MOC_LITERAL(43, 702, 4), // "list"
QT_MOC_LITERAL(44, 707, 23), // "slotParseGroupBuddyInfo"
QT_MOC_LITERAL(45, 731, 16), // "QList<BuddyInfo>"
QT_MOC_LITERAL(46, 748, 23), // "slotUpFileReplyFinished"
QT_MOC_LITERAL(47, 772, 11), // "slotGetFile"
QT_MOC_LITERAL(48, 784, 5), // "msgID"
QT_MOC_LITERAL(49, 790, 12), // "slotSaveFile"
QT_MOC_LITERAL(50, 803, 25), // "slotRequestHttpFileResult"
QT_MOC_LITERAL(51, 829, 16), // "slotOpenDocument"
QT_MOC_LITERAL(52, 846, 17), // "slotOpenGroupFile"
QT_MOC_LITERAL(53, 864, 11), // "slotZoomImg"
QT_MOC_LITERAL(54, 876, 11), // "strFileName"
QT_MOC_LITERAL(55, 888, 13), // "slotVideoPlay"
QT_MOC_LITERAL(56, 902, 9), // "mediaPath"
QT_MOC_LITERAL(57, 912, 24), // "slotCancleLoadorDownLoad"
QT_MOC_LITERAL(58, 937, 12), // "slotSendFile"
QT_MOC_LITERAL(59, 950, 16), // "slotSendFileByID"
QT_MOC_LITERAL(60, 967, 24), // "slotContextMenuRequested"
QT_MOC_LITERAL(61, 992, 3), // "pos"
QT_MOC_LITERAL(62, 996, 14), // "slotSetManager"
QT_MOC_LITERAL(63, 1011, 17), // "slotCancelManager"
QT_MOC_LITERAL(64, 1029, 13), // "slotAddFriend"
QT_MOC_LITERAL(65, 1043, 27), // "slotHttpAddPersonResultInfo"
QT_MOC_LITERAL(66, 1071, 7), // "bResult"
QT_MOC_LITERAL(67, 1079, 20), // "slotShowOrHideSearch"
QT_MOC_LITERAL(68, 1100, 18), // "slotOpenSearchUser"
QT_MOC_LITERAL(69, 1119, 9) // "slotDebug"

    },
    "GroupChatWidget\0sigClose\0\0sigShowPerChat\0"
    "strUserID\0sigBtnCloseWClicked\0"
    "sigKeyUpDown\0QKeyEvent*\0sigGroupBuddyPerChat\0"
    "sigCancle\0sigShowWindowMinsize\0"
    "sigShowNormalWindow\0sigOpenMessageLog\0"
    "slotClickedClose\0slotClickedCutPic\0"
    "slotClickedExpress\0slotClickedFont\0"
    "slotClickedPicture\0slotClickedSend\0"
    "slotClickedShake\0slotClickedVoiceChat\0"
    "slotExpressNormalImagePath\0strPath\0"
    "slotClickedDoubleItem\0QListWidgetItem*\0"
    "item\0slotOnBtnCloseWClicked\0slotGroupFile\0"
    "doUpLoadFileProgress\0sendnum\0total\0"
    "slotDownLoadFileProgress\0"
    "slotUpPicReplyFinished\0result\0strResult\0"
    "slotStartGroupUserThread\0slotGroupUserInfoLoad\0"
    "slotThreadLoadGroupUserInfo\0BuddyInfo\0"
    "buddyInfo\0slotReLoadGroupUserList\0"
    "slotUpdateGroupBuddyImage\0slotCefDrags\0"
    "list\0slotParseGroupBuddyInfo\0"
    "QList<BuddyInfo>\0slotUpFileReplyFinished\0"
    "slotGetFile\0msgID\0slotSaveFile\0"
    "slotRequestHttpFileResult\0slotOpenDocument\0"
    "slotOpenGroupFile\0slotZoomImg\0strFileName\0"
    "slotVideoPlay\0mediaPath\0"
    "slotCancleLoadorDownLoad\0slotSendFile\0"
    "slotSendFileByID\0slotContextMenuRequested\0"
    "pos\0slotSetManager\0slotCancelManager\0"
    "slotAddFriend\0slotHttpAddPersonResultInfo\0"
    "bResult\0slotShowOrHideSearch\0"
    "slotOpenSearchUser\0slotDebug"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupChatWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      50,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  264,    2, 0x06 /* Public */,
       3,    1,  265,    2, 0x06 /* Public */,
       5,    0,  268,    2, 0x06 /* Public */,
       6,    1,  269,    2, 0x06 /* Public */,
       8,    1,  272,    2, 0x06 /* Public */,
       9,    0,  275,    2, 0x06 /* Public */,
      10,    0,  276,    2, 0x06 /* Public */,
      11,    0,  277,    2, 0x06 /* Public */,
      12,    0,  278,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  279,    2, 0x08 /* Private */,
      14,    0,  280,    2, 0x08 /* Private */,
      15,    0,  281,    2, 0x08 /* Private */,
      16,    0,  282,    2, 0x08 /* Private */,
      17,    0,  283,    2, 0x08 /* Private */,
      18,    0,  284,    2, 0x08 /* Private */,
      19,    0,  285,    2, 0x08 /* Private */,
      20,    0,  286,    2, 0x08 /* Private */,
      21,    1,  287,    2, 0x08 /* Private */,
      23,    1,  290,    2, 0x08 /* Private */,
      26,    0,  293,    2, 0x08 /* Private */,
      27,    0,  294,    2, 0x08 /* Private */,
      28,    2,  295,    2, 0x08 /* Private */,
      31,    2,  300,    2, 0x08 /* Private */,
      32,    2,  305,    2, 0x08 /* Private */,
      35,    0,  310,    2, 0x08 /* Private */,
      36,    1,  311,    2, 0x08 /* Private */,
      37,    1,  314,    2, 0x08 /* Private */,
      40,    0,  317,    2, 0x08 /* Private */,
      41,    2,  318,    2, 0x08 /* Private */,
      42,    1,  323,    2, 0x08 /* Private */,
      44,    2,  326,    2, 0x08 /* Private */,
      46,    2,  331,    2, 0x0a /* Public */,
      47,    1,  336,    2, 0x0a /* Public */,
      49,    1,  339,    2, 0x0a /* Public */,
      50,    1,  342,    2, 0x0a /* Public */,
      51,    1,  345,    2, 0x0a /* Public */,
      52,    1,  348,    2, 0x0a /* Public */,
      53,    1,  351,    2, 0x0a /* Public */,
      55,    1,  354,    2, 0x0a /* Public */,
      57,    0,  357,    2, 0x0a /* Public */,
      58,    1,  358,    2, 0x0a /* Public */,
      59,    1,  361,    2, 0x0a /* Public */,
      60,    1,  364,    2, 0x08 /* Private */,
      62,    0,  367,    2, 0x08 /* Private */,
      63,    0,  368,    2, 0x08 /* Private */,
      64,    0,  369,    2, 0x08 /* Private */,
      65,    2,  370,    2, 0x08 /* Private */,
      67,    1,  375,    2, 0x08 /* Private */,
      68,    1,  378,    2, 0x08 /* Private */,
      69,    2,  381,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   29,   30,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QByteArray,   33,   34,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 38,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap,    2,    2,
    QMetaType::Void, QMetaType::QStringList,   43,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 45,    2,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Bool, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::Bool,   33,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::QString,   54,
    QMetaType::Void, QMetaType::QString,   56,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   54,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::QPoint,   61,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   66,   34,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,

       0        // eod
};

void GroupChatWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupChatWidget *_t = static_cast<GroupChatWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigClose(); break;
        case 1: _t->sigShowPerChat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sigBtnCloseWClicked(); break;
        case 3: _t->sigKeyUpDown((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 4: _t->sigGroupBuddyPerChat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sigCancle(); break;
        case 6: _t->sigShowWindowMinsize(); break;
        case 7: _t->sigShowNormalWindow(); break;
        case 8: _t->sigOpenMessageLog(); break;
        case 9: _t->slotClickedClose(); break;
        case 10: _t->slotClickedCutPic(); break;
        case 11: _t->slotClickedExpress(); break;
        case 12: _t->slotClickedFont(); break;
        case 13: _t->slotClickedPicture(); break;
        case 14: _t->slotClickedSend(); break;
        case 15: _t->slotClickedShake(); break;
        case 16: _t->slotClickedVoiceChat(); break;
        case 17: _t->slotExpressNormalImagePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->slotClickedDoubleItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 19: _t->slotOnBtnCloseWClicked(); break;
        case 20: _t->slotGroupFile(); break;
        case 21: _t->doUpLoadFileProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 22: _t->slotDownLoadFileProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 23: _t->slotUpPicReplyFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 24: _t->slotStartGroupUserThread(); break;
        case 25: _t->slotGroupUserInfoLoad((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->slotThreadLoadGroupUserInfo((*reinterpret_cast< BuddyInfo(*)>(_a[1]))); break;
        case 27: _t->slotReLoadGroupUserList(); break;
        case 28: _t->slotUpdateGroupBuddyImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QPixmap(*)>(_a[2]))); break;
        case 29: _t->slotCefDrags((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 30: _t->slotParseGroupBuddyInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<BuddyInfo>(*)>(_a[2]))); break;
        case 31: _t->slotUpFileReplyFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 32: _t->slotGetFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 33: { bool _r = _t->slotSaveFile((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 34: _t->slotRequestHttpFileResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->slotOpenDocument((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 36: _t->slotOpenGroupFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 37: _t->slotZoomImg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 38: _t->slotVideoPlay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 39: _t->slotCancleLoadorDownLoad(); break;
        case 40: _t->slotSendFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 41: _t->slotSendFileByID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 42: _t->slotContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 43: _t->slotSetManager(); break;
        case 44: _t->slotCancelManager(); break;
        case 45: _t->slotAddFriend(); break;
        case 46: _t->slotHttpAddPersonResultInfo((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 47: _t->slotShowOrHideSearch((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 48: _t->slotOpenSearchUser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 49: _t->slotDebug((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GroupChatWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupChatWidget::sigClose)) {
                *result = 0;
            }
        }
        {
            typedef void (GroupChatWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupChatWidget::sigShowPerChat)) {
                *result = 1;
            }
        }
        {
            typedef void (GroupChatWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupChatWidget::sigBtnCloseWClicked)) {
                *result = 2;
            }
        }
        {
            typedef void (GroupChatWidget::*_t)(QKeyEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupChatWidget::sigKeyUpDown)) {
                *result = 3;
            }
        }
        {
            typedef void (GroupChatWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupChatWidget::sigGroupBuddyPerChat)) {
                *result = 4;
            }
        }
        {
            typedef void (GroupChatWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupChatWidget::sigCancle)) {
                *result = 5;
            }
        }
        {
            typedef void (GroupChatWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupChatWidget::sigShowWindowMinsize)) {
                *result = 6;
            }
        }
        {
            typedef void (GroupChatWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupChatWidget::sigShowNormalWindow)) {
                *result = 7;
            }
        }
        {
            typedef void (GroupChatWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupChatWidget::sigOpenMessageLog)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject GroupChatWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GroupChatWidget.data,
      qt_meta_data_GroupChatWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GroupChatWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupChatWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GroupChatWidget.stringdata0))
        return static_cast<void*>(const_cast< GroupChatWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int GroupChatWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 50)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 50;
    }
    return _id;
}

// SIGNAL 0
void GroupChatWidget::sigClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void GroupChatWidget::sigShowPerChat(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GroupChatWidget::sigBtnCloseWClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void GroupChatWidget::sigKeyUpDown(QKeyEvent * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GroupChatWidget::sigGroupBuddyPerChat(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GroupChatWidget::sigCancle()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void GroupChatWidget::sigShowWindowMinsize()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void GroupChatWidget::sigShowNormalWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void GroupChatWidget::sigOpenMessageLog()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
