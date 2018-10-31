/****************************************************************************
** Meta object code from reading C++ file 'normalwindows.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../trainsys/normalwindows.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'normalwindows.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_normalWindows_t {
    QByteArrayData data[12];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_normalWindows_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_normalWindows_t qt_meta_stringdata_normalWindows = {
    {
QT_MOC_LITERAL(0, 0, 13), // "normalWindows"
QT_MOC_LITERAL(1, 14, 22), // "on_backCommand_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 60, 29), // "on_pushButtonresearch_clicked"
QT_MOC_LITERAL(5, 90, 26), // "on_pushButtonCheck_clicked"
QT_MOC_LITERAL(6, 117, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(7, 141, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(8, 165, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(9, 189, 28), // "on_tableWidget_doubleClicked"
QT_MOC_LITERAL(10, 218, 5), // "index"
QT_MOC_LITERAL(11, 224, 30) // "on_tableWidget_2_doubleClicked"

    },
    "normalWindows\0on_backCommand_clicked\0"
    "\0on_pushButton_clicked\0"
    "on_pushButtonresearch_clicked\0"
    "on_pushButtonCheck_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked\0"
    "on_tableWidget_doubleClicked\0index\0"
    "on_tableWidget_2_doubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_normalWindows[] = {

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
       8,    0,   65,    2, 0x08 /* Private */,
       9,    1,   66,    2, 0x08 /* Private */,
      11,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   10,
    QMetaType::Void, QMetaType::QModelIndex,   10,

       0        // eod
};

void normalWindows::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        normalWindows *_t = static_cast<normalWindows *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_backCommand_clicked(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButtonresearch_clicked(); break;
        case 3: _t->on_pushButtonCheck_clicked(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->on_pushButton_3_clicked(); break;
        case 6: _t->on_pushButton_4_clicked(); break;
        case 7: _t->on_tableWidget_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_tableWidget_2_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject normalWindows::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_normalWindows.data,
      qt_meta_data_normalWindows,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *normalWindows::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *normalWindows::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_normalWindows.stringdata0))
        return static_cast<void*>(const_cast< normalWindows*>(this));
    return QWidget::qt_metacast(_clname);
}

int normalWindows::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
