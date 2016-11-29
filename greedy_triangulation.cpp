#include "greedy_triangulation.h"
#include <iostream>
#include <pcl/io/vtk_io.h>
#include <pcl/surface/processing.h>
#include <pcl/surface/vtk_smoothing/vtk_mesh_subdivision.h>
#include <pcl/surface/vtk_smoothing/vtk.h>
using namespace pcl;

/*calculate every points of cloudpoint normal vector*/
PointCloud<PointNormal>::Ptr calculate_normal(PointCloud<PointXYZ>::Ptr &cloud)
{
    NormalEstimation<PointXYZ, Normal> ne;
    PointCloud<Normal>::Ptr normals(new PointCloud<Normal>);
    search::KdTree<PointXYZ>::Ptr tree(new search::KdTree<PointXYZ>);

    tree->setInputCloud(cloud);
    ne.setInputCloud(cloud);
    ne.setSearchMethod(tree);
    ne.setKSearch(20);
    ne.compute(*normals);       //calculate normal vector

    PointCloud<PointNormal>::Ptr cloud_with_normals(new PointCloud<PointNormal>);
    //combine normal vectors with points
    concatenateFields(*cloud, *normals, *cloud_with_normals);
    return cloud_with_normals;


}

PolygonMesh reconstruct_mesh(pcl::PointCloud<pcl::PointNormal>::Ptr cloud_normals)
{
    search::KdTree<PointNormal>::Ptr tree2(new search::KdTree<PointNormal>);

    tree2->setInputCloud(cloud_normals);

    //use greedy triangulation algrithom reconstruct
    GreedyProjectionTriangulation<PointNormal> gp3;

    //build polygonmesh
    PolygonMesh triangles;

    //set the maximum distance between connected points (maximum edge length)
    gp3.setSearchRadius(25);  //0.025

    //Set typical value for the parameters
    gp3.setMu(2.5);
    gp3.setMaximumNearestNeighbors(100);
    gp3.setMaximumSurfaceAngle(M_PI/4);   //45 degrees
    gp3.setMaximumAngle(M_PI/18);         //10 degrees
    gp3.setMaximumAngle(2*M_PI/3);        //120 degrees
    gp3.setNormalConsistency(false);

    /* Get result */
    gp3.setInputCloud (cloud_normals);
    gp3.setSearchMethod(tree2);
	gp3.reconstruct(triangles);
    pcl::io::saveVTKFile("mymesh.vtk", triangles);
    return triangles;
}

PolygonMesh rebuild(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud)
{
    PointCloud<PointNormal>::Ptr ne;
    ne = calculate_normal(cloud);
    PolygonMesh::Ptr mesh(new PolygonMesh);
    *mesh = reconstruct_mesh(ne);
    std::cout<<"nihao"<<std::endl;


    return *mesh;
}

