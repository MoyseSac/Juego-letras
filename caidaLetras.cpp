#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define WIDTH 58
#define HEIGHT 20

//metodos que usaremos en el juego 
void gotoxy(int x, int y);
void DibujarMarco();
void clearFrame(int PosX, int PosY);
void Ganar();
void pantallaCarga();
void nivel_uno();
void nivel_dos();
char randomChar();

//variables globales del juego 
bool ganar_uno= false;
bool perder_uno= false;
bool perder_dos=false; 
bool partida=true;
int contadorAciertos=0;
int contadorFallos=0;





int main() {
	pantallaCarga();
	srand(time(NULL));
	DibujarMarco();
	nivel_uno();
	if(ganar_uno){
		system("cls");
		Ganar();
	}else if(perder_uno=true){
		printf("Hay que ser malo para perder en el nvl 1");
	}
	
	
	return 0;
}





void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char randomChar() {
	return 'a' + rand() % 26;
}

void DibujarMarco() {
	int i;
	for (i = 0; i < WIDTH; i++) {
		gotoxy(i + 1, 1);
		printf("%c", char(224));
		gotoxy(i + 1, HEIGHT);
		printf("%c", char(79));
	}
	for (i = 1; i <= HEIGHT; i++) {
		gotoxy(1, i);
		printf("%c", char(79));
		gotoxy(WIDTH, i);
		printf("%c", char(79));
	}
	

	
}

//nivel uno del juego velocidad lenta 
void nivel_uno(){
	int x = rand() % WIDTH + 1;
	int y = 2;
	char letter = randomChar();
	void clearFrame(int PosX, int PosY);
	
	//inicio de juego hasta que el usuario pierda o gane 
	while (partida){ 
		gotoxy(x, y);
		printf("%c", letter);
		Sleep(300);  //un valor bajo de velocidad para el nvl1
		
		if (_kbhit()) { // Verifica si se ha presionado una tecla
			char pressedKey = _getch(); // Obtiene la tecla presionada
			
			if (pressedKey == letter) {
				printf("\b \b"); // Borra la letra si es correcta
				letter = randomChar(); // Genera una nueva letra
				x = rand() % WIDTH + 1; // Reinicia la posición en x
				y=2;
				contadorAciertos++;
			} else {
				contadorFallos++;
			}
			
		}
		
		//verificamos si la letra ha llegado al borde de la pantalla
		if(y==HEIGHT){
			printf("\b \b"); // Borra la letra si se llego al final de la pantalla 
			x = rand() % WIDTH + 1; // Reinicia la posición en x
			y=3;
			contadorFallos++;
		}
		
		//verificamos si debemos terminar el juego, cambiamos el estado del while 
		if(contadorAciertos==5){
			partida=false;
			ganar_uno=true;
			
			
		}else if(contadorFallos==5){
			printf("Lo lamento ha perdido");
			partida=false;
			perder_uno=true;
		}
		
		clearFrame(x, y);
		y++; 
	}
}

void nivel_dos() {
		int x = rand() % WIDTH + 1;
		int y = 2;
		char letter = randomChar();
		void clearFrame(int PosX, int PosY);
		
		//inicio de juego hasta que el usuario pierda o gane 
		while (partida) {
			gotoxy(x, y);
			printf("%c", letter);
			Sleep(100);  //aumentamos la velocidad
			
			if (_kbhit()) { // Verifica si se ha presionado una tecla
				char pressedKey = _getch(); // Obtiene la tecla presionada
				
				if (pressedKey == letter) {
					printf("\b \b"); // Borra la letra si es correcta
					letter = randomChar(); // Genera una nueva letra
					x = rand() % WIDTH + 1; // Reinicia la posición en x
					y = 3;
					contadorAciertos++;
				}
				else {
					contadorFallos++;
				}
				
			}
			
			//verificamos si la letra ha llegado al borde de la pantalla
			if (y == HEIGHT) {
				printf("\b \b"); // Borra la letra si se llego al final de la pantalla 
				x = rand() % WIDTH + 1; // Reinicia la posición en x
				y = 3;
				contadorFallos++;
			}
			
			//verificamos si debemos terminar el juego, cambiamos el estado del while 
			if (contadorAciertos == 5) {
				partida = false;
				Ganar(); // función para indicar que ha ganado
			}
			else if (contadorFallos == 5) {
				printf("Lo lamento ha perdido");
				partida = false;
				perder_dos = true;
			}
			
			clearFrame(x, y);
			y++;
		}
	}

void Ganar(){
	char heart[6][10] = {
		{' ', '*', '*', ' ', '*', '*', ' '},
	{'*', '*', '*', '*', '*', '*', '*'},
		{'*', '*', '*', '*', '*', '*', '*'},
	{' ', '*', '*', '*', '*', '*', ' '},
		{' ', ' ', '*', '*', '*', ' ', ' '},
	{' ', ' ', ' ', '*', ' ', ' ', ' '}
	};
	
	
	for (int i = 0; i < 6; i++) {
		gotoxy(53,18+i);
		printf("%s\n", heart[i]);
	}
}


void clearFrame(int PosX, int PosY) {
	
	gotoxy(PosX, PosY - 1);
	printf(" ");
	
}

void pantallaCarga(){
	int col,r,c,q;
	gotoxy(30,13);
	printf("Cargando juego... ");
	gotoxy(30,14);
	printf("Presione cualquier tecla");
	gotoxy(30,15);
	for(r=1; r<=20; r++)
	{
		for(q=0; q<=100000000; q++); //to display the character slowly
		printf("%c",177);
	}
	getch();
	system("cls");
}

