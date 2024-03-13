#include "all_pack.hpp"

int random(int min, int max)
{
	int number = min + rand() % (max - min + 1);
	return number;
}

void print_matrix(vec& main_vector, int len)
{
	system("cls");
	std::cout
		<< "\t\t\t    ---------------МАТРИЦА---------------\n\n\t";

	int counter{ 0 };
	for (auto element : main_vector)
	{
		if (counter == len)
		{
			std::cout << "\n\n\t";
			counter = 0;
		}

		if (element > 99)
			std::cout << element << "\t";
		else if (element > 9 and element < 100)
			std::cout << element << " \t";
		else if (element < 10)
			std::cout << " " << element << " \t";
		counter++;
	}
	std::cout << "\n\n\t\t\t    ---------------МАТРИЦА---------------\n\n\n\n";

	std::cout << "Нажми Enter чтобы продолжить...";
	std::cin.get();
}

void random_set(vec& main_vector, int min, int max)
{
	for (int index{ 0 }; index < main_vector.size(); index++)
		main_vector.at(index) = random(min, max);
}

void data_reset(data& data_array)
{
	data_array.at(BUBBLE).sort_name = "Пузырьковая сортировка";
	data_array.at(SHAKER).sort_name = "Шейкерная сортировка";
	data_array.at(GNOME).sort_name = "Гномья сортировка";
	data_array.at(SELECT).sort_name = "Сортировка выбором";
	data_array.at(INSERT).sort_name = "Сортировка вставкой";
	data_array.at(SHELL).sort_name = "Сортировка Шелла";

	for (int i = BUBBLE; i < SHELL + 1; i++)
	{
		data_array.at(i).compares = 0;
		data_array.at(i).swaps = 0;
		data_array.at(i).time.zero;
	}
}

void sorting(arr& main_array, vec& main_vector, data& data_array)
{
	system("cls");

	std::cout
		<< "\t\t\t ВЫБОР СОРТИРОВКИ\n\n"
		<< "1) Я хочу использовать пузырьковую сортировку\n"
		<< "2) Я хочу использовать шейкерную сортировку\n"
		<< "3) Я хочу использовать гномью сортировку\n"
		<< "4) Я хочу использовать сортировку выбором\n"
		<< "5) Я хочу использовать сортировку вставкой\n"
		<< "6) Я хочу использовать сортировку Шелла\n"
		<< "7) Я хочу выйти в меню!\n\n"
		<< "Выбор: ";
}


void main_menu(arr& main_array, vec& main_vector, data& data_array)
{
	std::cout << "Введи длину и ширину матрицы чисел через пробел: ";
	int len, width,volume;
	std::cin >> len >> width;
	system("cls");

	volume = len * width;
	main_vector.resize(volume);

	int answer{};
	do
	{
		std::cout
			<< "\t\t\tМЕНЮ\n"
			<< "1) Я хочу выбрать сортировку\n"
			<< "2) Я хочу вывести матрицу элементов\n"
			<< "3) Я хочу сравнить сортировки\n"
			<< "4) Я хочу выйти!\n\n"
			<< "Выбор: ";
		std::cin >> answer;

		switch (answer)
		{
		case(SORT):		sorting(main_array, main_vector,data_array);	 break;
		case(PRINT):	print_matrix(main_vector, len);					 break;
		case(COMPARE):  
		case(EXIT):														 break;
		default: std::cout << "Неверный индекс!";						 break;
		}

	} while( answer != EXIT);
}