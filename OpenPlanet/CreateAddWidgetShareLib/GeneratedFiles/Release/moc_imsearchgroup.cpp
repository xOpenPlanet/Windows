/****************************************************************************
** Meta object code from reading C++ file 'imsearchgroup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../imsearchgroup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imsearchgroup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IMSearchGroup_t {
    QByteArrayData data[10];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IMSearchGroup_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IMSearchGroup_t qt_meta_stringdata_IMSearchGroup = {
    {
QT_MOC_LITERAL(0, 0, 13), // "IMSearchGroup"
QT_MOC_LITERAL(1, 14, 18), // "doClickSearchGroup"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 27), // "doHttpSearchGroupResultInfo"
QT_MOC_LITERAL(4, 62, 6), // "bState"
QT_MOC_LITERAL(5, 69, 9), // "strResult"
QT_MOC_LITERAL(6, 79, 10), // "doAddGroup"
QT_MOC_LITERAL(7, 90, 10), // "strGroupID"
QT_MOC_LITERAL(8, 101, 24), // "doHttpAddGroupResultInfo"
QT_MOC_LITERAL(9, 126, 7) // "bResult"

    },
    "IMSearchGroup\0doClickSearchGroup\0\0"
    "doHttpSearchGroupResultInfo\0bState\0"
    "strResult\0doAddGroup\0strGroupID\0"
    "doHttpAddGroupResultInfo\0bResult"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IMSearchGroup[] = {

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

void IMSearchGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IMSearchGroup *_t = static_cast<IMSearchGroup *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doClickSearchGroup(); break;
        case 1: _t->doHttpSearchGroupResultInfo((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->doAddGroup((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->doHttpAddGroupResultInfo((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject IMSearchGroup::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IMSearchGroup.data,
      qt_meta_data_IMSearchGroup,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IMSearchGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IMSearchGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IMSearchGroup.stringdata0))
        return static_cast<void*>(const_cast< IMSearchGroup*>(this));
    return QWidget::qt_metacast(_clname);
}

int IMSearchGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
