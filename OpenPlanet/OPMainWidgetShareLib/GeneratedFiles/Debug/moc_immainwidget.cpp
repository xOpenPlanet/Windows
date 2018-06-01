/****************************************************************************
** Meta object code from reading C++ file 'immainwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../immainwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'immainwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IMMainWidget_t {
    QByteArrayData data[23];
    char stringdata0[323];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IMMainWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IMMainWidget_t qt_meta_stringdata_IMMainWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "IMMainWidget"
QT_MOC_LITERAL(1, 13, 7), // "sigExit"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "sigUserProfile"
QT_MOC_LITERAL(4, 37, 11), // "sigMenuItem"
QT_MOC_LITERAL(5, 49, 16), // "sigDormancyState"
QT_MOC_LITERAL(6, 66, 15), // "sigTrayOpenChat"
QT_MOC_LITERAL(7, 82, 4), // "type"
QT_MOC_LITERAL(8, 87, 7), // "buddyID"
QT_MOC_LITERAL(9, 95, 4), // "show"
QT_MOC_LITERAL(10, 100, 8), // "slotExit"
QT_MOC_LITERAL(11, 109, 14), // "slotFullScreen"
QT_MOC_LITERAL(12, 124, 15), // "slotCheckWidget"
QT_MOC_LITERAL(13, 140, 22), // "slotSysTrayIconClicked"
QT_MOC_LITERAL(14, 163, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(15, 197, 6), // "reason"
QT_MOC_LITERAL(16, 204, 28), // "slotSetMainWidgetStatusLabel"
QT_MOC_LITERAL(17, 233, 3), // "msg"
QT_MOC_LITERAL(18, 237, 21), // "slotDealTrayIconFlash"
QT_MOC_LITERAL(19, 259, 23), // "slotMessageRevFlashTime"
QT_MOC_LITERAL(20, 283, 18), // "slotShowAllClicked"
QT_MOC_LITERAL(21, 302, 16), // "slotCountMessage"
QT_MOC_LITERAL(22, 319, 3) // "num"

    },
    "IMMainWidget\0sigExit\0\0sigUserProfile\0"
    "sigMenuItem\0sigDormancyState\0"
    "sigTrayOpenChat\0type\0buddyID\0show\0"
    "slotExit\0slotFullScreen\0slotCheckWidget\0"
    "slotSysTrayIconClicked\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0slotSetMainWidgetStatusLabel\0"
    "msg\0slotDealTrayIconFlash\0"
    "slotMessageRevFlashTime\0slotShowAllClicked\0"
    "slotCountMessage\0num"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IMMainWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    1,   91,    2, 0x06 /* Public */,
       5,    1,   94,    2, 0x06 /* Public */,
       6,    2,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  102,    2, 0x0a /* Public */,
      10,    0,  103,    2, 0x0a /* Public */,
      11,    0,  104,    2, 0x0a /* Public */,
      12,    2,  105,    2, 0x0a /* Public */,
      13,    1,  110,    2, 0x0a /* Public */,
      16,    1,  113,    2, 0x0a /* Public */,
      18,    1,  116,    2, 0x0a /* Public */,
      19,    0,  119,    2, 0x0a /* Public */,
      20,    0,  120,    2, 0x0a /* Public */,
      21,    1,  121,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QVariant,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,

       0        // eod
};

void IMMainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IMMainWidget *_t = static_cast<IMMainWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigExit(); break;
        case 1: _t->sigUserProfile(); break;
        case 2: _t->sigMenuItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sigDormancyState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->sigTrayOpenChat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 5: _t->show(); break;
        case 6: _t->slotExit(); break;
        case 7: _t->slotFullScreen(); break;
        case 8: _t->slotCheckWidget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->slotSysTrayIconClicked((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 10: _t->slotSetMainWidgetStatusLabel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->slotDealTrayIconFlash((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->slotMessageRevFlashTime(); break;
        case 13: _t->slotShowAllClicked(); break;
        case 14: _t->slotCountMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IMMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IMMainWidget::sigExit)) {
                *result = 0;
            }
        }
        {
            typedef void (IMMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IMMainWidget::sigUserProfile)) {
                *result = 1;
            }
        }
        {
            typedef void (IMMainWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IMMainWidget::sigMenuItem)) {
                *result = 2;
            }
        }
        {
            typedef void (IMMainWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IMMainWidget::sigDormancyState)) {
                *result = 3;
            }
        }
        {
            typedef void (IMMainWidget::*_t)(int , QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IMMainWidget::sigTrayOpenChat)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject IMMainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IMMainWidget.data,
      qt_meta_data_IMMainWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IMMainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IMMainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IMMainWidget.stringdata0))
        return static_cast<void*>(const_cast< IMMainWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int IMMainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void IMMainWidget::sigExit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void IMMainWidget::sigUserProfile()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void IMMainWidget::sigMenuItem(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IMMainWidget::sigDormancyState(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void IMMainWidget::sigTrayOpenChat(int _t1, QVariant _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
