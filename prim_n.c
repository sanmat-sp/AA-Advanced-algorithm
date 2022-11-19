#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define V 9

int minKey(int key[], int mstSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == 0 && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int graph[V][V])
{
	printf("Edge \tWeight\n");
	for (int i = 1; i < V; i++)
        printf("%d - %d \t %d\n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
	int parent[V];

	int key[V];

	int mstSet[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = 0;

	key[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet);

		mstSet[u] = 1;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && mstSet[v] == 0&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	printMST(parent, graph);
}

int main()
{
	clock_t t1, t2, t;
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	t1= clock();
	primMST(graph);
	t2= clock();
	t=t2-t1;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time taken for Prim's algorith(normal method) : %f", time_taken);
	return 0;
}
