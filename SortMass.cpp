// Lab19.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <math.h>

#define NMIN 0
#define NMAX 100

void FillMass(short* mass, size_t N) {
	for (short* i = mass; i < mass + N; ++i)
		*i = (float)rand() / RAND_MAX * (NMAX - NMIN) + NMIN;
}

void FindMinMax(short* A, size_t N, size_t& min, size_t& max) {
	min = max = 0;
	for (size_t i = 0; i < N; ++i) {
		if (A[i] <= A[min]) min = i;
		if (A[i] > A[max]) max = i;
	}
}

short* SubMass(short* mass, size_t N) {
	short *out, *e;
	out = e = new short[N];
	for (short* i = mass; i < mass + N; ++i, ++e)
		*e = *i;
	return out;
}

void PrintA(short *A, size_t N) {
	printf("[%hd", *A);
	for (short* i = A + 1; i < A + N; ++i)
		printf(", %hd", *i);
	printf("]\n");
}

void InsertionSort(short* data, size_t len) {
	short key = 0;
	unsigned i = 0;
	for (unsigned j = 1; j < len; j++) {
		key = data[j];
		i = j - 1;
		while (i >= 0 && data[i] > key) {
			data[i + 1] = data[i--];
			data[i + 1] = key;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	size_t N, min, max;
	short *A, *B;

	do {
		printf("\nДлинна = ");
		scanf_s("%u", &N);

		A = new short[N];

		FillMass(A, N);
		printf("\nИсходный массив: ");
		PrintA(A, N);

		FindMinMax(A, N, min, max);

		printf("\nПоследний минимальный = %u", A[min]);
		printf("\n  Первый максимальный = %u", A[max]);

		if (min > max) {
			max += min;
			min = max - min;
			max -= min;
		}

		N = max - min - 1;
		if (N <= 0) {
			printf("\nПустой подмассив!");
			continue;
		}

		B = SubMass(A + min + 1, N);
		InsertionSort(B, N);
		delete[]A;

		printf("\n Подмассив: ");
		PrintA(B, N);

		printf("\nМедиана: ");
		if (N % 2 == 0)
			printf("%.1f", (float)(B[N / 2 - 1] + B[N / 2]) / 2);
		else
			printf("%d", B[N / 2]);
		delete[]B;
	} while (printf("\nESC - выход..."), _getch() != 27);
}




