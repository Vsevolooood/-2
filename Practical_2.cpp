#include <iostream>
#include <chrono>
#include <time.h>
//#include <stdo.h>
using namespace std;
// быстрая сортировка
void qs(int qsarr[], int left, int right)
{
	int l = left;
	int r = right;
	int mid = qsarr[(l + r) / 2];
	int center = mid;
	while (l < r)
	{
		while (qsarr[l] < center)
		{
			l++;
		}
		while (qsarr[r] > center)
		{
			r--;
		}
		if (l <= r)
		{
			swap(qsarr[l], qsarr[r]);
			l++;
			r--;
		}
	}
	if (l < right)
	{
		qs(qsarr, l, right);
	}
	if (r > left)
	{
		qs(qsarr, left, r);
	}
}
// алгоритм бинарного поиска

int binarySearch(int arr[], int value, int start, int end)
{
	if (end >= start)
	{

		int mid = start + (end - start) / 2;

		if (arr[mid] == value)
		{
			return mid;

		}
		if (arr[mid] > value)
		{
			return binarySearch(arr, value, start, mid - 1);
		}
		if (arr[mid] < value)
		{
			return binarySearch(arr, value, mid + 1, end);
		}
	}
	return -1;
}
//максимальный и минимальный элемент массива
void minMaxSort(int sortArr[], int size)
{
	auto minMaxTimeStart = chrono::high_resolution_clock::now();
	int min = sortArr[0];
	int max = sortArr[size - 1];
	auto minMaxTimeEnd = chrono::high_resolution_clock::now();
	cout << "\nМаксимальный и манимальный элемент в отсортированном массиве\n" << "Минимальное значение:" << min << "\nМаксимальное значение:" << max;
	auto duration = chrono::duration_cast<chrono::microseconds>(minMaxTimeEnd - minMaxTimeStart);
	cout << endl << "время поиска этих элементов в отсортированном массиве " << duration.count() << " микросек\n";
	int sortAverage = (min + max) / 2;
	cout << endl << "Среднее значение в отсортированном массиые: " << sortAverage << endl;

	auto sortAverageTimeStart = chrono::high_resolution_clock::now();
	int value = sortAverage;
	int k;
	k = 0;
	for (int i = 0; i < size; i++)
	{
		if (sortArr[i] == sortAverage)
		{
			cout << "Элемент находится в позиции " << i << endl;
			k++;

		}
	}
	if (k == 0)
		cout << "такого элемента нет в массиве";
	auto sortAverageTimeEnd = chrono::high_resolution_clock::now();
	auto duration1 = chrono::duration_cast<chrono::microseconds>(sortAverageTimeEnd - sortAverageTimeStart);
	cout << endl << "время поиска этих элементов в отсортированном массиве " << duration1.count() << " микросек\n";
	//почему 0 мс?
}
void minMaxNonSort(int nonSortArr[], int size)
{
	auto minMaxTimeStart = chrono::high_resolution_clock::now();
	int min = nonSortArr[0];
	int max = nonSortArr[0];
	for (int i = 0; i < size; i++)
	{
		if (nonSortArr[i] < min)
		{
			min = nonSortArr[i];
		}

		if (nonSortArr[i] > max)
		{
			max = nonSortArr[i];
		}
	}
	auto minMaxTimeEnd = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(minMaxTimeEnd - minMaxTimeStart);
	cout << "\n\nМаксимальный и манимальный элемент в не отсортированном массиве\n" << "Минимальное значение:" << min << "\nМаксимальное значение:" << max;
	cout << endl << "время поиска этих элементов в отсортированном массиве " << duration.count() << " микросек\n";
	int nonSortAverage = (min + max) / 2;
	cout << endl << "Среднее значение в не отсортированном массиве: " << nonSortAverage << endl;
	auto AverageTimeStart = chrono::high_resolution_clock::now();
	int k;
	k = 0;
	for (int i = 0; i < size; i++)
	{
		if (nonSortArr[i] == nonSortAverage)
		{
			cout << "Элемент находится в позиции " << i << endl;
			k++;
		}
	}
	if (k == 0)
		cout << "такого элемента нет в массиве";
	auto AverageTimeEnd = chrono::high_resolution_clock::now();
	auto duration1 = chrono::duration_cast<chrono::microseconds>(AverageTimeEnd - AverageTimeStart);
	cout << endl << "время поиска этих элементов в отсортированном массиве " << duration1.count() << " микросек\n";

}

