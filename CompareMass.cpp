﻿// Lab21.cpp: определяет точку входа для консольного приложения.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <cstdlib> // содержит srand() и rand()
#include<time.h>

#define SIZE 5
#define NMAX 100
#define NMIN -100

int main()
{
	int t;
	do
	{
		setlocale(LC_ALL, "Russian");
		int mass1[SIZE], mass2[SIZE];
		int a, b, n, y, min, i;
		srand(time(0));
		printf("Введите 1, если да. Введите 2, если нет \n");
		printf("Значения в массиве случайные? : ");
		scanf_s("%d", &y);
		if (y != 2 && y != 1)
			printf("Ошибка! ");

		else
		{
			if (y == 1)
			{
				for (i = 0; i < SIZE; i++)
					mass1[i] = int((float)rand() / RAND_MAX * (NMAX - NMIN) + NMIN); // Заполнение массива данными
				for (n = 0; n < SIZE; n++)
					mass2[n] = int((float)rand() / RAND_MAX * (NMAX - NMIN) + NMIN);
			};
			if (y == 2)
			{
				for (i = 0; i < SIZE; i++) // Ввод массива с клавиатуры
				{
					printf("mass1[i]= ", i); // Подсказка для пользователя
					scanf("%d", &mass1[i]); // Ввод элемента массива
				}for (n = 0; n < SIZE; n++) // Ввод массива с клавиатуры
				{
					printf("mass2[n]= ", n); // Подсказка для пользователя
					scanf("%d", &mass2[n]); // Ввод элемента массива
				}
			}
		}
		min = NMAX;
		b = 0;
		a = 0;
		for (i = 0; i < SIZE; i++)
			printf("% d", mass1[i]);
		printf("\n");
		for (n = 0; n < SIZE; n++)
		{

			printf("% d", mass2[n]);
			b = mass2[n];
			for (i = 0; i < SIZE; i++)
			{
				if (mass2[n] != mass1[i])
				a++;
			}

			if (a == SIZE && mass2[n] < min)
				min = mass2[n];
			a = 0;
		}
		if (min != NMAX)
			printf("\n%d\n", min);
		else
			printf("\nОдинаковые массивы");
		printf("\nПродолжить ? (1-да / 2-нет)");
		scanf("\n%d", &t);
	} while (t != 2);

}
