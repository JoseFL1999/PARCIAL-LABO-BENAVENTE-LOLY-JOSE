/*
 * biblio.c
 *
 *  Created on: 19 may 2022
 *      Author: --
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "biblioPersonal.h"
#include "biblioCENSO.h"

int initVivienda(eVivienda* list,int len)
{
	int ret;
	int i;
	ret=-1;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			(list+i)->isEmpty=1;// isEmpty=1
		}
		ret=0;
	}

	return ret;
}

int hardCodedCensista(eCensista* list, int len)
{
	int ret;
	ret=-1;
	if(list!=NULL && len>0)
	{
		(list+0)->idCensista=100;
		strcpy((list+0)->name,"Ana");
		(list+0)->age = 34;
		strcpy((list+0)->telefono,"1203-2345");
		(list+0)->isEmpty=0;

		(list+1)->idCensista=101;
		strcpy((list+1)->name,"Juan");
		(list+1)->age = 24;
		strcpy((list+1)->telefono,"4301-54678");
		(list+1)->isEmpty=0;

		(list+2)->idCensista=102;
		strcpy((list+2)->name,"Sol");
		(list+2)->age = 47;
		strcpy((list+2)->telefono,"5902-37487");
		(list+2)->isEmpty=0;
		ret=0;
	}
	return ret;
}

int hardCodedTypeVivienda(eTypeVivienda* list, int len)
{
	int ret;
	ret=-1;
	if(list!=NULL && len>0)
	{
		(list+0)->idTypeVivienda=1;
		strcpy((list+0)->description,"CASA");
		(list+1)->idTypeVivienda=2;
		strcpy((list+1)->description,"DEPARTAMENTO");
		(list+2)->idTypeVivienda=3;
		strcpy((list+2)->description,"CASILLA");
		(list+3)->idTypeVivienda=4;
		strcpy((list+3)->description,"RANCHO");
		ret=0;
	}
		return ret;
}

int thereAreVivienda(eVivienda* list, int lenVivienda)
{
	int ret;
	int i;
	ret=-1;
	if(list!=NULL && lenVivienda>0)
	{
		for(i=0;i<lenVivienda;i++)
		{
			if((list+i)->isEmpty==0) //compare if id exist
			{
				ret=0;
				break;
			}
		}
	}
	return ret;// return 0 if not errors or -1 if exist error
}

int findIdVivienda(eVivienda* list, int len, int id)
{
	int ret;
	int i;
	ret=-1;
	if(list!=NULL && len>0 && id>=20000)
	{
		for(i=0; i<len; i++)
		{
			if((list+i)->idVivienda == id && (list+i)->isEmpty == 0)//compare if id exist and id it is active
			{
				ret=i;
				break;
			}
		}
	}
	return ret;//return position array of the id
}

int findIdCencista(eCensista* list, int len, int id)
{
	int i;
	int ret;
	ret=-1;
	if(list!=NULL && len>0 && id>=100)
	{
		for(i=0; i<len; i++)
		{
			if((list+i)->idCensista == id && (list+i)->isEmpty == 0)//compare if id exist and id it is active
			{
				ret=i;
				break;
			}
		}
	}
	return ret;//return position array of the id
}

int getStreet(char* street,char* message, char* messageError, int retry)
{
	int ret;
	char bufferStreet[25];
	ret=-1;
	if(street!=NULL && message!=NULL && messageError!=NULL && retry>0)
	{
		system("cls");
		printf(message);
		fflush(stdin);
		gets(bufferStreet);
		while(isAlphanumeric(bufferStreet)==0 || strlen(bufferStreet)<1 || strlen(bufferStreet)>25)
		{
			system("cls");
			printf(messageError);
			fflush(stdin);
			gets(bufferStreet);
			retry--;
			if(retry==0)
			{
				break;
			}
		}
		if(isAlphanumeric(bufferStreet)!=0)
		{
			if(convertWordFirstUppAndRestLower(bufferStreet)==0)
			{
				strcpy(street, bufferStreet);
				ret=0;
			}
		}
	}
	return ret; // return -1
}

int printListCensista(eCensista* list, int lenCencista)
{
	int ret;
	int i;
	ret=-1;
	if(list!=NULL && lenCencista>0)
	{
		system("cls");
		printf("            CENCISTAS\n");
		printf("***************************************\n");
		printf("|LEGAJO|  |NOMBRE|  |EDAD|   |TELEFONO|\n");
		for(i=0;i<lenCencista;i++)
		{
			if((list+i)->isEmpty==0)
			{
				printf("  %-3d      %-5s      %-2d      %-10s\n",(list+i)->idCensista, (list+i)->name, (list+i)->age, (list+i)->telefono);

			}
		}
		printf("***************************************\n");
		ret=0;
	}
	return ret;
}

int printListVivienda(eVivienda* listVivienda, int lenVivienda, eCensista* listCensista, int lenCensista, eTypeVivienda* listTypeVivienda, int lenTypeVivienda)
{
	int ret;
	int i;
	int j;
	int k;
	ret=-1;
	if(listVivienda!=NULL&& listCensista!=NULL && listTypeVivienda!=NULL && lenVivienda>0 && lenCensista>0 && lenTypeVivienda>0)
	{
		printf("                                 LISTA DE VIVIENDAS\n");
		printf("******************************************************************************************************\n");
		printf("| ID |      | CALLE |         | C. PERSONAS |  | C. HABITACIONES |  | TIPO DE VIVIENDA |  | CENSISTA |\n");
		for(i=0;i<lenVivienda;i++)
		{
			if((listVivienda+i)->isEmpty==0)
			{
				for(j=0;j<lenTypeVivienda;j++)
				{
					if((listVivienda+i)->idTypeVivienda == (listTypeVivienda+j)->idTypeVivienda)
					{
						for(k=0;k<lenCensista;k++)
						{
							if((listVivienda+i)->idCensista == (listCensista+k)->idCensista)
							{
								printf("%-5d        %-25s%-2d               %-2d             %-12s          %-6s\n",(listVivienda+i)->idVivienda,
																					(listVivienda+i)->street, (listVivienda+i)->amountPersons,
																					(listVivienda+i)->amountRoom, (listTypeVivienda+j)->description,
																					(listCensista)->name);

								break;

							}
						}
					}
				}
			}
		}
		printf("******************************************************************************************************\n");
		ret=0;
	}


	return ret;
}

int getIdCencista(eCensista*list, int lenCencista, int* idCensista)
{
	int ret;
	int countError;
	char auxIdCencista[5];
	countError=0;
	ret=-1;
	if(list!=NULL && lenCencista>0)
	{
		do{
			system("cls");
			if(printListCensista(list,lenCencista)==0)
			{
				if(countError==0)
				{
					printf("Ingrese legajo del cencista: ");
					fflush(stdin);
					gets(auxIdCencista);
					countError++;
				}
				else
				{
					printf("Error ingrese un legajo valido del cencista: ");
					fflush(stdin);
					gets(auxIdCencista);
				}
			}
		}while(isNum(auxIdCencista)==0 || findIdCencista(list,lenCencista,atoi(auxIdCencista))==-1);
		if(isNum(auxIdCencista)!=0 || findIdCencista(list,lenCencista,atoi(auxIdCencista))!=-1)
		{
			*idCensista = atoi(auxIdCencista);
			ret=0;
		}
	}


	return ret;
}

int getIdVivienda(eVivienda* listVivienda, int lenVivienda, eCensista* listCensista, int lenCensista, eTypeVivienda* listTypeVivienda, int lenTypeVivienda, int* position)
{
	int ret;
	int countError;
	char id[7];
	countError=0;
	ret=-1;
	if(listVivienda!=NULL&& listCensista!=NULL && listTypeVivienda!=NULL && position!=NULL && lenVivienda>0 && lenCensista>0 && lenTypeVivienda>0)
	{
		do
		{
			system("cls");
			if(printListVivienda(listVivienda, lenVivienda, listCensista, lenCensista, listTypeVivienda, lenTypeVivienda)==0)
			{
				if(countError==0)
				{
					printf("\nIngrese el ID VIVIENDA(o escriba 's' para salir):");
					fflush(stdin);
					gets(id);
					if((*id==83 || *id ==115 )&& strlen(id)==1)
					{
						*position=-1;
						ret=0;
						break;
					}
					countError++;
				}
				else
				{
					printf("\nError ingrese un ID VIVIENDA valido(o escriba 's' para salir): ");
					fflush(stdin);
					gets(id);
					if((*id==83 || *id ==115 )&& strlen(id)==1)
					{
						*position=-1;
						ret=0;
						break;
					}
				}

			}
		}while(isNum(id)==0 || findIdVivienda(listVivienda, lenVivienda, atoi(id))==-1);
		if(isNum(id)!=0 || findIdVivienda(listVivienda, lenVivienda, atoi(id))!=-1)
		{
			*position = findIdVivienda(listVivienda, lenVivienda, atoi(id));
			ret=0;
		}
	}
	return ret;
}

int getDataVivienda(eCensista* list,int lenCencista, char* street, int* amountPersons, int* amountRoom, int* idTypeVivienda, int* legajoCensista)
{
	int ret;
	ret=-1;
	if(street!=NULL && lenCencista>0)
	{
		if(getStreet(street,"Ingrese la calle: ","Error, ingrese una calle valida:",100) == 0)
		{
			if(getMenuForInt(amountPersons,"Ingrese la cantidad de personas que residen en la vivienda: ",
												"Ingrese una cantidad valida de personas que residen en la vivienda:",30,0) == 0)
			{
				if(getMenuForInt(amountRoom,"Ingrese la cantidad de habitaciones de la vivienda:",
												"Ingrese una cantidad valida de habitaciones de la vivienda: ",15,0) == 0)
				{
					if(getMenuForInt(idTypeVivienda,"1. CASA \n2. DEPARTAMENTO \n3. CASILLA \n4. RANCHO \nElija el tipo de vivienda: ",
														"1. CASA \n2. DEPARTAMENTO \n3. CASILLA \n4. RANCHO \nError, elija una opcion valida de tipo de vivienda:",
														4,1) == 0)
					{
						if(getIdCencista(list, lenCencista,legajoCensista) == 0)
						{
							ret=0;
						}
						else
						{
							printf("ERROR F GETIDCENCISTA");
						}

					}
					else
					{
						printf("ERROR F GETIDTYPEVIVIENDA");
					}
				}
				else
				{
					printf("ERROR F GETAMOUNTROOM");
				}
			}
			else
			{
				printf("ERROR F GETAMOUNTPERSONS");
			}
		}
		else
		{
			printf("ERROR F GETSTREET");
		}
	}

	return ret;
}

int addDataVivienda(eVivienda* list, int lenVivienda, int* idVivienda, char* street, int amountPersons, int amountRoom, int idTypeVivienda, int idCensista)
{
	int ret;
	int i;
	ret=-1;
	if(list!=NULL && lenVivienda>0 && street!=NULL && idVivienda!=NULL)
	{
		for(i=0;i<lenVivienda;i++)
		{
			if((list+i)->isEmpty==1)
			{
				(list+i)->idVivienda = *idVivienda;
				strcpy((list+i)->street,street);
				(list+i)->amountPersons = amountPersons;
				(list+i)->amountRoom = amountRoom;
				(list+i)->idTypeVivienda = idTypeVivienda;
				(list+i)->idCensista = idCensista;
				(list+i)->isEmpty = 0;
				*idVivienda=*idVivienda+1;
				ret=0;
				break;
			}
		}
	}
	return ret;
}

int subMenuModify(eVivienda* list, int len, int position)
{
	int ret;
	int option;
	ret=-1;
	if(list!=NULL && len>0)
	{
		do{
			if(getMenuForInt(&option,"1. MODIFICAR CALLE \n2. MODIFICAR CANTIDAD DE PERSONAS \n3. MODIFICAR CANTIDAD DE HABITACION "
									"\n4. MODIFICAR TIPO DE VIVIENDA \n5. SALIR \nElija una opcion: ","1. MODIFICAR CALLE \n2. MODIFICAR CANTIDAD DE PERSONAS "
									"\n3. MODIFICAR CANTIDAD DE HABITACION \n4. MODIFICAR TIPO DE VIVIENDA \n5. SALIR \nError, elija una opcion valida: ",5,1)==0)
			{
				switch(option)
				{
					case 1:
						if(getStreet((list+position)->street,"Ingrese la nueva calle:", "Error ingrese una calle valida: ", 100)==0)
						{
							printf("\nCalle modificada con exito.\n");
							system("pause");
						}
						else
						{
							printf("\nError, no se pudo modificar la calle.\n");
							system("pause");
						}
						break;
					case 2:
						if(getMenuForInt(&(list+position)->amountPersons,"Ingrese la nueva cantidad de personas", "Error ingrese una cantidad de personas valida: ",30,0)==0)
						{
							printf("\nCantidad de personas modificada con exito.\n");
							system("pause");
						}
						else
						{
							printf("\nError, no se pudo modificar la cantidad de personas.");
							system("pause");
						}
						break;
					case 3:
						if(getMenuForInt(&(list+position)->amountRoom,"Ingrese la nueva cantidad de habitaciones", "Error ingrese una cantidad de habitaciones valida: ",15,0)==0)
						{
							printf("\nCantidad de habitaciones modificada con exito.\n");
							system("pause");
						}
						else
						{
							printf("\nError, no se pudo modificar la cantidad de habitaciones.");
							system("pause");
						}
						break;
					case 4:
						if(getMenuForInt(&(list+position)->idTypeVivienda,"1. CASA \n2. DEPARTAMENTO \n3. CASILLA \n4. RANCHO \nElija el nuevo tipo de vivienda: ",
																				"1. CASA \n2. DEPARTAMENTO \n3. CASILLA \n4. RANCHO "
																				"\nError, elija una opcion valida de tipo de vivienda:",
																				4,1) == 0)
						{
							printf("\nTipo de vivienda modificado con exito.\n");
							system("pause");
						}
						else
						{
							printf("\nError, no se pudo modificar el tipo de vivienda.");
							system("pause");
						}
						break;
					default:
						break;

				}
			}
		}while(option!=5);
		ret=0;
	}
	return ret;
}

int removeVivienda(eVivienda* list, int lenVivienda, int position)
{
	int ret;
	ret=-1;
	if(list!=NULL && lenVivienda>0 && position>=0)
	{
		(list+position)->isEmpty=1;
		ret=0;
	}
	return ret;
}

int removeViviendaWithValidate(eVivienda* list, int lenVivienda, int position)
{
	int ret;
	int countError;
	char option[10];
	int optionInt;
	countError=0;
	ret=-1;
	if(list!=NULL && lenVivienda>0 && position>=0)
	{
		do
		{
			if(countError==0)
			{
				system("cls");
				printf("ESTA SEGURO QUE DESEA DAR DE BAJA A LA VIVIENDA :\n");
				printf("***************************\n");
				printf("| ID |      | CALLE |  \n");
				printf("%-5d        %-25s\n",(list+position)->idVivienda,(list+position)->street);
				printf("***************************\n");
				printf("\n1. SI \n2. CANCELAR BAJA");
				printf("\nElija una opcion: ");
				gets(option);
				countError++;
			}
			else
			{
				system("cls");
				printf("ESTA SEGURO QUE DESEA DAR DE BAJA  A LA VIVIENDA: \n");
				printf("***************************\n");
				printf("| ID |      | CALLE |  \n");
				printf("%-5d        %-25s\n",(list+position)->idVivienda,(list+position)->street);
				printf("***************************\n");
				printf("\n1. SI \n2. CANCELAR BAJA");
				printf("\nError, elija una opcion valida: ");
				gets(option);
			}

		}while(isNum(option)==0 || atoi(option)>2 || atoi(option)<1);
		optionInt=atoi(option);
		switch(optionInt)
		{
			case 1:
				if(removeVivienda(list,lenVivienda,position)==0)
				{
					system("cls");
					printf("El ID %d fue dado de baja correctamente\n",(list+position)->idVivienda);
					system("pause");
				}
				else
				{
					system("cls");
					printf("No se pudo dar de baja al ID %d\n",(list+position)->idVivienda);
					system("pause");
				}
				break;
			case 2:
				system("cls");
				printf("Baja cancelada con exito\n");
				system("pause");
				break;
		}
		ret=0;
	}
	return ret;
}

int sortViviendaByStreet(eVivienda* listVivienda, int lenVivienda)
{
	int ret;
	int i;
	int flag1;
	int flag2;
	eVivienda aux;
	flag1=1;
	flag2=1;
	ret=-1;
	if(listVivienda!=NULL && lenVivienda>0)
	{
		while(flag1==1)
		{
			flag1=0;
			for(i=1;i<lenVivienda;i++)
			{

				if(strcmp((listVivienda+i)->street, (listVivienda+i-1)->street)<0)
				{
					aux = *(listVivienda+i);
					*(listVivienda+i) = *(listVivienda+i-1);
					*(listVivienda+i-1) = aux;
					flag1=1;
				}
			}
		}
		while(flag2==1)
		{
			flag2=0;
			for(i=1;i<lenVivienda;i++)
			{
				if(strcmp((listVivienda+i)->street, (listVivienda+i-1)->street)==0)
				{
					if((listVivienda+i)->amountPersons < (listVivienda+i-1)->amountPersons)
					{
						aux = *(listVivienda+i);
						*(listVivienda+i) = *(listVivienda+i-1);
						*(listVivienda+i-1) = aux;
						flag2=1;
					}
				}
			}

		}
		ret=0;
	}
	return ret;
}

int printListViviendaByStreet(eVivienda* listVivienda, int lenVivienda, eCensista* listCensista, int lenCensista, eTypeVivienda* listTypeVivienda, int lenTypeVivienda)
{
	int ret;
	int i;
	ret=-1;
	eVivienda bufferList[lenVivienda];
	if(listVivienda!=NULL&& listCensista!=NULL && listTypeVivienda!=NULL && lenVivienda>0 && lenCensista>0 && lenTypeVivienda>0)
	{
		for(i=0;i<lenVivienda;i++)
		{
			*(bufferList+i) = *(listVivienda+i);
		}
		if(sortViviendaByStreet(bufferList,lenVivienda)==0)
		{
			if(printListVivienda(bufferList, lenVivienda, listCensista, lenCensista, listTypeVivienda, lenTypeVivienda)==0)
			{
				ret=0;
			}
		}
	}

	return ret;
}

int printListViviendaForCensista(eVivienda* listVivienda, int lenVivienda, eCensista* listCensista, int lenCensista, eTypeVivienda* listTypeVivienda, int lenTypeVivienda, int idCensista)
{
	int ret;
	int i;
	int j;
	int k;
	ret=-1;
	if(listVivienda!=NULL&& listCensista!=NULL && listTypeVivienda!=NULL && lenVivienda>0 && lenCensista>0 && lenTypeVivienda>0)
	{
		printf("| ID VIVIENDA |      | CALLE |         | C. PERSONAS |  | C. HABITACIONES |  | TIPO DE VIVIENDA | \n");
		for(i=0;i<lenVivienda;i++)
		{
			if((listVivienda+i)->isEmpty==0)
			{
				for(j=0;j<lenTypeVivienda;j++)
				{
					if((listVivienda+i)->idTypeVivienda == (listTypeVivienda+j)->idTypeVivienda)
					{
						for(k=0;k<lenCensista;k++)
						{
							if(((listVivienda+i)->idCensista == (listCensista+k)->idCensista )&& (listCensista+k)->idCensista == idCensista)
							{
								printf("%-5d                %-25s%-2d               %-2d             %-12s         \n",(listVivienda+i)->idVivienda,
																					(listVivienda+i)->street, (listVivienda+i)->amountPersons,
																					(listVivienda+i)->amountRoom, (listTypeVivienda+j)->description);
								ret=0;
								break;

							}
						}
					}
				}
			}
		}
		printf("******************************************************************************************************\n");

	}


	return ret;
}

int printListCensistaWithVivienda(eVivienda* listVivienda, int lenVivienda, eCensista* listCensista, int lenCensista, eTypeVivienda* listTypeVivienda, int lenTypeVivienda)
{
	int ret;
	int i;
	ret=-1;
	if(listVivienda!=NULL&& listCensista!=NULL && listTypeVivienda!=NULL && lenVivienda>0 && lenCensista>0 && lenTypeVivienda>0)
	{
		system("cls");
		for(i=0;i<lenCensista;i++)
		{
			printf("\n%d-%s  %d años  tel:%s\n\n",(listCensista+i)->idCensista,(listCensista+i)->name, (listCensista+i)->age ,(listCensista+i)->telefono);
			if(printListViviendaForCensista(listVivienda, lenVivienda, listCensista, lenCensista, listTypeVivienda, lenTypeVivienda, (listCensista+i)->idCensista)!=0)
			{
				printf("NO TIENE NINGUNA VIVIENDA CENSADA\n\n");
			}
		}
		ret=0;

	}
	return ret;
}


