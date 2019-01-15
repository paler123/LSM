#pragma once

#include <Eigen/Dense>

namespace lsm::regression_base {

constexpr std::size_t get_point_count(std::size_t degree, std::size_t base_size) {
    return degree ^ base_size; // fixit!
}

template<typename T>
using Matrix = Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>;

template<typename WalkOp, typename FieldType>
Matrix<FieldType> create_walk(std::size_t degree, Matrix<FieldType> const& base) {

}


}

