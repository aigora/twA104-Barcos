//#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>
#include "SerialClass.h"
#define COLUM 19
#define FIL 19
#define N 30
#define DIM 30
using namespace std;


int PantallaBienvenida();//primera pantalla al abrir el juego
void ComprobarCorreo(char[], int, int, int);//comprobacion del correo electronico
void Correo(int, int);//introduce un correo electronico
void FicheroJugadores(char[], int, int, int *, int);//creacion de fichero con los datos de los jugadores
int seleccion_n_2(int p);////funcion para la seleccion del segundo numero
void Tablero();//imprime en pantalla un tablero para que elijan la opcion 

void main()
{
	// Puerto serie.
	//Puerto_serie->Open();
	//Notese que antes hay que asignarle al COM 3 una cadena para poder usarla con el serial port
	char port[] = "COM3";
	Serial* Puerto = new Serial(port);
	//Puerto->IsConnected();
	char AGUA1[] = "AGUA1", AGUA2[] = "AGUA2", AGUA3[] = "AGUA3", AGUA4[] = "AGUA4", AGUA5[] = "AGUA5", AGUA6[] = "AGUA6", AGUA7[] = "AGUA7", AGUA8[] = "AGUA8", AGUA9[] = "AGUA9"; // Envía "Luz_ON" al puerto serie.
	char TOCADO1[] = "TOCADO1", TOCADO2[] = "TOCADO2", TOCADO3[] = "TOCADO3", TOCADO4[] = "TOCADO4", TOCADO5[] = "TOCADO5", TOCADO6[] = "TOCADO6", TOCADO7[] = "TOCADO7", TOCADO8[] = "TOCADO8", TOCADO9[] = "TOCADO9";
	char FIN[] = "FIN";
	char lectura[50] = "\0"; // Guardan datos de entrada del puerto.
	int partidas_perdidas = 0, partidas_ganadas = 0;
	int  p1 = 0, i, j, numero, y, m, n, cont = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0, opc, a, verificar = 0, verificar2 = 0, contador = 0, contador2 = 0, suma=0;
	int matriz[3][3] = { { 0,0,0 },{ 0,0,0 },{ 0,0,0 } };

	int opci;

	opci = PantallaBienvenida();

	if (opci == 1)
	{
		Tablero();
		do {
			for (m = 0; m < 3; m++)
			{
				for (n = 0; n < 3; n++)
				{
					y = matriz[m][n];
					if (y == 1)
						contador2++;
				}
			}
			if (contador2 == 0) {
				do {
					printf("Elige el primer cuadrado donde posicionar el barco\n");
					scanf_s("%d", &numero);
				} while (numero >= 9 && numero <= 1);

			}
			else {
				numero = seleccion_n_2(numero);
			}


			switch (numero)
			{
			case 1: matriz[0][0] = 1;
				break;
			case 2: matriz[0][1] = 1;
				break;
			case 3: matriz[0][2] = 1;
				break;
			case 4: matriz[1][0] = 1;
				break;
			case 5: matriz[1][1] = 1;
				break;
			case 6: matriz[1][2] = 1;
				break;
			case 7: matriz[2][0] = 1;
				break;
			case 8: matriz[2][1] = 1;
				break;
			case 9: matriz[2][2] = 1;
				break;
			}
		} while (contador2 < 1);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("%d\t", matriz[i][j]);
			}
			printf("\n");
		}
		do {
			printf("Cuando estes listo y quieres empezar el juego pulsa 1:\n");
			scanf_s("%d", &a);
		} while (a != 1);

		system("CLS");
		printf("Empieza el juego:\n");
		printf("Introduce la posicion : \n");

		do {
			do
			{
				printf("Selecciona la coordenada del punto :\n");
				scanf_s("%d", &p1);
				if (p1 >= 1 && p1 <= 9)
					verificar2++;
				else
					printf("La coordenada no es correcta, vuelve a introducirla \n");
			} while (verificar2 < 1);

			switch (p1)
			{
			case 1:
			{
				if (matriz[0][0] == 1)
				{
					Puerto->WriteData(TOCADO1, sizeof(TOCADO1) - 1);
					cont++;
					c1=1;
					printf("Tocado\n");
				}
				if (matriz[0][0] == 0)
				{
					Puerto->WriteData(AGUA1, sizeof(AGUA1) - 1);
					printf("Agua\n");
				}
				break;
			}
			case 2:
			{
				if (matriz[0][1] == 1)
				{
					Puerto->WriteData(TOCADO2, sizeof(TOCADO2) - 1);
					cont++;
					c2=1;
					printf("Tocado\n");
				}
				if (matriz[0][1] == 0)
				{
					Puerto->WriteData(AGUA2, sizeof(AGUA2) - 1);
					printf("Agua\n");
				}
				break;
			}
			case 3:
			{
				if (matriz[0][2] == 1)
				{
					Puerto->WriteData(TOCADO3, sizeof(TOCADO3) - 1);
					cont++;
					c3 = 1;
					printf("Tocado\n");
				}
				if (matriz[0][2] == 0)
				{
					Puerto->WriteData(AGUA3, sizeof(AGUA3) - 1);
					printf("Agua\n");
				}
				break;
			}
			case 4:
			{
				if (matriz[1][0] == 1)
				{
					Puerto->WriteData(TOCADO4, sizeof(TOCADO4) - 1);
					cont++;
					c4 = 1;
					printf("Tocado\n");
				}
				if (matriz[1][0] == 0)
				{
					Puerto->WriteData(AGUA4, sizeof(AGUA4) - 1);
					printf("Agua\n");
				}
				break;
			}
			case 5:
			{
				if (matriz[1][1] == 1)
				{
					Puerto->WriteData(TOCADO5, sizeof(TOCADO5) - 1);
					cont++;
					c5 = 1;
					printf("Tocado\n");
				}
				if (matriz[1][1] == 0)
				{
					Puerto->WriteData(AGUA5, sizeof(AGUA5) - 1);
					printf("Agua\n");
				}
				break;
			}
			case 6:
			{
				if (matriz[1][2] == 1)
				{
					Puerto->WriteData(TOCADO6, sizeof(TOCADO6) - 1);
					cont++;
					c6 = 1;
					printf("Tocado\n");
				}
				if (matriz[1][2] == 0)
				{
					Puerto->WriteData(AGUA6, sizeof(AGUA6) - 1);
					printf("Agua\n");
				}
				break;
			}
			case 7:
			{
				if (matriz[2][0] == 1)
				{
					Puerto->WriteData(TOCADO7, sizeof(TOCADO7) - 1);
					cont++;
					c7 = 1;
					printf("Tocado\n");
				}
				if (matriz[2][0] == 0)
				{
					Puerto->WriteData(AGUA7, sizeof(AGUA7) - 1);
					printf("Agua\n");
				}
				break;
			}
			case 8:
			{
				if (matriz[2][1] == 1)
				{
					Puerto->WriteData(TOCADO8, sizeof(TOCADO8) - 1);
					cont++;
					c8 = 1;
					printf("Tocado\n");
				}
				if (matriz[2][1] == 0)
				{
					Puerto->WriteData(AGUA8, sizeof(AGUA8) - 1);
					printf("Agua\n");
				}
				break;
			}
			case 9:
			{
				if (matriz[2][2] == 1)
				{
					Puerto->WriteData(TOCADO9, sizeof(TOCADO9) - 1);
					cont++;
					c9 = 1;
					printf("Tocado\n");
				}
				if (matriz[2][2] == 0)
				{
					Puerto->WriteData(AGUA9, sizeof(AGUA9) - 1);
					printf("Agua\n");
				}
				break;
			}


			}
			contador++;
			suma = c1 + c2 + c3 + c4 + c5 + c6 + c7 + c8 + c9;
			if (contador == 3 && cont == 0|| contador == 4 && cont == 1|| cont==3)
			{
				system("color 4C");
				printf("Ha perdido\n");
				partidas_perdidas++;
				break;
			}
			if (suma==2)
			{
				system("color 2A");
				printf("Ha ganado\n");
				partidas_ganadas++;
				break;
			}
		} while (cont < 3);

		Correo(partidas_ganadas, partidas_perdidas);
		Sleep(500);

		cin.ignore(256, '\n'); // Limpiar buffer del teclado.
		Puerto->WriteData(FIN, sizeof(FIN) - 1);
	}
	else
		exit(1);

	system("pause");

}

