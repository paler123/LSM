#include "Model.hpp"
#include <gtest/gtest.h>

namespace
{
using namespace lsm;

TEST(SimpleModel, properly_initializes_times)
{
    auto tested = SimpleModel(5.0, 3);
    auto expected_times = std::vector<double>{0.0, 2.5, 5.0};
    ASSERT_EQ(tested.times, expected_times);
}

}


