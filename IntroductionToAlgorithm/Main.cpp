
#include <iostream>
#include <string>
using namespace std;

void printArr(int arr[], int n) {
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] <<" ";
	}
	cout << endl;
}

void exercise2_1_1() {
	std::cout << "Exercise2.1-1\n===========" << std::endl;
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

void merge_sort(int arr[],int p, int r) {
	//如果数组长度小于等于1 则无需做任何操作
	if (p < r) {
		int q = (p + r) / 2;
		int lenL = q - p + 1;
		int lenR = r - q;
		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, r);
		int L[1000];
		int R[1000];
		for (int i = p, j = 0; i < p + lenL; i++, j++) {
			L[j] = arr[i];
		}
		for (int i = q + 1, j = 0; i < q + lenR + 1; i++, j++) {
			R[j] = arr[i];
		}
		
		int i = 0, j = 0, k = p;
		while (i < lenL && j < lenR) {
			if (R[j] > L[i]) {
				arr[k] = L[i];
				i++;
				k++;
			}
			else {
				arr[k] = R[j];
				j++;
				k++;
			}
		}
			//某个数组先被遍历完，把另一个数组直接放进去；
		while (i < lenL) {
			arr[k++] = L[i++];
		}
		while (j < lenR) {
			arr[k++] = R[j++];
		}
	}
}

void exercise2_3_1() {
	//归并排序
	std::cout << "Exercise2.3-1\n===========\n归并排序" << std::endl;
	int arr[1000];
	int n;
	std::cout << "Input n and n numbers follow:" << std::endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	merge_sort(arr, 0, n-1);
	printArr(arr, n);
}

void run() {
	exercise2_3_1();
}

int main() {
	cout << "Hello World" << endl;
	cout << "===========" << endl;
	run();
	return 0;
}