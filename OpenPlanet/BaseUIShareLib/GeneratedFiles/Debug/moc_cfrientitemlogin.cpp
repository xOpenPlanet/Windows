/****************************************************************************
** Meta object code from reading C++ file 'cfrientitemlogin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../baseUI/cfrientitemlogin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cfrientitemlogin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CFrientItemLogin_t {
    QByteArrayData data[4];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CFrientItemLogin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CFrientItemLogin_t qt_meta_stringdata_CFrientItemLogin = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CFrientItemLogin"
QT_MOC_LITERAL(1, 17, 17), // "sigLoginEditClose"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 18) // "slotLoginEditClose"

    },
    "CFrientItemLogin\0sigLoginEditClose\0\0"
    "slotLoginEditClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CFrientItemLogin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CFrientItemLogin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CFrientItemLogin *_t = static_cast<CFrientItemLogin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigLoginEditClose((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotLoginEditClose(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CFrientItemLogin::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CFrientItemLogin::sigLoginEditClose)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CFrientItemLogin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CFrientItemLogin.data,
      qt_meta_data_CFrientItemLogin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CFrientItemLogin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CFrientItemLogin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CFrientItemLogin.stringdata0))
        return static_cast<void*>(const_cast< CFrientItemLogin*>(this));
    return QWidget::qt_metacast(_clname);
}

int CFrientItemLogin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void CFrientItemLogin::sigLoginEditClose(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE