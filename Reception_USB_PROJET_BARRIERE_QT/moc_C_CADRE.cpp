/****************************************************************************
** Meta object code from reading C++ file 'C_CADRE.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "C_CADRE.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'C_CADRE.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_C_CADRE_t {
    QByteArrayData data[11];
    char stringdata[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_C_CADRE_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_C_CADRE_t qt_meta_stringdata_C_CADRE = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 21),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 21),
QT_MOC_LITERAL(4, 53, 19),
QT_MOC_LITERAL(5, 73, 20),
QT_MOC_LITERAL(6, 94, 22),
QT_MOC_LITERAL(7, 117, 19),
QT_MOC_LITERAL(8, 137, 17),
QT_MOC_LITERAL(9, 155, 19),
QT_MOC_LITERAL(10, 175, 21)
    },
    "C_CADRE\0Signal_Set_Info_Carte\0\0"
    "Signal_Set_Etat_Carte\0Slot_Set_Info_Carte\0"
    "Slot_Connexion_Carte\0Slot_Connexion_Serveur\0"
    "Slot_Set_Etat_Carte\0Slot_On_Connexion\0"
    "Slot_On_Deconnexion\0Slot_On_Lecture_Dispo\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_C_CADRE[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x05,
       3,    0,   62,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    1,   63,    2, 0x09,
       5,    0,   66,    2, 0x09,
       6,    0,   67,    2, 0x09,
       7,    0,   68,    2, 0x09,
       8,    0,   69,    2, 0x09,
       9,    0,   70,    2, 0x09,
      10,    0,   71,    2, 0x09,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void C_CADRE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        C_CADRE *_t = static_cast<C_CADRE *>(_o);
        switch (_id) {
        case 0: _t->Signal_Set_Info_Carte((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->Signal_Set_Etat_Carte(); break;
        case 2: _t->Slot_Set_Info_Carte((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->Slot_Connexion_Carte(); break;
        case 4: _t->Slot_Connexion_Serveur(); break;
        case 5: _t->Slot_Set_Etat_Carte(); break;
        case 6: _t->Slot_On_Connexion(); break;
        case 7: _t->Slot_On_Deconnexion(); break;
        case 8: _t->Slot_On_Lecture_Dispo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (C_CADRE::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&C_CADRE::Signal_Set_Info_Carte)) {
                *result = 0;
            }
        }
        {
            typedef void (C_CADRE::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&C_CADRE::Signal_Set_Etat_Carte)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject C_CADRE::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_C_CADRE.data,
      qt_meta_data_C_CADRE,  qt_static_metacall, 0, 0}
};


const QMetaObject *C_CADRE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *C_CADRE::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_C_CADRE.stringdata))
        return static_cast<void*>(const_cast< C_CADRE*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int C_CADRE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void C_CADRE::Signal_Set_Info_Carte(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void C_CADRE::Signal_Set_Etat_Carte()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
