#pragma once

#include "Model.hpp"
#include "OptionEvaluation.hpp"
#include "option_types.hpp"

namespace lsm::options {

template <Types type>
struct EurOption {
    OptionEvaluation eval(const models::RawModel&) { return {}; }
    double payoffAtExpiry(double assetPrice) {
        if constexpr(type == Types::call)
            return strike < assetPrice ? assetPrice - strike : 0.0;
        else
            return strike > assetPrice ? strike - assetPrice : 0.0;
    }
    double strike;
    double expiry;
};
} // namespace lsm::options
