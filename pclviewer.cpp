#include "pclviewer.h"
#include "kdtree.h"
#include "greedy_triangulation.h"
#include "smoothSurface.h"
#include "ui_pclviewer.h"
#include <QMainWindow>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>

#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QIODevice>
#include <QDockWidget>

#include <iostream>
#include <string>

PCLViewer::PCLViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PCLViewer)
{
    //ui->setWindowState(Qt::WindowMaximized);
    ui->setupUi(this);
    this->setWindowTitle("PCL viewer");
    ui->subwindow->setWindowState(Qt::WindowMaximized);

    mesh.reset(new pcl::PolygonMesh);
    smoothMesh.reset(new pcl::PolygonMesh);

    viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
    //initialize vtk
    viewer->setBackgroundColor(0.1, 0.1, 0.1);
    ui->qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
    viewer->setupInteractor(ui->qvtkWidget->GetInteractor(), ui->qvtkWidget->GetRenderWindow());
    ui->qvtkWidget->update();

    // add pointcloud
    cloud.reset(new PointCloudT);
    std::cout<< cloud->points.size() <<std::endl;
    simplifycloud.reset(new PointCloudT);
    //char* fileName = "/home/huangliang/rabbit.pcd";
    //pcl::io::loadPCDFile(fileName, *cloud);
    //simplifycloud = cloud;
    //simplify_old_cloud = cloud;
    /*
    viewer->addPointCloud(cloud, "cloud");
    viewer->resetCamera();
    ui->qvtkWidget->update();
    */
    //connect(ui->KtreeSlider, SIGNAL(sliderMoved(int)), this, SLOT(SimplifyPointcloud()));

    ui->ShowDockWidget->setMinimumWidth(250);
    ui->ShowDockWidget->setMinimumHeight(400);
    connect(ui->KtreeSlider, SIGNAL(valueChanged(int)), this, SLOT(SimplifyPointcloud()));
    connect(ui->ReconstructButton, SIGNAL(clicked(bool)), this, SLOT(ReconstructPolygonmesh()));
    connect(ui->ResetButton, SIGNAL(clicked(bool)), this, SLOT(ResetPointcloud()));
    connect(ui->BuildButton, SIGNAL(clicked(bool)),this, SLOT(CurvesurfaceReform()));
    connect(ui->ClearButton, SIGNAL(clicked(bool)), this, SLOT(clearCloudSlot()));

    connect(ui->OpenAction, SIGNAL(triggered(bool)), this, SLOT(openFileSlot()));
    connect(ui->FilterButton, SIGNAL(clicked(bool)), this, SLOT(filterSurfaceSlot()));

}

PCLViewer::~PCLViewer()
{
    delete ui;
}

void PCLViewer::SimplifyPointcloud()
{

   //PointCloudT::Ptr simplifyCloud;
   simplifycloud = KdTree(cloud, ui->KtreeSlider->value());
   viewer->removePointCloud();
   viewer->addPointCloud(simplifycloud);
   //simplify_old_cloud = simplify_new_cloud;
   viewer->resetCamera();
   ui->qvtkWidget->update();
   ui->lcdNumber->display(ui->KtreeSlider->value());

   //std::cout<<ui->KtreeSlider->value()<<std::endl;
}

void PCLViewer::ReconstructPolygonmesh()
{
    *mesh = rebuild(simplifycloud);
    viewer->removePointCloud();
    viewer->addPolygonMesh(*mesh, "chongjian");
    viewer->setRepresentationToWireframeForAllActors();
    viewer->resetCamera();
    ui->qvtkWidget->update();

}

void PCLViewer::filterSurfaceSlot()
{
    smoothMesh = smoothSurface(mesh);
    viewer->removePolygonMesh("chongjian");
    viewer->addPolygonMesh(*smoothMesh, "SmoothMesh");
    viewer->resetCamera();
    ui->qvtkWidget->update();
}


void PCLViewer::ResetPointcloud()
{
    viewer->removePolygonMesh("SmoothMesh");
    std::cout<<"qingkong"<<std::endl;
    smoothMesh.reset(new pcl::PolygonMesh);
    viewer->addPointCloud(cloud);
    viewer->resetCamera();
    ui->qvtkWidget->update();
    ui->KtreeSlider->setValue(0);
    ui->lcdNumber->display(ui->KtreeSlider->value());
}

/*jiang duobianxing wangge yong mian de xingshi xian
 * shi chu lai
 */
void PCLViewer::CurvesurfaceReform()
{
   // viewer->removePolygonMesh("chongjian");
    viewer->setRepresentationToSurfaceForAllActors();
    ui->qvtkWidget->update();
    std::cout<<"qumianchongjian"<<std::endl;

}

void PCLViewer::openFileSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());
    if (fileName.isEmpty())
    {
        QMessageBox::information(this, "Error Message", "Please select file");
        return;
    }
    std::cout << fileName.toStdString() <<std::endl;

    std::string fileAbsolutPath = fileName.toStdString();     //put Qstring convert to string
    char* cloudFileName = (char*) fileAbsolutPath.data();      //put string convert to char*

    // load pointcloud
    pcl::io::loadPCDFile(cloudFileName, *cloud);
    simplifycloud = cloud;

    if (cloud->points.size() > 0)
    {
        viewer->removePointCloud();
        viewer->resetCamera();
        ui->qvtkWidget->update();
    }

    viewer->addPointCloud(cloud, "cloud");
    viewer->resetCamera();
    ui->qvtkWidget->update();

}

void PCLViewer::clearCloudSlot()
{
    if(cloud->points.size() > 0)      //
    {
        //cloud.reset(new PointCloudT);        // reset pointcloud
        //viewer->addPointCloud(cloud, "cloud");
        viewer->removePointCloud();
        viewer->resetCamera();
        ui->qvtkWidget->update();
    }
}

