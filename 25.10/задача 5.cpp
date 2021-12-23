/*
Массив длины N в случайном порядке заполнен целыми числами из диапазона от 0 до N. 
Каждое число встречается в массиве не более одного раза. Найти отсутствующее число (дырку). Сложность алгоритма O(N). 
Использование дополнительной памяти, пропорциональной длине массива, не допускается.
А что если две дырки будет, получится линейным алгоритмом? 
*/
#include <iostream>

bool exam(int M[], int N, int num) {
	for (int i = 0; i < N; ++i)
		if (M[i] == num)
			return true;
	return false;
}
int main() {
	int len;
	std::cout << "Input lenght of sequence: ";
	std::cin >> len;

	int* M = new int[len];
	srand(time(nullptr));
	
	for (int i = 0; i < len; ++i)
		do {
			M[i] = rand() % (len + 1);
		} while (exam(M, i, M[i]));

	for (int i = 0; i < len; ++i)
		std::cout << M[i] << ' ';
	std::cout << std::endl;

	int result = len * (len + 1) / 2;

	for (int i = 0; i < len; ++i)
		result -= M[i];

	std::cout << "hole: " << result << std::endl;

}
