// Lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <queue>
#include <locale.h>
#include <malloc.h>
#include <windows.h>

using namespace std;
void rand_Zap_vz_or(int* Matrix, int n) {
	srand(time(NULL));
	printf("Взвешаный орентированный граф\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) {
				Matrix[i * n + j] = 0;
			}
			if (i < j) {
				if (rand() % 100 > 50) {
					Matrix[i * n + j] = rand() % 10;
					if (rand() % 100 > 50)
						Matrix[j * n + i] = 0;
					else
						Matrix[j * n + i] = Matrix[i * n + j];
				}
				else 
					if (rand() % 100 > 50) {
						Matrix[j * n + i] = rand() % 10;
						Matrix[i * n + j] = 0;
					}
					else{
						Matrix[i * n + j] = 0;
						Matrix[j * n + i] = 0;
					}
			}
		}
}
void rand_Zap_vz_nor(int* Matrix, int n) {
	srand(time(NULL));
	printf("Взвешаный неорентированный граф\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) {
				Matrix[i * n + j] = 0;
			}
			if (i < j) {
				if (rand() % 100 > 50)
					Matrix[i * n + j] = rand() % 10;
				else
					Matrix[i * n + j] = 0;
				Matrix[j * n + i] = Matrix[i * n + j];
			}
		}
}
void rand_Zap_nor(int* Matrix, int n) {
	srand(time(NULL));
	printf("Не взвешаный неорентированный граф\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) {
				Matrix[i * n + j] = 0;
			}
			if (i < j) {
				Matrix[i * n + j] = rand() % 2;
				Matrix[j * n + i] = Matrix[i * n + j];
			}
		}
}
void rand_Zap_or(int* Matrix, int n) {
	srand(time(NULL));
	printf("Не взвешаный орентированный граф\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) {
				Matrix[i * n + j] = 0;
			}
			if (i < j) {
				if (rand() % 100 > 50) {
					Matrix[i * n + j] = rand() % 2;
					if (rand() % 100 > 50)
						Matrix[j * n + i] = 0;
					else
						Matrix[j * n + i] = Matrix[i * n + j];
				}
				else
					if (rand() % 100 > 50) {
						Matrix[j * n + i] = rand() % 2;
						Matrix[i * n + j] = 0;
					}
					else {
						Matrix[i * n + j] = 0;
						Matrix[j * n + i] = 0;
					}
			}
		}
}
void print_G(int* Matrix, int n) {
	printf("  ");
	for (int i = 0; i < n; i++)
		printf("%3d", i + 1);
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		printf("%2d", i + 1);
		for (int j = 0; j < n; j++) {

			printf("%3d", Matrix[i * n + j]);
		}
		printf("\n");
	}
	printf("\n");


}
void dsit_0(int* Matrix, int n) {
	for (int i = 0; i < n; i++)
		Matrix[i] = -1;
}
void BFSD_vz(int* Matrix, int* dist, int n, int v) {
	queue <int> Q;
	Q.push(v);
	dist[v] = 0;
	while (Q.empty() == false) {
		v = Q.front();
		Q.pop();
		printf("%d ", v + 1);
		for (int i = 0; i < n; i++) {
			if ((Matrix[v*n+i] != 0) && dist[i] == -1) {
				Q.push(i);
				dist[i] = dist[v] + Matrix[v * n + i];
			}
		}
	}
	printf("\n");
}
void BFSD(int* Matrix, int* dist, int n, int v)
{
	queue <int> Q;
	Q.push(v);
	dist[v] = 0;
	while (Q.empty() == false) {
		v = Q.front();
		Q.pop();
		printf("%d ", v + 1);
		for (int i = 0; i < n; i++) {
			if ((Matrix[v * n + i] == 1) && dist[i] == -1) {
				Q.push(i);
				dist[i] = dist[v] + 1;
			}
		}
	}
	printf("\n");
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Rus");
	if (argc != 3) {
		printf("Error: found %d arguments. Needs exactly 2", argc - 1);
		exit(1);
	}
	int* a, * DIST, size;
	printf("введите кол-во вершин\n");
	scanf("%d", &size);
	a = (int*)malloc(size * size * sizeof(int));
	DIST = (int*)malloc(size * sizeof(int));
	switch (atoi(argv[1]))
	{
	case 0: switch (atoi(argv[2])) {
		case 0:rand_Zap_nor(a, size);
			break;
		case 1:rand_Zap_or(a, size);
			break;
	}
		  break;
	case 1:switch (atoi(argv[2])) {
		case 0:rand_Zap_vz_nor(a, size);
			break;
		case 1:rand_Zap_vz_or(a, size);
			break;
	}
		  break;
	}
	print_G(a, size);

	switch (atoi(argv[1]))
	{
	case 0:for (int i = 0; i < size; i++) {
		dsit_0(DIST, size);
		printf("от вершины %d\n", i + 1);
		BFSD(a, DIST, size, i);
		for (int j = 0; j < size; j++)
		{
			if (DIST[j] != -1)
				printf("%d \t", DIST[j]);
			else
				printf("нет прохода \t");
		}
		printf("\n");
		
	}
		  break;
	case 1:for (int i = 0; i < size; i++) {
		dsit_0(DIST, size);
		printf("от вершины %d\n", i + 1);
		BFSD_vz(a, DIST, size, i);
		for (int j = 0; j < size; j++)
		{
			if (DIST[j] != -1)
				printf("%d \t", DIST[j]);
			else
				printf("нет прохода \t");
		}
		printf("\n");
	}
		  break;
	}
}


