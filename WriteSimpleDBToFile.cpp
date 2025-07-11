// Lab23.cpp: определяет точку входа для консольного приложения.
//


#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <cstring>
#include <ctype.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

struct ManInfo
{
	char Family[60]; // Фамилия
	short Age; // Возраст
	float Weight; // Вес
	float Height; // Рост
};
void ViewInfo(ManInfo* Arr, int Len)
{
	int i;

	printf("========================================================\n");
	printf("| N | Фамилия | Возраст | Вес | Рост |\n");
	printf("========================================================\n");
	for (i = 0; i < Len; i++)
		printf("| %2d | %-20s | %2d | %3.1f | %3.1f |\n", i + 1,
			Arr[i].Family, Arr[i].Age, Arr[i].Weight, Arr[i].Height);
	printf("========================================================\n");
}


void OutputToFile(char* FName) // Выводит инф-ю в файл с именем FName
{
	FILE* f1;
	ManInfo dat;
	char key;
	f1 = fopen(FName, "a");
	printf("Output to file:\n");
	do
	{
		printf("Family: ");
		scanf("%s", dat.Family);
		fflush(stdin); // сбросить входной поток
		printf("Age: ");
		scanf("%d", &dat.Age);
		fflush(stdin); // сбросить входной поток
		printf("Weight: ");
		scanf("%f", &dat.Weight);
		fflush(stdin); // сбросить входной поток
		printf("Height: ");
		scanf("%f", &dat.Height);
		fflush(stdin); // сбросить входной поток
		fprintf(f1, "%s\n", dat.Family);
		fprintf(f1, "%d\n", dat.Age);
		fprintf(f1, "%f\n", dat.Weight);
		fprintf(f1, "%f\n", dat.Height);
		printf("Repeat?");
		key = _getch();
	} while (key != 'n' && key != 'N');
	fclose(f1);
}

void SortMinfo(ManInfo* Arr, int Len)
{
	int i, j, im;
	ManInfo tmp;
	for (i = 0; i < Len - 1; i++)
	{
		im = i;
		for (j = i + 1; j < Len; j++)
			if (strcmp(Arr[im].Family, Arr[j].Family) > 0)
				im = j;
		tmp = Arr[i];
		Arr[i] = Arr[im];
		Arr[im] = tmp;
	}
} // Сортировка
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	FILE* f1;
	char path[256];
	int i;
	ManInfo* Minfo = 0;
	int Count = 5;
	char key;
	for (;;) // Бесконечный цикл
	{
		printf("Select:\n 0 - Exit\n 1 - Output to file\n 2 - Get from file\n 3 - Sort\n");
		key = _getch();
		switch (key)
		{
		case '0':
			if (Minfo) delete[] Minfo;
			return 0;
		case '1':
			printf("\nВведите имя файла: ");
			scanf("%s", path);
			OutputToFile(path);
			break;
		case '2':
			printf("Get from file\n");
			f1 = fopen("list.txt", "r");
			if (f1 == NULL) // Открываем для чтения
			{
				printf("File not found\n");
				_getch();
				break;
			}
			i = fscanf(f1, "%d\n", &Count);
			if (i != 1 || Count < 1 || Count > 100)
			{
				printf("Error in file\n");
				fclose(f1);
				_getch();
				break;
			}
			if (Minfo) delete[] Minfo;
			Minfo = new ManInfo[Count];
			for (i = 0; i < Count; i++)
			{
				fscanf(f1, "%s\n", &Minfo[i].Family);
				fscanf(f1, "%d\n", &Minfo[i].Age);
				fscanf(f1, "%f\n", &Minfo[i].Weight);
				fscanf(f1, "%f\n", &Minfo[i].Height);
			}

			ViewInfo(Minfo, Count);
			fclose(f1);
			break;
		case '3':
			printf("Sort\n");
			SortMinfo(Minfo, Count);
			ViewInfo(Minfo, Count);
			break;
		}
	}
	return 0;
}


