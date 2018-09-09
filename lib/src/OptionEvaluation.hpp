#pragma once

#include <Eigen/Dense>
#include <optional>

namespace lsm::options
{
struct OptionEvaluation
{
    Eigen::MatrixXd values;
    std::optional<std::vector<Eigen::MatrixXd>> model_enhancements;  
}; 
}
