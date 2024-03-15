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

void sorting(arr& sort_array, vec& main_vector, data& data_array)
{
	int answer{};
	do
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

		std::cin >> answer;

		if (answer > 0 and answer < sort_array.size())
		{
			system("cls");
			std::cout << "Сортирую...";
			Sleep(2000);
			Sort_fcn sort_fcn = sort_array.at(answer);
			sort_fcn(main_vector, data_array.at(answer).swaps, data_array.at(answer).compares, data_array.at(answer).time);

			system("cls");
			std::cout
				<< "Сортировка завершена успешно, данные сохранены!\n\n"
				<< "Нажмите Enter...";
			std::cin.get();
			system("cls");
		}
		else std::cout << "Неверный индекс!";

	} while (answer != 7);
}

void sort_set(arr& main_array,data& data_array)
{
	main_array = { none,bubble_sort,shaker_sort,gnome_sort,insert_sort,shell_sort };

	data_array.at(BUBBLE).sort_name = " Пузырьковая";
	data_array.at(SHAKER).sort_name = " Шейкерная";
	data_array.at(GNOME).sort_name =  " Гномья";
	data_array.at(SELECT).sort_name = " Выбором";
	data_array.at(INSERT).sort_name = " \tВставкой";
	data_array.at(SHELL).sort_name =  " Шелла";
}

void compare(data const& data_array)
{
	system("cls");

	for (int i = 1; i < data_array.size(); i++)
		std::cout << data_array.at(i).sort_name << "\t\t";
	std::cout << "\n";

	for (int i = 1; i < data_array.size(); i++)
		std::cout << data_array.at(i).compares << " ср.\t\t";
	std::cout << "\n";

	for (int i = 1; i < data_array.size(); i++)
		std::cout<< data_array.at(i).swaps << " пер.\t\t";
	std::cout << "\n";

	for (int i = 1; i < data_array.size(); i++)
		std::cout << data_array.at(i).time.count() << "с\t\t\t";

	std::cin.ignore(32000, '\n');
	std::cout << "\n\nНажмите Enter...";
	std::cin.get();
	system("cls");
}

void main_menu(arr& sort_array, vec& main_vector, data& data_array)
{
	std::cout << "Введи длину и ширину матрицы чисел через пробел: ";
	int len, width,volume;
	std::cin >> len >> width;
	system("cls");

	volume = len * width;
	main_vector.resize(volume);

	sort_set(sort_array, data_array);
	random_set(main_vector, 1, 999);

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
		case(SORT):		sorting(sort_array, main_vector,data_array);	 break;
		case(PRINT):	print_matrix(main_vector, len);					 break;
		case(COMPARE):  compare(data_array);							 break;
		case(EXIT):														 break;
		default: std::cout << "Неверный индекс!";						 break;
		}

	} while( answer != EXIT);
}