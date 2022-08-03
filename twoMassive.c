#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* twoMassive(int n1, int n2, int n3, int* arr1, int* arr2) {
	int * arr3 = (int*)malloc(sizeof(int)*n3);
	for (int i = 0; i < n1; i++) {
		arr3[i] = arr1[i];
	}
	for (int j = 0; j < n2; j++) {
		arr3[j+n1] = arr2[j]; 
	}
	return arr3;
}

int main() {
	int* arr1;
	int* arr2;
	int n1;
	int n2;
	srand(time(NULL));
	scanf("%d %d", &n1, &n2);
	int n3 = n1 + n2;
	int* res;
	//Выделение памяти
	arr1 = (int*)malloc(sizeof(int) * n1);
	arr2 = (int*)malloc(sizeof(int) * n2);
	res = (int*)malloc(sizeof(int) * n3);
	//Рандомное заполнение массива
	for (int i = 0; i < n1; i++) {
		arr1[i] = rand() % 100;
	}
	for (int j = 0; j < n2; j++) {
		arr2[j] = rand() % 100;
	}
	res = twoMassive(n1, n2, n3, arr1, arr2);
	//Вывод
	printf("Первый массив:\n");
	for (int b = 0; b< n1; b++) {
		printf("%d ", arr1[b]);
	}
	printf("\nВторой массив:\n");
	for (int c = 0; c < n2; c++) {
		printf("%d ", arr2[c]);
	}
	printf("\nКонечный массив:\n");
	for (int k = 0; k < n3; k++) {
		printf("%d ", res[k]);
	}
}
