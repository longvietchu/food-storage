#pragma once
#include<stdio.h>
#include <iostream>
#include<string.h>
using namespace std;
void edit(char* foodedit, int numedit) {
	int choice;
	FILE* old, * newrec;
	old = fopen("foodstorage.dat", "r");
	newrec = fopen("newfoodstorage.dat", "w");
	while (fscanf(old, "%s %d", add.name, &add.quantity) != EOF)
	{
		if (strcmp(foodedit, add.name) == 0) {
			int newnum = add.quantity - numedit;
			printf("%d\n", newnum);
			fprintf(newrec, "%s %d\n", add.name, newnum);
		}
		else {
			fprintf(newrec, "%s %d\n", add.name, add.quantity);
		}
	}


	fclose(old);
	fclose(newrec);
	remove("foodstorage.dat");
	rename("newfoodstorage.dat", "foodstorage.dat");
	remove("newfoodstorage.dat");
};