int seleccion_n_2(int p)
{
	int  n;

	switch (p)
	{
	case 1:
		do {
			printf("Solo puedes elegir el 2 y el 4\n");
			scanf_s("%d", &n);
		} while (n != 2 && n != 4);
		break;
	case 2:

		do {
			printf("Solo puedes elegir el 1,3 y el 5\n");
			scanf_s("%d", &n);
		} while (n != 1 && n != 3 && n != 5);
		break;
	case 3:

		do {
			printf("Solo puedes elegir el 2 y el 6\n");
			scanf_s("%d", &n);
		} while (n != 2 && n != 6);
		break;
	case 4:

		do {
			printf("Solo puedes elegir el 1,5 y el 7\n");
			scanf_s("%d", &n);
		} while (n != 1 && n != 5 && n != 7);
		break;
	case 5:

		do {
			printf("Solo puedes elegir el 2,4,6 y el 8\n");
			scanf_s("%d", &n);
		} while (n != 2 && n != 4 && n != 6 && n != 8);
		break;
	case 6:

		do {
			printf("Solo puedes elegir el 3,5 y el 9\n");
			scanf_s("%d", &n);
		} while (n != 3 && n != 5 && n != 9);
		break;
	case 7:

		do {
			printf("Solo puedes elegir el 4 y el 8\n");
			scanf_s("%d", &n);
		} while (n != 8 && n != 4);
		break;
	case 8:

		do {
			printf("Solo puedes elegir el 5,7 y el 9\n");
			scanf_s("%d", &n);
		} while (n != 5 && n != 7 && n != 9);
		break;
	case 9:

		do {
			printf("Solo puedes elegir el 6 y el 8\n");
			scanf_s("%d", &n);
		} while (n != 8 && n != 6);
		break;
	}
	return n;
}

