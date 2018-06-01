/****************************************************************************
** Meta object code from reading C++ file 'contactsdatamanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../contactsdatamanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contactsdatamanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ContactsDataManager_t {
    QByteArrayData data[8];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ContactsDataManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ContactsDataManager_t qt_meta_stringdata_ContactsDataManager = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ContactsDataManager"
QT_MOC_LITERAL(1, 20, 17), // "sigAddCreateGroup"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 12), // "sigAddPerson"
QT_MOC_LITERAL(4, 52, 11), // "sigOpenChat"
QT_MOC_LITERAL(5, 64, 15), // "slotAddressInfo"
QT_MOC_LITERAL(6, 80, 14), // "slotPerProfile"
QT_MOC_LITERAL(7, 95, 16) // "slotGroupProfile"

    },
    "ContactsDataManager\0sigAddCreateGroup\0"
    "\0sigAddPerson\0sigOpenChat\0slotAddressInfo\0"
    "slotPerProfile\0slotGroupProfile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ContactsDataManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    2,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   51,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       7,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QVariant,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void ContactsDataManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ContactsDataManager *_t = static_cast<ContactsDataManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigAddCreateGroup(); break;
        case 1: _t->sigAddPerson(); break;
        case 2: _t->sigOpenChat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 3: _t->slotAddressInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slotPerProfile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->slotGroupProfile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ContactsDataManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactsDataManager::sigAddCreateGroup)) {
                *result = 0;
            }
        }
        {
            typedef void (ContactsDataManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactsDataManager::sigAddPerson)) {
                *result = 1;
            }
        }
        {
            typedef void (ContactsDataManager::*_t)(int , QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactsDataManager::sigOpenChat)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject ContactsDataManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ContactsDataManager.data,
      qt_meta_data_ContactsDataManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ContactsDataManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContactsDataManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ContactsDataManager.stringdata0))
        return static_cast<void*>(const_cast< ContactsDataManager*>(this));
    return QObject::qt_metacast(_clname);
}

int ContactsDataManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ContactsDataManager::sigAddCreateGroup()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ContactsDataManager::sigAddPerson()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ContactsDataManager::sigOpenChat(int _t1, QVariant _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
