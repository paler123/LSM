#pragma once

#include <Eigen/Dense>
#include <vector>

namespace lsm::models {
struct RawModel {
    std::vector<double> times;
    std::vector<Eigen::MatrixXd> assets;
};
/*
 *   Simple market model for lsm pricing.
 *   Specified by providing:
 *     - expiry and number of steps
 *     - vector of assets trajectories in appropriate times
 *   Time starts at t=0.0 in the model, and progresses in equal steps until
 * expiry
 */
struct SimpleModel {
    SimpleModel(double expiry, int steps);
    std::vector<double> times;
};
} // namespace lsm::models
