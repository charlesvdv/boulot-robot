#pragma once

#include <type_traits>
#include <cmath>

namespace pathplanning::math {

    // Check whether two floating points numbers are almost equals
    // Taken from https://en.cppreference.com/w/cpp/types/numeric_limits/epsilon
    template<class T>
    auto
        almost_equal(T x, T y, int ulp = 5) -> typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
    {
        // the machine epsilon has to be scaled to the magnitude of the values used
        // and multiplied by the desired precision in ULPs (units in the last place)
        return std::fabs(x-y) <= std::numeric_limits<T>::epsilon() * std::fabs(x+y) * ulp
            // unless the result is subnormal
            || std::fabs(x-y) < std::numeric_limits<T>::min();
    }

}