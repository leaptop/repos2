/****************************************************************************
** Meta object code from reading C++ file 'startdialog_ladyshkin_golcev.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../lab_2/startdialog_ladyshkin_golcev.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'startdialog_ladyshkin_golcev.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_startdialog_ladyshkin_golcev_t {
    QByteArrayData data[3];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_startdialog_ladyshkin_golcev_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_startdialog_ladyshkin_golcev_t qt_meta_stringdata_startdialog_ladyshkin_golcev = {
    {
QT_MOC_LITERAL(0, 0, 28), // "startdialog_ladyshkin_golcev"
QT_MOC_LITERAL(1, 29, 17), // "slotButtonClicked"
QT_MOC_LITERAL(2, 47, 0) // ""

    },
    "startdialog_ladyshkin_golcev\0"
    "slotButtonClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_startdialog_ladyshkin_golcev[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void startdialog_ladyshkin_golcev::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        startdialog_ladyshkin_golcev *_t = static_cast<startdialog_ladyshkin_golcev *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotButtonClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject startdialog_ladyshkin_golcev::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_startdialog_ladyshkin_golcev.data,
      qt_meta_data_startdialog_ladyshkin_golcev,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *startdialog_ladyshkin_golcev::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *startdialog_ladyshkin_golcev::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_startdialog_ladyshkin_golcev.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int startdialog_ladyshkin_golcev::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
