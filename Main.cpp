#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <forward_list>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG



void print(int);
void generate_data();
void print_test_data();

const int SIZE = 10;
int* m_array;
std::vector<int> m_vector;
std::forward_list<int> m_flist;

template<class FowardIterator>
void FowardSort(FowardIterator begin, FowardIterator end)
{
	for (FowardIterator it1 = begin; it1 != end ; it1++)
	{
		for (FowardIterator it2 = begin; it2 != end; it2++)
		{
			if (*it1 < *it2)
			{
				auto temp = *it2;
				*it2 = *it1;
				*it1 = temp;
			}
		}
	}
}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Initalize random
	srand((unsigned)time(NULL));
	generate_data();

	print_test_data();

	//Uppgift 1
	std::cout << "Uppgift 1" << std::endl;
	std::sort(m_vector.begin(), m_vector.end());
	std::sort(m_array, m_array + SIZE);
	std::cout << "Sorted in order" << std::endl;
	print_test_data();

	
	std::sort(m_vector.rbegin(), m_vector.rend());
	std::sort(m_array, m_array + SIZE, [](int first, int last) { return last < first; });

	std::cout << "Sorted in reverse order" << std::endl;
	print_test_data();

	//Uppgift 2
	std::cout << "Uppgift 2" << std::endl;
	m_vector.erase(std::remove_if(m_vector.begin(), m_vector.end(), [](int i) {return i % 2 == 0; }), m_vector.end());
	print_test_data();

	//Uppgift 3
	std::cout << "Uppgift 3" << std::endl;
	FowardSort(m_flist.begin(), m_flist.end());
	print_test_data();

	int temp;
	std::cin >> temp;

	delete[] m_array;
	return 0;
}

void print_test_data()
{
	std::cout << "Vector values: ";
	std::for_each(m_vector.begin(), m_vector.end(), print);
	std::cout << std::endl;
	std::cout << "Array values: ";
	std::for_each(m_array, m_array + SIZE, print);
	std::cout << std::endl;
	std::cout << "Forward list: ";
	std::for_each(m_flist.begin(), m_flist.end(), print);
	std::cout << std::endl;

}

void print(int value)
{
	std::cout << value << " ";
}

//Creates a container and print it
void generate_data()
{
	m_array = new int[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		m_vector.push_back(rand());
		m_array[i] = rand();
		m_flist.push_front(rand());
	}
}