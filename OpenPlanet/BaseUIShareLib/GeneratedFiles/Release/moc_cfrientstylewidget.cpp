/****************************************************************************
** Meta object code from reading C++ file 'cfrientstylewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../baseUI/cfrientstylewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cfrientstylewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CFrientStyleWidget_t {
    QByteArrayData data[13];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CFrientStyleWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CFrientStyleWidget_t qt_meta_stringdata_CFrientStyleWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CFrientStyleWidget"
QT_MOC_LITERAL(1, 19, 17), // "sigLoginEditClose"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 19), // "sigCurrentChatClose"
QT_MOC_LITERAL(4, 58, 12), // "sigAddPerson"
QT_MOC_LITERAL(5, 71, 30), // "sigRemoveBuddyFromCGMemberList"
QT_MOC_LITERAL(6, 102, 13), // "sigNumChanged"
QT_MOC_LITERAL(7, 116, 17), // "sigClickAcceptBtn"
QT_MOC_LITERAL(8, 134, 16), // "doLoginEditClose"
QT_MOC_LITERAL(9, 151, 18), // "doCurrentChatClose"
QT_MOC_LITERAL(10, 170, 11), // "doAddPerson"
QT_MOC_LITERAL(11, 182, 20), // "OnCGRemoveBtnClicked"
QT_MOC_LITERAL(12, 203, 16) // "doClickAcceptBtn"

    },
    "CFrientStyleWidget\0sigLoginEditClose\0"
    "\0sigCurrentChatClose\0sigAddPerson\0"
    "sigRemoveBuddyFromCGMemberList\0"
    "sigNumChanged\0sigClickAcceptBtn\0"
    "doLoginEditClose\0doCurrentChatClose\0"
    "doAddPerson\0OnCGRemoveBtnClicked\0"
    "doClickAcceptBtn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CFrientStyleWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    1,   72,    2, 0x06 /* Public */,
       4,    1,   75,    2, 0x06 /* Public */,
       5,    1,   78,    2, 0x06 /* Public */,
       6,    0,   81,    2, 0x06 /* Public */,
       7,    0,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   83,    2, 0x0a /* Public */,
       9,    0,   84,    2, 0x0a /* Public */,
      10,    0,   85,    2, 0x0a /* Public */,
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CFrientStyleWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CFrientStyleWidget *_t = static_cast<CFrientStyleWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigLoginEditClose((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigCurrentChatClose((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sigAddPerson((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sigRemoveBuddyFromCGMemberList((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->sigNumChanged(); break;
        case 5: _t->sigClickAcceptBtn(); break;
        case 6: _t->doLoginEditClose(); break;
        case 7: _t->doCurrentChatClose(); break;
        case 8: _t->doAddPerson(); break;
        case 9: _t->OnCGRemoveBtnClicked(); break;
        case 10: _t->doClickAcceptBtn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CFrientStyleWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CFrientStyleWidget::sigLoginEditClose)) {
                *result = 0;
            }
        }
        {
            typedef void (CFrientStyleWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CFrientStyleWidget::sigCurrentChatClose)) {
                *result = 1;
            }
        }
        {
            typedef void (CFrientStyleWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CFrientStyleWidget::sigAddPerson)) {
                *result = 2;
            }
        }
        {
            typedef void (CFrientStyleWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CFrientStyleWidget::sigRemoveBuddyFromCGMemberList)) {
                *result = 3;
            }
        }
        {
            typedef void (CFrientStyleWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CFrientStyleWidget::sigNumChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (CFrientStyleWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CFrientStyleWidget::sigClickAcceptBtn)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject CFrientStyleWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CFrientStyleWidget.data,
      qt_meta_data_CFrientStyleWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CFrientStyleWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CFrientStyleWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CFrientStyleWidget.stringdata0))
        return static_cast<void*>(const_cast< CFrientStyleWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CFrientStyleWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void CFrientStyleWidget::sigLoginEditClose(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CFrientStyleWidget::sigCurrentChatClose(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CFrientStyleWidget::sigAddPerson(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CFrientStyleWidget::sigRemoveBuddyFromCGMemberList(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CFrientStyleWidget::sigNumChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void CFrientStyleWidget::sigClickAcceptBtn()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
