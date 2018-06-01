/****************************************************************************
** Meta object code from reading C++ file 'groupprofilewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../groupprofilewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'groupprofilewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GroupProfileWidget_t {
    QByteArrayData data[10];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GroupProfileWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GroupProfileWidget_t qt_meta_stringdata_GroupProfileWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "GroupProfileWidget"
QT_MOC_LITERAL(1, 19, 12), // "sigGroupChat"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 13), // "slotGroupChat"
QT_MOC_LITERAL(4, 47, 21), // "slotUploadHeaderImage"
QT_MOC_LITERAL(5, 69, 8), // "filePath"
QT_MOC_LITERAL(6, 78, 20), // "slotHttpChangeAvatar"
QT_MOC_LITERAL(7, 99, 7), // "success"
QT_MOC_LITERAL(8, 107, 4), // "byte"
QT_MOC_LITERAL(9, 112, 17) // "slotAvatarChanged"

    },
    "GroupProfileWidget\0sigGroupChat\0\0"
    "slotGroupChat\0slotUploadHeaderImage\0"
    "filePath\0slotHttpChangeAvatar\0success\0"
    "byte\0slotAvatarChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupProfileWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   44,    2, 0x08 /* Private */,
       4,    1,   45,    2, 0x08 /* Private */,
       6,    2,   48,    2, 0x08 /* Private */,
       9,    2,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QVariant,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool, QMetaType::QByteArray,    7,    8,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    7,    8,

       0        // eod
};

void GroupProfileWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupProfileWidget *_t = static_cast<GroupProfileWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigGroupChat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 1: _t->slotGroupChat(); break;
        case 2: _t->slotUploadHeaderImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slotHttpChangeAvatar((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 4: _t->slotAvatarChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GroupProfileWidget::*_t)(int , QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupProfileWidget::sigGroupChat)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject GroupProfileWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GroupProfileWidget.data,
      qt_meta_data_GroupProfileWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GroupProfileWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupProfileWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GroupProfileWidget.stringdata0))
        return static_cast<void*>(const_cast< GroupProfileWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int GroupProfileWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void GroupProfileWidget::sigGroupChat(int _t1, QVariant _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