void lessThanA(int aArr[], int size)
{
	cout << endl << "Пожалуйста введите число: ";
	int count = 0;
	int a;
	cin >> a;
	cout << endl;
	for (int m = 0; m < size; m++)
	{
		if (aArr[m] < a) {
			count++;
		}
	}
	cout << "Количество элементов меньше введённого: " << a << ": " << count << endl;
	system("pause");
	system("cls");
}
void moreThanB(int bArr[], int size)
{
	cout << "Пожалуйста введите число:";
	int count = 0;
	int b, i;
	cin >> b;
	cout << endl;
	for (int m = 0; m < size; m++)
	{
		if (bArr[m] > b) {
			count++;
		}
	}
	cout << "Количество элементов больше введённого: " << b << ": " << count << endl;
	system("pause");
	system("cls");
}
void arr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 200 - 100;
	}
}
//
void taskSeven(int arrSeven[], int size)
{
	cout << "Бинарный поиск элемента\n ";
	auto timeStart = chrono::high_resolution_clock::now();
	int userNum;
	cout << "\nВведите число: ";
	cin >> userNum;
	int resultSearch = binarySearch(arrSeven, userNum, 0, size - 1);
	if (resultSearch == -1)
	{
		cout << "Элемент не найден" << endl;
	}
	else
	{
		int g;
		for (g = resultSearch; arrSeven[g] > arrSeven[resultSearch] - 1; g--)
		{

		}
		for (int i = g; arrSeven[i] < arrSeven[resultSearch] + 1; i++)
		{

			if (arrSeven[i] == userNum)
			{
				cout << "Элемент находится в позиции: " << i << endl;
			}
		}
	}
	auto timeEnd = chrono::high_resolution_clock::now();
	cout << endl << "Время, затраченное на поиск: " << (chrono::duration_cast<chrono::microseconds> (timeEnd - timeStart).count()) << " микросек\n";
}
//
void taskSeven2(int arr[], int size)
{
	auto timeStart = chrono::high_resolution_clock::now();
	cout << "\nПоиск элемента перебором\n ";
	int userNum;
	cout << "\nВведите число: ";
	cin >> userNum;
	int k;
	k = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == userNum)
		{
			cout << "Элемент находится в позиции " << i << endl;
			k++;

		}
	}
	if (k == 0)
		cout << "такого элемента нет в массиве";

	auto timeEnd = chrono::high_resolution_clock::now();
	cout << endl << "Время, затраченное на поиск перебором: " << (chrono::duration_cast<chrono::microseconds> (timeEnd - timeStart).count()) << " микросек\n";
	system("pause");
	system("cls");
}
void conclusionNonSortArr(int arr[], int size)
{
	cout << " неотсортированный массив\n";
	for (int g = 0; g < size; g++)
	{
		cout << arr[g] << ' ';
	}
}
void conclusionSortArr(int arr[], int size)
{
	auto timeStart = chrono::high_resolution_clock::now();
	qs(arr, 0, size - 1);
	auto timeEnd = chrono::high_resolution_clock::now();
	cout << endl << " отсортированный массив\n";
	for (int g = 0; g < size; g++)
	{
		cout << arr[g] << ' ';
	}
	cout << endl << "Время, затраченное на сортировку " << (chrono::duration_cast<chrono::microseconds> (timeEnd - timeStart).count()) << " микросек\n";

}
void move(int arr8[], int size1)
{
	cout << endl;
	auto timeStart = chrono::high_resolution_clock::now();
	int num1;
	int num2;
	cout << "Введите 2 индекса, которые хотите поменять местами: ";
	cin >> num1 >> num2;
	swap(arr8[num1], arr8[num2]);
	int g;
	for (g = 0; g < size1; g++)
	{
		if (g == num1 || g == num2)
		{
			cout << "!";
		}

		cout << arr8[g] << ' ';
		
	}
	auto timeEnd = chrono::high_resolution_clock::now();
	cout << endl << "Время, затраченное на обмен: " << (chrono::duration_cast<chrono::microseconds> (timeEnd - timeStart).count()) << " микросек\n";
	
	system("pause");
	system("cls");
}
void shellSort(int array[], int n) 
{
	for (int interval = n / 2; interval > 0; interval /= 2) 
	{
		for (int i = interval; i < n; i += 1) 
		{
			int key = array[i];
			int j;
			for (j = i; j >= interval && array[j - interval] > key; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = key;
		}
	}
	cout << "\nСортировка Шелла:\n";
	for (int g = 0; g < n; g++)
	{
		cout << array[g] << ' ';
	}
	cout << endl;
	system("pause");
	system("cls");
}
/*как пример сортировка вставками из степика
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Сдвигаем элементы массива, которые больше key, на одну позицию вперед
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
Сортировка Шелла обладает несколькими преимуществами: 
она проста в понимании и реализации и эффективна для средних и относительно малых данных. 
Однако существуют и недостатки: алгоритм не является устойчивым (может изменять порядок равных элементов) 
и имеет более высокую сложность по сравнению с более продвинутыми алгоритмами для больших объёмов данных.
}*/
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	const short size = 100;
	int randarr[size];
	int enterButton;
	do {
		cout << "1. Выыод отсортированного и не отсортированного массива.\n";
		cout << "2. Вывод максимального и минимального значения массива, их среднего значения.\n";
		cout << "3. Вывод количества элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем" << endl;
		cout << "4. Вывод количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем." << endl;
		cout << "5. Вывод информацию о том, есть ли введенное пользователем число в отсортированном массиве." << endl;
		cout << "6. Обмен местами элементы массива, индексы которых вводит пользователь.\n";
		cout << "7. Сортировка Шелла.\n";
		cout << "8. Выход из программы.\n";
		cout << "Выберете 1 из вариантов: ";
		cin >> enterButton;
		cout << "\n\n";
		while (cin.fail()) {
			cin.clear();
			cin.ignore(10000000000, '\n');
		}
		switch (enterButton) {
		case 1:
			system("cls");
			arr(randarr, size);
			conclusionNonSortArr(randarr, size);
			conclusionSortArr(randarr, size);
			system("pause");
			system("cls");
			break;
			return 0;
		case 2:
			system("cls");
			arr(randarr, size);
			conclusionNonSortArr(randarr, size);
			minMaxNonSort(randarr, size);
			conclusionSortArr(randarr, size);
			minMaxSort(randarr, size);
			system("pause");
			system("cls");
			cin.clear();
			cin.ignore(10000000000, '\n');
			break;
			return 0;
		case 3:
			system("cls");
			arr(randarr, size);
			conclusionSortArr(randarr, size);
			lessThanA(randarr, size);
			cin.clear();
			cin.ignore(10000000000, '\n');
			break;
			return 0;
		case 4:
			system("cls");
			arr(randarr, size);
			conclusionSortArr(randarr, size);
			moreThanB(randarr, size);
			cin.clear();
			cin.ignore(10000000000, '\n');
			break;
			return 0;
		case 5:
			system("cls");
			arr(randarr, size);
			conclusionSortArr(randarr, size);
			taskSeven(randarr, size);
			taskSeven2(randarr, size);
			cin.clear();
			cin.ignore(10000000000, '\n');
			break;
			return 0;
		case 6:
			system("cls");
			arr(randarr, size);
			conclusionSortArr(randarr, size);
			move(randarr, size);
			cin.clear();
			cin.ignore(10000000000, '\n');
			break;
			return 0;
		case 7:
			system("cls");
			arr(randarr, size);
			shellSort(randarr, size);
			break;
			return 0;
		case 8:
			exit(0);
			break;
			return 0;
		default:
			cout << "Такой вариант отсутствует :) \n\n";
			break;
		}
	} while (true);
	system("cls");
	return 0;
}


