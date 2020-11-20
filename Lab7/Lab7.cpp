// Lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <queue>
#include <locale.h>

#include <windows.h>
using namespace std;
const int s = 6;
void rand_Zap(int* Matrix, int n) {
	srand(time(NULL));
	printf("G\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) {
				Matrix[i * n + j] = 0;
			}
			if (i < j) {
				Matrix[i * n + j] = rand() % 10;
				Matrix[j * n + i] = Matrix[i * n + j];
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
void BFSD(int* Matrix, int* dist, int n, int v) {
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
int main()
{
	setlocale(LC_ALL, "Rus");
	int G[s][s], DIST[s], v;
	rand_Zap(&G[0][0], s);
	print_G(&G[0][0], s);
	for (int i = 0; i < s; i++) {
		dsit_0(&DIST[0], s);
		printf("от вершины %d\n", i + 1);
		BFSD(&G[0][0],&DIST[0], s, i);
		for (int j = 0; j < s; j++)
		{
			if (DIST[j] != -1)
				printf("%d \t", DIST[j]);
			else
				printf("нет прохода \t");
		}
		printf("\n");
	}
}


