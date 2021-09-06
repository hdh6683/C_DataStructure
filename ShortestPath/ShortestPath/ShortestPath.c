#include <stdio.h>
#define MAX_VERTICES 6
#define _CRT_SECURE_NO_WARNINGS
#define FALSE 0
#define TRUE 1

int cost[][MAX_VERTICES] =
{ 
{	0,     50,      10,  1000,     45, 1000},
{ 1000,       0,     15,  1000,     10, 1000},
{    20,  1000,       0,      15, 1000, 1000},
{ 1000,     20,  1000,       0,     35, 1000},
{ 1000, 1000,      30,  1000,       0, 1000},
{ 1000, 1000,  1000,        3,  1000,     0} };

int distance[MAX_VERTICES], n = MAX_VERTICES;
short int found[MAX_VERTICES];

void shortestpath(int v, int cost[][MAX_VERTICES], int distance[], int n, short int found[]) {
	int i, u, w;
	for (i = 0; i < n; i++) {
		found[i] = FALSE; distance[i] = cost[v][i];
	}
	found[v] = TRUE;
	distance[v] = 0;
	for (i = 0; i < n - 2; i++) {
		u = choose(distance, n, found);
		found[u] = TRUE;
		for (w = 0; w < n; w++)
			if (!found[w])
				if (distance[u] + cost[u][w] < distance[w])
					distance[w] = distance[u] + cost[u][w];
	}
}

int choose(int distance[], int n, short int found[]) {
	int i, min, minpos;

	min = INT_MAX;
	minpos = -1;
	for(i=0;i<n;i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}