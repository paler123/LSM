#pragma once
#include <vector>
#include <Eigen/Dense>

namespace lsm::pricing {

using ExecutionStrategy = std::vector<std::size_t>;

struct FullExecutionStrategy {
    ExecutionStrategy executions;
    std::vector<Eigen::VectorXd> regression_coefficients;
};

/*
 * Core LSM functions.
 * In:
 *  - regressands : vector of length equal to time steps in model, each regressand is a
 *                  matrix of explanatory variables (one var/ col) calculated for each trajectory
 *  - option_value : matrix of size number_of_trajectories x time_steps, containing payoffs
 *                   discounted to model start point
 * Out:
 *  Stopping time for given model (so model step at which option should be executed on each traj)
 *  option_value : the discounted payoffs are ultimately replaced by correct (discounted) option
 *                values at given time / trajectory
 */
ExecutionStrategy find_strategy(
        std::vector<Eigen::MatrixXd> const & regressands,
        Eigen::MatrixXd & option_value);

/*
 *  Same as find_strategy, but outputs also regression coefficients for each time step
 *  The coefficients can e.g. be used to price same option in different model / simulation
 */
FullExecutionStrategy find_full_strategy(
        std::vector<Eigen::MatrixXd> const & regressands,
        Eigen::MatrixXd & option_value);

}
