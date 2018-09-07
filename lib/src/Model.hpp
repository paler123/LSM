#pragma once

#include<vector>
#include<Eigen/Dense>

namespace lsm
{
    /*
     *   Simple market model for lsm pricing.
     *   Specified by providing:
     *     - expiry and number of steps
     *     - vector of assets trajectories in appropriate times
     *   Time starts at t=0.0 in the model, and progresses in equal steps until expiry
     */
    struct SimpleModel {
        SimpleModel(double expiry, int steps);
        std::vector<double> times;
    };
}

