/****************************************************************************
** Meta object code from reading C++ file 'changeavatarwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../userprofile/changeavatarwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'changeavatarwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChangeAvatarWidget_t {
    QByteArrayData data[6];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChangeAvatarWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChangeAvatarWidget_t qt_meta_stringdata_ChangeAvatarWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ChangeAvatarWidget"
QT_MOC_LITERAL(1, 19, 20), // "sigUploadHeaderImage"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 15), // "slotUploadImage"
QT_MOC_LITERAL(4, 57, 16), // "slotConfirmImage"
QT_MOC_LITERAL(5, 74, 10) // "slotCancel"

    },
    "ChangeAvatarWidget\0sigUploadHeaderImage\0"
    "\0slotUploadImage\0slotConfirmImage\0"
    "slotCancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChangeAvatarWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   37,    2, 0x08 /* Private */,
       4,    0,   38,    2, 0x08 /* Private */,
       5,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChangeAvatarWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChangeAvatarWidget *_t = static_cast<ChangeAvatarWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUploadHeaderImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotUploadImage(); break;
        case 2: _t->slotConfirmImage(); break;
        case 3: _t->slotCancel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ChangeAvatarWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChangeAvatarWidget::sigUploadHeaderImage)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ChangeAvatarWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChangeAvatarWidget.data,
      qt_meta_data_ChangeAvatarWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChangeAvatarWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChangeAvatarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChangeAvatarWidget.stringdata0))
        return static_cast<void*>(const_cast< ChangeAvatarWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChangeAvatarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void ChangeAvatarWidget::sigUploadHeaderImage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
