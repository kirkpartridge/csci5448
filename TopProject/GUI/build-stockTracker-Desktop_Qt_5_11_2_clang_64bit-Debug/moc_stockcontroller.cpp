/****************************************************************************
** Meta object code from reading C++ file 'stockcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../stockTracker/stockcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stockcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StockController_t {
    QByteArrayData data[10];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StockController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StockController_t qt_meta_stringdata_StockController = {
    {
QT_MOC_LITERAL(0, 0, 15), // "StockController"
QT_MOC_LITERAL(1, 16, 21), // "handleImportCSVButton"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 21), // "handleExportCSVButton"
QT_MOC_LITERAL(4, 61, 26), // "handleAddTransactionButton"
QT_MOC_LITERAL(5, 88, 32), // "handleCancelAddTransactionButton"
QT_MOC_LITERAL(6, 121, 29), // "handleAddNewTransactionButton"
QT_MOC_LITERAL(7, 151, 18), // "handleSymbolButton"
QT_MOC_LITERAL(8, 170, 16), // "handleBackButton"
QT_MOC_LITERAL(9, 187, 18) // "handleSearchButton"

    },
    "StockController\0handleImportCSVButton\0"
    "\0handleExportCSVButton\0"
    "handleAddTransactionButton\0"
    "handleCancelAddTransactionButton\0"
    "handleAddNewTransactionButton\0"
    "handleSymbolButton\0handleBackButton\0"
    "handleSearchButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StockController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StockController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StockController *_t = static_cast<StockController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleImportCSVButton(); break;
        case 1: _t->handleExportCSVButton(); break;
        case 2: _t->handleAddTransactionButton(); break;
        case 3: _t->handleCancelAddTransactionButton(); break;
        case 4: _t->handleAddNewTransactionButton(); break;
        case 5: _t->handleSymbolButton(); break;
        case 6: _t->handleBackButton(); break;
        case 7: _t->handleSearchButton(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject StockController::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_StockController.data,
      qt_meta_data_StockController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *StockController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StockController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StockController.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int StockController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
