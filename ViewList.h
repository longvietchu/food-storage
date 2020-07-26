#pragma once
#include<stdio.h>
#include <iostream>
#include<string.h>
using namespace std;
void view_list() {
	FILE* view;
	view = fopen("foodstorage.dat", "r");
	int test = 0;
	system("cls");
	printf("\nNAME\t\t\tQUANTITY\n");
	while (fscanf(view, "%s %d", add.name, &add.quantity) != EOF)
	{
		printf("\n%s\t\t\t%d", add.name, add.quantity);
		test++;
	}

	fclose(view);
	if (test == 0)
	{
		system("cls");
		printf("\nNO RECORDS!!\n");
	}

view_list_invalid:
	printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1)
		menu();
	else if (main_exit == 0)
		close();
	else
	{
		printf("\nInvalid!\a");
		goto view_list_invalid;
	}
}