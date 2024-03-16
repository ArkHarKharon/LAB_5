#include "all_pack.hpp"

void bubble_sort(vec& main_vector, long& swap, long& compare, seconds& time)
{
	auto start = std::chrono::steady_clock::now();
	for (size_t i = 0; i < main_vector.size(); i++)
	{
		for (size_t j = 0; j < main_vector.size() - 1; j++)
		{
			if (main_vector.at(j) > main_vector.at(j + 1))
			{
				int temp = main_vector.at(j);
				main_vector.at(j) = main_vector.at(j + 1);
				main_vector.at(j + 1) = temp;
				swap++;
			}
			compare++;
		}
	}
	auto end = std::chrono::steady_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

void shaker_sort(vec& main_vector, long& swap, long& compare, seconds& time)
{
	auto start = std::chrono::steady_clock::now();

	std::size_t i, j, k;
	std::size_t n = main_vector.size();

	for (i = 0; i < n;)
	{
		for (j = i + 1; j < n; j++)
		{
			if (main_vector.at(j) < main_vector.at(j - 1))
			{
				std::swap(main_vector[j], main_vector[j - 1]);
				swap++;
			}
			compare++;
		}
		n--;

		for (k = n - 1; k > i; k--)
		{
			if (main_vector.at(k) < main_vector.at(k - 1))
			{
				std::swap(main_vector.at(k), main_vector.at(k - 1));
				swap++;
			}
			compare++;
		}
		i++;
	}
	auto end = std::chrono::steady_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

void gnome_sort(vec& main_vector, long& swap, long& compare, seconds& time)
{
	auto start = std::chrono::steady_clock::now();

	std::size_t index = 0;
	while (index < main_vector.size())
	{
		if (index == 0)
		{
			index++;
			compare++;
		}
		if (main_vector.at(index) >= main_vector.at(index - 1))
		{
			index++;
			compare++;
		}
		else
		{
			std::swap(main_vector.at(index), main_vector.at(index - 1));
			index--;
			swap++;
		}
	}
	auto end = std::chrono::steady_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

void select_sort(vec& main_vector, long& swap, long& compare, seconds& time)
{
	auto start = std::chrono::steady_clock::now();

	std::size_t i, j, min_index;

	for (i = 0; i < main_vector.size() - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < main_vector.size(); j++) {
			if (main_vector.at(j) < main_vector.at(min_index))
			{
				min_index = j;
				compare++;
			}
		}

		if (min_index != i)
		{
			std::swap(main_vector.at(min_index), main_vector.at(i));
			swap++;
		}
	}
	auto end = std::chrono::steady_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

void insert_sort(vec& main_vector, long& swap, long& compare, seconds& time)
{
	auto start = std::chrono::steady_clock::now();

	for (size_t i = 1; i < main_vector.size(); i++)
	{
		int key = main_vector.at(i);
		size_t j = i - 1;
		while (j >= 0 and main_vector.at(j) > key)
		{
			main_vector.at(j + 1) = main_vector.at(j);
			j--;
			swap++;
			compare++;
		}
		main_vector.at(j + 1) = key;
	}
	auto end = std::chrono::steady_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

void shell_sort(vec& main_vector, long& swap, long& compare, seconds& time)
{
	auto start = std::chrono::steady_clock::now();

	for (std::size_t interval = main_vector.size() / 2; interval > 0; interval /= 2)
	{
		for (std::size_t i = interval; i < main_vector.size(); i += 1)
		{
			std::size_t j;
			int temp = main_vector.at(i);
			for (j = i; j >= interval and main_vector.at(j - interval) > temp; j -= interval)
			{
				main_vector.at(j) = main_vector.at(j - interval);
				compare++;
				swap++;
			}
			main_vector.at(j) = temp;
		}
	}
	auto end = std::chrono::steady_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

void none(vec& main_vector, long& swap, long& compare, seconds& time)
{

}
