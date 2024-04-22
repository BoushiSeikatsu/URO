/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../QTProjekt/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "onTableClicked",
    "",
    "QModelIndex",
    "index",
    "exportFile",
    "importFile",
    "openOptionsSlot",
    "openAboutSlot",
    "openQtInfo",
    "resetSearch",
    "findAF",
    "createAF",
    "editAF",
    "deleteAF"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[11];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[6];
    char stringdata5[11];
    char stringdata6[11];
    char stringdata7[16];
    char stringdata8[14];
    char stringdata9[11];
    char stringdata10[12];
    char stringdata11[7];
    char stringdata12[9];
    char stringdata13[7];
    char stringdata14[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 14),  // "onTableClicked"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 11),  // "QModelIndex"
        QT_MOC_LITERAL(39, 5),  // "index"
        QT_MOC_LITERAL(45, 10),  // "exportFile"
        QT_MOC_LITERAL(56, 10),  // "importFile"
        QT_MOC_LITERAL(67, 15),  // "openOptionsSlot"
        QT_MOC_LITERAL(83, 13),  // "openAboutSlot"
        QT_MOC_LITERAL(97, 10),  // "openQtInfo"
        QT_MOC_LITERAL(108, 11),  // "resetSearch"
        QT_MOC_LITERAL(120, 6),  // "findAF"
        QT_MOC_LITERAL(127, 8),  // "createAF"
        QT_MOC_LITERAL(136, 6),  // "editAF"
        QT_MOC_LITERAL(143, 8)   // "deleteAF"
    },
    "MainWindow",
    "onTableClicked",
    "",
    "QModelIndex",
    "index",
    "exportFile",
    "importFile",
    "openOptionsSlot",
    "openAboutSlot",
    "openQtInfo",
    "resetSearch",
    "findAF",
    "createAF",
    "editAF",
    "deleteAF"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x0a,    1 /* Public */,
       5,    0,   83,    2, 0x0a,    3 /* Public */,
       6,    0,   84,    2, 0x0a,    4 /* Public */,
       7,    0,   85,    2, 0x0a,    5 /* Public */,
       8,    0,   86,    2, 0x0a,    6 /* Public */,
       9,    0,   87,    2, 0x0a,    7 /* Public */,
      10,    0,   88,    2, 0x0a,    8 /* Public */,
      11,    0,   89,    2, 0x0a,    9 /* Public */,
      12,    0,   90,    2, 0x0a,   10 /* Public */,
      13,    0,   91,    2, 0x0a,   11 /* Public */,
      14,    0,   92,    2, 0x0a,   12 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
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

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'onTableClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QModelIndex, std::false_type>,
        // method 'exportFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'importFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openOptionsSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openAboutSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openQtInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetSearch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'findAF'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createAF'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'editAF'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteAF'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onTableClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 1: _t->exportFile(); break;
        case 2: _t->importFile(); break;
        case 3: _t->openOptionsSlot(); break;
        case 4: _t->openAboutSlot(); break;
        case 5: _t->openQtInfo(); break;
        case 6: _t->resetSearch(); break;
        case 7: _t->findAF(); break;
        case 8: _t->createAF(); break;
        case 9: _t->editAF(); break;
        case 10: _t->deleteAF(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
