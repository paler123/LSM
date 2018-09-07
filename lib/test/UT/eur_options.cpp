#include "eur_options.hpp"
#include <gtest/gtest.h>
#include <vector>

using namespace options;

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
    auto times =      std::vector<double>{0.0, 0.5, 1.0, 2.0, 3.5};
    auto trajectory = std::vector<double>{1.0, 2.3, 5.7, 4.0, 12.0};

}

}
