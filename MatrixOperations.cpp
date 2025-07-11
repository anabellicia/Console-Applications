// Lab18.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void L7PrintArray(int* arr, size_t N) {
	printf("[%d", *arr);
	for (int* i = arr + 1; i < arr + N; ++i)
		printf(", %d", *i);
	printf("]\n");
}

void L7ArrayRandom(int* arr, size_t N) {
	for (int* i = arr; i < arr + N; ++i)
		*i = (float)rand() / RAND_MAX * 200 - 100;
}

void L7ArrayManualy(int* arr, size_t N) {
	for (size_t i = 0; i < N; ++i) {
		printf("A[%u]=", i);
		scanf_s("%d", arr + i);
	}
}

void L7ArrayRange(int* arr, size_t N) {
	int K;
	printf("\nШаг: "); scanf_s("%d", &K);
	for (int* i = arr; i < arr + N; ++i)
		*i = K * (i - arr);
}

int* L7PosArray(int* arr, size_t N, size_t& M) {
	M = 0;
	for (size_t i = 0; i < N; ++i)
		if (arr[i] > 0) M++;
	int* C = new int[M];
	for (size_t i = 0, k = 0; i < N; ++i)
		if (arr[i] > 0)
			C[k++] = arr[i];
	return C;
}

int* L7NegArray(int* arr, size_t N, size_t& M) {
	M = 0;
	for (size_t i = 0; i < N; ++i)
		if (arr[i] < 0) M++;
	int* C = new int[M];
	for (size_t i = 0, k = 0; i < N; ++i)
		if (arr[i] < 0)
			C[k++] = arr[i];
	return C;
}

int L7Main() {
	int* A, *B, *C;
	size_t N, PN, NN;

	do {
		printf("\nДлинна массива: ");
		scanf_s("%u", &N);

		A = new int[N];

		printf("\nЗаполнить массив\n\t1 - случайно\n\t2 - вручную\n\t3 - с шагом\n:=>");
		switch (_getch()) {
		case '1':
		default: L7ArrayRandom(A, N); break;
		case '2': L7ArrayManualy(A, N); break;
		case '3': L7ArrayRange(A, N); break;
		}
		printf("\nA = ");
		L7PrintArray(A, N);

		B = L7PosArray(A, N, PN);
		C = L7NegArray(A, N, NN);

		printf("\nB = ");
		L7PrintArray(B, PN);
		printf("\nC = ");
		L7PrintArray(C, NN);
	} while (printf("\nESC - выход..."), _getch() != 27);

	return 0;
}

void L81Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void L81Rotate180(int** A, size_t N) {
	for (size_t i = 0; i < N; ++i)
		for (size_t j = 0; j < N - i; ++j)
			L81Swap(*(A + i) + j, *(A + N - j - 1) + N - i - 1);

	for (size_t i = 0; i < N; ++i)
		for (size_t j = 0; j < N - i; ++j)
			L81Swap(*(A + i) + N - j - 1, *(A + N - j - 1) + i);
}

void L81PrintMatrix(int** A, size_t N) {
	for (int** i = A; i < A + N; ++i) {
		for (int* j = *i; j < *i + N; ++j)
			printf("%3d ", *j);
		printf("\n");
	}
}

void L81MatrixRandom(int** A, size_t N) {
	for (int** i = A; i < A + N; ++i)
		for (int* j = *i; j < *i + N; ++j)
			*j = (float)rand() / RAND_MAX * 100 - 50;
}

void L81MatrixRange(int** A, size_t N) {
	size_t n = 0;
	for (int** i = A; i < A + N; ++i)
		for (int* j = *i; j < *i + N; ++j)
			*j = ++n;
}

int L81Main() {
	int **A;
	size_t N;

	do {
		printf("\nДлинна массива: ");
		scanf_s("%u", &N);

		A = new int*[N];
		for (int** i = A; i < A + N; ++i)
			*i = new int[N];

		printf("\nЗаполнить массив\n\t1 - случайно\n\t2 - по порядку\n:=>");
		switch (_getch()) {
		case '1':
		default: L81MatrixRandom(A, N); break;
		case '2': L81MatrixRange(A, N); break;
		}
		printf("\nМатрица:\n");
		L81PrintMatrix(A, N);
		L81Rotate180(A, N);
		printf("\nМатрица после поворота:\n");
		L81PrintMatrix(A, N);
	} while (printf("\nESC - выход..."), _getch() != 27);

	return 0;
}

void L82Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void L82Rotate180(int* A, size_t N) {
	for (size_t i = 0; i < N; ++i)
		for (size_t j = 0; j < N - i; ++j)
			L82Swap(A + N * i + j, A + N * (N - j) - i - 1);

	for (size_t i = 0; i < N; ++i)
		for (size_t j = 0; j < N - i; ++j)
			L82Swap(A + N * i + N - j - 1, A + N * (N - j - 1) + i);
}

void L82PrintMatrix(int* A, size_t N) {
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < N; ++j)
			printf("%3d ", *(A + N * i + j));
		printf("\n");
	}
}

void L82MatrixRandom(int* A, size_t N) {
	for (int *i = A; i < A + N * N; ++i)
		*i = (float)rand() / RAND_MAX * 100 - 50;
}

void L82MatrixRange(int* A, size_t N) {
	size_t n = 0;
	for (int *i = A; i < A + N * N; ++i)
		*i = ++n;
}

int L82Main() {
	int* A;
	size_t N;

	do {
		printf("\nДлинна массива: ");
		scanf_s("%u", &N);

		A = new int[N * N];

		printf("\nЗаполнить массив\n\t1 - случайно\n\t2 - по порядку\n:=>");
		switch (_getch()) {
		case '1':
		default: L82MatrixRandom(A, N); break;
		case '2': L82MatrixRange(A, N); break;
		}
		printf("\nМатрица:\n");
		L82PrintMatrix(A, N);
		L82Rotate180(A, N);
		printf("\nМатрица после поворота:\n");
		L82PrintMatrix(A, N);
	} while (printf("\nESC - выход..."), _getch() != 27);

	return 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	printf("\nРабота\n\t7 - 7 (9)\n\t8 - 8\n:=>");
	switch (_getch()) {
	case '7':
	case '9':
		L7Main(); break;
	case '8':
		printf("\nВид:\n\t1 - двумерный\n\t2 - одномерный\n:=>");
		switch (_getch()) {
		case '1': L81Main(); break;
		case '2': L82Main();
		default: break;
		}
	default: break;
	}
}