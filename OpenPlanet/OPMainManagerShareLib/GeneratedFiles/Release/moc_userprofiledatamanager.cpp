/****************************************************************************
** Meta object code from reading C++ file 'userprofiledatamanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../userprofiledatamanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userprofiledatamanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserProfileDataManager_t {
    QByteArrayData data[8];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserProfileDataManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserProfileDataManager_t qt_meta_stringdata_UserProfileDataManager = {
    {
QT_MOC_LITERAL(0, 0, 22), // "UserProfileDataManager"
QT_MOC_LITERAL(1, 23, 17), // "slotProfileWidget"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 21), // "slotUploadHeaderImage"
QT_MOC_LITERAL(4, 64, 20), // "slotHttpChangeAvatar"
QT_MOC_LITERAL(5, 85, 17), // "slotAvatarChanged"
QT_MOC_LITERAL(6, 103, 12), // "slotUserInfo"
QT_MOC_LITERAL(7, 116, 8) // "UserInfo"

    },
    "UserProfileDataManager\0slotProfileWidget\0"
    "\0slotUploadHeaderImage\0slotHttpChangeAvatar\0"
    "slotAvatarChanged\0slotUserInfo\0UserInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserProfileDataManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    1,   40,    2, 0x08 /* Private */,
       4,    2,   43,    2, 0x08 /* Private */,
       5,    2,   48,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void UserProfileDataManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserProfileDataManager *_t = static_cast<UserProfileDataManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotProfileWidget(); break;
        case 1: _t->slotUploadHeaderImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotHttpChangeAvatar((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 3: _t->slotAvatarChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->slotUserInfo((*reinterpret_cast< UserInfo(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject UserProfileDataManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UserProfileDataManager.data,
      qt_meta_data_UserProfileDataManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserProfileDataManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserProfileDataManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserProfileDataManager.stringdata0))
        return static_cast<void*>(const_cast< UserProfileDataManager*>(this));
    return QObject::qt_metacast(_clname);
}

int UserProfileDataManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
