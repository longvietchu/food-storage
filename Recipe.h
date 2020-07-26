#pragma once
#include<stdio.h>
#include <iostream>
#include<string.h>
using namespace std;
void recipe() {
	int numrecipe;
	FILE* fp;
	fp = fopen("recipe.dat", "a+");
recipe_no:
	system("cls");
	printf("\t\t\t\xB2\xB2\xB2\ ADD RECIPE  \xB2\xB2\xB2\xB2");
	printf("\nEnter the Recipe number:");
	scanf("%d", &Check.Ing_no);
	if (Check.Ing_no == Add.Ing_no)
	{
		printf("Recipe no. already exist!");
		goto recipe_no;

	}
	Add.Ing_no = Check.Ing_no;
	printf("Enter the food name: ");
	scanf("%s", &Add.foodname);
	printf("The number of recipe you want to add? ");
	scanf("%d", &Add.num_recipe);
	fprintf(fp, "%d %d %s ", Add.Ing_no, Add.num_recipe, Add.foodname);
	for (int i = 0; i < Add.num_recipe; i++) {
		printf("Enter the name of ingredients %d ", i + 1);
		scanf("%s", &Add.nameIng[i]);
		printf("Enter the quantity of ingredients %d ", i + 1);
		scanf("%d", &Add.quantityIng[i]);
		if (i == Add.num_recipe - 1) {
			fprintf(fp, "%s %d \n", Add.nameIng[i], Add.quantityIng[i]);
		}
		else {
			fprintf(fp, "%s %d ", Add.nameIng[i], Add.quantityIng[i]);
		}

	}
	fclose(fp);
	printf("\nRecipe created successfully!");
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

void addrecipebonus() {
	int numrecipe;
	FILE* fp;
	fp = fopen("recipebonus.dat", "a+");
recipe_no:
	system("cls");
	printf("\t\t\t\xB2\xB2\xB2\ ADD RECIPE BONUS \xB2\xB2\xB2\xB2");
	printf("\nEnter the food name: ");
	scanf("%s", &bAdd.bfoodname);
	printf("The number of recipe you want to add? ");
	scanf("%d", &bAdd.bnum_recipe);
	fprintf(fp, "%d %s ", bAdd.bnum_recipe, bAdd.bfoodname);
	for (int i = 0; i < bAdd.bnum_recipe; i++) {
		printf("Enter the name of ingredients %d ", i + 1);
		scanf("%s", &bAdd.bnameIng[i]);
		printf("Enter the quantity of ingredients %d ", i + 1);
		scanf("%d", &bAdd.bquantityIng[i]);
		fprintf(fp, "%s %d ", bAdd.bnameIng[i], bAdd.bquantityIng[i]);
	}
	printf("Enter the price of ingredients: ");
	scanf("%d", &bAdd.price);
	fprintf(fp, "%d\n", bAdd.price);
	fclose(fp);
	printf("\nRecipe bonus created successfully!");
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