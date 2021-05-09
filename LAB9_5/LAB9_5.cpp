#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h>   
int main()
{
	setlocale(LC_ALL, "Russian");
	char *str2, *str, **s;
	int *ind, *ind2;
	int oi, n, m, k, i = 0, j = 0, x = 0, sum = 0, q = 0, l = 0, i1=0, i3 = 0;
	printf("Введите кол-во строк и символов в них: ");
	while (!(scanf_s("%d %d", &n, &m)))
	{
		rewind(stdin);
		printf("Ошибка ввода. Введите кол-во строк и символов в них: ");
	}
	s = (char**)calloc(n, sizeof(char*));
	m ++;
	for (int i = 0; i < n; i++)
		s[i] = (char*)calloc(m, sizeof(char));
	k = m * n;
	//Память под строки для сортировки
	str = (char*)calloc(k, sizeof(char));
	str2 = (char*)calloc(k, sizeof(char));
	//ввод
	printf("Введите текст:\n");
	rewind(stdin);
	for (i = 0; i < n; i++)
	{
		fgets(s[i], m, stdin);
		rewind(stdin);
	}
	m --;
	//в одну строку
	q = 0;
	for (i = 0; i < n; i++)
	{
		if (i != 0)
		{
			str[q] = ' '; q++;
		}
		for (j = 0; j < m; j++)
		{
			str[q] = s[i][j];
			q++;
		}
	}
	//Память под массивы с длинами слов
	ind = (int*)calloc(q, sizeof(int));
	ind2 = (int*)calloc(q, sizeof(int));
	//длина слов
	oi = 0;
	sum = 0;
	for (i = 0; i < q; i++)
	{
		if (str[i] == ' ')
		{
			ind[oi] = sum; ind2[oi] = sum; sum = 0; oi++;
		}
		else { sum++; }
		if (i == q - 1)
		{
			ind[oi] = sum; ind2[oi] = sum; sum = 0; oi++;
		}
	}
	//cортировка 1 массива с длинами
	str[q] = ' ';
	for (i = 0; i < oi; i++)
	{
		for (j = 0; j < oi - i; j++)
		{
			if (ind[j] < ind[j + 1])
			{

				x = ind[j];
				ind[j] = ind[j + 1];
				ind[j + 1] = x;
			}
		}
	}
	//запись новой строки
	for (i = 0; i < oi; i++)
	{
		for (j = 0; j < oi; j++)
		{
			if (ind[i] == ind2[j])
			{
				l = 0;
				x = 0;
				while (l != j)
				{
					if (str[x] == ' ')
					{
						l++;
					}
					x++;
				}
				for (i1 = 0; i1 <= ind2[j]; i1++)
				{

					str2[i3] = str[i1 + x];
					i3++;
				}
				ind[i] = -1;
				ind2[j] = -1; j = oi;
			}
		}
	}
	//Вывод и очищение памяти
	printf("Итогова строка:\n");
	for (i = 0; i < q; i++)
	{
		printf("%c", str2[i]);
	}
	for (int k = 0; k < n; k++)
		free(s[k]);
	free(s);
	free(str);
	free(str2);
	free(ind);
	free(ind2);
	return 0;
}