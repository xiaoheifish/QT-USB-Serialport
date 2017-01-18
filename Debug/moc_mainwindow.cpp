/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "writeOne"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "writeserial"
QT_MOC_LITERAL(4, 33, 10), // "showserial"
QT_MOC_LITERAL(5, 44, 1), // "s"
QT_MOC_LITERAL(6, 46, 11), // "showserial2"
QT_MOC_LITERAL(7, 58, 26), // "on_buttonSelfWrite_clicked"
QT_MOC_LITERAL(8, 85, 25), // "on_buttonSelfRead_clicked"
QT_MOC_LITERAL(9, 111, 25), // "on_buttonAddWrite_clicked"
QT_MOC_LITERAL(10, 137, 28), // "on_buttonSelfWrite_2_clicked"
QT_MOC_LITERAL(11, 166, 12), // "showResponse"
QT_MOC_LITERAL(12, 179, 27), // "on_buttonSelfRead_2_clicked"
QT_MOC_LITERAL(13, 207, 27), // "on_buttonAddWrite_2_clicked"
QT_MOC_LITERAL(14, 235, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(15, 257, 25), // "on_radioButtonUSB_clicked"
QT_MOC_LITERAL(16, 283, 28), // "on_radioButtonSerial_clicked"
QT_MOC_LITERAL(17, 312, 25) // "on_buttonReadStop_clicked"

    },
    "MainWindow\0writeOne\0\0writeserial\0"
    "showserial\0s\0showserial2\0"
    "on_buttonSelfWrite_clicked\0"
    "on_buttonSelfRead_clicked\0"
    "on_buttonAddWrite_clicked\0"
    "on_buttonSelfWrite_2_clicked\0showResponse\0"
    "on_buttonSelfRead_2_clicked\0"
    "on_buttonAddWrite_2_clicked\0"
    "on_pushButton_clicked\0on_radioButtonUSB_clicked\0"
    "on_radioButtonSerial_clicked\0"
    "on_buttonReadStop_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    1,   91,    2, 0x08 /* Private */,
       6,    1,   94,    2, 0x08 /* Private */,
       7,    0,   97,    2, 0x08 /* Private */,
       8,    0,   98,    2, 0x08 /* Private */,
       9,    0,   99,    2, 0x08 /* Private */,
      10,    0,  100,    2, 0x08 /* Private */,
      11,    1,  101,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->writeOne(); break;
        case 1: _t->writeserial(); break;
        case 2: _t->showserial((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->showserial2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_buttonSelfWrite_clicked(); break;
        case 5: _t->on_buttonSelfRead_clicked(); break;
        case 6: _t->on_buttonAddWrite_clicked(); break;
        case 7: _t->on_buttonSelfWrite_2_clicked(); break;
        case 8: _t->showResponse((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_buttonSelfRead_2_clicked(); break;
        case 10: _t->on_buttonAddWrite_2_clicked(); break;
        case 11: _t->on_pushButton_clicked(); break;
        case 12: _t->on_radioButtonUSB_clicked(); break;
        case 13: _t->on_radioButtonSerial_clicked(); break;
        case 14: _t->on_buttonReadStop_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
