#pragma once
#include <vector>
#include <Eigen/Dense>

namespace lsm::pricing {

using ExecutionStrategy = std::vector<std::size_t>;

struct FullExecutionStrategy {
    ExecutionStrategy executions;
    std::vector<Eigen::VectorXd> regression_coefficients;
};

ExecutionStrategy find_strategy(
        std::vector<Eigen::MatrixXd> const & regressands,
        Eigen::MatrixXd const & discounted_payoffs);

FullExecutionStrategy find_full_strategy(
        std::vector<Eigen::MatrixXd> const & regressands,
        Eigen::MatrixXd const & discounted_payoffs);

}
