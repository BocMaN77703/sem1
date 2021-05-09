//НОМЕР 7
#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "rus");
	const int N = 100;
	int i = 0, x=0, n=0,z=0, ms[N], res;
	printf("Введите колличество элементов массива (не более 100): ");
	while (scanf_s("%d", &n) == 0 || n>N) {
		printf("Введите колличество элементов массива (число не более 100): "); //проверка на правильность ввода и ввод
		rewind(stdin);
	}
	printf("Введите элементы массива: ");
	for (i = 0; i < n; i++) {
		while (scanf_s("%d", &ms[i]) == 0) {
			printf("Вы ввели не число. Введите элементы массива: "); //проверка на правильность ввода и ввод
			rewind(stdin);
		}
	}
	x = ms[0] * ms[1];
	for (i = 1; i < n; i++)            // отбор
		if (ms[i] * ms[i - 1] >= x) {
			x = ms[i] * ms[i - 1];
			z = i + 1;
		}
	printf("Номер элемента произведение которого с предыдущим наибольшее: %d", z);
	return 0;
}