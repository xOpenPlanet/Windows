/****************************************************************************
** Meta object code from reading C++ file 'scannetworksetwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../scannetworksetwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scannetworksetwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScanNetWorkSetWidget_t {
    QByteArrayData data[6];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScanNetWorkSetWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScanNetWorkSetWidget_t qt_meta_stringdata_ScanNetWorkSetWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "ScanNetWorkSetWidget"
QT_MOC_LITERAL(1, 21, 22), // "slotPressRadioButtonON"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 6), // "bCheck"
QT_MOC_LITERAL(4, 52, 23), // "slotPressRadioButtonOFF"
QT_MOC_LITERAL(5, 76, 11) // "slotConfirm"

    },
    "ScanNetWorkSetWidget\0slotPressRadioButtonON\0"
    "\0bCheck\0slotPressRadioButtonOFF\0"
    "slotConfirm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScanNetWorkSetWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       5,    0,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,

       0        // eod
};

void ScanNetWorkSetWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScanNetWorkSetWidget *_t = static_cast<ScanNetWorkSetWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotPressRadioButtonON((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->slotPressRadioButtonOFF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->slotConfirm(); break;
        default: ;
        }
    }
}

const QMetaObject ScanNetWorkSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ScanNetWorkSetWidget.data,
      qt_meta_data_ScanNetWorkSetWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ScanNetWorkSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScanNetWorkSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ScanNetWorkSetWidget.stringdata0))
        return static_cast<void*>(const_cast< ScanNetWorkSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ScanNetWorkSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
