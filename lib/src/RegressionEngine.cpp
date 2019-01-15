#include "RegressionEngine.hpp"

using namespace Eigen;

namespace lsm::pricing {

namespace {
struct DiscardCoefficients {
    VectorXd coefficients;
    void add(VectorXd&& cur_coefficients) {
        coefficients = std::move(cur_coefficients);
    }
    VectorXd& current() { return coefficients; }
};

struct StoreCoefficients {
    StoreCoefficients(std::vector<VectorXd>& sink) : storage{sink} {}
    void add(VectorXd&& cur_coefficients) {
        storage.emplace_back(std::move(cur_coefficients));
    }
    VectorXd& current() { return storage.back(); }

    private:
    std::vector<VectorXd> storage;
};

/*
 * Core LSM implementation used by each public find_strategy function.
 * Templated on coefficients storage policy for convenience.
 */
template <typename CoefficientsStoragePolicy>
ExecutionStrategy find_strategy(
    std::vector<MatrixXd> const& regressands,
    MatrixXd& option_value,
    CoefficientsStoragePolicy& coefficients_storage) {
    auto result =
        ExecutionStrategy(option_value.rows(), option_value.cols() - 1);
    for(auto i = option_value.cols() - 2; i >= 0; --i) {
        // regress values at i+1 to regressands at i. Values at T are equal to
        // payoff
        coefficients_storage.add(regressands[i]
                                     .bdcSvd(ComputeThinU | ComputeThinV)
                                     .solve(option_value.col(i + 1)));
        // get current option values estimated based on regression
        VectorXd regression_values =
            regressands[i] * coefficients_storage.current();
        for(auto j = 0u; j < result.size(); ++j)
            // this forces asap execution
            if(option_value(j, i) >= regression_values(j))
                result[j] = i;
            else
                option_value(j, i) = regression_values(j);
    }
    return result;
}
} // namespace

ExecutionStrategy find_strategy(std::vector<MatrixXd> const& regressands,
                                MatrixXd& option_value) {
    auto coefficients_policy = DiscardCoefficients{};
    return find_strategy(regressands, option_value, coefficients_policy);
}

FullExecutionStrategy find_full_strategy(
    std::vector<MatrixXd> const& regressands, MatrixXd& option_value) {
    auto result = FullExecutionStrategy{};
    result.regression_coefficients.reserve(option_value.cols() - 1);
    auto coefficients_policy =
        StoreCoefficients{result.regression_coefficients};
    result.executions =
        find_strategy(regressands, option_value, coefficients_policy);
    return result;
}
} // namespace lsm::pricing
