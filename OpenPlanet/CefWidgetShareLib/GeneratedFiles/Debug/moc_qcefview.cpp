/****************************************************************************
** Meta object code from reading C++ file 'qcefview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qcefview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcefview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QCefView_t {
    QByteArrayData data[18];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QCefView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QCefView_t qt_meta_stringdata_QCefView = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QCefView"
QT_MOC_LITERAL(1, 9, 10), // "sigZoomImg"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 12), // "sigVideoPlay"
QT_MOC_LITERAL(4, 34, 11), // "sigOpenFile"
QT_MOC_LITERAL(5, 46, 10), // "sigOpenDir"
QT_MOC_LITERAL(6, 57, 15), // "sigOpenDocument"
QT_MOC_LITERAL(7, 73, 23), // "sigCancleLoadorDownLoad"
QT_MOC_LITERAL(8, 97, 15), // "sigSendFileByID"
QT_MOC_LITERAL(9, 113, 10), // "sigGetFile"
QT_MOC_LITERAL(10, 124, 11), // "sigSaveFile"
QT_MOC_LITERAL(11, 136, 10), // "sigOpenUrl"
QT_MOC_LITERAL(12, 147, 7), // "sigDrag"
QT_MOC_LITERAL(13, 155, 16), // "sigOpenGroupFile"
QT_MOC_LITERAL(14, 172, 11), // "sigSendFile"
QT_MOC_LITERAL(15, 184, 17), // "sigRecoveryResult"
QT_MOC_LITERAL(16, 202, 18), // "sigTransactionData"
QT_MOC_LITERAL(17, 221, 9) // "slotStyle"

    },
    "QCefView\0sigZoomImg\0\0sigVideoPlay\0"
    "sigOpenFile\0sigOpenDir\0sigOpenDocument\0"
    "sigCancleLoadorDownLoad\0sigSendFileByID\0"
    "sigGetFile\0sigSaveFile\0sigOpenUrl\0"
    "sigDrag\0sigOpenGroupFile\0sigSendFile\0"
    "sigRecoveryResult\0sigTransactionData\0"
    "slotStyle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCefView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       3,    1,   97,    2, 0x06 /* Public */,
       4,    1,  100,    2, 0x06 /* Public */,
       5,    1,  103,    2, 0x06 /* Public */,
       6,    1,  106,    2, 0x06 /* Public */,
       7,    0,  109,    2, 0x06 /* Public */,
       8,    1,  110,    2, 0x06 /* Public */,
       9,    1,  113,    2, 0x06 /* Public */,
      10,    1,  116,    2, 0x06 /* Public */,
      11,    1,  119,    2, 0x06 /* Public */,
      12,    1,  122,    2, 0x06 /* Public */,
      13,    1,  125,    2, 0x06 /* Public */,
      14,    1,  128,    2, 0x06 /* Public */,
      15,    1,  131,    2, 0x06 /* Public */,
      16,    1,  134,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    0,  137,    2, 0x08 /* Private */,

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

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void QCefView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QCefView *_t = static_cast<QCefView *>(_o);
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
        case 15: _t->slotStyle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QCefView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefView::sigZoomImg)) {
                *result = 0;
            }
        }
        {
            typedef void (QCefView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefView::sigVideoPlay)) {
                *result = 1;
            }
        }
        {
            typedef void (QCefView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefView::sigOpenFile)) {
                *result = 2;
            }
        }
        {
            typedef void (QCefView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefView::sigOpenDir)) {
                *result = 3;
            }
        }
        {
            typedef void (QCefView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefView::sigOpenDocument)) {
                *result = 4;
            }
        }
        {
            typedef void (QCefView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefView::sigCancleLoadorDownLoad)) {
                *result = 5;
            }
        }
        {
            typedef void (QCefView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefView::sigSendFileByID)) {
                *result = 6;
            }
        }
        {
            typedef void (QCefView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefView::sigGetFile)) {
                *result = 7;
            }
        }
        {
            typedef void (QCefView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefView::sigSaveFile)) {
                *result = 8;
            }
        }
        {
            typedef void (QCefView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefView::sigOpenUrl)) {
                *result = 9;
            }
        }
        {
            typedef void (QCefView::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefView::sigDrag)) {
                *result = 10;
            }
        }
        {
            typedef void (QCefView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefView::sigOpenGroupFile)) {
                *result = 11;
            }
        }
        {
            typedef void (QCefView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefView::sigSendFile)) {
                *result = 12;
            }
        }
        {
            typedef void (QCefView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefView::sigRecoveryResult)) {
                *result = 13;
            }
        }
        {
            typedef void (QCefView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefView::sigTransactionData)) {
                *result = 14;
            }
        }
    }
}

const QMetaObject QCefView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QCefView.data,
      qt_meta_data_QCefView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QCefView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCefView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QCefView.stringdata0))
        return static_cast<void*>(const_cast< QCefView*>(this));
    return QWidget::qt_metacast(_clname);
}

int QCefView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void QCefView::sigZoomImg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QCefView::sigVideoPlay(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QCefView::sigOpenFile(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QCefView::sigOpenDir(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QCefView::sigOpenDocument(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QCefView::sigCancleLoadorDownLoad()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void QCefView::sigSendFileByID(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QCefView::sigGetFile(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QCefView::sigSaveFile(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QCefView::sigOpenUrl(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void QCefView::sigDrag(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void QCefView::sigOpenGroupFile(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void QCefView::sigSendFile(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void QCefView::sigRecoveryResult(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void QCefView::sigTransactionData(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}
QT_END_MOC_NAMESPACE
