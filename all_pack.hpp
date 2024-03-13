#pragma once

#include <iostream>
#include <array>
#include <vector>
#include <functional>
#include <chrono>
#include <string>

#include "prototypes.hpp"
#include "enums.hpp"
#include "sort_data.hpp"

using vec = std::vector<int>;
using Sort_fcn = std::function<void(vec &main_vector, int& swaps, int& compares,seconds& time)>;
using seconds = std::chrono::duration<long long>;
using data = std::array<Sort_data, 7>;

typedef std::array<Sort_fcn, 6> arr;