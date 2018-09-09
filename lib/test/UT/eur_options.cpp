#include "eur_options.hpp"
#include "Model.hpp"
#include <gtest/gtest.h>
#include <vector>

using namespace lsm::options;
using namespace lsm::models;

namespace
{

TEST(call_option, properly_evaluates_payoff_at_expiry)
{
    auto call_option = EurOption<Types::call>{130.0, 1.0};
    ASSERT_DOUBLE_EQ(call_option.payoffAtExpiry(1.0), 0.0);
    ASSERT_DOUBLE_EQ(call_option.payoffAtExpiry(140.0), 10.0);
}

TEST(put_option, properly_evaluates_payoff_at_expiry)
{
    auto put_option = EurOption<Types::put>{120.0, 1.0};
    ASSERT_DOUBLE_EQ(put_option.payoffAtExpiry(10.0), 110.0);
    ASSERT_DOUBLE_EQ(put_option.payoffAtExpiry(130.0), 0.0);
}

TEST(eur_options, properly_evaluates_payoff_on_trajectories)
{
    auto call_option = EurOption<Types::call>{10.0, 3.5};
    auto times = std::vector<double>{0.0, 0.5, 1.0, 2.0, 3.5};
    auto assets = Eigen::MatrixXd(1, 5);
    assets << 5.0, 6.0, 7.0, 8.0, 11.0;  
    auto model = RawModel{std::move(times), std::vector{std::move(assets)}};
    auto expected_payoffs = Eigen::MatrixXd(1, 5);
    expected_payoffs << 0.0, 0.0, 0.0, 0.0, 1.0;
    auto expected_eval = OptionEvaluation{std::move(expected_payoffs), {}};
    auto option_evaluation = call_option.eval(model);
    ASSERT_EQ(option_evaluation, expected_eval);    
}

}
