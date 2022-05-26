/*
 ============================================================================
 Name        : PARCIAL.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ===================     =========================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioPersonal.h"
#include "biblioCENSO.h"

#define QTY_CENSISTA 3
#define QTY_VIVIENDA 15
#define QTY_TYPEVIVIENDA 4
int main(void) {
	setbuf(stdout,NULL);
	eTypeVivienda aTypeVivienda[QTY_TYPEVIVIENDA];
	eCensista aCensista[QTY_CENSISTA];
	eVivienda aVivienda[QTY_VIVIENDA];
	char option;
	int idVivienda;
	char auxStreet[25];
	int auxAmountPersons;
	int auxAmountRoom;
	int auxIdTypeVivienda;
	int auxIdCensista;
	int positionModify;
	int positionRemove;
	idVivienda=20000;
	if(initVivienda(aVivienda, QTY_VIVIENDA) == 0
			&& hardCodedCensista(aCensista, QTY_CENSISTA)==0
			&& hardCodedTypeVivienda(aTypeVivienda, QTY_TYPEVIVIENDA)==0)
	{
		do{
			if(getMenuForChar(&option,	"A. ALTA VIVIENDA \nB. MODIFICAR VIVIENDA \nC. BAJA VIVIENDA \nD. LISTAR VIVIENDAS "
					"\nE. LISTAR CENSISTAS \nF. LISTA CENSISTA CON VIVIENDAS CENSADAS \nG. SALIR \nElija una opcion: ",
					"A. ALTA VIVIENDA \nB. MODIFICAR VIVIENDA \nC. BAJA VIVIENDA"
					"\nD. LISTAR VIVIENDAS \nE. LISTAR CENSISTAS\nF. LISTA CENSISTA CON VIVIENDAS CENSADAS\nG. SALIR "
					"\nElija una opcion valida :" , 71,65)==0)
			{
				switch(option)
				{
				case 'A'://ALTA VIVIENDA
					if(getDataVivienda(aCensista, QTY_CENSISTA, auxStreet, &auxAmountPersons, &auxAmountRoom, &auxIdTypeVivienda, &auxIdCensista) == 0)
					{
						if(addDataVivienda(aVivienda, QTY_VIVIENDA, &idVivienda, auxStreet, auxAmountPersons, auxAmountRoom, auxIdTypeVivienda, auxIdCensista) == 0)
						{
							system("cls");
							printf("ALTA EXITOSA\n");
							system("pause");
						}
						else
						{
							system("cls");
							printf("ERROR NO SE CARGARON LOS DATOS\n");
							system("pause");
						}
					}
					else
					{
						system("cls");
						printf("ERROR NO SE TOMO LOS DATOS.\n");
						system("pause");

					}
					break;
				case 'B'://MODIFICAR VIVIENDA
					if(thereAreVivienda(aVivienda, QTY_VIVIENDA)==0)
					{
						if(getIdVivienda(aVivienda, QTY_VIVIENDA, aCensista, QTY_CENSISTA, aTypeVivienda, QTY_TYPEVIVIENDA, &positionModify) == 0)
						{
							if(positionModify==-1)
							{
								break;
							}
							if(subMenuModify(aVivienda, QTY_VIVIENDA, positionModify)!=0)
							{
								system("cls");
								printf("ERROR SUBMENUMODIFY\n");
								system("pause");
							}
						}
						else
						{
							system("cls");
							printf("ERROR F B SUBMENUMODIFY\n");
							system("pause");
						}
					}
					else
					{
						system("cls");
						printf("ERROR NO HAY VIVIENDAS CARGADAS\n");
						system("pause");
					}
					break;
				case 'C'://BAJA VIVIENDA
					if(thereAreVivienda(aVivienda, QTY_VIVIENDA)==0)
					{
						if(getIdVivienda(aVivienda, QTY_VIVIENDA, aCensista, QTY_CENSISTA, aTypeVivienda, QTY_TYPEVIVIENDA, &positionRemove) == 0)
						{
							if(positionRemove==-1)
							{
								break;
							}
							if(removeViviendaWithValidate(aVivienda, QTY_VIVIENDA, positionRemove)!=0)
							{
								system("cls");
								printf("ERROR F C REMOVEVIVIENDAWITH\n");
								system("pause");
							}
						}
						else
						{
							system("cls");
							printf("ERROR F C SUBMENUMODIFY\n");
							system("pause");
						}
					}
					else
					{
						system("cls");
						printf("ERROR NO HAY VIVIENDAS CARGADAS\n");
						system("pause");
					}
					break;
				case 'D'://LISTA VIVIENDAS
					if(thereAreVivienda(aVivienda, QTY_VIVIENDA)==0)
					{
						system("cls");
						if(printListViviendaByStreet(aVivienda, QTY_VIVIENDA, aCensista, QTY_CENSISTA, aTypeVivienda, QTY_TYPEVIVIENDA)==0)
						{
							system("pause");
						}
						else
						{
							system("cls");
							printf("ERROR F D PRINTLIST\n");
							system("pause");
						}
					}
					else
					{
						system("cls");
						printf("ERROR NO HAY VIVIENDAS CARGADAS\n");
						system("pause");
					}
					break;
				case 'E'://LISTA CENSISTAS
					if(printListCensista(aCensista, QTY_CENSISTA)==0)
					{
						system("pause");
					}
					else
					{
						system("cls");
						printf("ERROR F E PRINTLISTCENSISTA\n");
						system("pause");
					}
					break;
				case 'F':// PRINT LIST CENSISTA CON VIVIENDA CENSADA
					if(printListCensistaWithVivienda(aVivienda, QTY_VIVIENDA, aCensista, QTY_CENSISTA, aTypeVivienda, QTY_TYPEVIVIENDA)==0)
					{
						system("pause");
					}
					else
					{
						system("cls");
						printf("ERROR F F PRINTLISTCENSISTAWITHVIVIENDA\n");
						system("pause");

					}
					break;
				}
			}
		}while(option!='G');
	}
	else
	{
		printf("ERROR INIT\n");
		system("pause");
	}


	return 0;
}
