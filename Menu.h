#pragma once
#include<stdio.h>
#include <iostream>
#include<string.h>
using namespace std;
void menu(void) {
	int choice;
	char lt[10] = "banhmi";
	system("cls");
	system("color B");
	printf("\n\n\t\t\t\tFAST FOOD MANAGEMENT SYSTEM");
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\t\t1.Create new ingredient\n\t\t2.Update information of existing ingredient\n\t\t3.View ingredient's list\n\t\t4.Add recipe\n\t\t5.Order\n\t\t6.Add recipe(bonus)\n\t\t7.Order(bonus)\n\t\t0.Exit\n\n\n\n\nEnter your choice > ");
	scanf("%d", &choice);

	system("cls");
	switch (choice)
	{
	case 1 : add_ingredients();
		break;
	case 2 : checkorder(lt, -2);
		break;
	case 3 : view_list();
		break;
	case 4 : recipe();
		break;
	case 5 : order();
		break;
	case 6 : addrecipebonus();
		break;
	case 7 : orderbonus();
		break;
	default : close();
		break;

	}
};
