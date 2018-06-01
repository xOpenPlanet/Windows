/****************************************************************************
** Meta object code from reading C++ file 'httpnetworksharelib.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../httpnetworksharelib.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpnetworksharelib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HttpNetWork__HttpNetWorkShareLib_t {
    QByteArrayData data[9];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpNetWork__HttpNetWorkShareLib_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpNetWork__HttpNetWorkShareLib_t qt_meta_stringdata_HttpNetWork__HttpNetWorkShareLib = {
    {
QT_MOC_LITERAL(0, 0, 32), // "HttpNetWork::HttpNetWorkShareLib"
QT_MOC_LITERAL(1, 33, 16), // "sigReplyFinished"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 7), // "bResult"
QT_MOC_LITERAL(4, 59, 9), // "strResult"
QT_MOC_LITERAL(5, 69, 17), // "slotReplyFinished"
QT_MOC_LITERAL(6, 87, 14), // "QNetworkReply*"
QT_MOC_LITERAL(7, 102, 5), // "reply"
QT_MOC_LITERAL(8, 108, 18) // "slotRequestTimeout"

    },
    "HttpNetWork::HttpNetWorkShareLib\0"
    "sigReplyFinished\0\0bResult\0strResult\0"
    "slotReplyFinished\0QNetworkReply*\0reply\0"
    "slotRequestTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpNetWork__HttpNetWorkShareLib[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   34,    2, 0x08 /* Private */,
       8,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

       0        // eod
};

void HttpNetWork::HttpNetWorkShareLib::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HttpNetWorkShareLib *_t = static_cast<HttpNetWorkShareLib *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigReplyFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->slotReplyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->slotRequestTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HttpNetWorkShareLib::*_t)(bool , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HttpNetWorkShareLib::sigReplyFinished)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject HttpNetWork::HttpNetWorkShareLib::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HttpNetWork__HttpNetWorkShareLib.data,
      qt_meta_data_HttpNetWork__HttpNetWorkShareLib,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HttpNetWork::HttpNetWorkShareLib::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpNetWork::HttpNetWorkShareLib::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HttpNetWork__HttpNetWorkShareLib.stringdata0))
        return static_cast<void*>(const_cast< HttpNetWorkShareLib*>(this));
    return QObject::qt_metacast(_clname);
}

int HttpNetWork::HttpNetWorkShareLib::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void HttpNetWork::HttpNetWorkShareLib::sigReplyFinished(bool _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_HttpNetWork__HttpDownLoadFile_t {
    QByteArrayData data[12];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpNetWork__HttpDownLoadFile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpNetWork__HttpDownLoadFile_t qt_meta_stringdata_HttpNetWork__HttpDownLoadFile = {
    {
QT_MOC_LITERAL(0, 0, 29), // "HttpNetWork::HttpDownLoadFile"
QT_MOC_LITERAL(1, 30, 15), // "sigDownFinished"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 19), // "sigDownloadProgress"
QT_MOC_LITERAL(4, 67, 9), // "bytesSent"
QT_MOC_LITERAL(5, 77, 10), // "bytesTotal"
QT_MOC_LITERAL(6, 88, 13), // "replyFinished"
QT_MOC_LITERAL(7, 102, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 117, 5), // "reply"
QT_MOC_LITERAL(9, 123, 18), // "onDownloadProgress"
QT_MOC_LITERAL(10, 142, 11), // "onReadyRead"
QT_MOC_LITERAL(11, 154, 24) // "slotLoadorDownLoadCancle"

    },
    "HttpNetWork::HttpDownLoadFile\0"
    "sigDownFinished\0\0sigDownloadProgress\0"
    "bytesSent\0bytesTotal\0replyFinished\0"
    "QNetworkReply*\0reply\0onDownloadProgress\0"
    "onReadyRead\0slotLoadorDownLoadCancle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpNetWork__HttpDownLoadFile[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    2,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   52,    2, 0x0a /* Public */,
       9,    2,   55,    2, 0x0a /* Public */,
      10,    0,   60,    2, 0x0a /* Public */,
      11,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HttpNetWork::HttpDownLoadFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HttpDownLoadFile *_t = static_cast<HttpDownLoadFile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigDownFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sigDownloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 2: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->onDownloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 4: _t->onReadyRead(); break;
        case 5: _t->slotLoadorDownLoadCancle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HttpDownLoadFile::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HttpDownLoadFile::sigDownFinished)) {
                *result = 0;
            }
        }
        {
            typedef void (HttpDownLoadFile::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HttpDownLoadFile::sigDownloadProgress)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject HttpNetWork::HttpDownLoadFile::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HttpNetWork__HttpDownLoadFile.data,
      qt_meta_data_HttpNetWork__HttpDownLoadFile,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HttpNetWork::HttpDownLoadFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpNetWork::HttpDownLoadFile::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HttpNetWork__HttpDownLoadFile.stringdata0))
        return static_cast<void*>(const_cast< HttpDownLoadFile*>(this));
    return QObject::qt_metacast(_clname);
}

