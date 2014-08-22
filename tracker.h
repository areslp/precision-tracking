/*
 * aligner.h
 *
 *  Created on: Nov 20, 2011
 *      Author: davheld
 */

#ifndef MOVING_SYNCHRONIZER_MODEL_BUILDER_H_
#define MOVING_SYNCHRONIZER_MODEL_BUILDER_H_

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

#include "motion_model.h"
#include "precision_tracker.h"

class Tracker {
public:
  Tracker();
  virtual ~Tracker();

  void clear();

  void addPoints(
      const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& current_points,
      const double timestamp,
      const Eigen::Vector3f& centroid,
      Eigen::Vector3f* estimated_velocity);

private:

  pcl::PointCloud<pcl::PointXYZRGB>::Ptr previousModel_;
  double prev_timestamp_;

  boost::shared_ptr<MotionModel> motion_model_;

  PrecisionTracker precision_tracker_;

};


#endif /* MOVING_SYNCHRONIZER_MODEL_BUILDER_H_ */