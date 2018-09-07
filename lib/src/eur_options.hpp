#pragma once

#include "option_types.hpp"

namespace options
{

template <Types type>
struct EurOption
{
    double payoffAtExpiry(double assetPrice)
    {
        if constexpr (type == Types::call)
            return strike < assetPrice ? assetPrice - strike : 0.0;
        return strike > assetPrice ? strike - assetPrice : 0.0;
    }
    double strike;
    double expiry;
};

}

