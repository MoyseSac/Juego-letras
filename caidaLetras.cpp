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
	system("cls");
	if(ganar){
		Ganar();
		Sleep(1000);
		system("cls");
		DibujarMarco();
		nivel_dos();
		system("cls");
		if(ganar){
			Ganar();
			Sleep(1000);
			system("cls");
			DibujarMarco();
			nivel_tres();
			system("cls");
			if(ganar){
				Ganar();
				Sleep(1000);
				system("cls");
			}else if(perder){
				printf("Tan cerca pero tan lejos");
			}
		}else if(perder){
			printf("Llegaste lejos, vuelve a intentarlo");
		}
	}else if(perder){
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
	//reiniciamos las variables que controlan el comportamiento del juego 
		partida=true;
		ganar=false;
		perder=false;
		contadorAciertos=0;
		contadorFallos=0;
		
		
		int x = rand() % WIDTH + 1;
		int y = 2;
		char letter = randomChar();
		
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
				ganar=true;
			}
			else if (contadorFallos == 5) {
				printf("Lo lamento ha perdido");
				partida = false;
				perder= true;
			}
			
			clearFrame(x, y);
			y++;
	}
}

void nivel_tres() {
	//reiniciamos las variables que controlan el comportamientod del juego 
	partida=true;
	ganar=false;
	perder=false;
	contadorAciertos=0;
	contadorFallos=0;
	
	
	int x1 = rand() % WIDTH + 1;
	int x2 = rand() % WIDTH + 1;
	int x3 = rand() % WIDTH +1;
	int y1 = 3, y2=3, y3=3;
	char letter1 = randomChar();
	char letter2 = randomChar();
	char letter3 = randomChar();
	
	//inicio de juego hasta que el usuario pierda o gane 
	while (partida) {
		gotoxy(x1, y1);
		printf("%c", letter1);
		gotoxy(x2, y2);
		printf("%c", letter2);
		gotoxy(x3, y3);
		printf("%c", letter3);
		Sleep(150);  //aumentamos la velocidad
		
		
		if (_kbhit()) { // Verifica si se ha presionado una tecla
			char pressedKey = _getch(); // Obtiene la tecla presionada
			
			if (pressedKey == letter1 ) {
				printf("\b \b"); // Borra la letra si es correcta
				letter1 = randomChar(); // Genera una nueva letra
				x1 = rand() % WIDTH + 1; // Reinicia la posición en x
				y1 = 3;
				contadorAciertos++;
			}else if(pressedKey == letter2){
				printf("\b \b"); // Borra la letra si es correcta
				letter2 = randomChar(); // Genera una nueva letra
				x2 = rand() % WIDTH + 1; // Reinicia la posición en x
				y2 = 3;
				contadorAciertos++;
			}else if(pressedKey == letter3){
				printf("\b \b"); // Borra la letra si es correcta
				letter3 = randomChar(); // Genera una nueva letra
				x3 = rand() % WIDTH + 1; // Reinicia la posición en x
				y3 = 3;
				contadorAciertos++;
			}
			else {
				contadorFallos++;
			}
			
		}
		
		//verificamos si la letra ha llegado al borde de la pantalla
		if (y1 == HEIGHT) {
			printf("\b \b"); // Borra la letra si se llego al final de la pantalla 
			x1 = rand() % WIDTH + 1; // Reinicia la posición en x
			y1 = 3;
			contadorFallos++;
		}else if(y2== HEIGHT){
			printf("\b \b"); // Borra la letra si se llego al final de la pantalla 
			x2 = rand() % WIDTH + 1; // Reinicia la posición en x
			y2 = 3;
			contadorFallos++;
		}else if(y3==HEIGHT){
			printf("\b \b"); // Borra la letra si se llego al final de la pantalla 
			x3 = rand() % WIDTH + 1; // Reinicia la posición en x
			y3 = 3;
			contadorFallos++;
		}
		
		//verificamos si debemos terminar el juego, cambiamos el estado del while 
		if (contadorAciertos == 5) {
			partida = false;
			ganar=true;
		}
		else if (contadorFallos == 10) {
			printf("Lo lamento ha perdido");
			partida = false;
			perder= true;
		}
		
		clearFrame(x1, y1);
		clearFrame(x2, y2);
		clearFrame(x3, y3);
		y1++;
		y2++;
		y3++;
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

