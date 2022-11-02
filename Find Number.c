#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int a;
	srand(time(NULL));
	a = rand() % 100;
	
	//Цикл

	for (int k = 100; k > 0; k--) {
		if (k == a) {
			printf("Число а =  %d\n", k);
		} 
	}
	
	//Решение
	
	int i = 0;
	
	for (int k = 0; k < 10; k++) {
		if (k > 7) {
			printf("Вы совершили больше 7 попыток\n");
			return 1;
		}
		
		printf("Введите ваше число: \n");
		scanf("%d", &i);
		
		if (i != a) {
			if (i > a) {
				printf("Загаданное число меньше\n");
			}
			else {
				printf("Загаданное число больше\n");
			}
		}
		else {
			printf("Вы угадали число с попытки номер: %d", k+1);
			return 1;
		}
	}
}
