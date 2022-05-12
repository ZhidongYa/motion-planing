/****************************************************************************
** Meta object code from reading C++ file 'PathPlanningWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PathPlanningWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PathPlanningWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PathPlanningWindow_t {
    QByteArrayData data[22];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PathPlanningWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PathPlanningWindow_t qt_meta_stringdata_PathPlanningWindow = {
    {
QT_MOC_LITERAL(0, 0, 18), // "PathPlanningWindow"
QT_MOC_LITERAL(1, 19, 4), // "quit"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "closeEvent"
QT_MOC_LITERAL(4, 36, 12), // "QCloseEvent*"
QT_MOC_LITERAL(5, 49, 5), // "event"
QT_MOC_LITERAL(6, 55, 15), // "resetSceneryAll"
QT_MOC_LITERAL(7, 71, 9), // "loadScene"
QT_MOC_LITERAL(8, 81, 11), // "std::string"
QT_MOC_LITERAL(9, 93, 9), // "sceneFile"
QT_MOC_LITERAL(10, 103, 15), // "checkBoxOption1"
QT_MOC_LITERAL(11, 119, 16), // "buttonRunPlanner"
QT_MOC_LITERAL(12, 136, 13), // "visualizeGrid"
QT_MOC_LITERAL(13, 150, 11), // "buttonStep2"
QT_MOC_LITERAL(14, 162, 11), // "buttonStep3"
QT_MOC_LITERAL(15, 174, 16), // "sliderTrajectory"
QT_MOC_LITERAL(16, 191, 3), // "pos"
QT_MOC_LITERAL(17, 195, 19), // "comboBoxSelectScene"
QT_MOC_LITERAL(18, 215, 5), // "scene"
QT_MOC_LITERAL(19, 221, 23), // "comboBoxSelectAlgorithm"
QT_MOC_LITERAL(20, 245, 4), // "algo"
QT_MOC_LITERAL(21, 250, 20) // "rebuildVisualization"

    },
    "PathPlanningWindow\0quit\0\0closeEvent\0"
    "QCloseEvent*\0event\0resetSceneryAll\0"
    "loadScene\0std::string\0sceneFile\0"
    "checkBoxOption1\0buttonRunPlanner\0"
    "visualizeGrid\0buttonStep2\0buttonStep3\0"
    "sliderTrajectory\0pos\0comboBoxSelectScene\0"
    "scene\0comboBoxSelectAlgorithm\0algo\0"
    "rebuildVisualization"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PathPlanningWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    1,   80,    2, 0x0a /* Public */,
       6,    0,   83,    2, 0x0a /* Public */,
       7,    1,   84,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    0,   88,    2, 0x0a /* Public */,
      12,    0,   89,    2, 0x0a /* Public */,
      13,    0,   90,    2, 0x0a /* Public */,
      14,    0,   91,    2, 0x0a /* Public */,
      15,    1,   92,    2, 0x0a /* Public */,
      17,    1,   95,    2, 0x0a /* Public */,
      19,    1,   98,    2, 0x0a /* Public */,
      21,    0,  101,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,

       0        // eod
};

void PathPlanningWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PathPlanningWindow *_t = static_cast<PathPlanningWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->quit(); break;
        case 1: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 2: _t->resetSceneryAll(); break;
        case 3: _t->loadScene((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: _t->checkBoxOption1(); break;
        case 5: _t->buttonRunPlanner(); break;
        case 6: _t->visualizeGrid(); break;
        case 7: _t->buttonStep2(); break;
        case 8: _t->buttonStep3(); break;
        case 9: _t->sliderTrajectory((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->comboBoxSelectScene((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->comboBoxSelectAlgorithm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->rebuildVisualization(); break;
        default: ;
        }
    }
}

const QMetaObject PathPlanningWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PathPlanningWindow.data,
      qt_meta_data_PathPlanningWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PathPlanningWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PathPlanningWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PathPlanningWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PathPlanningWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