int HttpNetWork::HttpDownLoadFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void HttpNetWork::HttpDownLoadFile::sigDownFinished(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HttpNetWork::HttpDownLoadFile::sigDownloadProgress(qint64 _t1, qint64 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_HttpNetWork__HttpUpLoadFile_t {
    QByteArrayData data[12];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpNetWork__HttpUpLoadFile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpNetWork__HttpUpLoadFile_t qt_meta_stringdata_HttpNetWork__HttpUpLoadFile = {
    {
QT_MOC_LITERAL(0, 0, 27), // "HttpNetWork::HttpUpLoadFile"
QT_MOC_LITERAL(1, 28, 17), // "sigUpLoadFinished"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 7), // "bResult"
QT_MOC_LITERAL(4, 55, 9), // "byteArray"
QT_MOC_LITERAL(5, 65, 17), // "sigUpLoadProgress"
QT_MOC_LITERAL(6, 83, 9), // "bytesSent"
QT_MOC_LITERAL(7, 93, 10), // "bytesTotal"
QT_MOC_LITERAL(8, 104, 13), // "replyFinished"
QT_MOC_LITERAL(9, 118, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 133, 16), // "OnUploadProgress"
QT_MOC_LITERAL(11, 150, 24) // "slotLoadorDownLoadCancle"

    },
    "HttpNetWork::HttpUpLoadFile\0"
    "sigUpLoadFinished\0\0bResult\0byteArray\0"
    "sigUpLoadProgress\0bytesSent\0bytesTotal\0"
    "replyFinished\0QNetworkReply*\0"
    "OnUploadProgress\0slotLoadorDownLoadCancle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpNetWork__HttpUpLoadFile[] = {

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
       5,    2,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   49,    2, 0x0a /* Public */,
      10,    2,   52,    2, 0x0a /* Public */,
      11,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QByteArray,    3,    4,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    6,    7,
    QMetaType::Void,

       0        // eod
};

void HttpNetWork::HttpUpLoadFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HttpUpLoadFile *_t = static_cast<HttpUpLoadFile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUpLoadFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->sigUpLoadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 2: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->OnUploadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 4: _t->slotLoadorDownLoadCancle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HttpUpLoadFile::*_t)(bool , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HttpUpLoadFile::sigUpLoadFinished)) {
                *result = 0;
            }
        }
        {
            typedef void (HttpUpLoadFile::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HttpUpLoadFile::sigUpLoadProgress)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject HttpNetWork::HttpUpLoadFile::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HttpNetWork__HttpUpLoadFile.data,
      qt_meta_data_HttpNetWork__HttpUpLoadFile,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HttpNetWork::HttpUpLoadFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpNetWork::HttpUpLoadFile::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HttpNetWork__HttpUpLoadFile.stringdata0))
        return static_cast<void*>(const_cast< HttpUpLoadFile*>(this));
    return QObject::qt_metacast(_clname);
}

int HttpNetWork::HttpUpLoadFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void HttpNetWork::HttpUpLoadFile::sigUpLoadFinished(bool _t1, QByteArray _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HttpNetWork::HttpUpLoadFile::sigUpLoadProgress(qint64 _t1, qint64 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
