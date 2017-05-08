/****************************************************************************
** Meta object code from reading C++ file 'pclviewer.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pclviewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pclviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PCLViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      32,   10,   10,   10, 0x0a,
      57,   10,   10,   10, 0x0a,
      75,   10,   10,   10, 0x0a,
      96,   10,   10,   10, 0x0a,
     111,   10,   10,   10, 0x0a,
     128,   10,   10,   10, 0x0a,
     148,   10,   10,   10, 0x0a,
     158,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PCLViewer[] = {
    "PCLViewer\0\0SimplifyPointcloud()\0"
    "ReconstructPolygonmesh()\0ResetPointcloud()\0"
    "CurvesurfaceReform()\0openFileSlot()\0"
    "clearCloudSlot()\0filterSurfaceSlot()\0"
    "mlsSlot()\0downSamplingSlot()\0"
};

void PCLViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PCLViewer *_t = static_cast<PCLViewer *>(_o);
        switch (_id) {
        case 0: _t->SimplifyPointcloud(); break;
        case 1: _t->ReconstructPolygonmesh(); break;
        case 2: _t->ResetPointcloud(); break;
        case 3: _t->CurvesurfaceReform(); break;
        case 4: _t->openFileSlot(); break;
        case 5: _t->clearCloudSlot(); break;
        case 6: _t->filterSurfaceSlot(); break;
        case 7: _t->mlsSlot(); break;
        case 8: _t->downSamplingSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PCLViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PCLViewer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PCLViewer,
      qt_meta_data_PCLViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PCLViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PCLViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PCLViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PCLViewer))
        return static_cast<void*>(const_cast< PCLViewer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PCLViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
static const uint qt_meta_data_MlsDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_MlsDialog[] = {
    "MlsDialog\0"
};

void MlsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MlsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MlsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MlsDialog,
      qt_meta_data_MlsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MlsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MlsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MlsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MlsDialog))
        return static_cast<void*>(const_cast< MlsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MlsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_DownSampingDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_DownSampingDialog[] = {
    "DownSampingDialog\0"
};

void DownSampingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DownSampingDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DownSampingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DownSampingDialog,
      qt_meta_data_DownSampingDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DownSampingDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DownSampingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DownSampingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DownSampingDialog))
        return static_cast<void*>(const_cast< DownSampingDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int DownSampingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
