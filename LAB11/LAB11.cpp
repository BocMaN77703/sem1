#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int maxwordsize (int n, int m, char** s);
int strwithmaxword(int n, int m, char** s, int(*fun)(int, int, char**));

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m, max, num;
	char** s;
	printf("Введите кол-во строк и символов в них: ");
	while ((scanf_s("%d%d", &n, &m)) != 2)
	{
		rewind(stdin);
		printf("Ошибка ввода. Введите кол-во строк и символов в них: ");
	}
	//Выделение памяти
	s = (char**)calloc(n, sizeof(char*));
	m += 1;
	for (int i = 0; i < n; i++)
	{
		s[i] = (char*)calloc(m, sizeof(char));
	}
	printf("\n");
	//Ввод
	printf("Введите текст (Не более %d символов в строке):\n", m-1);
	rewind(stdin);
	for (int i = 0; i < n; i++)
	{
		fgets(s[i], m, stdin);
		rewind(stdin);
	}
	//Поиск слова с максимальным числом символов
	int(*fun)(int, int, char**); //Указатель на функцию
	fun = maxwordsize;
	num = strwithmaxword(n, m, s, fun);
	printf("\n");
	printf("Длина наибольшего слова: %d\n\n", fun(n, m, s));
	printf("Номер строки с наибольшим символом: %d\n\n", num);
	printf("Cтрока с наибольшим символом:\n");
	for (int i = 0; i < n; i++)
	{
		if (i == num - 1)
			puts(s[i]);
	}
	//Очищение памяти
	for (int i = 0; i < n; i++)
	{
		free(s[i]);
	}
	free(s);
	return 0;
}

int maxwordsize(int n, int m, char **s)
{
	int a=0, max=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((s[i][j] != ' ') && (s[i][j] != '\0') && (s[i][j] != '\n'))
				a++;
			else
			{
				if(a>=max)
				{
					max = a;
				}
				a = 0;
			}
		}
	}
	return max;
}

int strwithmaxword(int n, int m, char** s, int(*fun)(int, int, char**))
{
	int num=0, a=0, b;
	b = fun(n, m, s);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((s[i][j] != ' ') && (s[i][j] != '\0') && (s[i][j] != '\n'))
				a++;
			else
			{
				if (a == b)
				{
					num = i+1;
				}
				a = 0;
			}
		}
	}
	return num;
}