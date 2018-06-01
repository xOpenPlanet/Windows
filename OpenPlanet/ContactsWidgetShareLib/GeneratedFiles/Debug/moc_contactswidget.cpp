/****************************************************************************
** Meta object code from reading C++ file 'contactswidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../contactswidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contactswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ContactsWidget_t {
    QByteArrayData data[9];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ContactsWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ContactsWidget_t qt_meta_stringdata_ContactsWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ContactsWidget"
QT_MOC_LITERAL(1, 15, 17), // "sigAddCreateGroup"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 12), // "sigAddPerson"
QT_MOC_LITERAL(4, 47, 14), // "slotSwitchTabs"
QT_MOC_LITERAL(5, 62, 2), // "id"
QT_MOC_LITERAL(6, 65, 7), // "checked"
QT_MOC_LITERAL(7, 73, 15), // "slotClickSearch"
QT_MOC_LITERAL(8, 89, 17) // "slotAddBtnClicked"

    },
    "ContactsWidget\0sigAddCreateGroup\0\0"
    "sigAddPerson\0slotSwitchTabs\0id\0checked\0"
    "slotClickSearch\0slotAddBtnClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ContactsWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   41,    2, 0x08 /* Private */,
       7,    0,   46,    2, 0x08 /* Private */,
       8,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    5,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ContactsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ContactsWidget *_t = static_cast<ContactsWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigAddCreateGroup(); break;
        case 1: _t->sigAddPerson(); break;
        case 2: _t->slotSwitchTabs((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->slotClickSearch(); break;
        case 4: _t->slotAddBtnClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ContactsWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactsWidget::sigAddCreateGroup)) {
                *result = 0;
            }
        }
        {
            typedef void (ContactsWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactsWidget::sigAddPerson)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ContactsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ContactsWidget.data,
      qt_meta_data_ContactsWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ContactsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContactsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ContactsWidget.stringdata0))
        return static_cast<void*>(const_cast< ContactsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ContactsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ContactsWidget::sigAddCreateGroup()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ContactsWidget::sigAddPerson()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
