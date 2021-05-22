#include<iostream>
#include"Graph_Link.cpp"
#include"Graph_Matrix.cpp"
using namespace std;

#define ERROR -1

Vertex FindMinDist(LGraph Graph, WeightType dist[])
{
	Vertex MinV, V;
	WeightType MinDist = INFINITY;

	for (V = 0; V < Graph->Nv; ++V) {
		if (dist[V]!=0 && dist[V] < MinDist) {
			MinDist = dist[V];
			MinV = V;
		}
	}

	if (MinDist < INFINITY)
		return MinV;
	else return ERROR;
}

int Prim(MGraph Graph, LGraph MST)
{
	WeightType dist[MaxVertexNum], TotalWeight;
	Vertex parent[MaxVertexNum], V, W;
	int VCount;
	Edge E;

	for (V = 0; V < VCount; ++V) {
		dist[V] = Graph->G[0][V];
		parent[V] = 0;
	}
	TotalWeight = 0;
	VCount = 0;
	MST = CreateGraph(Graph->Nv);
	E = (Edge)malloc(sizeof(struct ENode));

	VCount++;
	parent[0] = -1;
	dist[0] - 0;

	while (1) {
		V = FindMinDist(Graph, dist);

		if (V == ERROR) {
			break;
		}

		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(Graph, E);

		TotalWeight += dist[V];
		dist[V] = 0;

		for (W = 0; W < Graph->Nv; ++W) {
			if (!dist[W] && Graph->G[V][W] < INFINITY) {
				if (Graph->G[V][W] < dist[W]) {
					dist[W] = Graph->G[V][W];
					parent[W] = V;
				}
			}
		}
	}
	if (VCount < Graph->Nv)
		TotalWeight = ERROR;

	return TotalWeight;
}