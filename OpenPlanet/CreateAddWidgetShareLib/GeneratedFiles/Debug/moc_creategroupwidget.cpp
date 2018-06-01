/****************************************************************************
** Meta object code from reading C++ file 'creategroupwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../creategroupwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'creategroupwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateGroupWidget_t {
    QByteArrayData data[17];
    char stringdata0[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateGroupWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateGroupWidget_t qt_meta_stringdata_CreateGroupWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CreateGroupWidget"
QT_MOC_LITERAL(1, 18, 29), // "sigInsertGroupItemToGroupList"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 9), // "GroupInfo"
QT_MOC_LITERAL(4, 59, 10), // "group_info"
QT_MOC_LITERAL(5, 70, 21), // "sigCreateGroupSuccess"
QT_MOC_LITERAL(6, 92, 8), // "group_id"
QT_MOC_LITERAL(7, 101, 25), // "OnContactsListItemClicked"
QT_MOC_LITERAL(8, 127, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(9, 144, 8), // "the_item"
QT_MOC_LITERAL(10, 153, 32), // "OnMemberListItemRemoveBtnClicked"
QT_MOC_LITERAL(11, 186, 8), // "buddy_id"
QT_MOC_LITERAL(12, 195, 18), // "OnCancelBtnClicked"
QT_MOC_LITERAL(13, 214, 19), // "OnConfirmBtnClicked"
QT_MOC_LITERAL(14, 234, 15), // "OnGetHttpResult"
QT_MOC_LITERAL(15, 250, 7), // "success"
QT_MOC_LITERAL(16, 258, 6) // "result"

    },
    "CreateGroupWidget\0sigInsertGroupItemToGroupList\0"
    "\0GroupInfo\0group_info\0sigCreateGroupSuccess\0"
    "group_id\0OnContactsListItemClicked\0"
    "QListWidgetItem*\0the_item\0"
    "OnMemberListItemRemoveBtnClicked\0"
    "buddy_id\0OnCancelBtnClicked\0"
    "OnConfirmBtnClicked\0OnGetHttpResult\0"
    "success\0result"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateGroupWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   55,    2, 0x08 /* Private */,
      10,    1,   58,    2, 0x08 /* Private */,
      12,    0,   61,    2, 0x08 /* Private */,
      13,    0,   62,    2, 0x08 /* Private */,
      14,    2,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   15,   16,

       0        // eod
};

void CreateGroupWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateGroupWidget *_t = static_cast<CreateGroupWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigInsertGroupItemToGroupList((*reinterpret_cast< GroupInfo(*)>(_a[1]))); break;
        case 1: _t->sigCreateGroupSuccess((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->OnContactsListItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->OnMemberListItemRemoveBtnClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->OnCancelBtnClicked(); break;
        case 5: _t->OnConfirmBtnClicked(); break;
        case 6: _t->OnGetHttpResult((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CreateGroupWidget::*_t)(GroupInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateGroupWidget::sigInsertGroupItemToGroupList)) {
                *result = 0;
            }
        }
        {
            typedef void (CreateGroupWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateGroupWidget::sigCreateGroupSuccess)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CreateGroupWidget::staticMetaObject = {
    { &BaseWindow::staticMetaObject, qt_meta_stringdata_CreateGroupWidget.data,
      qt_meta_data_CreateGroupWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateGroupWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateGroupWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateGroupWidget.stringdata0))
        return static_cast<void*>(const_cast< CreateGroupWidget*>(this));
    return BaseWindow::qt_metacast(_clname);
}

int CreateGroupWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWindow::qt_metacall(_c, _id, _a);
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
void CreateGroupWidget::sigInsertGroupItemToGroupList(GroupInfo _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CreateGroupWidget::sigCreateGroupSuccess(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
