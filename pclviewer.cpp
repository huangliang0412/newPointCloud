#include "pclviewer.h"
#include "kdtree.h"
#include "greedy_triangulation.h"
#include "smoothSurface.h"
#include "ui_pclviewer.h"

#include "pretreatment.h"
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
#include <QInputDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <qdebug.h>

#include <iostream>
#include <string>

PCLViewer::PCLViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PCLViewer)
{
    //ui->setWindowState(Qt::WindowMaximized);
   //QLabel *point_lable = new QLable(tr("The Number of Points"));
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
    //std::cout<< cloud->points.size() <<std::endl;
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
    ui->PointsNumber->setMinimumHeight(60);
    ui->PointsNumber->setNumDigits(8);
    ui->lcdNumber->setMinimumHeight(50);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignHCenter);
    connect(ui->KtreeSlider, SIGNAL(valueChanged(int)), this, SLOT(SimplifyPointcloud()));

    connect(ui->MLSButton, SIGNAL(clicked(bool)), this, SLOT(mlsSlot()));
    connect(ui->DownSampingButton, SIGNAL(clicked(bool)), this, SLOT(downSamplingSlot()));


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
   int number = simplifycloud->size();
   //std::cout << number << std::endl;
   ui->PointsNumber->display(number);

   //std::cout<<ui->KtreeSlider->value()<<std::endl;
}

void PCLViewer::mlsSlot() {
    //QInputDialog *mlsDialog = new QInputDialog;
    MlsDialog *mlsDialog = new MlsDialog;
    mlsDialog->setWindowTitle(tr("SET MLS"));
    mlsDialog->exec();
    double mls_search_radius;
    mlsDialog->getStr(mls_search_radius);
    delete mlsDialog;
    PreTreatment prement;
    prement.mls(simplifycloud, mls_search_radius);
    viewer->removePointCloud();
    viewer->addPointCloud(simplifycloud);

    //PreTreatment::mls(cloud);
    viewer->resetCamera();
    ui->qvtkWidget->update();
    int number = simplifycloud->size();
    ui->PointsNumber->display(number);
}

void PCLViewer::downSamplingSlot() {
    DownSampingDialog *downDialog = new DownSampingDialog;
    downDialog->setWindowTitle(tr("SET DownSamping"));
    downDialog->exec();
    double leaf_size;
    downDialog->getStr(leaf_size);
    delete downDialog;
    PreTreatment prement;
    prement.downSamping(simplifycloud, leaf_size);
    viewer->removePointCloud();
    viewer->addPointCloud(simplifycloud);
    viewer->resetCamera();
    ui->qvtkWidget->update();
   // ui->PointsNumber->display(simplifycloud->size());


   // PreTreatment::downSamping(cloud);
   // viewer->resetCamera();
    //ui->qvtkWidget->update();

    int  number = simplifycloud->size();
   //std::cout << number << std::endl;
  //int pnum = 100;
   ui->PointsNumber->display(number);
}


void PCLViewer::ReconstructPolygonmesh()
{
    Triangulation *triang = new Triangulation;
    triang->setWindowTitle(tr("ReconstructPolygonmesh"));

    triang->exec();
    double maxp2plength;
    double searchradius;
    triang->getData(&maxp2plength, &searchradius);
    delete triang;
    *mesh = rebuild(simplifycloud, maxp2plength, searchradius);
    viewer->removePointCloud();
    viewer->addPolygonMesh(*mesh, "chongjian");
    viewer->setRepresentationToWireframeForAllActors();
    viewer->resetCamera();
    ui->qvtkWidget->update();

}

void PCLViewer::filterSurfaceSlot()
{
    /*
    smoothMesh = smoothSurface(mesh);
    viewer->removePolygonMesh("chongjian");
    viewer->addPolygonMesh(*smoothMesh, "SmoothMesh");
    viewer->resetCamera();
    ui->qvtkWidget->update();
    */
}


