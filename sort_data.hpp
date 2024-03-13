#pragma once
#include "all_pack.hpp"

using seconds = std::chrono::duration<long long>; 

struct Sort_data
{
	std::string sort_name;
	long swaps;
	long compares;
	seconds time;
};