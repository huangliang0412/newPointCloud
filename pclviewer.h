#ifndef PCLVIEWER_H
#define PCLVIEWER_H
// Qt Library
#include <QMainWindow>

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/PolygonMesh.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>
// visualization Toolkit
#include <vtkRenderWindow.h>

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <qdebug.h>

#include <iostream>
//#include "smoothSurface.h"
typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

namespace Ui {
class PCLViewer;
}

class MlsDialog;
class DownSampingDialog;
class PCLViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit PCLViewer(QWidget *parent = 0);
    ~PCLViewer();


public slots:
    void SimplifyPointcloud();   //simplify pointcloud
    void ReconstructPolygonmesh();

    void ResetPointcloud();      //reset
    void CurvesurfaceReform();     //qumian chongjian

    void openFileSlot();
    void clearCloudSlot();          //clear the cloud data from the vtk

    void filterSurfaceSlot();       // let surface get more smoother

    void mlsSlot();
    void downSamplingSlot();

protected:
    //boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    pcl::visualization::PCLVisualizer::Ptr viewer;
    PointCloudT::Ptr cloud, simplifycloud;
    pcl::PolygonMesh::Ptr mesh, smoothMesh;


private:
    Ui::PCLViewer *ui;
};

class MlsDialog : public QDialog {
    Q_OBJECT

public:
    explicit MlsDialog(QWidget *parent = 0);
    ~MlsDialog();
    void inline getStr(double& mls_search_radius) {
        str = line_1->text();
        mls_search_radius = str.toDouble();
       // std::cout << mls_search_radius << std::endl;
        //qDebug() << str;
    }

public slots:
    //void accept();
    //void reject();


private:
    QString str;
    QLabel *label_1;
    QLineEdit *line_1;
    QDialogButtonBox *buttonbox;
};

class DownSampingDialog : public QDialog {
    Q_OBJECT

public:
    explicit DownSampingDialog(QWidget *parent = 0);
    ~DownSampingDialog();
    void inline getStr(double & leaf_size) {
        str = line_1->text();
        leaf_size = str.toDouble();
        //qDebug() << str;
    }

public slots:
    //void accept();
    //void reject();


private:
    QString str;
    QLabel *label_1;
    QLineEdit *line_1;
    QDialogButtonBox *buttonbox;
};

class Triangulation : public QDialog {
    Q_OBJECT

public:
    explicit Triangulation(QWidget *parent = 0);
    ~Triangulation();
    void inline getData(double *maxp2plength, double *searchradius) {
        *maxp2plength = line_1->text().toDouble();
        *searchradius = line_2->text().toDouble();
    }

public slots:

private:
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *line_1;
    QLineEdit *line_2;
    QLineEdit *line_3;
    QLineEdit *line_4;
};

#endif // PCLVIEWER_H
