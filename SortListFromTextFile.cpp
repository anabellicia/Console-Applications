// Lab20.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <ctype.h>

void PrintList(char** list, int len) {
	for (char** i = list; i < list + len; ++i)
		printf("\n(%u) %s", strlen(*i), *i);
}

void SortList(char** list, int from, int to) {
	if (from >= to)
		return;
	int i = from, j = to, x = strlen(list[(i + j) / 2]);
	char* tmp;
	while (i <= j) {
		while (strlen(list[i]) < x) i++;
		while (strlen(list[j]) > x) j--;
		if (i <= j) {
			tmp = list[i];
			list[i++] = list[j];
			list[j--] = tmp;
		}
	}
	SortList(list, from, j);
	SortList(list, i, to);
}

char* SubStr(char* begin, char* end) {
	int len = end - begin + 1;
	char* out = (char *)malloc((len + 1) * sizeof(char));
	for (int i = 0; i < len; ++i)
		out[i] = *(begin + i);
	out[len] = 0x00;
	return out;
}

char** SplitText(char* text, int* length) {
	*length = 0;
	char** out, *b, *e, *i = text;
	int k = 0;
	while (*i != 0x00) {
		while (*i != 0x00 && !isalpha(*i) && !isdigit(*i)) i++;
		while (*i != 0x00 && *i != '.' && *i != '!' && *i != '?') i++;
		*length += 1;
	}
	out = (char**)malloc(--*length * sizeof(char));
	i = text;
	while (*i != 0x00) {
		while (*i != 0x00 && !isalpha(*i) && !isdigit(*i)) i++;
		b = i;
		while (*i != 0x00 && *i != '.' && *i != '!' && *i != '?') i++;
		e = i;
		if (*i == 0x00)
			continue;
		while (*e != 0x00 && !isalpha(*e) && !isdigit(*e)) e--;
		out[k] = SubStr(b, e + 1);
		if (*i != 0x00)
			out[k][strlen(out[k]) - 1] = *i;
		k++;
	}

	return out;
}

char* ReadFile(char* path) {
	FILE* fp = fopen(path, "rb");
	if (fp == NULL)
		return NULL;
	fseek(fp, 0L, SEEK_END);
	int len = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	char* text = (char *)malloc((len + 1) * sizeof(char));
	text[len] = 0x00;
	fread(text, 1, len, fp);
	fclose(fp);
	return text;
}

void WriteFile(char* path, char** text, int len) {
	FILE* fp = fopen(path, "wb");
	for (char** i = text; i < text + len; ++i)
		fprintf(fp, "(%u) %s\n", strlen(*i), *i);
	fclose(fp);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char* path = (char *)malloc(256 * sizeof(char)), *text, ** list;
	int llen;

	printf("\nВведите путь к исходному тексту: ");
	scanf("%s", path);

	text = ReadFile(path);
	if (text == NULL) {
		printf("\nФайл не найден!");
		return 0;
	}

	printf("\nФайл размером %u прочитан", strlen(text));

	list = SplitText(text, &llen);
	SortList(list, 0, llen - 1);

	printf("\nОтсортированный список: ");
	PrintList(list, llen);

	printf("\nВведите файл для сохранения списка: ");
	scanf("%s", path);

	WriteFile(path, list, llen);
	printf("\nЗапись завершена");

	_getch();
	return 0;
}