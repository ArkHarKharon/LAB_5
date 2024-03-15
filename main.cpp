#include "all_pack.hpp"

int main()
{
	setlocale(0, "");
	arr sort_array{};  //массив указателей на ф-ции
	vec main_vector{}; //вектор с данными для сортировки
	data data_array{}; //массив данных о сортировках

	main_menu(sort_array, main_vector, data_array);
}