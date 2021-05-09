#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int minimal(int**, int);
void changestolb(int**, int, int);
void changestr(int**, int, int);

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, min, imin = 0, jmin = 0;
	int** mat;
	printf_s("Введите размерность квадратной матрицы: ");
	while ((scanf_s("%d", &n)) != 1)
	{
		rewind(stdin);
		printf_s("Ошибка ввода. Введите размерность квадратной матрицы: ");
	}
	printf("\n");
	//Выделение памяти
	mat = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
		mat[i] = (int*)calloc(n, sizeof(int));
	//Ввод матрицы
	printf_s("Введите матрицу:\n\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			while ((scanf_s("%d", &mat[i][j])) != 1)
			{
				rewind(stdin);
				printf_s("Ошибка ввода. Введите число:\n");
			}
		}
	}
	printf("\n");
	// Нахождение минимального значения
	min = minimal(mat, n);
	// Нахождение индексов минимального элемента
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] == min)
			{
				imin = i;
				jmin = j;
			}
		}
	}
	// Меняем местами столбцы и строки
	changestolb(mat, jmin, n);
	changestr(mat, imin, n);
	// Вывод итоговой матрицы
	printf_s("Итоговая матрица:\n\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf_s("%4d", mat[i][j]);
		}
		printf("\n");
	}
	// Очищение памяти
	for (int i = 0; i < n; i++)
		free(mat[i]);
	free(mat);
	return 0;
}

int minimal(int** mat, int n)
{
	int min;
	min = mat[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] <= min)
			{
				min = mat[i][j];
			}
		}
	return min;
}

void changestolb(int** mat, int jmin, int size)
{
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		temp = mat[i][jmin];
		mat[i][jmin] = mat[i][0];
		mat[i][0] = temp;
	}
}

void changestr(int** mat, int imin, int size)
{
	int temp = 0;
	for (int j = 0; j < size; j++)
	{
		temp = mat[imin][j];
		mat[imin][j] = mat[size - 1][j];
		mat[size - 1][j] = temp;
	}
}