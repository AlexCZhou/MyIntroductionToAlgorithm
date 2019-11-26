
#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] <<" ";
	}
	cout << endl;
}

void exercise2_1_2() {
	std::cout << "Exercise2.1-2\n=============" << std::endl;
	int arr[100];
	int n;
	std::cout << "Input n and n numbers follow:" << std::endl;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] < key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	printArr(arr, n);
}

void exercise2_1_1() {
	std::cout << "Exercise2.1-1\n=============" << std::endl;
	int arr[] = { 31, 41, 59, 26, 41, 58 };
	std::cout << "Original: ";
	printArr(arr, 6);
	for (int j = 1; j < 6; j++) {
		int key = arr[j];
		int i = j - 1;
		while (i >= 0 && arr[i] > key) {
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = key;
		std::cout << j << " : ";
		printArr(arr, 6);
	}
	std::cout << "Final: ";
	printArr(arr, 6);
	std::cout << std::endl;
}

void run() {
	exercise2_1_2();
}

int main() {
	cout << "Hello World" << endl;
	cout << "===========\n" << endl;
	run();
	return 0;
}