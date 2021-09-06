#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define FALSE 0
#define TRUE 1
short int visited[MAX_VERTICES];

void dfs(int v) {
	node_pointer w;
	visited[v] = TRUE;
	printf("%5d", v);
	for (w = graph[v]; w; w = w->link)
		if (!visited[w->vertex])dfs(w->vertex);
}


typedef struct queue* queue_pointer;
typedef struct queue {
	int vertex;
	queue_pointer link;
};
void addq(queue_pointer*, queue_pointer*, int);
int deleteq(queue_pointer*);

void bfs(int v) {
	node_pointer w;
	queue_pointer front = NULL, rear = NULL;

	printf("%5d", v);
	visited[v] = TRUE;
	addq(&front, &rear, v);
	while (front) {
		v = deleteq(&front);
		for(w=graph[v];w;w=w->link)
			if (!visited[w->vertex]) {
				printf("%5d", w->vertex);
				addq(&front, &rear, w->vertex);
				visited[w->vertex] = TRUE;
			}
	}
}