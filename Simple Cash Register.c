#include <stdio.h>
#include <stdlib.h>

int main() {
	int cost_soup = 300;
	int cost_pasta = 500;
	int cost_tort = 400;
	int cost_salat = 250;
	int cost_kompot = 100;
	int cost_result = 0;
	int kolvo = 0;
	int user_variant;
	int exit = 0;
	
	do {
		//Список меню и запоминание выбора:
		printf("Выберите продукт из списка меню:\n1 - Суп Борщ\t\tЦена: %d\n2 - Итальянская паста\tЦена: %d\n3 - Торт Медовик\tЦена: %d\n4 - Салат Цезарь\tЦена: %d\n5 - Компот\t\tЦена: %d\n", cost_soup, cost_pasta, cost_tort, cost_salat, cost_kompot);
		scanf("%d", &user_variant);
		
		//Количество
		printf("Укажите количество:\n");
		scanf("%d", &kolvo);
		
		//Обработка выбора
		if (user_variant == 1) {
			printf("Вы выбрали Суп Борщ!\n");
			cost_result += cost_soup * kolvo;
		}
		else if (user_variant == 2) {
			printf("Вы выбрали Итальянскую пасту!\n");
			cost_result += cost_pasta * kolvo;
		}
		else if (user_variant == 3) {
		printf("Вы выбрали Торт Медовик!\n");
			cost_result += cost_tort * kolvo;
		}
		else if (user_variant == 4) {
			printf("Вы выбрали Салат Цезарь!\n");
			cost_result += cost_salat * kolvo;
		}
		else if (user_variant == 5) {
			printf("Вы выбрали Компот!\n");
			cost_result += cost_kompot * kolvo;
		}
		
		printf("Итоговая сумма: %d\n", cost_result);
		
		//Повторение
		printf("Желаете заказать что-то ещё?\n1 - Да\n2 - нет\n");
		scanf("%d", &exit);	
	}while (exit == 1);
	printf("Спасибо за заказ!\n");	
}
