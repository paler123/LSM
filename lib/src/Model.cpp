#include "Model.hpp"

namespace
{
std::vector<double> get_equidistant_times(double expiry, int steps)
{
    std::vector<double> result;
    result.reserve(static_cast<std::size_t>(steps));
    auto s = static_cast<double>(steps);
    for (int i = 0; i < steps; ++i) {
        auto d = static_cast<double>(i);
        result.push_back(d / (s - 1.0) * expiry);
    }
    return result;
}
}


namespace lsm::models
{

SimpleModel::SimpleModel(double expiry, int steps)
: times{get_equidistant_times(expiry, steps)}
{}

}
