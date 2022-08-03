#include <stdio.h>
#include <time.h>

int main() {
	
	//Объявление переменных
	int cost_min = 60;
	int cost_middle = 100;
	int cost_max = 150;
	int cost_ticket = 0;
	int cost_result = 0;
	int marshrut = 10;
	int kolvo_ticket;
	int point_first;
	int point_second;
	int point_result;
	int people_train;
	int variant = 0;
	int people_result;
	
	srand(time(NULL));
	
	do {
	
		do {
			//Выбор станций
			printf("Маршрут с 1ой по 10ую станцию!\n");
			do {
				printf("Здравствуйте, укажите с какой станции произошла посадка\n");
				scanf("%d", &point_first);
				if (point_first < 1 || point_first > 10) {
					printf("Такой остановки нет!\n");
				}
				else if (point_first == 10) {
					printf("Это конечная станция!\nПоезд дальше не идёт.\n");
				}
			}while (point_first < 1 && point_first > marshrut);
			do {
				printf("Укажите до какой остановки хотите купить билет\n");
				scanf("%d", &point_second);
				if (point_second < 1 || point_second > 10) {
					printf("Такой остановки нет!\n");
				}
				else if (point_second == 1) {
					printf("Вы и так уже на 1ой станции\n");
				}
			}while(point_second < 1 && point_second > marshrut);
			if (point_first >= point_second) {
				printf("Некорректные данные!\n");
			}
		}while(point_first >= point_second);
		
		//Обработка цены билета
		point_result = point_first - point_second;
		if (point_result <=3) {
			cost_ticket = cost_min;
		}
		else if (point_result > 3 && point_result <=7) {
				cost_ticket = cost_middle;
		}
		else if (point_result > 7) {
		cost_ticket = cost_max;
		}
		
		//Обработка количества билетов
		people_train = rand() % 100;
		printf("Количество купленных билетов: %d\n", people_train);
		do {
			printf("Укажите количество билетов\n");
			scanf("%d", &kolvo_ticket);
			if (kolvo_ticket > 100 - people_train) {
				printf("Данное количество билетов превышает вместимость поезда\n");
			}
		}while (kolvo_ticket > 100 - people_train);
		
		//Итоговая цена
		cost_result = cost_ticket * kolvo_ticket;
		people_result = people_train + kolvo_ticket;
		if (people_train == 100) {
		printf("Билетов нет!\nКоличество купленных билетов = %d", people_train);
		}
		
		//Повторение цикла
		printf("Желаете ещё купить билеты?\n1 - Купить билеты\n2 - Возврат билета\n3 - Нет\n");
		scanf("%d", &variant);
		} while (variant == 1);
		printf("Вы отправились с остановки №%d\tДо остановки №%d\nИтоговая цена: %d\tКоличество, людей в поезде = %d\n",point_first, point_second, cost_result, people_result);
}
