/*
 * biblio.h
 *
 *  Created on: 19 may 2022
 *      Author: --
 */

#ifndef BIBLIOCENSO_H_
#define BIBLIOCENSO_H_
typedef struct{
	int idTypeVivienda;
	char description[15];
}eTypeVivienda;

typedef struct{
	int idCensista;
	char name[10];
	int age;
	char telefono[10];
	int isEmpty;
}eCensista;

typedef struct{
	int idVivienda;
	char street[25];
	int amountPersons;
	int amountRoom;
	int idTypeVivienda;
	int idCensista;
	int isEmpty;
}eVivienda;


int initVivienda(eVivienda* list,int len);
/// Inicializa el isEmpty en 1
/// @param list - array a inicializar
/// @param len - tamaño del arrray
/// @return retorna 0 si no hubo errores o -1 si hubo algun error

int hardCodedCensista(eCensista* list, int len);
/// Hardcodea los censistas
/// @param list -array a hardcodear
/// @param len - tamaño del array
/// @return retorna 0 si no hubo errores o -1 si hubo algun error

int hardCodedTypeVivienda(eTypeVivienda* list, int len);
/// Hardcodea los tipo de vivienda
/// @param list -array a hardcodear
/// @param len - tamaño del array
/// @return retorna 0 si no hubo errores o -1 si hubo algun error

int thereAreVivienda(eVivienda* list, int lenVivienda);
/// Busca si hay viviendas dado de alta (isEmpty==0)
/// @param list -array a buscar
/// @param len - tamaño del arrray
/// @return retorna 0 si hay alguna vivienda o -1 si hubo algun error o no hay viviendas

int findIdVivienda(eVivienda* list, int len,int id);
/// Busca el id de vivienda si existe
/// @param list -array a buscar
/// @param len - tamaño del arrray
/// @return retorna 0 si no hubo errores o -1 si hubo algun error

int findIdCencista(eCensista* list, int len, int id);
///Busca el id de censista si existe
/// @param list -array a buscar
/// @param len - tamaño del arrray
/// @return retorna 0 si no hubo errores o -1 si hubo algun error

int printListCensista(eCensista* list, int lenCensista);
/// Imprime la lista de censistas
/// @param list - array a imprimir
/// @param lenCensista -tamaño del array
/// @return retorna 0 si no hubo errores o -1 si hubo algun error

int printListVivienda(eVivienda* listVivienda, int lenVivienda, eCensista* listCensista, int lenCensista, eTypeVivienda* listTypeVivienda, int lenTypeVivienda);
///Imprime la lista de vivienda
/// @param listVivienda -array vivienda a imprimir
/// @param lenVivienda -tamaño array vivienda
/// @param listCensista -array censista a imprimir
/// @param lenCensista -tamaño array censista
/// @param listTypeVivienda -array tipo de vivienda a imprimir
/// @param lenTypeVivienda -tamaño array tipo de vivienda
/// @return retorna 0 si no hubo errores o -1 si hubo algun error
///

int getIdCencista(eCensista*list, int lenCensista, int* idCensista);
/// Obtener el id censista existente y validado
/// @param listCensista - array censista
/// @param lenCensista - tamaño array censista
/// @return retorna 0 si no hubo errores o -1 si hubo algun error

int getIdVivienda(eVivienda* listVivienda, int lenVivienda, eCensista* listCensista, int lenCensista, eTypeVivienda* listTypeVivienda, int lenTypeVivienda, int* position);
/// Obtener el id vivienda existente y validado
/// @param listVivienda
/// @param lenVivienda
/// @param listCensista
/// @param listTypeVivienda
/// @param lenTypeVivienda
/// @param position
/// @return retorna 0 si no hubo errores o -1 si hubo algun error

int getDataVivienda(eCensista* list,int lenCensista, char* street, int* amountPersons, int* amountRoom, int* idTypeVivienda, int* idCensista);
/// Funcion para obtener los datos de vivienda
/// @param list - array de censista
/// @param lenCensista - tamaño array censista
/// @param street - devuelve la calle
/// @param amountPersons - devuelve cantidad de personas
/// @param amountRoom - devuelve cantidad de habitaciones
/// @param idTypeVivienda - devuelve el id de tipo de vivienda
/// @param idCensista - devuelve el id del censista
/// @return retorna 0 si no hubo errores o -1 si hubo algun error

int addDataVivienda(eVivienda* list, int lenVivienda, int* idVivienda, char* street, int amountPersons, int amountRoom, int idTypeVivienda, int idCensista);
/// Agrega los datos de vivienda a una posicion libre del array
/// @param list -array de vivienda
/// @param lenVivienda - tamaño array vivienda
/// @param idVivienda - recibe id vivienda a agregar al array vivienda y devuelve otro id sumado +1
/// @param street - recibe calle y agrega al array vivienda
/// @param amountPersons - recibe cantidad personas y agrega al array vivienda
/// @param amountRoom - recibe cantidad habitaciones y agrega al array vivienda
/// @param idTypeVivienda - recibe id tipo  de vivienda y agrega al array vivienda
/// @param idCensista - recibe id censista y agrega al array vivienda
/// @return retorna 0 si no hubo errores o -1 si hubo algun error

int subMenuModify(eVivienda* list, int len, int position);
/// Sub menu para modificar vivienda
/// @param list - array vivienda
/// @param len - tamaño array vivienda
/// @param position - posicion del array a modificar
/// @return retorna 0 si no hubo errores o -1 si hubo algun error

int removeVivienda(eVivienda* list, int len, int position);
/// Da de baja la vivienda (isEmpty=1)
/// @param list - array vivienda
/// @param lenVivienda -tamaño array vivienda
/// @param position - posicion del array a dar de baja
/// @return retorna 0 si no hubo errores o -1 si hubo algun error


int removeViviendaWithValidate(eVivienda* list, int lenVivienda, int position);
/// Da de baja la vivienda con validacion del usuario si esta seguro
/// @param list -array vivienda
/// @param lenVivienda -tamaño array vivienda
/// @param position -posicion del array a dar de baja
/// @return retorna 0 si no hubo errores o -1 si hubo algun error

int sortViviendaByStreet(eVivienda* listVivienda, int lenVivienda);
/// Ordena la lista de vivienda por calle
/// @param listVivienda -array vivienda
/// @param lenVivienda -tamaño array vivienda
/// @return retorna 0 si no hubo errores o -1 si hubo algun error

int printListViviendaByStreet(eVivienda* listVivienda, int lenVivienda, eCensista* listCensista, int lenCensista, eTypeVivienda* listTypeVivienda, int lenTypeVivienda);
/// Imprime la lista de vivienda ordenado por calle
/// @param listVivienda -array vivienda
/// @param lenVivienda -tamaño array vivienda
/// @param listCensista -array censista
/// @param lenCensista -tamaño array censista
/// @param listTypeVivienda -array tipo de vivienda
/// @param lenTypeVivienda -tamaño array tipo de vivienda
/// @return retorna 0 si no hubo errores o -1 si hubo algun error

int printListViviendaForCensista(eVivienda* listVivienda, int lenVivienda, eCensista* listCensista, int lenCensista, eTypeVivienda* listTypeVivienda, int lenTypeVivienda, int idCensista);

int printListCensistaWithVivienda(eVivienda* listVivienda, int lenVivienda, eCensista* listCensista, int lenCensista, eTypeVivienda* listTypeVivienda, int lenTypeVivienda);

#endif /* BIBLIOCENSO_H_ */
