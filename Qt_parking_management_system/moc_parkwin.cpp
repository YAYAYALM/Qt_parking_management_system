/****************************************************************************
** Meta object code from reading C++ file 'parkwin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "parkwin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parkwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParkWin_t {
    QByteArrayData data[14];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParkWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParkWin_t qt_meta_stringdata_ParkWin = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ParkWin"
QT_MOC_LITERAL(1, 8, 18), // "on_rightBt_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "on_upBt_clicked"
QT_MOC_LITERAL(4, 44, 23), // "on_actionexit_triggered"
QT_MOC_LITERAL(5, 68, 7), // "getData"
QT_MOC_LITERAL(6, 76, 10), // "getweather"
QT_MOC_LITERAL(7, 87, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 102, 1), // "p"
QT_MOC_LITERAL(9, 104, 18), // "on_adminBt_clicked"
QT_MOC_LITERAL(10, 123, 5), // "incar"
QT_MOC_LITERAL(11, 129, 7), // "getcard"
QT_MOC_LITERAL(12, 137, 3), // "fun"
QT_MOC_LITERAL(13, 141, 5) // "adfun"

    },
    "ParkWin\0on_rightBt_clicked\0\0on_upBt_clicked\0"
    "on_actionexit_triggered\0getData\0"
    "getweather\0QNetworkReply*\0p\0"
    "on_adminBt_clicked\0incar\0getcard\0fun\0"
    "adfun"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParkWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,
      12,    0,   74,    2, 0x08 /* Private */,
      13,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ParkWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ParkWin *_t = static_cast<ParkWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_rightBt_clicked(); break;
        case 1: _t->on_upBt_clicked(); break;
        case 2: _t->on_actionexit_triggered(); break;
        case 3: _t->getData(); break;
        case 4: _t->getweather((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->on_adminBt_clicked(); break;
        case 6: _t->incar(); break;
        case 7: _t->getcard(); break;
        case 8: _t->fun(); break;
        case 9: _t->adfun(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject ParkWin::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ParkWin.data,
      qt_meta_data_ParkWin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ParkWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParkWin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ParkWin.stringdata0))
        return static_cast<void*>(const_cast< ParkWin*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ParkWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
