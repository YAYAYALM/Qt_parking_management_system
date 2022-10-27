/****************************************************************************
** Meta object code from reading C++ file 'adminlogwin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "adminlogwin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminlogwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AdminLogWin_t {
    QByteArrayData data[13];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminLogWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminLogWin_t qt_meta_stringdata_AdminLogWin = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AdminLogWin"
QT_MOC_LITERAL(1, 12, 23), // "on_actionquit_triggered"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 17), // "on_leftBt_clicked"
QT_MOC_LITERAL(4, 55, 18), // "on_rightBt_clicked"
QT_MOC_LITERAL(5, 74, 19), // "on_updataBt_clicked"
QT_MOC_LITERAL(6, 94, 16), // "on_carBt_clicked"
QT_MOC_LITERAL(7, 111, 16), // "on_monBt_clicked"
QT_MOC_LITERAL(8, 128, 26), // "on_tableWidget_itemClicked"
QT_MOC_LITERAL(9, 155, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(10, 173, 4), // "item"
QT_MOC_LITERAL(11, 178, 19), // "on_deleteBt_clicked"
QT_MOC_LITERAL(12, 198, 17) // "on_cheCar_clicked"

    },
    "AdminLogWin\0on_actionquit_triggered\0"
    "\0on_leftBt_clicked\0on_rightBt_clicked\0"
    "on_updataBt_clicked\0on_carBt_clicked\0"
    "on_monBt_clicked\0on_tableWidget_itemClicked\0"
    "QTableWidgetItem*\0item\0on_deleteBt_clicked\0"
    "on_cheCar_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminLogWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    1,   65,    2, 0x08 /* Private */,
      11,    0,   68,    2, 0x08 /* Private */,
      12,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AdminLogWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdminLogWin *_t = static_cast<AdminLogWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionquit_triggered(); break;
        case 1: _t->on_leftBt_clicked(); break;
        case 2: _t->on_rightBt_clicked(); break;
        case 3: _t->on_updataBt_clicked(); break;
        case 4: _t->on_carBt_clicked(); break;
        case 5: _t->on_monBt_clicked(); break;
        case 6: _t->on_tableWidget_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->on_deleteBt_clicked(); break;
        case 8: _t->on_cheCar_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject AdminLogWin::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AdminLogWin.data,
      qt_meta_data_AdminLogWin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AdminLogWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminLogWin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AdminLogWin.stringdata0))
        return static_cast<void*>(const_cast< AdminLogWin*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AdminLogWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
