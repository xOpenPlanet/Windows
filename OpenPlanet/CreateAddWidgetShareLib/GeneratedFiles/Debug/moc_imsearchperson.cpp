/****************************************************************************
** Meta object code from reading C++ file 'imsearchperson.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../imsearchperson.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imsearchperson.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IMSearchPerson_t {
    QByteArrayData data[10];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IMSearchPerson_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IMSearchPerson_t qt_meta_stringdata_IMSearchPerson = {
    {
QT_MOC_LITERAL(0, 0, 14), // "IMSearchPerson"
QT_MOC_LITERAL(1, 15, 13), // "doClickSearch"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 28), // "doHttpSearchPersonResultInfo"
QT_MOC_LITERAL(4, 59, 6), // "bState"
QT_MOC_LITERAL(5, 66, 9), // "strResult"
QT_MOC_LITERAL(6, 76, 11), // "doAddPerson"
QT_MOC_LITERAL(7, 88, 10), // "strBuddyID"
QT_MOC_LITERAL(8, 99, 25), // "doHttpAddPersonResultInfo"
QT_MOC_LITERAL(9, 125, 7) // "bResult"

    },
    "IMSearchPerson\0doClickSearch\0\0"
    "doHttpSearchPersonResultInfo\0bState\0"
    "strResult\0doAddPerson\0strBuddyID\0"
    "doHttpAddPersonResultInfo\0bResult"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IMSearchPerson[] = {

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
       3,    2,   35,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       8,    2,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    9,    5,

       0        // eod
};

void IMSearchPerson::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IMSearchPerson *_t = static_cast<IMSearchPerson *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doClickSearch(); break;
        case 1: _t->doHttpSearchPersonResultInfo((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->doAddPerson((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->doHttpAddPersonResultInfo((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject IMSearchPerson::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IMSearchPerson.data,
      qt_meta_data_IMSearchPerson,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IMSearchPerson::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IMSearchPerson::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IMSearchPerson.stringdata0))
        return static_cast<void*>(const_cast< IMSearchPerson*>(this));
    return QWidget::qt_metacast(_clname);
}

int IMSearchPerson::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
