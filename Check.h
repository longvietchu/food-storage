#pragma once
#include<stdio.h>
#include <iostream>
#include<string.h>
using namespace std;
void checkorder(char* a, int b) {

	FILE* fsp, * newrep;
	fsp = fopen("foodstorage.dat", "r");
	newrep = fopen("newfoodstorage.dat", "w");
	while (fscanf(fsp, "%s %d", check.name, &check.quantity) != EOF)
	{
		if (strcmp(check.name, a) == 0) {
			if (check.quantity < b) {
				int newmore, newamount;
				int lacknum = b - check.quantity;
				printf("Ban can phai nhap them it nhat %d %s de co the lam mon an\n", lacknum, a);
				printf("Vui long nhap so luong %s muon them vao: ", a);
				scanf("%d", &newmore);
				newamount = newmore + check.quantity - b;
				fprintf(newrep, "%s %d\n", check.name, newamount);
			}
			else {
				int newnum = check.quantity - b;
				fprintf(newrep, "%s %d\n", check.name, newnum);
			}
		}
		else {
			fprintf(newrep, "%s %d\n", check.name, check.quantity);
		}
	}
	fclose(fsp);
	fclose(newrep);
	remove("foodstorage.dat");
	rename("newfoodstorage.dat", "foodstorage.dat");
	remove("newfoodstorage.dat");
}

int testIngredients(char* nametest, int amount) {
	FILE* fnew;
	fnew = fopen("foodstorage.dat", "r");
	while (fscanf(fnew, "%s %d", check.name, &check.quantity) != EOF) {
		if (strcmp(check.name, nametest) == 0) {
			if (check.quantity < amount) {
				return 0;
			}
			else {
				return 1;
			}
		}
	}
}

int checkorderbonus(char* foodBonus, int numfoodb, int price) {
	FILE* fkp, * fjp;
	char str[1000];
	fkp = fopen("foodstorage.dat", "r");
	fjp = fopen("recipebonus.dat", "r");
	int m = 0;
	/*printf("first %s\n", foodBonus);*/
	while (fscanf(fkp, "%s %d", check.name, &check.quantity) != EOF)
	{
		if (strcmp(check.name, foodBonus) == 0) {
			if (check.quantity < numfoodb) {
				m = 1;
				printf("We don't have enough %s\n", foodBonus);
				printf("We suggest you a food: \n");
				char suggestname[20];
				int pricesuggest = 0;
				while (fgets(str, 1000, fjp) != NULL)
				{
					if (str[0] == '3') {
						int testbonus = 0;
						if (sscanf(str, "%d %s %s %d %s %d %s %d %d", &bAdd.bnum_recipe, &bAdd.bfoodname, &bAdd.bnameIng[0], &bAdd.bquantityIng[0], &bAdd.bnameIng[1], &bAdd.bquantityIng[1], &bAdd.bnameIng[2], &bAdd.bquantityIng[2], &bAdd.price)) {

							for (int i = 0; i < 3; i++) {
								int k = testIngredients(bAdd.bnameIng[i], bAdd.bquantityIng[i]);
								if (k == 1) {
									testbonus++;
								}
							}

						}
						if (testbonus == 3) {
							if (bAdd.price > pricesuggest) {
								strcpy(suggestname, bAdd.bfoodname);
								pricesuggest = bAdd.price;
							}

						}
					}

				}
				printf("%s %d\n", suggestname, pricesuggest);
			}
		}
	}
	fclose(fkp);
	fclose(fjp);
	if (m == 1) {
		return 1;
	}
	else {
		return 0;
	}
}