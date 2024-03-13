#pragma once

#include <array>
#include <vector>

#include "sort_data.hpp"

using vec = std::vector<int>;
using Sort_fcn = std::function<void(vec& main_vector, int& swaps, int& compares,seconds& time)>;
typedef std::array<Sort_fcn, 6> arr;
using seconds = std::chrono::duration<long long>;
using data = std::array<Sort_data, 7>;


void bubble_sort(vec& main_vector, long& swap, long& compare, seconds& time);
void shaker_sort(vec& main_vector, long& swap, long& compare, seconds& time);
void gnome_sort(vec& main_vector, long& swap, long& compare, seconds& time);
void select_sort(vec& main_vector, long& swap, long& compare, seconds& time);
void insert_sort(vec& main_vector, long& swap, long& compare, seconds& time);
void shell_sort(vec& main_vector, long& swap, long& compare, seconds& time);

int random(int min, int max);
void print_matrix(vec& main_vector, int len);
void random_set(vec& main_vector, int min, int max);
void data_reset(data& data_array);
void sorting(arr& main_array, vec& main_vector, data& data_array);


void main_menu(arr& main_array, vec& main_vector, data& data_array);

