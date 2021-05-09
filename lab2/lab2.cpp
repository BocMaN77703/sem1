/*Лабораторная работа номер 2
Задание 6
Шипко Александр*/
#include <stdio.h>
#include <math.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Rus"); //Русификация вывода
	float a=0, b=0, c=0;
		printf("Введите числа a, b, c: ");
		if (!(scanf_s("%f%f%f", &a, &b, &c))) { //Проверка на правильность ввода и ввод
			printf("Вы ввели не число. Ошибка ввода."); 
			return 0;
		}
	if (a >= b && b >= c) {
		printf_s("a=%f\nb=%f\nc=%f", a*2, b*2, c*2); //Вывод удвоенных значений
	}
	else {
		printf_s("a=%f\nb=%f\nc=%f", fabsl(a), fabsl(b), fabsl(c)); //Вывод абсолютных хначений
	}
	return 0;
	}


