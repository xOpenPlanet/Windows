/****************************************************************************
** Meta object code from reading C++ file 'messagelog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../messagelog/messagelog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messagelog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MessageLog_t {
    QByteArrayData data[25];
    char stringdata0[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MessageLog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MessageLog_t qt_meta_stringdata_MessageLog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MessageLog"
QT_MOC_LITERAL(1, 11, 4), // "show"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 11), // "slotZoomImg"
QT_MOC_LITERAL(4, 29, 11), // "strfileName"
QT_MOC_LITERAL(5, 41, 13), // "slotVideoPlay"
QT_MOC_LITERAL(6, 55, 9), // "mediaPath"
QT_MOC_LITERAL(7, 65, 12), // "slotOpenFile"
QT_MOC_LITERAL(8, 78, 8), // "fileName"
QT_MOC_LITERAL(9, 87, 11), // "slotOpenDir"
QT_MOC_LITERAL(10, 99, 7), // "fileDir"
QT_MOC_LITERAL(11, 107, 15), // "maxOrRstrWindow"
QT_MOC_LITERAL(12, 123, 15), // "doClickContacts"
QT_MOC_LITERAL(13, 139, 12), // "doClickGroup"
QT_MOC_LITERAL(14, 152, 14), // "doClickPerItem"
QT_MOC_LITERAL(15, 167, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(16, 184, 16), // "doClickGroupItem"
QT_MOC_LITERAL(17, 201, 11), // "toFirstPage"
QT_MOC_LITERAL(18, 213, 9), // "toEndPage"
QT_MOC_LITERAL(19, 223, 10), // "toLastPage"
QT_MOC_LITERAL(20, 234, 10), // "toNextPage"
QT_MOC_LITERAL(21, 245, 18), // "doShowDateSelector"
QT_MOC_LITERAL(22, 264, 13), // "toDateLogPage"
QT_MOC_LITERAL(23, 278, 8), // "doSearch"
QT_MOC_LITERAL(24, 287, 13) // "doClearSearch"

    },
    "MessageLog\0show\0\0slotZoomImg\0strfileName\0"
    "slotVideoPlay\0mediaPath\0slotOpenFile\0"
    "fileName\0slotOpenDir\0fileDir\0"
    "maxOrRstrWindow\0doClickContacts\0"
    "doClickGroup\0doClickPerItem\0"
    "QListWidgetItem*\0doClickGroupItem\0"
    "toFirstPage\0toEndPage\0toLastPage\0"
    "toNextPage\0doShowDateSelector\0"
    "toDateLogPage\0doSearch\0doClearSearch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageLog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    1,  105,    2, 0x0a /* Public */,
       5,    1,  108,    2, 0x0a /* Public */,
       7,    1,  111,    2, 0x0a /* Public */,
       9,    1,  114,    2, 0x0a /* Public */,
      11,    0,  117,    2, 0x08 /* Private */,
      12,    1,  118,    2, 0x08 /* Private */,
      13,    1,  121,    2, 0x08 /* Private */,
      14,    1,  124,    2, 0x08 /* Private */,
      16,    1,  127,    2, 0x08 /* Private */,
      17,    0,  130,    2, 0x08 /* Private */,
      18,    0,  131,    2, 0x08 /* Private */,
      19,    0,  132,    2, 0x08 /* Private */,
      20,    0,  133,    2, 0x08 /* Private */,
      21,    0,  134,    2, 0x08 /* Private */,
      22,    1,  135,    2, 0x08 /* Private */,
      23,    0,  138,    2, 0x08 /* Private */,
      24,    0,  139,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MessageLog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MessageLog *_t = static_cast<MessageLog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->show(); break;
        case 1: _t->slotZoomImg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotVideoPlay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slotOpenFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slotOpenDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->maxOrRstrWindow(); break;
        case 6: _t->doClickContacts((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->doClickGroup((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->doClickPerItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->doClickGroupItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->toFirstPage(); break;
        case 11: _t->toEndPage(); break;
        case 12: _t->toLastPage(); break;
        case 13: _t->toNextPage(); break;
        case 14: _t->doShowDateSelector(); break;
        case 15: _t->toDateLogPage((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 16: _t->doSearch(); break;
        case 17: _t->doClearSearch(); break;
        default: ;
        }
    }
}

const QMetaObject MessageLog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MessageLog.data,
      qt_meta_data_MessageLog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MessageLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageLog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MessageLog.stringdata0))
        return static_cast<void*>(const_cast< MessageLog*>(this));
    return QWidget::qt_metacast(_clname);
}

int MessageLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
