#ifndef PRETREATMENT_H
#define PRETREATMENT_H

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/kdtree/flann.h>
#include <pcl/surface/mls.h>

class PreTreatment {
public:
    void mls(pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud, float mls_search_radius);
    void downSamping(pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud, float downSamping_K);
/*
private:
    float mls_search_radius;
    float downSamping_K;
*/
};

#endif // PRETREATMENT_H
