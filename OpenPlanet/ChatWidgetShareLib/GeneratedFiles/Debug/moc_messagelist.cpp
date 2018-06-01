/****************************************************************************
** Meta object code from reading C++ file 'messagelist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MessageWidget/messagelist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messagelist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MessageList_t {
    QByteArrayData data[12];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MessageList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MessageList_t qt_meta_stringdata_MessageList = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MessageList"
QT_MOC_LITERAL(1, 12, 18), // "sigDoubleClickItem"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "sigCloseChat"
QT_MOC_LITERAL(4, 45, 20), // "sigDealTrayIocnFlash"
QT_MOC_LITERAL(5, 66, 13), // "sigMessageNum"
QT_MOC_LITERAL(6, 80, 19), // "doDoubleClickedItem"
QT_MOC_LITERAL(7, 100, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 117, 4), // "item"
QT_MOC_LITERAL(9, 122, 19), // "slotCountMessageNum"
QT_MOC_LITERAL(10, 142, 13), // "slotKeyUpDown"
QT_MOC_LITERAL(11, 156, 10) // "QKeyEvent*"

    },
    "MessageList\0sigDoubleClickItem\0\0"
    "sigCloseChat\0sigDealTrayIocnFlash\0"
    "sigMessageNum\0doDoubleClickedItem\0"
    "QListWidgetItem*\0item\0slotCountMessageNum\0"
    "slotKeyUpDown\0QKeyEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,
       4,    1,   55,    2, 0x06 /* Public */,
       5,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   61,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,

       0        // eod
};

void MessageList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MessageList *_t = static_cast<MessageList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigDoubleClickItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigCloseChat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sigDealTrayIocnFlash((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sigMessageNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->doDoubleClickedItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->slotCountMessageNum(); break;
        case 6: _t->slotKeyUpDown((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MessageList::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageList::sigDoubleClickItem)) {
                *result = 0;
            }
        }
        {
            typedef void (MessageList::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageList::sigCloseChat)) {
                *result = 1;
            }
        }
        {
            typedef void (MessageList::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageList::sigDealTrayIocnFlash)) {
                *result = 2;
            }
        }
        {
            typedef void (MessageList::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MessageList::sigMessageNum)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject MessageList::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_MessageList.data,
      qt_meta_data_MessageList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MessageList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MessageList.stringdata0))
        return static_cast<void*>(const_cast< MessageList*>(this));
    return QListWidget::qt_metacast(_clname);
}

int MessageList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MessageList::sigDoubleClickItem(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MessageList::sigCloseChat(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MessageList::sigDealTrayIocnFlash(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MessageList::sigMessageNum(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
