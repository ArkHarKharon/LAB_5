#pragma once

#include <array>
#include <vector>

#include "sort_data.hpp"

using vec = std::vector<int>;
using Sort_fcn = std::function<void(vec& main_vector, long& swaps, long& compares,seconds& time)>;
using seconds = std::chrono::duration<long long,std::milli>;
using data = std::array<Sort_data, 7>;

typedef std::array<Sort_fcn, 7> arr;


void bubble_sort(vec& main_vector, long& swap, long& compare, seconds& time);
void shaker_sort(vec& main_vector, long& swap, long& compare, seconds& time);
void gnome_sort(vec& main_vector, long& swap, long& compare, seconds& time);
void select_sort(vec& main_vector, long& swap, long& compare, seconds& time);
void insert_sort(vec& main_vector, long& swap, long& compare, seconds& time);
void shell_sort(vec& main_vector, long& swap, long& compare, seconds& time);
void none(vec& main_vector, long& swap, long& compare, seconds& time);


int random(int min, int max);
void print_matrix(vec& main_vector, int len);
void random_set(vec& main_vector, int min, int max);
void data_reset(data& data_array);
void sort_set(arr& main_array, data& data_array);
void sorting(arr& sort_array, vec& main_vector, data& data_array);
void compare(data const& data_array);
void settings(vec& main_vector, int len, int width);

void main_menu(arr& sort_array, vec& main_vector, data& data_array);

