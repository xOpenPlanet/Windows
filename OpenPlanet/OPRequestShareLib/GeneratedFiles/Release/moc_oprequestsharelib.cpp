/****************************************************************************
** Meta object code from reading C++ file 'oprequestsharelib.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../oprequestsharelib.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'oprequestsharelib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OPRequestShareLib_t {
    QByteArrayData data[12];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OPRequestShareLib_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OPRequestShareLib_t qt_meta_stringdata_OPRequestShareLib = {
    {
QT_MOC_LITERAL(0, 0, 17), // "OPRequestShareLib"
QT_MOC_LITERAL(1, 18, 11), // "sigIntegral"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "sigBalance"
QT_MOC_LITERAL(4, 42, 16), // "sigBaseBuddyInfo"
QT_MOC_LITERAL(5, 59, 8), // "sigNonce"
QT_MOC_LITERAL(6, 68, 11), // "sigTransfer"
QT_MOC_LITERAL(7, 80, 18), // "slotIntegralResult"
QT_MOC_LITERAL(8, 99, 17), // "slotBalanceResult"
QT_MOC_LITERAL(9, 117, 17), // "slotBaseBuddyInfo"
QT_MOC_LITERAL(10, 135, 12), // "slotGetNonce"
QT_MOC_LITERAL(11, 148, 12) // "slotTransfer"

    },
    "OPRequestShareLib\0sigIntegral\0\0"
    "sigBalance\0sigBaseBuddyInfo\0sigNonce\0"
    "sigTransfer\0slotIntegralResult\0"
    "slotBalanceResult\0slotBaseBuddyInfo\0"
    "slotGetNonce\0slotTransfer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OPRequestShareLib[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,
       4,    1,   70,    2, 0x06 /* Public */,
       5,    1,   73,    2, 0x06 /* Public */,
       6,    2,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   81,    2, 0x08 /* Private */,
       8,    2,   86,    2, 0x08 /* Private */,
       9,    2,   91,    2, 0x08 /* Private */,
      10,    2,   96,    2, 0x08 /* Private */,
      11,    2,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QVariant,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,

       0        // eod
};

void OPRequestShareLib::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OPRequestShareLib *_t = static_cast<OPRequestShareLib *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigIntegral((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigBalance((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sigBaseBuddyInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sigNonce((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->sigTransfer((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 5: _t->slotIntegralResult((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->slotBalanceResult((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->slotBaseBuddyInfo((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->slotGetNonce((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->slotTransfer((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OPRequestShareLib::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OPRequestShareLib::sigIntegral)) {
                *result = 0;
            }
        }
        {
            typedef void (OPRequestShareLib::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OPRequestShareLib::sigBalance)) {
                *result = 1;
            }
        }
        {
            typedef void (OPRequestShareLib::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OPRequestShareLib::sigBaseBuddyInfo)) {
                *result = 2;
            }
        }
        {
            typedef void (OPRequestShareLib::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OPRequestShareLib::sigNonce)) {
                *result = 3;
            }
        }
        {
            typedef void (OPRequestShareLib::*_t)(bool , QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OPRequestShareLib::sigTransfer)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject OPRequestShareLib::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_OPRequestShareLib.data,
      qt_meta_data_OPRequestShareLib,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OPRequestShareLib::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OPRequestShareLib::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OPRequestShareLib.stringdata0))
        return static_cast<void*>(const_cast< OPRequestShareLib*>(this));
    return QObject::qt_metacast(_clname);
}

int OPRequestShareLib::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void OPRequestShareLib::sigIntegral(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OPRequestShareLib::sigBalance(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void OPRequestShareLib::sigBaseBuddyInfo(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void OPRequestShareLib::sigNonce(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void OPRequestShareLib::sigTransfer(bool _t1, QVariant _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