int PantallaBienvenida()//Primera pantalla del juego .
{
	int opc;
	do
	{
		system("color B0");
		system("CLS");
		printf("\n\t\tHUNDE LA FLOTA \n\n\t\t\t");
		printf("| \n\t\t\t|) \n\t\t\t|)) \n\t\t\t|))) \n\t\t\t|))))\n\t\t     ___|____)___ \n\t\t    |___________/ \n\n\n");
		printf("\t\t1 - Nueva Partida.\n\t\t2 - Salir\n\n");
		scanf_s("%d", &opc);
		getchar();
	} while (opc != 1 && opc != 2);
	return opc;
}

void Correo(int a, int b)//Pide al usuario un correo electronico y verifica que este tenga un @ y al menos un punto despues del @ .
{
	char correo[DIM], *pcorreo;
	int l = 0, l2 = 0, i = 0, l3 = 0;
	pcorreo = &correo[0];
	do {
		printf("Introduce tu correo electronico:\n");
		getchar();
		gets_s(correo);
		while (*(pcorreo + i) != '\0')
		{
			if (*(pcorreo + i) == '@')
				l = i;
			if (*(pcorreo + i) == '.')
				l2 = i;
			if (l > 0 && l < l2)
				l3 = 1;
			i++;
		}
		i = 0;
	} while (l3 != 1);
	ComprobarCorreo(correo, DIM, a, b);

}

