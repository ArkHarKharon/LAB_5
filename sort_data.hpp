#pragma once
#include "all_pack.hpp"

using seconds = std::chrono::duration<long long,std::milli>; 

struct Sort_data
{
	std::string sort_name = "none";
	size_t num = 0;
	long swaps = 0;
	long compares = 0;
	seconds time{0};
};