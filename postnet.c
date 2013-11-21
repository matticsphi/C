/*
 * Author: Mattics Phi
 * Class: CPE 357 - 05
 * Date: 4/5/11
 * Assignment 1
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define maxCode 11
#define minCode 5

void cat(char code[], char c, int length);
int findCheckSum(char code[], int count);
void catBarcode(char barcode[], char c);
void printBarcode(char code[], int count, int check);

int main()
{
	int count = 0, check;
	char c, code[13] = "";

	/* Checks each character input until end of file*/
	while ((c = getchar()) != EOF) {
		/* If input is done */
		if (c == '\n') {
			/* If input was just a return, do nothing,
			 * else, print out the barcode */
			if (count == 0);
			else if (count < minCode || count > maxCode) {
				printf("Invalid delivery data\n");
				count = 0;
			} else {
				check = findCheckSum(code, count++);
				printBarcode(code, count, check);
				count = 0;
			}
		/* Concatenates the digit into the character array */
		} else if (isdigit(c))
			cat(code, c, count++);
		/* If input are not digits, output error and skip
		 * until next line */
		else if (isalpha(c)) {
			while ((c = getchar()) != '\n');
			printf("Invalid delivery data\n");
			count = 0;
		/* Skips spaces */
		} else if (isspace(c));
	}
	return 0;
}

/* Function to concatenate characters into the char array */
void cat(char code[], char c, int length)
{
	code[length] = c;
	code[length + 1] = '\0';
}

/* Function to find the checksum of the input */
int findCheckSum(char code[], int length)
{
	int i, total = 0;

	for (i = 0; i < length; i++)
		total += code[i] - '0';

	return 10 - (total % 10);
}

/* Function that concatenates the barcode together */
void catBarcode(char barcode[], char c)
{
	if (c == '0')
		strcat(barcode, "::...");
	else if (c == '1')
		strcat(barcode, "...::");
	else if (c == '2')
		strcat(barcode, "..:.:");
	else if (c == '3')
		strcat(barcode, "..::.");
	else if (c == '4')
		strcat(barcode, ".:..:");
	else if (c == '5')
		strcat(barcode, ".:.:.");
	else if (c == '6')
		strcat(barcode, ".::..");
	else if (c == '7')
		strcat(barcode, ":...:");
	else if (c == '8')
		strcat(barcode, ":..:.");
	else if (c == '9')
		strcat(barcode, ":.:..");
}

/* Function to print out the barcode */
void printBarcode(char code[], int length, int check)
{
	int i;
	char barcode[63] = ":";

	/* Goes through each digit and makes the correct barcode */
	for (i = 0; i < length; i++)
		catBarcode(barcode, code[i]);

	catBarcode(barcode, check + '0');
	strcat(barcode, ":");

	printf("%-11s -> %s\n", code, barcode);
}
