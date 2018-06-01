/****************************************************************************
** Meta object code from reading C++ file 'ewalletmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ewalletmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ewalletmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EWalletManager_t {
    QByteArrayData data[9];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EWalletManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EWalletManager_t qt_meta_stringdata_EWalletManager = {
    {
QT_MOC_LITERAL(0, 0, 14), // "EWalletManager"
QT_MOC_LITERAL(1, 15, 11), // "slotRefresh"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "slotSetIntegral"
QT_MOC_LITERAL(4, 44, 14), // "slotSetBalance"
QT_MOC_LITERAL(5, 59, 12), // "slotTransfer"
QT_MOC_LITERAL(6, 72, 7), // "otherID"
QT_MOC_LITERAL(7, 80, 9), // "toAddress"
QT_MOC_LITERAL(8, 90, 5) // "value"

    },
    "EWalletManager\0slotRefresh\0\0slotSetIntegral\0"
    "slotSetBalance\0slotTransfer\0otherID\0"
    "toAddress\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EWalletManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x08 /* Private */,
       4,    1,   38,    2, 0x08 /* Private */,
       5,    3,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    8,

       0        // eod
};

void EWalletManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EWalletManager *_t = static_cast<EWalletManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotRefresh(); break;
        case 1: _t->slotSetIntegral((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotSetBalance((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slotTransfer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject EWalletManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EWalletManager.data,
      qt_meta_data_EWalletManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EWalletManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EWalletManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EWalletManager.stringdata0))
        return static_cast<void*>(const_cast< EWalletManager*>(this));
    return QObject::qt_metacast(_clname);
}

int EWalletManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
