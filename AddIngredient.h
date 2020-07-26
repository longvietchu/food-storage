#pragma once
#include<stdio.h>
#include <iostream>
#include<string.h>
using namespace std;
void add_ingredients() {
	int choice;
	FILE* fs;
	fs = fopen("foodstorage.dat", "a+");
ingredient_no:
	system("cls");
	printf("\t\t\t\xB2\xB2\xB2\ ADD INGREDIENTS  \xB2\xB2\xB2\xB2");
	printf("\nEnter the name of ingredient: ");
	scanf("%s", &add.name);
	printf("\nEnter the quantity: ");
	scanf("%d", &add.quantity);

	fprintf(fs, "%s %d\n", add.name, add.quantity);
	fclose(fs);
	printf("\nIngredient created successfully!");
add_invalid:
	printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit: ");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1)
		menu();
	else if (main_exit == 0)
		close();
	else
	{
		printf("\nInvalid!\a");
		goto add_invalid;
	}
}
