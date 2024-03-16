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
		<< "\t\t\t    ---------------�������---------------\n\n\t";

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
	std::cout << "\n\n\t\t\t    ---------------�������---------------\n\n\n\n";

	std::cin.ignore(32000, '\n');
	std::cout << "����� Enter ����� ����������...";
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
	data_array.at(BUBBLE).sort_name = "����������� ����������";
	data_array.at(SHAKER).sort_name = "��������� ����������";
	data_array.at(GNOME).sort_name = "������ ����������";
	data_array.at(SELECT).sort_name = "���������� �������";
	data_array.at(INSERT).sort_name = "���������� ��������";
	data_array.at(SHELL).sort_name = "���������� �����";

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
			<< "\t\t\t ----------------����� ����������----------------\n\n"
			<< "1) � ���� ������������ ����������� ����������\n"
			<< "2) � ���� ������������ ��������� ����������\n"
			<< "3) � ���� ������������ ������ ����������\n"
			<< "4) � ���� ������������ ���������� �������\n"
			<< "5) � ���� ������������ ���������� ��������\n"
			<< "6) � ���� ������������ ���������� �����\n"
			<< "7) � ���� ����� � ����!\n\n"
			<< "�����: ";

		std::cin >> answer;

		if (answer > 0 and answer < sort_array.size())
		{
			system("cls");
			std::cout << "��������...";
			Sleep(2000);

			Sort_fcn sort_fcn = sort_array.at(answer);
			sort_fcn(main_vector, data_array.at(answer).swaps, data_array.at(answer).compares, data_array.at(answer).time);
			data_array.at(answer).num = main_vector.size();

			system("cls");
			std::cin.ignore(32000, '\n');
			std::cout
				<< "���������� ��������� �������, ������ ���������!\n\n"
				<< "������� Enter...";
			std::cin.get();
		}
		else if (answer == sort_array.size())
			break;
		else std::cout << "�������� ������!";
	} while (answer != 7);
	system("cls");
}

void sort_set(arr& main_array,data& data_array)
{
	main_array = { none,bubble_sort,shaker_sort,gnome_sort,insert_sort,shell_sort };

	data_array.at(BUBBLE).sort_name = " �����������";
	data_array.at(SHAKER).sort_name = " ���������";
	data_array.at(GNOME).sort_name =  " ������";
	data_array.at(SELECT).sort_name = " �������";
	data_array.at(INSERT).sort_name = " ��������";
	data_array.at(SHELL).sort_name =  " �����";
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
			<< "���-�� ���������: " << element.num << '\n'
			<< "���-�� ���������: " << element.compares << '\n'
			<< "���-�� ������������: " << element.compares << '\n'
			<< "����� ����������: " << element.time.count() << "�c\n\n";

	}
	std::cin.ignore(32000, 'n');
	std::cout << "������� Enter...";
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
			<< "\t\t\t    ----------------���������----------------\n"
			<< "1) � ���� �������� ����\n"
			<< "2) � ���� �������� ���� ����\n"
			<< "3) � ���� ������������� ����� �������� ��������� �������\n"
			<< "4) � ���� �������� ������ ������� (�� ���� ����� � ����)\n"
			<< "5) � ���� ��������� � �������� ����\n\n"
			<< "�����: ";

		std::cin >> answer_settings;

		switch (answer_settings)
		{
		case(LANGUAGE):
			system("cls");
			std::cout << "����� ����...";
			Sleep(4000);
			std::cout << "�������, ���� ����, � �� ����� �����)))))";
			Sleep(3000);
			system("cls");
			break;

		case(GENERATE):
			system("cls");
			std::cout << "��������� ����� �������";
			Sleep(4000);
			random_set(main_vector, 1, 999);
			std::cout << "������!";
			Sleep(3000);
			system("cls");
			break;

		case(RESIZE):
			system("cls");
			std::cout
				<< "\t\t\t    ----------------��������� �������----------------\n"
				<< "�������� ������� ����� ������������!\n"
				<< "����� ����� ����� � ������ ������� ����� ������: ";
			std::cin >> new_len >> new_width;

			temp_len = new_len;
			temp_width = new_width;
			new_volume = new_len * new_width;

			main_vector.resize(new_volume);
			random_set(main_vector, 1, 999);

			system("cls");
			std::cout << "����� ������ �������...";
			Sleep(4000);
			std::cout << "������!";
			system("cls");
			break;

		case(MAIN_MENU): break;
		}
	} while (answer_settings != MAIN_MENU);
}

void main_menu(arr& sort_array, vec& main_vector, data& data_array)
{
	std::cout << "����� ����� � ������ ������� ����� ����� ������: ";
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
			<< "\t\t\t----------------����----------------\n"
			<< "1) � ���� ������� ����������\n"
			<< "2) � ���� ������� ������� ���������\n"
			<< "3) � ���� �������� ����������\n"
			<< "4) � ���� ������� ���������\n"
			<< "4) � ���� �����!\n\n"
			<< "�����: ";
		std::cin >> answer;

		switch (answer)
		{
		case(SORT):		sorting(sort_array, main_vector,data_array);	 break;
		case(PRINT):	print_matrix(main_vector, len);					 break;
		case(COMPARE):  compare(data_array);							 break;
		case(SETTINGS): settings(main_vector, len, width);				 break;
		case(EXIT):														 break;
		default: std::cout << "�������� ������!";						 break;
		}

	} while( answer != EXIT);
}