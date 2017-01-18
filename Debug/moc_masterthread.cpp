/****************************************************************************
** Meta object code from reading C++ file 'masterthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../masterthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'masterthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MasterThread_t {
    QByteArrayData data[8];
    char stringdata[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MasterThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MasterThread_t qt_meta_stringdata_MasterThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MasterThread"
QT_MOC_LITERAL(1, 13, 8), // "response"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 1), // "s"
QT_MOC_LITERAL(4, 25, 5), // "error"
QT_MOC_LITERAL(5, 31, 7), // "timeout"
QT_MOC_LITERAL(6, 39, 12), // "responserial"
QT_MOC_LITERAL(7, 52, 13) // "responserial2"

    },
    "MasterThread\0response\0\0s\0error\0timeout\0"
    "responserial\0responserial2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MasterThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       5,    1,   45,    2, 0x06 /* Public */,
       6,    1,   48,    2, 0x06 /* Public */,
       7,    1,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void MasterThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MasterThread *_t = static_cast<MasterThread *>(_o);
        switch (_id) {
        case 0: _t->response((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->timeout((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->responserial((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->responserial2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MasterThread::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MasterThread::response)) {
                *result = 0;
            }
        }
        {
            typedef void (MasterThread::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MasterThread::error)) {
                *result = 1;
            }
        }
        {
            typedef void (MasterThread::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MasterThread::timeout)) {
                *result = 2;
            }
        }
        {
            typedef void (MasterThread::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MasterThread::responserial)) {
                *result = 3;
            }
        }
        {
            typedef void (MasterThread::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MasterThread::responserial2)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject MasterThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MasterThread.data,
      qt_meta_data_MasterThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MasterThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MasterThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MasterThread.stringdata))
        return static_cast<void*>(const_cast< MasterThread*>(this));
    return QThread::qt_metacast(_clname);
}

int MasterThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MasterThread::response(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MasterThread::error(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MasterThread::timeout(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MasterThread::responserial(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MasterThread::responserial2(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
