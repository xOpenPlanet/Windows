/****************************************************************************
** Meta object code from reading C++ file 'cfriendlistwidgetbase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../baseUI/cfriendlistwidgetbase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cfriendlistwidgetbase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CFriendListWidgetBase_t {
    QByteArrayData data[17];
    char stringdata0[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CFriendListWidgetBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CFriendListWidgetBase_t qt_meta_stringdata_CFriendListWidgetBase = {
    {
QT_MOC_LITERAL(0, 0, 21), // "CFriendListWidgetBase"
QT_MOC_LITERAL(1, 22, 12), // "sigAddPerson"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 10), // "strBuddyID"
QT_MOC_LITERAL(4, 47, 19), // "sigMouseEnteredItem"
QT_MOC_LITERAL(5, 67, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 84, 4), // "item"
QT_MOC_LITERAL(7, 89, 18), // "sigMouseLeavedItem"
QT_MOC_LITERAL(8, 108, 17), // "sigClickAcceptBtn"
QT_MOC_LITERAL(9, 126, 12), // "sigChatClose"
QT_MOC_LITERAL(10, 139, 13), // "sigMessageNum"
QT_MOC_LITERAL(11, 153, 11), // "doAddPerson"
QT_MOC_LITERAL(12, 165, 32), // "slotOnMouseEnteredListWidgetItem"
QT_MOC_LITERAL(13, 198, 31), // "slotOnMouseLeavedListWidgetItem"
QT_MOC_LITERAL(14, 230, 18), // "slotClickAcceptBtn"
QT_MOC_LITERAL(15, 249, 17), // "slotClickCloseBtn"
QT_MOC_LITERAL(16, 267, 19) // "slotCountMessageNum"

    },
    "CFriendListWidgetBase\0sigAddPerson\0\0"
    "strBuddyID\0sigMouseEnteredItem\0"
    "QListWidgetItem*\0item\0sigMouseLeavedItem\0"
    "sigClickAcceptBtn\0sigChatClose\0"
    "sigMessageNum\0doAddPerson\0"
    "slotOnMouseEnteredListWidgetItem\0"
    "slotOnMouseLeavedListWidgetItem\0"
    "slotClickAcceptBtn\0slotClickCloseBtn\0"
    "slotCountMessageNum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CFriendListWidgetBase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       7,    1,   80,    2, 0x06 /* Public */,
       8,    0,   83,    2, 0x06 /* Public */,
       9,    1,   84,    2, 0x06 /* Public */,
      10,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   90,    2, 0x08 /* Private */,
      12,    1,   93,    2, 0x08 /* Private */,
      13,    1,   96,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    1,  100,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void CFriendListWidgetBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CFriendListWidgetBase *_t = static_cast<CFriendListWidgetBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigAddPerson((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigMouseEnteredItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->sigMouseLeavedItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->sigClickAcceptBtn(); break;
        case 4: _t->sigChatClose((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sigMessageNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->doAddPerson((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->slotOnMouseEnteredListWidgetItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->slotOnMouseLeavedListWidgetItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->slotClickAcceptBtn(); break;
        case 10: _t->slotClickCloseBtn((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->slotCountMessageNum(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CFriendListWidgetBase::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CFriendListWidgetBase::sigAddPerson)) {
                *result = 0;
            }
        }
        {
            typedef void (CFriendListWidgetBase::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CFriendListWidgetBase::sigMouseEnteredItem)) {
                *result = 1;
            }
        }
        {
            typedef void (CFriendListWidgetBase::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CFriendListWidgetBase::sigMouseLeavedItem)) {
                *result = 2;
            }
        }
        {
            typedef void (CFriendListWidgetBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CFriendListWidgetBase::sigClickAcceptBtn)) {
                *result = 3;
            }
        }
        {
            typedef void (CFriendListWidgetBase::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CFriendListWidgetBase::sigChatClose)) {
                *result = 4;
            }
        }
        {
            typedef void (CFriendListWidgetBase::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CFriendListWidgetBase::sigMessageNum)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject CFriendListWidgetBase::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_CFriendListWidgetBase.data,
      qt_meta_data_CFriendListWidgetBase,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CFriendListWidgetBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CFriendListWidgetBase::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CFriendListWidgetBase.stringdata0))
        return static_cast<void*>(const_cast< CFriendListWidgetBase*>(this));
    return QListWidget::qt_metacast(_clname);
}

int CFriendListWidgetBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CFriendListWidgetBase::sigAddPerson(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CFriendListWidgetBase::sigMouseEnteredItem(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CFriendListWidgetBase::sigMouseLeavedItem(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CFriendListWidgetBase::sigClickAcceptBtn()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void CFriendListWidgetBase::sigChatClose(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CFriendListWidgetBase::sigMessageNum(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE