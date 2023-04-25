#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//Board matrixes and hidden matrixes with the real positions defined
#define ARR_LEN 11

int row, col;
int set_counter = 10;
int set_counter_2 = 10;
int turn = 1;
int destroy_counter_1 = 0;
int destroy_counter_2 = 0;

char Hidden_Matrix_1[ARR_LEN][ARR_LEN] ={{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '1'},
                                         {'1', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'2', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'3', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'4', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'5', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'6', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'7', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'8', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'9', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'1', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}};
                                         
char Hidden_Matrix_2[ARR_LEN][ARR_LEN] ={{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '1'},
                                         {'1', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'2', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'3', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'4', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'5', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'6', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'7', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'8', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'9', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'1', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}};

char Board_Matrix_1[ARR_LEN][ARR_LEN] = {{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '1'},
                                         {'1', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'2', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'3', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'4', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'5', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'6', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'7', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'8', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'9', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'1', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}};
                                         
char Board_Matrix_2[ARR_LEN][ARR_LEN] = {{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '1'},
                                         {'1', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'2', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'3', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'4', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'5', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'6', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'7', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'8', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'9', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                         {'1', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}};


void print_Hidd_Mat_1(void){
	int i, j;
	
	for(i = 0; i < ARR_LEN; i++){
		for(j = 0; j < ARR_LEN; j++){
			printf("%c ", Hidden_Matrix_1[i][j]);
		}
		printf("\n");
	}
}

void print_Hidd_Mat_2(void){
	int i, j;
	
	for(i = 0; i < ARR_LEN; i++){
		for(j = 0; j < ARR_LEN; j++){
			printf("%c ", Hidden_Matrix_2[i][j]);
		}
		printf("\n");
	}
}

void print_Board_Mat_1(void){
	int i, j;
	
	for(i = 0; i < ARR_LEN; i++){
		for(j = 0; j < ARR_LEN; j++){
			printf("%c ", Board_Matrix_1[i][j]);
		}
		printf("\n");
	}
}

void print_Board_Mat_2(void){
	int i, j;
	
	for(i = 0; i < ARR_LEN; i++){
		for(j = 0; j < ARR_LEN; j++){
			printf("%c ", Board_Matrix_2[i][j]);
		}
		printf("\n");
	}
}

void set_player_1(void){
	while(set_counter > 0){
		printf("Tu tablero actualmente: \n");
		printf("\n");
		print_Hidd_Mat_1();
		printf("\n");
		printf("Te falta acomodar %d barcos \n", set_counter);
		printf("Introduce el numero de renglon en el que quieres poner el barco \n");
		printf("Usa numeros del 1 al 10 \n");
		scanf("%d", &row);
		if(row < 1 || row > 10){
			printf("Renglon invalido, porfavor intenta de nuevo \n");
			printf("Regresando al programa en 5 segundos \n");
			sleep(5);
			continue;
		}
		printf("Introduce el numero de columna en el que quieres poner el barco \n");
		scanf("%d", &col);
		if(col < 1 || col > 10){
			printf("Columna invalida, porfavor intenta de nuevo \n");
			printf("Regresando al programa en 5 segundos \n");
			sleep(5);
			continue;
		}
		if(Hidden_Matrix_1[row][col] == 'B'){
			printf("Espacio en tablero usado previamente, porfavor introduce otro espacio \n");
			printf("Regresando al programa en 5 segundos \n");
			sleep(5);
			continue;
		}
		Hidden_Matrix_1[row][col] = 'B';
		set_counter = set_counter-1;
	}
}

void set_player_2(void){
	while(set_counter_2 > 0){
		printf("Tu tablero actualmente: \n");
		printf("\n");
		print_Hidd_Mat_2();
		printf("\n");
		printf("Te falta acomodar %d barcos \n", set_counter_2);
		printf("Introduce el numero de renglon en el que quieres poner el barco \n");
		printf("Usa numeros del 1 al 10 \n");
		scanf("%d", &row);
		if(row < 1 || row > 10){
			printf("Renglon invalido, porfavor intenta de nuevo \n");
			printf("Regresando al programa en 5 segundos \n");
			sleep(5);
			continue;
		}
		printf("Introduce el numero de columna en el que quieres poner el barco \n");
		scanf("%d", &col);
		if(col < 1 || col > 10){
			printf("Columna invalida, porfavor intenta de nuevo \n");
			printf("Regresando al programa en 5 segundos \n");
			sleep(5);
			continue;
		}
		if(Hidden_Matrix_2[row][col] == 'B'){
			printf("Espacio en tablero usado previamente, porfavor introduce otro espacio \n");
			printf("Regresando al programa en 5 segundos \n");
			sleep(5);
			continue;
		}
		Hidden_Matrix_2[row][col] = 'B';
		set_counter_2 = set_counter_2-1;
	}
}

void* p1_th(void *args)
{	
	while(1){
		if(destroy_counter_1 == 10){
				pthread_exit(NULL);
			}
		if(turn == 1){
			printf("Turno de jugador 1 \n");
			printf("\n");
			printf("Tu tablero \n");
			print_Hidd_Mat_1();
			printf("\n");
			printf("B = Posicion de tus barcos \n");
			printf("D = Barco aliado destruido \n");
			printf("0 = Ataque enemigo fallido \n");
			printf("\n");
			printf("Tablero de tu enemigo \n");
			print_Board_Mat_2();
			printf("\n");
			printf("X = Barco enemigo destruido \n");
			printf("0 = Ataque aliado fallido \n");
			printf("\n");
			
			printf("Introduce el renglon del espacio que quieres atacar \n");
			printf("Usa numeros del 1 al 10 \n");
			scanf("%d", &row);
			if(row < 1 || row > 10){
				printf("Renglon invalido, porfavor intenta de nuevo \n");
				printf("Regresando al programa en 5 segundos \n");
				sleep(5);
				continue;
			}
			printf("Introduce la columna del espacio que quieres atacar \n");
			scanf("%d", &col);
			if(col < 1 || col > 10){
				printf("Columna invalida, porfavor intenta de nuevo \n");
				printf("Regresando al programa en 5 segundos \n");
				sleep(5);
				continue;
			}
			if(Board_Matrix_2[row][col] == 'X'){
				printf("Barco en ese espacio ya destruido, porfavor introduce otro espacio \n");
				printf("Regresando al programa en 5 segundos \n");
				sleep(5);
				continue;
			}
			if(Board_Matrix_2[row][col] == '0'){
				printf("Espacio vacio ya atacado, intenta otro \n");
				printf("Regresando al programa en 5 segundos \n");
				sleep(5);
				continue;
			}
			
			if(Hidden_Matrix_2[row][col] == 'B'){
				printf("HIT \n");
				printf("Barco destruido! \n");
				Hidden_Matrix_2[row][col] = 'D';
				Board_Matrix_2[row][col] = 'X';
				destroy_counter_2 = destroy_counter_2+1;
				if(destroy_counter_2 == 10){
					system("clear");
					printf("JUGADOR 1 GANA\n");
					printf("FELICIDADES\n");
					pthread_exit(NULL);
				} else {
					printf("Pasando a turno de jugador 2 en 5 segundos \n");
					sleep(5);
					system("clear");
					turn = 2;
				}
			}
			
			if(Hidden_Matrix_2[row][col] == '-'){
				printf("MISS  \n");
				printf("Espacio vacio!  \n");
				printf("Pasando a turno de jugador 2 en 5 segundos \n");
				sleep(5);
				system("clear");
				Board_Matrix_2[row][col] = '0';
				Hidden_Matrix_2[row][col] = '0';
				turn = 2;
			}
		}
	}
	pthread_exit(NULL);
}

void* p2_th(void *args)
{	
	while(1){
		if(destroy_counter_2 == 10){
				pthread_exit(NULL);
			}
		if(turn == 2){
			printf("Turno de jugador 2 \n");
			printf("\n");
			printf("Tu tablero \n");
			print_Hidd_Mat_2();
			printf("\n");
			printf("B = Posicion de tus barcos \n");
			printf("D = Barco aliado destruido \n");
			printf("0 = Ataque enemigo fallido \n");
			printf("\n");
			printf("Tablero de tu enemigo \n");
			print_Board_Mat_1();
			printf("\n");
			printf("X = Barco enemigo destruido \n");
			printf("0 = Ataque aliado fallido \n");
			printf("\n");
			
			printf("Introduce el renglon del espacio que quieres atacar \n");
			printf("Usa numeros del 1 al 10 \n");
			scanf("%d", &row);
			if(row < 1 || row > 10){
				printf("Renglon invalido, porfavor intenta de nuevo \n");
				printf("Regresando al programa en 5 segundos \n");
				sleep(5);
				continue;
			}
			printf("Introduce la columna del espacio que quieres atacar \n");
			scanf("%d", &col);
			if(col < 1 || col > 10){
				printf("Columna invalida, porfavor intenta de nuevo \n");
				printf("Regresando al programa en 5 segundos \n");
				sleep(5);
				continue;
			}
			if(Board_Matrix_1[row][col] == 'X'){
				printf("Barco en ese espacio ya destruido, porfavor introduce otro espacio \n");
				printf("Regresando al programa en 5 segundos \n");
				sleep(5);
				continue;
			}
			if(Board_Matrix_1[row][col] == '0'){
				printf("Espacio vacio ya atacado, intenta otro \n");
				printf("Regresando al programa en 5 segundos \n");
				sleep(5);
				continue;
			}
			
			if(Hidden_Matrix_1[row][col] == 'B'){
				printf("HIT \n");
				printf("Barco destruido! \n");
				Hidden_Matrix_1[row][col] = 'D';
				Board_Matrix_1[row][col] = 'X';
				destroy_counter_1 = destroy_counter_1+1;
				if(destroy_counter_1 == 10){
					system("clear");
					printf("JUGADOR 2 GANA\n");
					printf("FELICIDADES\n");
					pthread_exit(NULL);
				} else {
					printf("Pasando a turno de jugador 1 en 5 segundos \n");
					sleep(5);
					system("clear");
					turn = 1;
				}
			}
			
			if(Hidden_Matrix_2[row][col] == '-'){
				printf("MISS  \n");
				printf("Espacio vacio!  \n");
				printf("Pasando a turno de jugador 1 en 5 segundos \n");
				sleep(5);
				system("clear");
				Board_Matrix_1[row][col] = '0';
				Hidden_Matrix_1[row][col] = '0';
				turn = 1;
			}
		}
	}
	pthread_exit(NULL);
}


int main() {
	pthread_t turn_p1, turn_p2;
     int state;
     
     
	printf("Set de los barcos \n");
	printf("Jugador 1 toma la computadora y presiona alguna tecla para continuar\n");
	getchar();
	set_player_1();
	
	system("clear");
	
	printf("Set de los barcos \n");
	printf("Jugador 2 toma la computadora y espera 5 segundos \n");
	sleep(5);
	set_player_2();
	
	system("clear");
	
	printf("Turnos comenzando, pasa la computadora al jugador 1 y espera 5 segundos \n");
	sleep(5);
	
	state = pthread_create(&turn_p1, NULL, p1_th, NULL);
     state = pthread_create(&turn_p2, NULL, p2_th, NULL);
	
	pthread_join(turn_p1, NULL);
	pthread_join(turn_p2, NULL);
	
	return 0;
}



