#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	//Объявление переменных
	int* arr;
	int arr_size;
	int variant;
	int arr_max = 0;
	int arr_min = 0;
	
	srand(time(NULL));
	
	//Указание размерности
	printf("Укажите размерность массива:\n");
	scanf("%d", &arr_size);
	
	//Выделение памяти
	arr = (int*)malloc(sizeof(int) * arr_size);
	
	//Выбор заполнения массива
	printf("Укажите 1, если хотите заполнить массив самостоятельно.\nУкажите 2, если хотите заполнить массив рандомно.\n");
	scanf("%d", &variant);
	
	//Заполнение массива самостоятельно
	if (variant == 1) {
		for(int i = 0; i < arr_size; i++) {
			printf("arr[%d] = ", i);
    			scanf("%d", &arr[i]); 	
		}
		//Вывод массива
		printf("arr[%d] = ", arr_size);
		for (int i = 0; i < arr_size; i++) {
			printf("%d ", arr[i]);
		}
	}
	//Рандомное заполнение массива
	if (variant == 2) {
		//Рандомное заполнение массива
		for (int i = 0; i < arr_size; i++) {
			arr[i] = rand() % 100;
		}
		//Вывод массива
		printf("arr[%d] = ", arr_size);
		for (int i = 0; i < arr_size; i++) {
			printf("%d ", arr[i]);
		}
	}
	
	printf("\n");
	
	//Нахождение максимального и минимального элемента в массиве
	for (int i = 0; i < arr_size; i++) {
		if (arr_max < arr[i]){
			arr_max = arr[i];
		}
	}
	arr_min = arr[0];
	for (int i = 0; i < arr_size; i++) {
		if (arr_min > arr[i] ) {
			arr_min = arr[i];
		}
	}
	printf("Максимальное значение в массиве = %d\nМинимальное значение в массиве = %d\n", arr_max, arr_min);
}
