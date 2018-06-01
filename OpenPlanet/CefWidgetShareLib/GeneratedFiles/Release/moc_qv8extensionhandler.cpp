/****************************************************************************
** Meta object code from reading C++ file 'qv8extensionhandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qv8extensionhandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qv8extensionhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QV8ExtensionHandler_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QV8ExtensionHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QV8ExtensionHandler_t qt_meta_stringdata_QV8ExtensionHandler = {
    {
QT_MOC_LITERAL(0, 0, 19) // "QV8ExtensionHandler"

    },
    "QV8ExtensionHandler"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QV8ExtensionHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void QV8ExtensionHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject QV8ExtensionHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QV8ExtensionHandler.data,
      qt_meta_data_QV8ExtensionHandler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QV8ExtensionHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QV8ExtensionHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QV8ExtensionHandler.stringdata0))
        return static_cast<void*>(const_cast< QV8ExtensionHandler*>(this));
    if (!strcmp(_clname, "CefV8Handler"))
        return static_cast< CefV8Handler*>(const_cast< QV8ExtensionHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int QV8ExtensionHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
