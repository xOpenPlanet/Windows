/****************************************************************************
** Meta object code from reading C++ file 'qcefhandle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qcefhandle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcefhandle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QCefHandle_t {
    QByteArrayData data[17];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QCefHandle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QCefHandle_t qt_meta_stringdata_QCefHandle = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QCefHandle"
QT_MOC_LITERAL(1, 11, 10), // "sigZoomImg"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "sigVideoPlay"
QT_MOC_LITERAL(4, 36, 11), // "sigOpenFile"
QT_MOC_LITERAL(5, 48, 10), // "sigOpenDir"
QT_MOC_LITERAL(6, 59, 15), // "sigOpenDocument"
QT_MOC_LITERAL(7, 75, 23), // "sigCancleLoadorDownLoad"
QT_MOC_LITERAL(8, 99, 15), // "sigSendFileByID"
QT_MOC_LITERAL(9, 115, 10), // "sigGetFile"
QT_MOC_LITERAL(10, 126, 11), // "sigSaveFile"
QT_MOC_LITERAL(11, 138, 10), // "sigOpenUrl"
QT_MOC_LITERAL(12, 149, 7), // "sigDrag"
QT_MOC_LITERAL(13, 157, 16), // "sigOpenGroupFile"
QT_MOC_LITERAL(14, 174, 11), // "sigSendFile"
QT_MOC_LITERAL(15, 186, 17), // "sigRecoveryResult"
QT_MOC_LITERAL(16, 204, 18) // "sigTransactionData"

    },
    "QCefHandle\0sigZoomImg\0\0sigVideoPlay\0"
    "sigOpenFile\0sigOpenDir\0sigOpenDocument\0"
    "sigCancleLoadorDownLoad\0sigSendFileByID\0"
    "sigGetFile\0sigSaveFile\0sigOpenUrl\0"
    "sigDrag\0sigOpenGroupFile\0sigSendFile\0"
    "sigRecoveryResult\0sigTransactionData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCefHandle[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       3,    1,   92,    2, 0x06 /* Public */,
       4,    1,   95,    2, 0x06 /* Public */,
       5,    1,   98,    2, 0x06 /* Public */,
       6,    1,  101,    2, 0x06 /* Public */,
       7,    0,  104,    2, 0x06 /* Public */,
       8,    1,  105,    2, 0x06 /* Public */,
       9,    1,  108,    2, 0x06 /* Public */,
      10,    1,  111,    2, 0x06 /* Public */,
      11,    1,  114,    2, 0x06 /* Public */,
      12,    1,  117,    2, 0x06 /* Public */,
      13,    1,  120,    2, 0x06 /* Public */,
      14,    1,  123,    2, 0x06 /* Public */,
      15,    1,  126,    2, 0x06 /* Public */,
      16,    1,  129,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void QCefHandle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QCefHandle *_t = static_cast<QCefHandle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigZoomImg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigVideoPlay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sigOpenFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sigOpenDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->sigOpenDocument((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sigCancleLoadorDownLoad(); break;
        case 6: _t->sigSendFileByID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->sigGetFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->sigSaveFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->sigOpenUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->sigDrag((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 11: _t->sigOpenGroupFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->sigSendFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->sigRecoveryResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->sigTransactionData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QCefHandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefHandle::sigZoomImg)) {
                *result = 0;
            }
        }
        {
            typedef void (QCefHandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefHandle::sigVideoPlay)) {
                *result = 1;
            }
        }
        {
            typedef void (QCefHandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefHandle::sigOpenFile)) {
                *result = 2;
            }
        }
        {
            typedef void (QCefHandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefHandle::sigOpenDir)) {
                *result = 3;
            }
        }
        {
            typedef void (QCefHandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefHandle::sigOpenDocument)) {
                *result = 4;
            }
        }
        {
            typedef void (QCefHandle::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefHandle::sigCancleLoadorDownLoad)) {
                *result = 5;
            }
        }
        {
            typedef void (QCefHandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefHandle::sigSendFileByID)) {
                *result = 6;
            }
        }
        {
            typedef void (QCefHandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefHandle::sigGetFile)) {
                *result = 7;
            }
        }
        {
            typedef void (QCefHandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefHandle::sigSaveFile)) {
                *result = 8;
            }
        }
        {
            typedef void (QCefHandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefHandle::sigOpenUrl)) {
                *result = 9;
            }
        }
        {
            typedef void (QCefHandle::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefHandle::sigDrag)) {
                *result = 10;
            }
        }
        {
            typedef void (QCefHandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefHandle::sigOpenGroupFile)) {
                *result = 11;
            }
        }
        {
            typedef void (QCefHandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefHandle::sigSendFile)) {
                *result = 12;
            }
        }
        {
            typedef void (QCefHandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefHandle::sigRecoveryResult)) {
                *result = 13;
            }
        }
        {
            typedef void (QCefHandle::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefHandle::sigTransactionData)) {
                *result = 14;
            }
        }
    }
}

const QMetaObject QCefHandle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QCefHandle.data,
      qt_meta_data_QCefHandle,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QCefHandle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCefHandle::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QCefHandle.stringdata0))
        return static_cast<void*>(const_cast< QCefHandle*>(this));
    if (!strcmp(_clname, "CefClient"))
        return static_cast< CefClient*>(const_cast< QCefHandle*>(this));
    if (!strcmp(_clname, "CefDisplayHandler"))
        return static_cast< CefDisplayHandler*>(const_cast< QCefHandle*>(this));
    if (!strcmp(_clname, "CefLifeSpanHandler"))
        return static_cast< CefLifeSpanHandler*>(const_cast< QCefHandle*>(this));
    if (!strcmp(_clname, "CefLoadHandler"))
        return static_cast< CefLoadHandler*>(const_cast< QCefHandle*>(this));
    if (!strcmp(_clname, "CefContextMenuHandler"))
        return static_cast< CefContextMenuHandler*>(const_cast< QCefHandle*>(this));
    if (!strcmp(_clname, "CefDragHandler"))
        return static_cast< CefDragHandler*>(const_cast< QCefHandle*>(this));
    if (!strcmp(_clname, "CefRequestHandler"))
        return static_cast< CefRequestHandler*>(const_cast< QCefHandle*>(this));
    return QObject::qt_metacast(_clname);
}

int QCefHandle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void QCefHandle::sigZoomImg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QCefHandle::sigVideoPlay(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QCefHandle::sigOpenFile(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QCefHandle::sigOpenDir(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QCefHandle::sigOpenDocument(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QCefHandle::sigCancleLoadorDownLoad()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void QCefHandle::sigSendFileByID(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QCefHandle::sigGetFile(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QCefHandle::sigSaveFile(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QCefHandle::sigOpenUrl(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void QCefHandle::sigDrag(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void QCefHandle::sigOpenGroupFile(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void QCefHandle::sigSendFile(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void QCefHandle::sigRecoveryResult(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void QCefHandle::sigTransactionData(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}
QT_END_MOC_NAMESPACE
