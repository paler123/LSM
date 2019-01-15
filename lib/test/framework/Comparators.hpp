#pragma once

#include "OptionEvaluation.hpp"

namespace lsm::testing {

void assert_evaluation_equality(const options::OptionEvaluation& expected,
                                const options::OptionEvaluation& actual,
                                double precision = 1e-6);
}