void PCLViewer::ResetPointcloud()
{
    //viewer->removePolygonMesh("SmoothMesh");
    viewer->removePolygonMesh("chongjian");
    std::cout<<"qingkong"<<std::endl;
    //smoothMesh.reset(new pcl::PolygonMesh);
    mesh.reset(new pcl::PolygonMesh);
    //viewer->addPointCloud(cloud);
    simplifycloud.reset(new PointCloudT);


    //memcpy()
    pcl::copyPointCloud(*cloud, *simplifycloud);
    viewer->addPointCloud(simplifycloud);
    viewer->resetCamera();
    ui->qvtkWidget->update();
    ui->KtreeSlider->setValue(0);
    ui->lcdNumber->display(ui->KtreeSlider->value());
    //ui->PointsNumber->display(simplifycloud->size());
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
    //simplifycloud = cloud;
    pcl::io::loadPCDFile(cloudFileName, *simplifycloud);
    if (cloud->points.size() > 0)
    {
        viewer->removePointCloud();
        viewer->resetCamera();
        ui->qvtkWidget->update();
    }

    viewer->addPointCloud(cloud, "cloud");
    viewer->resetCamera();
    ui->qvtkWidget->update();
    int number = simplifycloud->size();
    ui->PointsNumber->display(number);

}

void PCLViewer::clearCloudSlot()
{
    if(!viewer->removePolygonMesh("chongjian"))
        viewer->removePointCloud("cloud");


    //viewer->removeCoordinateSystem();
    viewer->resetCamera();
    ui->qvtkWidget->update();

    ui->PointsNumber->display(0);
   // std::cout<<viewer->removeAllShapes() << "sfsf" << std::end;;
    /*
    std::cout << viewer->removePolygonMesh("chongjian") << "dddd" << std::endl;
    viewer->resetCamera();
    ui->qvtkWidget->update();
    /*
    if(cloud->points.size() > 0)      //
    {
        //cloud.reset(new PointCloudT);        // reset pointcloud
        //viewer->addPointCloud(cloud, "cloud");
        viewer->removePointCloud();
        viewer->resetCamera();
        ui->qvtkWidget->update();
    }
    */
}


/***********************MlsDialog****************************/

MlsDialog::MlsDialog(QWidget *parent) :
    QDialog(parent) {
    label_1 = new QLabel(tr("search radius"));
    line_1 = new QLineEdit;
    line_1->setAlignment(Qt::AlignRight);
    line_1->setText("5.00");
    buttonbox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    QHBoxLayout *box = new QHBoxLayout;
    box->addWidget(label_1);
    box->addWidget(line_1);
    QVBoxLayout *box_1 = new QVBoxLayout;
    box_1->addLayout(box);
    box_1->addWidget(buttonbox);
    setLayout(box_1);
    connect(buttonbox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonbox, SIGNAL(rejected()), this, SLOT(reject()));
}

MlsDialog::~MlsDialog() {}

/***********************DownSampingDialog************************/

DownSampingDialog::DownSampingDialog(QWidget *parent) :
    QDialog(parent) {
    label_1 = new QLabel(tr("LeafSize"));
    line_1 = new QLineEdit;
    line_1->setAlignment(Qt::AlignRight);
    line_1->setText("1.50");
    buttonbox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    QHBoxLayout *box = new QHBoxLayout;
    box->addWidget(label_1);
    box->addWidget(line_1);
    QVBoxLayout *box_1 = new QVBoxLayout;
    box_1->addLayout(box);
    box_1->addWidget(buttonbox);
    setLayout(box_1);
    connect(buttonbox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonbox, SIGNAL(rejected()), this, SLOT(reject()));
}

DownSampingDialog::~DownSampingDialog() {}

/******************************Triangulation**********************/
Triangulation::Triangulation(QWidget *parent) :
    QDialog(parent) {
    label_1 = new QLabel(tr("maxp2plength:"));
    line_1 = new QLineEdit;
    line_1->setAlignment(Qt::AlignRight);
    line_1->setText("2.50");
    label_2 = new QLabel(tr("maxsearchRidius:"));
    line_2 = new QLineEdit;
    line_2->setAlignment(Qt::AlignRight);
    line_2->setText("4.00");

    label_3 = new QLabel(tr("maxAngle:"));
    line_3 = new QLineEdit;
    line_3->setAlignment(Qt::AlignRight);
    line_3->setText("120");

    label_4 = new QLabel(tr("minAngle"));
    line_4 = new QLineEdit;
    line_4->setAlignment(Qt::AlignRight);
    line_4->setText("20");

    QVBoxLayout *box = new QVBoxLayout;
    box->addWidget(label_1);
    box->addWidget(line_1);
    box->addWidget(label_2);
    box->addWidget(line_2);
    box->addWidget(label_3);
    box->addWidget(line_3);
    box->addWidget(label_4);
    box->addWidget(line_4);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(
                QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    box->addWidget(buttonBox);
    setLayout(box);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

Triangulation::~Triangulation() {}
/*
void Triangulation getData(double *maxp2plength, double *searchradius) {

}
*/
