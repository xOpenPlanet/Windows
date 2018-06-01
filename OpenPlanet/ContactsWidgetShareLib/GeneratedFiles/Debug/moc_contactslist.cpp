/****************************************************************************
** Meta object code from reading C++ file 'contactslist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../contactslist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contactslist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ContactsList_t {
    QByteArrayData data[12];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ContactsList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ContactsList_t qt_meta_stringdata_ContactsList = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ContactsList"
QT_MOC_LITERAL(1, 13, 10), // "sigPerChat"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "type"
QT_MOC_LITERAL(4, 30, 10), // "strBuddyID"
QT_MOC_LITERAL(5, 41, 10), // "sigProfile"
QT_MOC_LITERAL(6, 52, 19), // "doDoubleClickedItem"
QT_MOC_LITERAL(7, 72, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 89, 4), // "item"
QT_MOC_LITERAL(9, 94, 13), // "doClickedItem"
QT_MOC_LITERAL(10, 108, 17), // "doListContextMenu"
QT_MOC_LITERAL(11, 126, 5) // "point"

    },
    "ContactsList\0sigPerChat\0\0type\0strBuddyID\0"
    "sigProfile\0doDoubleClickedItem\0"
    "QListWidgetItem*\0item\0doClickedItem\0"
    "doListContextMenu\0point"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ContactsList[] = {

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
       1,    2,   39,    2, 0x06 /* Public */,
       5,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   47,    2, 0x08 /* Private */,
       9,    1,   50,    2, 0x08 /* Private */,
      10,    1,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QVariant,    3,    4,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QPoint,   11,

       0        // eod
};

void ContactsList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ContactsList *_t = static_cast<ContactsList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigPerChat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 1: _t->sigProfile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->doDoubleClickedItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->doClickedItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->doListContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ContactsList::*_t)(int , QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactsList::sigPerChat)) {
                *result = 0;
            }
        }
        {
            typedef void (ContactsList::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactsList::sigProfile)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ContactsList::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_ContactsList.data,
      qt_meta_data_ContactsList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ContactsList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContactsList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ContactsList.stringdata0))
        return static_cast<void*>(const_cast< ContactsList*>(this));
    return QListWidget::qt_metacast(_clname);
}

int ContactsList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
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
void ContactsList::sigPerChat(int _t1, QVariant _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ContactsList::sigProfile(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
