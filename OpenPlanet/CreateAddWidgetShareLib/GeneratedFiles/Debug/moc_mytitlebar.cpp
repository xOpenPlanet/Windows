/****************************************************************************
** Meta object code from reading C++ file 'mytitlebar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mytitlebar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytitlebar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyTitleBar_t {
    QByteArrayData data[11];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyTitleBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyTitleBar_t qt_meta_stringdata_MyTitleBar = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MyTitleBar"
QT_MOC_LITERAL(1, 11, 19), // "sigButtonMinClicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 23), // "sigButtonRestoreClicked"
QT_MOC_LITERAL(4, 56, 19), // "sigButtonMaxClicked"
QT_MOC_LITERAL(5, 76, 21), // "sigButtonCloseClicked"
QT_MOC_LITERAL(6, 98, 18), // "onButtonMinClicked"
QT_MOC_LITERAL(7, 117, 22), // "onButtonRestoreClicked"
QT_MOC_LITERAL(8, 140, 18), // "onButtonMaxClicked"
QT_MOC_LITERAL(9, 159, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(10, 180, 11) // "onRollTitle"

    },
    "MyTitleBar\0sigButtonMinClicked\0\0"
    "sigButtonRestoreClicked\0sigButtonMaxClicked\0"
    "sigButtonCloseClicked\0onButtonMinClicked\0"
    "onButtonRestoreClicked\0onButtonMaxClicked\0"
    "onButtonCloseClicked\0onRollTitle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTitleBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
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

       0        // eod
};

void MyTitleBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyTitleBar *_t = static_cast<MyTitleBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigButtonMinClicked(); break;
        case 1: _t->sigButtonRestoreClicked(); break;
        case 2: _t->sigButtonMaxClicked(); break;
        case 3: _t->sigButtonCloseClicked(); break;
        case 4: _t->onButtonMinClicked(); break;
        case 5: _t->onButtonRestoreClicked(); break;
        case 6: _t->onButtonMaxClicked(); break;
        case 7: _t->onButtonCloseClicked(); break;
        case 8: _t->onRollTitle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyTitleBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTitleBar::sigButtonMinClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (MyTitleBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTitleBar::sigButtonRestoreClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (MyTitleBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTitleBar::sigButtonMaxClicked)) {
                *result = 2;
            }
        }
        {
            typedef void (MyTitleBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTitleBar::sigButtonCloseClicked)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MyTitleBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyTitleBar.data,
      qt_meta_data_MyTitleBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyTitleBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTitleBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyTitleBar.stringdata0))
        return static_cast<void*>(const_cast< MyTitleBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyTitleBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MyTitleBar::sigButtonMinClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MyTitleBar::sigButtonRestoreClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MyTitleBar::sigButtonMaxClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MyTitleBar::sigButtonCloseClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
