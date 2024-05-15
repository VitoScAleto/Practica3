#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <random>
#include <Windows.h>
#include <numeric>

using namespace std;


int GetRandomNumber(int min, int max)
{
	random_device rd;//random_device, который является источником недетерминированных случайных чисел.
	//Затем мы используем это устройство для заполнения генератора std::minstd_rand. Затем функция генератора() используется для генерации случайного числа
	minstd_rand generator(rd());

	uniform_int_distribution<int> distribution(min, max);// функция destribition для задания диапозона значений
	int random_number = distribution(generator);
	return random_number;
}



void Zadanie2()//находит самый часто встечающися элемент в массиве и удалает все эти элементы
{
	vector <int> MyVector = { 1,2,3,4,4,4,4,6,7,8,7,7,7,7,7,7,7 };

	cout << "Неотсортированный по частоте массив:  ";

	for (auto i : MyVector)
	{
		cout << i << " ";
	}
	cout << endl;

	map <int, int> frequencyMap;

	for (auto iter : MyVector) // заполняем map, где значения это кол-во вхождения элемента в вектор
	{
		frequencyMap[iter]++;
	}
	
	auto maxFrequency = max_element(frequencyMap.begin(), frequencyMap.end(), [](auto element1, auto element2) { // находим максимальное количество элемента в map
		return element1.second < element2.second;

	});

	MyVector.erase(remove(MyVector.begin(), MyVector.end(), maxFrequency->first), MyVector.end());//удаляем элементы из массива
	
	cout << "Максимальная частота = " << maxFrequency->second <<" числа = "<<maxFrequency->first << endl;
	cout << "Отсортированный массив ";

	for (auto it : MyVector)
	{
		cout << it << " ";
	}
}

void Zadanie1()//слияние двух отсортированных векторов в один с помощью merge
{
	int sizeVectorNotMerge = 0;

	cout << "Введите размер двух первых векторов" << endl;
	cin >> sizeVectorNotMerge;

	vector <int> Vector1(sizeVectorNotMerge);
	vector <int> Vector2(sizeVectorNotMerge);
	vector <int> MergeVector;

	for (auto it1 = begin(Vector1); it1 != end(Vector1); it1++)//  заполнение рандомными числами
	{
		*it1 = GetRandomNumber(0, 100);
		
		cout << *it1 << " ";
	}

	cout << endl;

	for (auto it2 = begin(Vector2); it2 != end(Vector2); it2++)// заполение рандомными числами
	{
		*it2 = GetRandomNumber(0, 100);

		cout << *it2 << " ";
	}
	cout << endl;

	sort(begin(Vector1), end(Vector1));

	sort(begin(Vector2), end(Vector2));

	merge(begin(Vector1),end(Vector1),begin(Vector2),end(Vector2), back_inserter(MergeVector));// слияние
	
	for (auto input : MergeVector)
	{
		cout << input << " ";
	}
	
}

void Zadanie3()
{
	string Predlojenie = "Все БуДет ХоРоШо. СдАм 3 ПраКтиКу";//считаем количество заглавных букв по условию лямбда функции

	cout << Predlojenie << endl;

	int quantityCapitalLetters = count_if(Predlojenie.begin(), Predlojenie.end(), [](char k) {return (k >= 'A' && k <= 'Z')||(k >= 'А' && k <= 'Я'); });// количество если 

	cout <<"Кол-во заглавных букв = " << quantityCapitalLetters << endl;
}

void Zadanie4()//  функция, которая принимает два вектора чисел и возвращает вектор, содержащий элементы, общие для обоих векторов.set_interseption
{
	int sizeVector = 0;

	cout << "Введите размер двух первых векторов" << endl;
	cin >> sizeVector;

	vector <int> Vector1(sizeVector);
	vector <int> Vector2(sizeVector);
	vector <int> v_intersection;

	for (auto it1 = begin(Vector1); it1 != end(Vector1); it1++)//  заполнение рандомными числами
	{
		*it1 = GetRandomNumber(0, 100);

		cout << *it1 << " ";
	}

	cout << endl;

	for (auto it2 = begin(Vector2); it2 != end(Vector2); it2++)// заполение рандомными числами
	{
		*it2 = GetRandomNumber(0, 100);

		cout << *it2 << " ";
	}

	sort(Vector1.begin(), Vector1.end());// сортируем потому что set_interseption предполагает что принимает отсортированные массивы
	sort(Vector2.begin(), Vector2.end());

	set_intersection(Vector1.begin(), Vector1.end(), Vector2.begin(), Vector2.end(), back_inserter(v_intersection));
	
	cout << "\nОбщие элементы для двух векторов:\t";

	for (auto i : v_intersection)
	{
		cout << i << " ";
	}

}
//
//void Zadanie5() //функция, которая принимает вектор целых чисел и целевую сумму, и возвращает вектор всех подмассивов, сумма элементов которых равна целевой.
//{
//	int sum = 0, sizeArr = 0;
//
//	cout << "Введите целевую сумму, по которой будут искаться подмассивы, сумма элементов которых равна целевой сумме" << endl;
//	cin >> sum;
//
//	cout << "Введите размер массива, в котором будут искаться подмассивы" << endl;
//	cin >> sizeArr;
//
//	vector <int> randomNumber(sizeArr);
//
//	for (auto& it : randomNumber)//  заполнение рандомными числами
//	{
//		it = GetRandomNumber(0, 100);
//
//		cout << it << " ";
//	}
//	sort(randomNumber.begin(), randomNumber.end());
//
//	
//
//		
//
//}

void Zadanie6()//Нахождение суммы четных элементов
{
	int sizeVector = 0;

	cout << "Введите размер массива" << endl;
	cin >> sizeVector;

	vector <int> randomNumber(sizeVector);

	for (auto& it : randomNumber)//  заполнение рандомными числами
	{
		it = GetRandomNumber(0, 100);

		cout << it << " ";
	}
	cout << endl;
	
	auto result = accumulate(begin(randomNumber), end(randomNumber), 0, [](int a, int b)
		{
			if (b % 2 == 0)
			{
				return a + b;
			}
			else return a;
		});

	cout << "Сумма четных элементов = " << result << endl;

}


void Zadanie7()//вывод уникальных элементов
{
	/*int sizeVector = 0;

	cout << "Введите размер массива" << endl;
	cin >> sizeVector;*/

	/*vector <int> randomNumber(sizeVector);*/

	//for (auto& it : randomNumber)//  заполнение рандомными числами
	//{
	//	it = GetRandomNumber(0, 100);

	//	cout << it << " ";
	//}
	//cout << endl;
	vector <int> randomNumber = {1,2,3111,111,3,1,1,1,1,4,5,5,5,5,6,6,6,4,3};

	auto iter = unique(randomNumber.begin(), randomNumber.end());

	for_each(begin(randomNumber), iter, [](int a)
		{
			cout << a << " ";

		});

}


int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	cout << "Задание 1\n" << endl;
	Zadanie1();
	cout <<"\n\nЗадание 2\n" << endl;
	Zadanie2();
	cout << "\n\nЗадание 3\n" << endl;
	Zadanie3();
	cout << "\n\nЗадание 4\n" << endl;
	Zadanie4();


	cout << "\n\nЗадание 6\n" << endl;
	Zadanie6();

	cout << "\n\nЗадание 7\n" << endl;
	Zadanie7();
}