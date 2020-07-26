#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <iostream>
#include<string.h>
using namespace std;
int main_exit;
void close(void)
{
	printf("\n\nThis C Mini Project is developed by Code With Our Team!");
}
struct {
	char name[60];
	int quantity;
}add, upd, check, del;
struct {
	char foodname[20];
	int num_recipe;
	char nameIng[5][60];
	int quantityIng[5];
	int Ing_no;
}Add, Check;
struct {
	char bfoodname[20];
	int bnum_recipe;
	char bnameIng[5][60];
	int bquantityIng[5];
	int price;
}bAdd, bCheck;
