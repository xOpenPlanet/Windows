/****************************************************************************
** Meta object code from reading C++ file 'parsesystemmessage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../parsesystemmessage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parsesystemmessage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParseSystemMessage_t {
    QByteArrayData data[30];
    char stringdata0[415];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParseSystemMessage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParseSystemMessage_t qt_meta_stringdata_ParseSystemMessage = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ParseSystemMessage"
QT_MOC_LITERAL(1, 19, 17), // "sigUpdateUserInfo"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 8), // "UserInfo"
QT_MOC_LITERAL(4, 47, 8), // "userInfo"
QT_MOC_LITERAL(5, 56, 13), // "sigUpdateInfo"
QT_MOC_LITERAL(6, 70, 19), // "sigAddFriendSuccess"
QT_MOC_LITERAL(7, 90, 9), // "BuddyInfo"
QT_MOC_LITERAL(8, 100, 18), // "sigAddSuccessGroup"
QT_MOC_LITERAL(9, 119, 9), // "GroupInfo"
QT_MOC_LITERAL(10, 129, 26), // "sigAddSuccessGroupUserInfo"
QT_MOC_LITERAL(11, 156, 10), // "strGroupID"
QT_MOC_LITERAL(12, 167, 5), // "buddy"
QT_MOC_LITERAL(13, 173, 16), // "sigUserQuitGroup"
QT_MOC_LITERAL(14, 190, 7), // "groupID"
QT_MOC_LITERAL(15, 198, 6), // "userID"
QT_MOC_LITERAL(16, 205, 15), // "sigDeleteFriend"
QT_MOC_LITERAL(17, 221, 4), // "type"
QT_MOC_LITERAL(18, 226, 14), // "sigDeleteGroup"
QT_MOC_LITERAL(19, 241, 29), // "slotRequestPersonInfoFinished"
QT_MOC_LITERAL(20, 271, 7), // "bResult"
QT_MOC_LITERAL(21, 279, 6), // "result"
QT_MOC_LITERAL(22, 286, 28), // "slotRequestGroupInfoFinished"
QT_MOC_LITERAL(23, 315, 20), // "slotRecvAddGroupUser"
QT_MOC_LITERAL(24, 336, 7), // "success"
QT_MOC_LITERAL(25, 344, 4), // "data"
QT_MOC_LITERAL(26, 349, 26), // "slotUpdateBuddyHeaderImage"
QT_MOC_LITERAL(27, 376, 7), // "buddyID"
QT_MOC_LITERAL(28, 384, 3), // "pix"
QT_MOC_LITERAL(29, 388, 26) // "slotUpdateGroupHeaderImage"

    },
    "ParseSystemMessage\0sigUpdateUserInfo\0"
    "\0UserInfo\0userInfo\0sigUpdateInfo\0"
    "sigAddFriendSuccess\0BuddyInfo\0"
    "sigAddSuccessGroup\0GroupInfo\0"
    "sigAddSuccessGroupUserInfo\0strGroupID\0"
    "buddy\0sigUserQuitGroup\0groupID\0userID\0"
    "sigDeleteFriend\0type\0sigDeleteGroup\0"
    "slotRequestPersonInfoFinished\0bResult\0"
    "result\0slotRequestGroupInfoFinished\0"
    "slotRecvAddGroupUser\0success\0data\0"
    "slotUpdateBuddyHeaderImage\0buddyID\0"
    "pix\0slotUpdateGroupHeaderImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParseSystemMessage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       5,    2,   82,    2, 0x06 /* Public */,
       6,    1,   87,    2, 0x06 /* Public */,
       8,    1,   90,    2, 0x06 /* Public */,
      10,    2,   93,    2, 0x06 /* Public */,
      13,    2,   98,    2, 0x06 /* Public */,
      16,    2,  103,    2, 0x06 /* Public */,
      18,    1,  108,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    2,  111,    2, 0x08 /* Private */,
      22,    2,  116,    2, 0x08 /* Private */,
      23,    2,  121,    2, 0x08 /* Private */,
      26,    2,  126,    2, 0x08 /* Private */,
      29,    2,  131,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QVariant,    2,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::QVariant,   17,   15,
    QMetaType::Void, QMetaType::QString,   14,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   20,   21,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   20,   21,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   24,   25,
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap,   27,   28,
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap,   27,   28,

       0        // eod
};

void ParseSystemMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ParseSystemMessage *_t = static_cast<ParseSystemMessage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUpdateUserInfo((*reinterpret_cast< UserInfo(*)>(_a[1]))); break;
        case 1: _t->sigUpdateInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 2: _t->sigAddFriendSuccess((*reinterpret_cast< BuddyInfo(*)>(_a[1]))); break;
        case 3: _t->sigAddSuccessGroup((*reinterpret_cast< GroupInfo(*)>(_a[1]))); break;
        case 4: _t->sigAddSuccessGroupUserInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< BuddyInfo(*)>(_a[2]))); break;
        case 5: _t->sigUserQuitGroup((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->sigDeleteFriend((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 7: _t->sigDeleteGroup((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->slotRequestPersonInfoFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->slotRequestGroupInfoFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->slotRecvAddGroupUser((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->slotUpdateBuddyHeaderImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QPixmap(*)>(_a[2]))); break;
        case 12: _t->slotUpdateGroupHeaderImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QPixmap(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ParseSystemMessage::*_t)(UserInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParseSystemMessage::sigUpdateUserInfo)) {
                *result = 0;
            }
        }
        {
            typedef void (ParseSystemMessage::*_t)(int , QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParseSystemMessage::sigUpdateInfo)) {
                *result = 1;
            }
        }
        {
            typedef void (ParseSystemMessage::*_t)(BuddyInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParseSystemMessage::sigAddFriendSuccess)) {
                *result = 2;
            }
        }
        {
            typedef void (ParseSystemMessage::*_t)(GroupInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParseSystemMessage::sigAddSuccessGroup)) {
                *result = 3;
            }
        }
        {
            typedef void (ParseSystemMessage::*_t)(QString , BuddyInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParseSystemMessage::sigAddSuccessGroupUserInfo)) {
                *result = 4;
            }
        }
        {
            typedef void (ParseSystemMessage::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParseSystemMessage::sigUserQuitGroup)) {
                *result = 5;
            }
        }
        {
            typedef void (ParseSystemMessage::*_t)(int , QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParseSystemMessage::sigDeleteFriend)) {
                *result = 6;
            }
        }
        {
            typedef void (ParseSystemMessage::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParseSystemMessage::sigDeleteGroup)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject ParseSystemMessage::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ParseSystemMessage.data,
      qt_meta_data_ParseSystemMessage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ParseSystemMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParseSystemMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ParseSystemMessage.stringdata0))
        return static_cast<void*>(const_cast< ParseSystemMessage*>(this));
    return QObject::qt_metacast(_clname);
}

int ParseSystemMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ParseSystemMessage::sigUpdateUserInfo(UserInfo _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ParseSystemMessage::sigUpdateInfo(int _t1, QVariant _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ParseSystemMessage::sigAddFriendSuccess(BuddyInfo _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ParseSystemMessage::sigAddSuccessGroup(GroupInfo _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ParseSystemMessage::sigAddSuccessGroupUserInfo(QString _t1, BuddyInfo _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ParseSystemMessage::sigUserQuitGroup(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ParseSystemMessage::sigDeleteFriend(int _t1, QVariant _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ParseSystemMessage::sigDeleteGroup(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
