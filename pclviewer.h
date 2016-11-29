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

//#include "smoothSurface.h"
typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

namespace Ui {
class PCLViewer;
}

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


protected:
    //boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    pcl::visualization::PCLVisualizer::Ptr viewer;
    PointCloudT::Ptr cloud, simplifycloud;
    pcl::PolygonMesh::Ptr mesh, smoothMesh;


private:
    Ui::PCLViewer *ui;
};

#endif // PCLVIEWER_H