void ComprobarCorreo(char c[], int dim, int a, int b)//borra la pantalla y hace volver a introducir el correo electronico .
{//de esta manera aseguramos que introduzca el mismo , solamente tiene 3 intentos antes de cerrar el programa . 
	system("CLS");
	char correo2[DIM], *pcorreo2;
	int Dim, *pv;
	int l = 0, l2 = 0, i = 0, l3 = 0, opc, cont = 0;
	pcorreo2 = &correo2[0];
	printf("Comprobamos si ha introducido bien su correo electronico.\n");
	printf("Tienes 1 intentos para validarlo:\n");
	printf("Por favor ,\n");
	printf("Introduce tu correo electronico otra vez:\n");
	do {

		gets_s(correo2);
		while (*(pcorreo2 + i) != '\0')
		{
			if (*(pcorreo2 + i) == '@')
				l = i;
			if (*(pcorreo2 + i) == '.')
				l2 = i;
			if (l > 0 && l < l2)
				l3 = 1;
			i++;
		}
		i = 0;
		cont++;
	} while (l3 != 1 && cont != 1);
	opc = strcmp(c, correo2);
	if (opc == 0)
	{
		printf("Los correos son iguales.\n");
		size_t size;//guarda el tamaño de memoria utilizado
		printf("Procederamos a crear o validar una contrasegna UNICAMENTE numerica.\nPuede estar comprendida entre 1-10 numeros.\n");
		do
		{
			printf("Introduce la dimension.\n");
			scanf_s("%d", &Dim);
		} while (Dim < 1 || Dim > 10);
		pv = (int *)malloc(Dim * sizeof(int));
		size = _msize(pv);
		if (pv == NULL)
			exit(1);
		printf("Introduce UNO A UNO los numeros de tu contrasegna:\n");
		for (i = 0; i < Dim; i++)
		{
			printf("Numero %d :", i + 1);
			scanf_s("%d", (pv + i));
		}
		FicheroJugadores(correo2, a, b, pv, Dim);
	}
	else
	{
		printf("Ha superado el numero de intentos permitidos.\n");
		exit(1);
	}

}

