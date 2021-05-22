#include<iostream>
#include"Graph_Matrix.cpp"
using namespace std;

Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
{
	Vertex V, MinV;
	int MinDist = INFINITY;
	for (V = 0; V < Graph->Nv; ++V) {
		if (!collected[V] && dist[V] < MinDist) {
			MinDist = dist[V];
			MinV = V;
		}
	}
	if (MinDist < INFINITY)
		return MinV;
	else return -1;
}

bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
{
	int collected[MaxVertexNum];
	Vertex V, W;

	for (V = 0; V < Graph->Nv; ++V) {
		dist[V] = Graph->G[S][V];
		if (dist[V] < INFINITY)
			path[V] = S;
		else
			path[V] = -1;
		collected[V] = false;
	}

	collected[S] = true;
	dist[S] = 0;

	while (1) {
		V = FindMinDist(Graph, dist, collected);
		if (V == -1) break;
		collected[V] = true;
		for (W = 0; W < Graph->Nv; ++W) {
			if (!collected[W] && Graph->G[V][W] < INFINITY) {
				if (Graph->G[V][W] < 0)
					return false;
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W];
					path[W] = V;
				}
			}
		}
	}

	return true;
}