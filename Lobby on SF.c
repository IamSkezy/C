#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Функция - отступ
void probel() {
	printf("\n");
}

//Функция для вывода жизней
int hp(int player_hp, int enemy_hp) {
	printf("Ваше здоровье:%d\tЗдоровье врага:%d\n", player_hp, enemy_hp);
}

int main() {
	const int ARR_SIZE = 3;
	const int MAP = 6;
	
	int player_arr[ARR_SIZE];
	int enemy_arr[ARR_SIZE];
	int player_hp=3;
	int enemy_hp=3;
	int player_position;
	int enemy_position;
	int player_coil;
	int enemy_coil;
	int player_counter;
	int enemy_counter;
	int result_player;
	int result_enemy;
	int run_game;
	int round_counter = 0;
	
	char position_one[4] = "#==";
	char position_two[4] = "=#=";
	char position_three[4] = "==#";
	char enemy_position_one[4] = "???";
	
	srand(time(NULL));
	
	//Приветствие 
	printf("ИГРА НАЧАЛАСЬ!\n");
	probel();
	
	while ((player_hp > 0) && (enemy_hp > 0 )) {
		//Заполнение массива
		for (int i = 0; i < ARR_SIZE; i++) {
			player_arr[i] = i+1;
			enemy_arr[i] = i+1;
		}
		
		//Счетчик раунда
		round_counter++;
		printf("Раунд номер: %d\n", round_counter);
		probel();
		
		//Обработка позиции player
		printf("Выберите позицию, которую хотите занять:\n1 - #==\n2 - =#=\n3 - ==#\n");
		scanf("%d", &player_position);
		
		probel();
		
		//Обработка позиции enemy
		enemy_position = rand() %4 + 1;
		
		//Отображение карты
		printf("Карта:\n");
		if (player_position == 1) {
			printf("%s%s\n", position_one, enemy_position_one);
		}
		else if (player_position == 2) {
			printf("%s%s\n", position_two, enemy_position_one);
		}
		else {
			printf("%s%s\n", position_three, enemy_position_one);
		}
		
		probel();
		
		//Обработка выбора койла у player
		printf("Выберите койл, который хотите кинуть:\n1 - Ближний\n2 - Средний\n3 - Дальний\n");
		scanf("%d", &player_coil);
		if (player_coil == 1) {
			printf("Вы кинули ближний койл\n");
		} 
		else if(player_coil == 2) {
			printf("Вы кинули средний койл\n");
		}
		else {
			printf("Вы кинули дальний койл\n");
		}
		
		probel();
		
		//Обработка выбора койла у enemy
		enemy_coil = rand() %4 + 1;
		if (enemy_coil == 1) {
			printf("Враг кинул ближний койл\n");
		}
		else if(enemy_coil == 2) {
			printf("Враг кинул средний койл\n");
		}
		else {
			printf("Враг кинул дальний койл\n");
		}
		
		probel();
		
		//Счетчик очков у player и enemy
		player_counter = player_coil + player_position;
		enemy_counter = enemy_coil + enemy_position;
		
		//Варианты попаданий
		if ( ((result_player = MAP - player_counter) == enemy_position - 1) && ((result_enemy = MAP - enemy_counter) == player_position - 1) ) {
			printf("Оба попали!\n");
			player_hp--;
			enemy_hp--;
		}
		else if ((result_player = MAP - player_counter) == enemy_position - 1) {
			printf("Вы попали!\n");
			enemy_hp--;
		}
		else if ((result_enemy = MAP - enemy_counter) == player_position - 1) {
			printf("Враг попал!\n");
			player_hp--;
		}
		else {
			printf("Никто не попал!\n");
		}
		
		probel();
		
		//Варианты победы
		if ((player_hp == 0) && (enemy_hp == 0) ){
			printf("НИЧЬЯ!\n");
		}
		else if((player_hp > 0) && (enemy_hp == 0)) {
			printf("ВЫ ПОБЕДИЛИ!\n");
		}
		else if ((player_hp == 0) && (enemy_hp > 0)) {
			printf("ВРАГ ПОБЕДИЛ!\n");
		}
		probel();
		
		//Отображение итоговой карты
		printf("Карта:\n");
		if (player_position == 1) {
			printf("%s", position_one);
			if (enemy_position == 1) {
				printf("%s", position_three);
			}	
			else if (enemy_position == 2) {
				printf("%s", position_two);
			}
			else {
				printf("%s", position_one);
			}
		}
		else if (player_position == 2) {
			printf("%s", position_two);
			if (enemy_position == 1) {
				printf("%s", position_three);
			}
			else if (enemy_position == 2) {
				printf("%s", position_two);
			}
			else {
				printf("%s", position_one);
			}
		}
		else {
			printf("%s", position_three);
			if (enemy_position == 1) {
				printf("%s", position_three);
			}
			else if (enemy_position == 2) {
				printf("%s", position_two);
			}
			else {
				printf("%s", position_one);
			}
		}
		probel();
		probel();
		
		//Вывод жизней
		hp(player_hp, enemy_hp);
		probel();		
	}
	
	//Запуск игры заново
	printf("1 - начать заново\n2 - закончить игру\n");
	scanf("%d", &run_game);
	if (run_game == 1) {
		main();
		probel();
	}
	else {
		return 0;
	}
}