void FicheroJugadores(char jug[], int partidas_ganadas, int partidas_perdidas, int *pv, int dim)//comprueba si tenemos ese correo en el .txt si es asi muestra por pantalla sus puntuaciones .
{//si no esta el correo electronico , escribe el actual e inicializa sus puntuaciones  para proximas partidas . 
	int partidas_ganadas_antiguas = 0, partidas_perdidas_antiguas = 0;
	int x, y;
	char correo[DIM];
	char contrasena2[10], contrasena[10];
	int opc, i = 0, opc2;
	int contador = 0;
	FILE *pjugadores, *p_aux;
	errno_t err, err2, error;
	x = partidas_ganadas + partidas_ganadas_antiguas;
	y = partidas_perdidas + partidas_perdidas_antiguas;

	err2 = fopen_s(&p_aux, "Auxiliar.txt", "w+");
	if (err2 == 0)
	{
		//printf("Apertura correcta.\n");
		for (i = 0; i < dim; i++)
		{
			fprintf_s(p_aux, "%d", *(pv + i));
		}
	}
	else
		printf("Apertura incorrecta del fichero auxiliar.\n");
	fclose(p_aux);

	err2 = fopen_s(&p_aux, "Auxiliar.txt", "r+");
	if (err2 == 0)
	{
		//printf("Apertura correcta.\n");
		while (!feof(p_aux))
		{
			fscanf_s(p_aux, "%s", contrasena, _countof(contrasena));
		}
	}
	else
		printf("Apertura incorrecta del fichero auxiliar.\n");

	err = fopen_s(&pjugadores, "RegistroPartidas.txt", "r+");
	if (err == 0)
	{
		//printf("Apertura correcta.\n\n");
		while (!feof(pjugadores))
		{
			fscanf_s(pjugadores, "%s %d %d %s", correo, _countof(correo), &partidas_ganadas_antiguas, &partidas_perdidas_antiguas, contrasena2, _countof(contrasena2));
			opc = strcmp(jug, correo);
			opc2 = strcmp(contrasena, contrasena2);
			if (opc == 0 )
			{
				if (opc2 == 0)
				{
					x = partidas_ganadas + partidas_ganadas_antiguas;
					y = partidas_perdidas + partidas_perdidas_antiguas;
					printf("Bienvenido de nuevo, usted ya ha jugado antes.\n");
					printf("Su correo electronico es :\n");
					puts(correo);
					printf("\n");
					printf("Sus estadisticas son:\n\n");
					printf("Tiene %d partidas ganadas.\n", x);
					printf("Y tiene %d partidas perdidas.\n", y);
					contador = strlen(correo);
					fseek(pjugadores, ftell(pjugadores) - contador - 5 - dim, SEEK_SET);
					fprintf_s(pjugadores, "%s %d %d %s", correo, x, y, contrasena2);
					break;
				}
				else
				{
					printf("Lo sentimos, ha introducido mal su contrasena.\nProcederemos a cerrar el juego.\n\n");
					break;
					
				}
			}

		}
		if (opc != 0 )
		{
			fprintf_s(pjugadores, "%s %d %d ", jug, x, y);
			for (i = 0; i < dim; i++)
			{
				fprintf_s(pjugadores, "%d", *(pv + i));
			}
			fprintf_s(pjugadores, "\n");
			printf("Bienvenido es su primera partida.\nGuardaremos sus datos para la proxima vez.\n");
			printf("Su correo electronico es :\n");
			puts(jug);
			printf("Su contrasegna esta formada por %d digitos.\n", dim);
			printf("\n");
			printf("Sus estadisticas son:\n\n");
			printf("Tiene %d partidas ganadas.\n", x);
			printf("Y tiene %d partidas perdidas.\n", y);
		}

	}
	if (err != 0)
	{
		error = fopen_s(&pjugadores, "RegistroPartidas.txt", "w+");
		//printf("Apertura correcta.\n\n");
		fprintf_s(pjugadores, "%s %d %d ", jug, x, y);
		for (i = 0; i < dim; i++)
		{
			fprintf_s(pjugadores, "%d", *(pv + i));
		}
		fprintf_s(pjugadores, "\n");
		printf("Bienvenido es su primera partida.\nGuardaremos sus datos para la proxima vez.\n");
		printf("Su correo electronico es :\n");
		puts(jug);
		printf("Su contrasegna esta formada por %d digitos.\n", dim);
		printf("\n");
		printf("Sus estadisticas son:\n\n");
		printf("Tiene %d partidas ganadas.\n", x);
		printf("Y tiene %d partidas perdidas.\n", y);
	}

	fclose(pjugadores);
	fclose(p_aux);
}


void Tablero()
{
	system("color B0");
	int f, c, i = 1;
	for (f = 0; f < FIL; f++)
	{
		for (c = 0; c < COLUM; c++)
		{
			if (f == 0 || f == FIL - 1 || f == FIL * 2 / 3 || f == FIL / 3 || c == 0 || c == COLUM - 1 || c == COLUM * 2 / 3 || c == COLUM / 3)
				printf("%c", 219);
			else if (f == 3 && c == 3)
				printf("1");
			else if (f == 3 && c == 9)
				printf("2");
			else if (f == 3 && c == 15)
				printf("3");
			else if (f == 9 && c == 3)
				printf("4");
			else if (f == 9 && c == 9)
				printf("5");
			else if (f == 9 && c == 15)
				printf("6");
			else if (f == 15 && c == 3)
				printf("7");
			else if (f == 15 && c == 9)
				printf("8");
			else if (f == 15 && c == 15)
				printf("9");
			else
				printf(" ");
		}
		printf("\n");
	}
}


