
/**************************************

	TRES en RAYA DELUXE
	by Fernando Paniagua (2016)

***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLAYER_1 1
#define PLAYER_2 2

void mostrarPortada();
void inicializar();
void visualizar();
void buscar3enraya();

int tablero[3][3];

/*
Método principal
*/
int main(void){
	int fila;
	int columna;
	int i=0;
	int player=PLAYER_1;

	mostrarPortada();
	inicializar();
	visualizar();

	do {
		printf("Jugador %i\n", player);
		printf("Introduce fila:");
		scanf("%i",&fila);
		printf("Introduce columna:");
		scanf("%i",&columna);
		fila--;//Corregimos el indice introducido por el jugador
		columna--;//Corregimos el indice introducido por el jugador
		if ((fila<0) || (fila>2) || (columna<0) || (columna>2)){
			printf ("* ERROR: CELDA FUERA DE RANGO [1-3][1-3] *\n");
		} else if (tablero[fila][columna]==-1) {//Celda libre
			if (player==PLAYER_1){
				tablero[fila][columna]=PLAYER_1;	
				player=PLAYER_2;
			} else {
				tablero[fila][columna]=PLAYER_2;	
				player=PLAYER_1;
			}
			i++;
			visualizar();
			buscar3enraya();
		} else {
			printf ("* ERROR: CELDA OCUPADA *\n");
		}
	} while (i<9);
	//Si se llega a este punto es que ha habido tablas
	printf("TABLAS - FIN DE PARTIDA\n");
	exit(0);
}


/*
Inicializa a -1 los elementos del array
*/
void inicializar(){
	int i;
	int j;
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			tablero[i][j]=-1;
		}
	}
}


/*
- Muestra el tablero. 
- Las celdas con valor -1 las muestra vacías.
- Las líneas se muestran utilizando los caracteres de la 
	tabla UNICODE por compatiblidad con Linux.
*/
void visualizar(){
	int i;
	int j;
	
	printf("%c",201);
	printf("%c%c%c",205,205,205);
	printf("%c",203);
	printf("%c%c%c",205,205,205);
	printf("%c",203);
	printf("%c%c%c",205,205,205);
	printf("%c\n",187);

	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			printf("%c",186);
			if (tablero[i][j]!=-1) {
				printf(" %i ", tablero[i][j]);	
			} else {
				printf("   ");
			}
		}
		printf("%c\n",186);
		if (i<2){
			printf("%c",204);
			printf("%c%c%c",205,205,205);
			printf("%c",206);
			printf("%c%c%c",205,205,205);
			printf("%c",206);
			printf("%c%c%c",205,205,205);
			printf("%c\n",185);
		}
	}

	printf("%c",200);
	printf("%c%c%c",205,205,205);
	printf("%c",202);
	printf("%c%c%c",205,205,205);
	printf("%c",202);
	printf("%c%c%c",205,205,205);
	printf("%c\n",188);
}


/*
Busca la existencia de tres en raya en las columnas, filas y diagonales.
Si encuentra tres en raya muestra el jugador que ha ganado y termina la ejecución.
*/
void buscar3enraya(){
	int i;
	for (i=0;i<3;i++){
		if ((tablero[0][i]!=-1) && (tablero[0][i]==tablero[1][i]) && (tablero[0][i]==tablero[2][i])){
			//3 EN RAYA EN LA COLUMNA i
			printf("3 EN RAYA - GANA JUGADOR %i\n", tablero[0][i]);
			exit(0);
		} else if ((tablero[i][0]!=-1) && (tablero[i][0]==tablero[i][1]) && (tablero[i][0]==tablero[i][2])){
			//3 EN RAYA EN LA FILA i
			printf("3 EN RAYA - GANA JUGADOR %i\n", tablero[i][0]);
			exit(0);
		} 
	}
	if ((tablero[0][0]!=-1) && (tablero[0][0]==tablero[1][1]) && (tablero[1][1]==tablero[2][2])){
		//3 EN RAYA EN DIAGONAL 1
		printf("3 EN RAYA - GANA JUGADOR %i\n", tablero[0][0]);
		exit(0);
	} else if ((tablero[2][0]!=-1) && (tablero[0][2]==tablero[1][1]) && (tablero[1][1]==tablero[2][0])){
		//3 EN RAYA EN DIAGONAL 2
		printf("3 EN RAYA - GANA JUGADOR %i\n", tablero[0][2]);
		exit(0);
	}	

}

/*
Muestra la portada del juego y los créditos.

La generación del texto ASCII se ha obtenido de:
 	http://patorjk.com/software/taag/#p=display&h=0&f=Crawford2&t=TRES%20EN%20RAYA
*/
void mostrarPortada(){
	char nada;
	printf(" ______  ____     ___   _____       ___  ____       ____    ____  __ __   ____ \n");
	printf("|      ||    \\   /  _] / ___/      /  _]|    \\     |    \\  /    ||  |  | /    |\n");
	printf("|      ||  D  ) /  [_ (   \\_      /  [_ |  _  |    |  D  )|  o  ||  |  ||  o  |\n");
	printf("|_|  |_||    / |    _] \\__  |    |    _]|  |  |    |    / |     ||  ~  ||     |\n");
	printf("  |  |  |    \\ |   [_  /  \\ |    |   [_ |  |  |    |    \\ |  _  ||___, ||  _  |\n");
	printf("  |  |  |  .  \\|     | \\    |    |     ||  |  |    |  .  \\|  |  ||     ||  |  |\n");
	printf("  |__|  |__|\\_||_____|  \\___|    |_____||__|__|    |__|\\_||__|__||____/ |__|__|\n");
    printf("\nBy Fernando Paniagua (2016)");
    printf("\n\nPulsa ENTER para comenzar...");                                                                           
	scanf("%c",&nada);
}