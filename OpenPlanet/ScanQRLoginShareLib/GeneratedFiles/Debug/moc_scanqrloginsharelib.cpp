/****************************************************************************
** Meta object code from reading C++ file 'scanqrloginsharelib.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../scanqrloginsharelib.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scanqrloginsharelib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScanQRLoginShareLib_t {
    QByteArrayData data[4];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScanQRLoginShareLib_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScanQRLoginShareLib_t qt_meta_stringdata_ScanQRLoginShareLib = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ScanQRLoginShareLib"
QT_MOC_LITERAL(1, 20, 19), // "sigCloseLoginWidget"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 17) // "sigQRLoginSuccess"

    },
    "ScanQRLoginShareLib\0sigCloseLoginWidget\0"
    "\0sigQRLoginSuccess"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScanQRLoginShareLib[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    1,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap,    2,

       0        // eod
};

void ScanQRLoginShareLib::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScanQRLoginShareLib *_t = static_cast<ScanQRLoginShareLib *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigCloseLoginWidget(); break;
        case 1: _t->sigQRLoginSuccess((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScanQRLoginShareLib::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScanQRLoginShareLib::sigCloseLoginWidget)) {
                *result = 0;
            }
        }
        {
            typedef void (ScanQRLoginShareLib::*_t)(QVariantMap );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScanQRLoginShareLib::sigQRLoginSuccess)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ScanQRLoginShareLib::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ScanQRLoginShareLib.data,
      qt_meta_data_ScanQRLoginShareLib,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ScanQRLoginShareLib::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScanQRLoginShareLib::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ScanQRLoginShareLib.stringdata0))
        return static_cast<void*>(const_cast< ScanQRLoginShareLib*>(this));
    return QObject::qt_metacast(_clname);
}

int ScanQRLoginShareLib::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ScanQRLoginShareLib::sigCloseLoginWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ScanQRLoginShareLib::sigQRLoginSuccess(QVariantMap _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
