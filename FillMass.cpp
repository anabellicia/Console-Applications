// Lab17.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void PrintMass(int* mass, size_t N) {
	printf("[%d", mass[0]);
	for (size_t i = 1; i < N; ++i)
		printf(", %d", mass[i]);
	printf("]\n");
}

void MassRandom(int* mass, size_t N) {
	for (size_t i = 0; i < N; ++i)
		mass[i] = (float)rand() / RAND_MAX * 200 - 100;
}

void MassManualy(int* mass, size_t N) {
	for (size_t i = 0; i < N; ++i) {
		printf("A[%u]=", i);
		scanf_s("%d", &mass[i]);
	}
}

void MassRange(int* mass, size_t N) {
	int K;
	printf("\nШаг: "); scanf_s("%d", &K);
	for (size_t i = 0; i < N; ++i)
		mass[i] = K * i;
}

int* PosMass(int* mass, size_t N, size_t &M) {
	M = 0;
	for (size_t i = 0; i < N; ++i)
		if (mass[i] > 0) M++;
	int* C = new int[M];
	for (size_t i = 0, k = 0; i < N; ++i)
		if (mass[i] > 0)
			C[k++] = mass[i];
	return C;
}

int* NegMass(int* mass, size_t N, size_t& M) {
	M = 0;
	for (size_t i = 0; i < N; ++i)
		if (mass[i] < 0) M++;
	int* C = new int[M];
	for (size_t i = 0, k = 0; i < N; ++i)
		if (mass[i] < 0)
			C[k++] = mass[i];
	return C;
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	int *A, *B, *C;
	size_t N, PN, NN;

	do {
		printf("\nДлинна массива: ");
		scanf_s("%u", &N);

		A = new int[N];

		printf("\nЗаполнить массив\n\t1 - случайно\n\t2 - вручную\n\t3 - с шагом\n:=>");
		switch (_getch()) {
		case '1':
		default: MassRandom(A, N); break;
		case '2': MassManualy(A, N); break;
		case '3': MassRange(A, N); break;
		}
		printf("\nA = ");
		PrintMass(A, N);

		B = PosMass(A, N, PN);
		C = NegMass(A, N, NN);

		printf("\nB = ");
		PrintMass(B, PN);
		printf("\nC = ");
		PrintMass(C, NN);
	} while (printf("\nESC - выход..."), _getch() != 27);
}