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

	std::cout << "����� Enter ����� ����������...";
	std::cin.get();
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

void sorting(arr& main_array, vec& main_vector, data& data_array)
{
	system("cls");

	std::cout
		<< "\t\t\t ����� ����������\n\n"
		<< "1) � ���� ������������ ����������� ����������\n"
		<< "2) � ���� ������������ ��������� ����������\n"
		<< "3) � ���� ������������ ������ ����������\n"
		<< "4) � ���� ������������ ���������� �������\n"
		<< "5) � ���� ������������ ���������� ��������\n"
		<< "6) � ���� ������������ ���������� �����\n"
		<< "7) � ���� ����� � ����!\n\n"
		<< "�����: ";
}


void main_menu(arr& main_array, vec& main_vector, data& data_array)
{
	std::cout << "����� ����� � ������ ������� ����� ����� ������: ";
	int len, width,volume;
	std::cin >> len >> width;
	system("cls");

	volume = len * width;
	main_vector.resize(volume);

	int answer{};
	do
	{
		std::cout
			<< "\t\t\t����\n"
			<< "1) � ���� ������� ����������\n"
			<< "2) � ���� ������� ������� ���������\n"
			<< "3) � ���� �������� ����������\n"
			<< "4) � ���� �����!\n\n"
			<< "�����: ";
		std::cin >> answer;

		switch (answer)
		{
		case(SORT):		sorting(main_array, main_vector,data_array);	 break;
		case(PRINT):	print_matrix(main_vector, len);					 break;
		case(COMPARE):  
		case(EXIT):														 break;
		default: std::cout << "�������� ������!";						 break;
		}

	} while( answer != EXIT);
}