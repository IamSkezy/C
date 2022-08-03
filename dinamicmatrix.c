#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int** matrix;
	int w = 0;
	int h = 0;
	int mem = 0;
	srand(time(NULL));
	scanf("%d %d", &w, &h);
	//Выделение памяти под указатели строки
	matrix = (int**)malloc(sizeof(int*) * w);
	//Заполнение строк и столбцов, и выделение памяти
	for (int i = 0; i < w; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * h);
		for (int j = 0; j < h; j++) {
			matrix[i][j] = rand() % 100;
		}
	}
	//Вывод массива
	for (int i = 0; i < w; i++) { //по строкам
		printf("\n");
		for (int j = 0; j < h; j++) { //по столбцам
			printf("%d ", matrix[i][j] );
		}
	}
}
