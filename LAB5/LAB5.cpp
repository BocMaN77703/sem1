//Номер 8
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
int main() {
	setlocale(LC_ALL, "rus"); //Русификация вывода
	int i, j, n=0, m=0, min=0, k=0;
	int** ms; 
	printf("Введите количесво строк и столбцов:");
	while (!scanf_s("%d%d", &n, &m)) {
		printf("Вы ввели не число. Введите колличество строк и столбцов: "); //проверка на правильность ввода и ввод
		rewind(stdin);
	}
	ms = (int**)malloc(n * sizeof(int)); //Выделение памяти
	for (i = 0; i < n; i++)
		ms[i] = (int*)malloc(m * sizeof(int));
	printf("Введите элементы массива:");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			while (!scanf_s("%d", &ms[i][j])){
				printf("Вы ввели не число. Введите элементы массива: ");
				rewind(stdin);
			}
		}
	}
	min = ms[0][0];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (ms[i][j] <= min) //Определение минимального элемента
				min = ms[i][j];
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (ms[i][j]%min==0) //Проверка на кратность
				k++;
		}
	}
	printf("Количество элементов кратных минимальному: %d", k); //Вывод
	for (int i = 0; i < n; i++)
		free(ms[i]); //Очищение памяти
	free(ms);
	return 0;
}