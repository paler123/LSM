#include "RegressionEngine.hpp"

using namespace Eigen;

namespace {
}

namespace lsm::pricing {

ExecutionStrategy find_strategy(
        std::vector<MatrixXd> const & regressands,
        MatrixXd const & discounted_payoffs) {
    auto result = ExecutionStrategy(discounted_payoffs.rows(),
                                    discounted_payoffs.cols() - 1);
    for (auto i = discounted_payoffs.cols() - 2; i >= 0; --i) {
        VectorXd regression_coefficients = regressands[i].
            bdcSvd(ComputeThinU | ComputeThinV).solve(discounted_payoffs.col(i + 1));
        VectorXd regression_values = regressands[i] * regression_coefficients;
        for (auto j = 0u; j < result.size(); ++j) {
            if (discounted_payoffs(j, i) >= regression_values(j)) {
                result[j] = i;
            }
        }
    }
    return result;
}


FullExecutionStrategy find_full_strategy(
        std::vector<MatrixXd> const & regressands,
        MatrixXd const & discounted_payoffs,
        MatrixXd const & numeraire);

}
