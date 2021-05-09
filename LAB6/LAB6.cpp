//num 9
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main() {
	double* ms;
	double m=0;
	int k=0, i=0;
	setlocale(LC_ALL, "Rus");
	printf("Введите колличество элементов массива: ");
	while (!scanf_s("%d", &k)) {
		rewind(stdin);
		printf("Вы ввели не число. Введите колличество элементов массива: ");
	}
	ms = (double*)malloc(k * sizeof(double));
	printf("Введите элементы массива: ");
	for (i = 0; i < k; i++) {
		while (!scanf_s("%lf", &ms[i])) {
			rewind(stdin);
			printf("Вы ввели не число. Введите элемент массива: ");
		}
	}
	m = ms[0];
	if (ms[0] >= 0) {
		for (i = 0; i < k; i++) {
			if (ms[i] <= m)
				m = ms[i];
		}
	}
	else {
		for (i = 0; i < k; i++) {
			if (ms[i] >= m)
				m = ms[i];
		}
	}
	m = m * m;
	printf("ИТОГОВАЯ ПОСЛДОВАТЕЛЬНОСТЬ:\n");
	for (i = 0; i < k; i++)
		printf("%.3lf ", ms[i]*m);
	free(ms);
	return 0;
}