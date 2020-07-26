#pragma once
#include<stdio.h>
#include <iostream>
#include<string.h>
using namespace std;
void order() {
checkfood:
	FILE* fop;
	char str[1000];
	fop = fopen("recipe.dat", "r");

	char nameorder[50] = "tri", ordermore[3];
	int test = 0, amount;
	system("cls");
	printf("Enter the name of food which you want to order: ");
	scanf("%s", &nameorder);
	while (fgets(str, 1000, fop) != NULL) {
		if (str[2] == '3') {
			if (sscanf(str, "%d %d %s %s %d %s %d %s %d", &Add.Ing_no, &Add.num_recipe, &Add.foodname, &Add.nameIng[0], &Add.quantityIng[0], &Add.nameIng[1], &Add.quantityIng[1], &Add.nameIng[2], &Add.quantityIng[2])) {
				if (strcmp(Add.foodname, nameorder) == 0) {
					test = 1;
					printf("Enter the amount of food which you want to order: ");
					scanf("%d", &amount);
					for (int i = 0; i < 3; i++) {
						checkorder(Add.nameIng[i], amount * Add.quantityIng[i]);
					}
					printf("Ban da order thanh cong!\n");
					printf("Ban co muon order them mon khac?(Y/N) ");
					fflush(stdin);
					scanf("%s", &ordermore);
					if (strcmp(ordermore, "Y") == 0) {
						goto checkfood;
					}
					else {
					add_invalid:
						printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
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
				}
			}
		}
		else {

		}
	}
	if (test == 0) {
		printf("We don't have this recipe\n");
		char putmore[3];
		printf("Ban co muon order them mon khac?(Y/N) ");
		fflush(stdin);
		scanf("%s", &putmore);
		if (strcmp(putmore, "Y") == 0) {
			goto checkfood;
		}
		else {
		_invalid:
			printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
			scanf("%d", &main_exit);
			system("cls");
			if (main_exit == 1)
				menu();
			else if (main_exit == 0)
				close();
			else
			{
				printf("\nInvalid!\a");
				goto _invalid;
			}
		}
	}
	fclose(fop);
}

void orderbonus() {
checkfood:
	FILE* fop;
	char str[1000];
	fop = fopen("recipebonus.dat", "r");
	char nameorder[50], ordermore[3];
	int test = 0, testq = 0, amount;
	system("cls");
	printf("Enter the name of food which you want to order: ");
	scanf("%s", &nameorder);
	while (fgets(str, 1000, fop) != NULL) {
		if (str[0] == '3') {
			if (sscanf(str, "%d %s %s %d %s %d %s %d %d", &bAdd.bnum_recipe, &bAdd.bfoodname, &bAdd.bnameIng[0], &bAdd.bquantityIng[0], &bAdd.bnameIng[1], &bAdd.bquantityIng[1], &bAdd.bnameIng[2], &bAdd.bquantityIng[2], &bAdd.price)) {
				if (strcmp(bAdd.bfoodname, nameorder) == 0) {
					test = 1;
					printf("Enter the amount of food which you want to order: ");
					scanf("%d", &amount);
					for (int i = 0; i < 3; i++) {
						int x = checkorderbonus(bAdd.bnameIng[i], amount * bAdd.bquantityIng[i], amount * bAdd.price);
						if (x == 1) {
							testq = 1;
							break;
						}
					}
					if (testq == 0) {
						for (int i = 0; i < 3; i++) {
							checkorder(bAdd.bnameIng[i], amount * bAdd.bquantityIng[i]);
						}
						printf("Ban da order thanh cong!\n");
					}
					printf("Ban co muon order them mon khac?(Y/N) ");
					fflush(stdin);
					scanf("%s", &ordermore);
					if (strcmp(ordermore, "Y") == 0) {
						goto checkfood;
					}
					else {
					add_invalid:
						printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
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
				}
			}
		}
		else {

		}
	}
	if (test == 0) {
		printf("We don't have this recipe\n");
		char putmore[3];
		printf("Ban co muon order them mon khac?(Y/N) ");
		fflush(stdin);
		scanf("%s", &putmore);
		if (strcmp(putmore, "Y") == 0) {
			goto checkfood;
		}
		else {
		_invalid:
			printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
			scanf("%d", &main_exit);
			system("cls");
			if (main_exit == 1)
				menu();
			else if (main_exit == 0)
				close();
			else
			{
				printf("\nInvalid!\a");
				goto _invalid;
			}
		}
	}
	fclose(fop);
}