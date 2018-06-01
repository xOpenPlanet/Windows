/****************************************************************************
** Meta object code from reading C++ file 'chatdatamanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chatdatamanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatdatamanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChatDataManager_t {
    QByteArrayData data[21];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatDataManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatDataManager_t qt_meta_stringdata_ChatDataManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ChatDataManager"
QT_MOC_LITERAL(1, 16, 16), // "sigWidgetMinSize"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 19), // "sigShowNormalWindow"
QT_MOC_LITERAL(4, 54, 20), // "sigDealTrayIocnFlash"
QT_MOC_LITERAL(5, 75, 18), // "sigCountMessageNum"
QT_MOC_LITERAL(6, 94, 8), // "recvChat"
QT_MOC_LITERAL(7, 103, 4), // "type"
QT_MOC_LITERAL(8, 108, 7), // "message"
QT_MOC_LITERAL(9, 116, 5), // "buddy"
QT_MOC_LITERAL(10, 122, 15), // "slotClickedChat"
QT_MOC_LITERAL(11, 138, 13), // "slotCloseChat"
QT_MOC_LITERAL(12, 152, 23), // "slotParseGroupBuddyInfo"
QT_MOC_LITERAL(13, 176, 16), // "QList<BuddyInfo>"
QT_MOC_LITERAL(14, 193, 22), // "slotUpdateMessageState"
QT_MOC_LITERAL(15, 216, 11), // "MessageInfo"
QT_MOC_LITERAL(16, 228, 14), // "slotShowPerLog"
QT_MOC_LITERAL(17, 243, 7), // "buddyID"
QT_MOC_LITERAL(18, 251, 16), // "slotOpenGroupLog"
QT_MOC_LITERAL(19, 268, 7), // "groupID"
QT_MOC_LITERAL(20, 276, 21) // "slotRevOtherDeviceMsg"

    },
    "ChatDataManager\0sigWidgetMinSize\0\0"
    "sigShowNormalWindow\0sigDealTrayIocnFlash\0"
    "sigCountMessageNum\0recvChat\0type\0"
    "message\0buddy\0slotClickedChat\0"
    "slotCloseChat\0slotParseGroupBuddyInfo\0"
    "QList<BuddyInfo>\0slotUpdateMessageState\0"
    "MessageInfo\0slotShowPerLog\0buddyID\0"
    "slotOpenGroupLog\0groupID\0slotRevOtherDeviceMsg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatDataManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    1,   81,    2, 0x06 /* Public */,
       5,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    3,   87,    2, 0x0a /* Public */,
       6,    2,   94,    2, 0x2a /* Public | MethodCloned */,
      10,    1,   99,    2, 0x08 /* Private */,
      11,    1,  102,    2, 0x08 /* Private */,
      12,    2,  105,    2, 0x08 /* Private */,
      14,    2,  110,    2, 0x08 /* Private */,
      16,    1,  115,    2, 0x08 /* Private */,
      18,    1,  118,    2, 0x08 /* Private */,
      20,    1,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QVariant, QMetaType::QVariant,    7,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QVariant,    7,    8,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13,    2,    2,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, 0x80000000 | 15,    2,

       0        // eod
};

void ChatDataManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChatDataManager *_t = static_cast<ChatDataManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigWidgetMinSize(); break;
        case 1: _t->sigShowNormalWindow(); break;
        case 2: _t->sigDealTrayIocnFlash((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sigCountMessageNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->recvChat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3]))); break;
        case 5: _t->recvChat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 6: _t->slotClickedChat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->slotCloseChat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->slotParseGroupBuddyInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<BuddyInfo>(*)>(_a[2]))); break;
        case 9: _t->slotUpdateMessageState((*reinterpret_cast< MessageInfo(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->slotShowPerLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->slotOpenGroupLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->slotRevOtherDeviceMsg((*reinterpret_cast< MessageInfo(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ChatDataManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatDataManager::sigWidgetMinSize)) {
                *result = 0;
            }
        }
        {
            typedef void (ChatDataManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatDataManager::sigShowNormalWindow)) {
                *result = 1;
            }
        }
        {
            typedef void (ChatDataManager::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatDataManager::sigDealTrayIocnFlash)) {
                *result = 2;
            }
        }
        {
            typedef void (ChatDataManager::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatDataManager::sigCountMessageNum)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ChatDataManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ChatDataManager.data,
      qt_meta_data_ChatDataManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChatDataManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatDataManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChatDataManager.stringdata0))
        return static_cast<void*>(const_cast< ChatDataManager*>(this));
    return QObject::qt_metacast(_clname);
}

int ChatDataManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ChatDataManager::sigWidgetMinSize()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ChatDataManager::sigShowNormalWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ChatDataManager::sigDealTrayIocnFlash(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChatDataManager::sigCountMessageNum(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
