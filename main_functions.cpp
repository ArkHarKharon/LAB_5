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

	std::cin.ignore(32000, '\n');
	std::cout << "Нажми Enter чтобы продолжить...";
	std::cin.get();
	system("cls");
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
			<< "\t\t\t ----------------ВЫБОР СОРТИРОВКИ----------------\n\n"
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
			data_array.at(answer).num = main_vector.size();

			system("cls");
			std::cin.ignore(32000, '\n');
			std::cout
				<< "Сортировка завершена успешно, данные сохранены!\n\n"
				<< "Нажмите Enter...";
			std::cin.get();
		}
		else if (answer == sort_array.size())
			break;
		else std::cout << "Неверный индекс!";
	} while (answer != 7);
	system("cls");
}

void sort_set(arr& main_array,data& data_array)
{
	main_array = { none,bubble_sort,shaker_sort,gnome_sort,insert_sort,shell_sort };

	data_array.at(BUBBLE).sort_name = " Пузырьковая";
	data_array.at(SHAKER).sort_name = " Шейкерная";
	data_array.at(GNOME).sort_name =  " Гномья";
	data_array.at(SELECT).sort_name = " Выбором";
	data_array.at(INSERT).sort_name = " Вставкой";
	data_array.at(SHELL).sort_name =  " Шелла";
}

void compare(data const& data_array)
{
	system("cls");

	for (const Sort_data element : data_array)
	{
		if (element.sort_name == "none")
			continue;

		std::cout
			<< "\t\t" << element.sort_name << '\n'
			<< "Кол-во элементов: " << element.num << '\n'
			<< "Кол-во сравнений: " << element.compares << '\n'
			<< "Кол-во перестановок: " << element.compares << '\n'
			<< "Время сортировки: " << element.time.count() << "мc\n\n";

	}
	std::cin.ignore(32000, 'n');
	std::cout << "Нажмите Enter...";
	std::cin.get();
}

void settings(vec& main_vector, int len, int width)
{
	int answer_settings{ 0 };
	int answer_color{ 0 };
	int answer_searching{ 0 };

	int volume{ len * width };
	int new_len{}; int new_width{};
	int& temp_len{ len };
	int& temp_width{ width };
	int& new_volume{ volume };

	do
	{
		std::cout
			<< "\t\t\t    ----------------НАСТРОЙКИ----------------\n"
			<< "1) Я хочу поменять язык\n"
			<< "2) Я хочу поменять цвет меню\n"
			<< "3) Я хочу сгенерировать новые значения элементов матрицы\n"
			<< "4) Я хочу изменить размер матрицы (на свой страх и риск)\n"
			<< "5) Я хочу вернуться в основное меню\n\n"
			<< "Выбор: ";

		std::cin >> answer_settings;

		switch (answer_settings)
		{
		case(LANGUAGE):
			system("cls");
			std::cout << "Меняю язык...";
			Sleep(4000);
			std::cout << "АХАХАХА, хрен тебе, а не смена языка)))))";
			Sleep(3000);
			system("cls");
			break;

		case(GENERATE):
			system("cls");
			std::cout << "Генерирую новую матрицу";
			Sleep(4000);
			random_set(main_vector, 1, 999);
			std::cout << "Готово!";
			Sleep(3000);
			system("cls");
			break;

		case(RESIZE):
			system("cls");
			std::cout
				<< "\t\t\t    ----------------ИЗМЕНЕНИЕ МАТРИЦЫ----------------\n"
				<< "Значения матрицы будут перезаписаны!\n"
				<< "Введи новые длину и ширину матрицы через пробел: ";
			std::cin >> new_len >> new_width;

			temp_len = new_len;
			temp_width = new_width;
			new_volume = new_len * new_width;

			main_vector.resize(new_volume);
			random_set(main_vector, 1, 999);

			system("cls");
			std::cout << "Меняю размер матрицы...";
			Sleep(4000);
			std::cout << "Готово!";
			system("cls");
			break;

		case(MAIN_MENU): break;
		}
	} while (answer_settings != MAIN_MENU);
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
			<< "\t\t\t----------------МЕНЮ----------------\n"
			<< "1) Я хочу выбрать сортировку\n"
			<< "2) Я хочу вывести матрицу элементов\n"
			<< "3) Я хочу сравнить сортировки\n"
			<< "4) Я хочу открыть настройки\n"
			<< "4) Я хочу выйти!\n\n"
			<< "Выбор: ";
		std::cin >> answer;

		switch (answer)
		{
		case(SORT):		sorting(sort_array, main_vector,data_array);	 break;
		case(PRINT):	print_matrix(main_vector, len);					 break;
		case(COMPARE):  compare(data_array);							 break;
		case(SETTINGS): settings(main_vector, len, width);				 break;
		case(EXIT):														 break;
		default: std::cout << "Неверный индекс!";						 break;
		}

	} while( answer != EXIT);
}