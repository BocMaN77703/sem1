#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "rus"); //����������� ������
	int a=0;
	for (int n = 0; (7 * (pow(n, 3)) + 81 * (pow(n, 2)) - pow(10, 6) < 0); n++) { //�������� �������� 
		if (n >= a)
			a = n;
	}
	printf("���������� n= %d", a);
	return 0;
}
