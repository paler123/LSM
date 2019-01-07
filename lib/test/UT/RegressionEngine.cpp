#include "RegressionEngine.hpp"
#include "gtest/gtest.h"

namespace {
using namespace lsm::pricing;
using namespace Eigen;

/*
 * this includes only simple sanity checks,
 * more complex cases will be tested in MT
 */
TEST(RegressionEngine, handlesForwardContractsTerminatingAtModelEnd) {

    MatrixXd discounted_payoffs (2, 2);
    discounted_payoffs << 0, 1,
                          0, 1;
    MatrixXd dummy_regressand (2, 1);
    dummy_regressand << 1, 1;
    std::vector<MatrixXd> regressands;
    regressands.push_back(dummy_regressand);
    regressands.push_back(dummy_regressand);

    std::vector<std::size_t> expected_executions {1u, 1u};

    ASSERT_EQ(expected_executions, find_strategy(regressands, discounted_payoffs));
}

TEST(RegressionEngine, handlesForwardContractsTerminatingBeforeModelEnd) {

    MatrixXd discounted_payoffs (2, 4);
    discounted_payoffs << 0, 1, 0, 0,
                          0, 1, 0, 0;
    MatrixXd dummy_regressand (2, 1);
    dummy_regressand << 1, 1;
    std::vector<MatrixXd> regressands;
    for (auto i = 0; i < discounted_payoffs.cols(); ++i) {
        regressands.push_back(dummy_regressand);
    }

    std::vector<std::size_t> expected_executions {1u, 1u};

    ASSERT_EQ(expected_executions, find_strategy(regressands, discounted_payoffs));
}
}
