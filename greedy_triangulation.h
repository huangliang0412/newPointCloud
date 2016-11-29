#ifndef GREEDY_TRIANGULATION_H
#define GREEDY_TRIANGULATION_H

#include <pcl/point_types.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include <pcl/visualization/pcl_visualizer.h>

//calculate each point of this cloudpoints normal vector
pcl::PointCloud<pcl::PointNormal>::Ptr calculate_normal(pcl::PointCloud<pcl::PointXYZ>::Ptr &);

//mesh reconstruct algorithm
pcl::PolygonMesh reconstruct_mesh(pcl::PointCloud<pcl::PointNormal>::Ptr);

pcl::PolygonMesh rebuild(pcl::PointCloud<pcl::PointXYZ>::Ptr &);
#endif // GREEDY_TRIANGULATION_H
