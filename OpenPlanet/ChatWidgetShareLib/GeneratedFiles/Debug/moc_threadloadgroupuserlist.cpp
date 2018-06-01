/****************************************************************************
** Meta object code from reading C++ file 'threadloadgroupuserlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../thread/threadloadgroupuserlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadloadgroupuserlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ThreadLoadGroupUserList_t {
    QByteArrayData data[5];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadLoadGroupUserList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadLoadGroupUserList_t qt_meta_stringdata_ThreadLoadGroupUserList = {
    {
QT_MOC_LITERAL(0, 0, 23), // "ThreadLoadGroupUserList"
QT_MOC_LITERAL(1, 24, 20), // "sigLoadGroupUserList"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 9), // "BuddyInfo"
QT_MOC_LITERAL(4, 56, 9) // "buddyInfo"

    },
    "ThreadLoadGroupUserList\0sigLoadGroupUserList\0"
    "\0BuddyInfo\0buddyInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadLoadGroupUserList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void ThreadLoadGroupUserList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThreadLoadGroupUserList *_t = static_cast<ThreadLoadGroupUserList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigLoadGroupUserList((*reinterpret_cast< BuddyInfo(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ThreadLoadGroupUserList::*_t)(BuddyInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThreadLoadGroupUserList::sigLoadGroupUserList)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ThreadLoadGroupUserList::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadLoadGroupUserList.data,
      qt_meta_data_ThreadLoadGroupUserList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ThreadLoadGroupUserList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadLoadGroupUserList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadLoadGroupUserList.stringdata0))
        return static_cast<void*>(const_cast< ThreadLoadGroupUserList*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadLoadGroupUserList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ThreadLoadGroupUserList::sigLoadGroupUserList(BuddyInfo _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
