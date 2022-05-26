/*
 * PersonalBiblio.h
 *
 *  Created on: 19 may 2022
 *      Author: --
 */

#ifndef BIBLIOPERSONAL_H_
#define BIBLIOPERSONAL_H_

int isNum(char* string);
/// Function valid if a string is only numbers
/// @param string -string to validate
/// @return returns 0 if the string is not numbers or 1 if it is numbers

int isFloat(char* string);
/// Function valid if a string is only float
/// @param string -string to validate
/// @return returns 0 if the string is not float or 1 if it is float

int isText(char* string);
/// Function valid if a string is only text
/// @param string  -string to validate
/// @return returns 0 if the string is not text or 1 if it is text

int isAlphanumeric(char *string);
/// Function valid if a string is alphanumeric
/// @param string -string to validate
/// @return returns 0 if the string is not alphanumeric or 1 if it is alphanumeric

int convertWordFirstUppAndRestLower(char* string);
/// Function converts word first char uppercase rest lowercase
/// @param string -string to convert
/// @return returns 0 if not errors or 1 if it errors

int convertStringMayus(char* string);
/// Function converts all string to uppercase
/// @param string -string to convert
/// @return returns 0 if not errors or 1 if it errors

int getMenuForInt(int* option, char* message, char* messageError, int maxOption, int minOption);
/// Function get a menu with validated input to int
/// @param option -option typed by the user
/// @param message -menu message to show
/// @param messageError -error message when you enter an incorrect option
/// @param maxOption -option max
/// @param minOption -option min
/// @return returns 0 if not errors or 1 if it errors

int getMenuForChar(char* option, char* message, char* messageError, int maxOption, int minOption);
/// Function get a menu with validated input to char
/// @param option -option typed by the user
/// @param message -menu message to show
/// @param messageError -error message when you enter an incorrect option
/// @param maxOption -option max
/// @param minOption -option min
/// @return returns 0 if not errors or 1 if it errors


#endif /* BIBLIOPERSONAL_H_ */
