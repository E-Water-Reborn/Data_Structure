#include<iostream>
#include"Queue.cpp"
using namespace std;

#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ENode* PtrToENode;
struct ENode {
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct GNode* PtrToGNode;
struct GNode {
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph CreateGraph(int VertexNum)
{
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	Graph->G[E->V1][E->V2] = E->Weight;
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	cin >> Nv;
	Graph = CreateGraph(Nv);

	cin >> Graph->Ne;
	if (Graph->Ne != 0) {
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; i < Graph->Ne; i++) {
			cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(Graph, E);
		}
	}

	for (V = 0; V < Graph->Nv; V++)
		cin >> Graph->Data[V];
	
	return Graph;
}

void Visit(Vertex V)
{
	cout << "???ڷ???" << V << endl;
}

bool Visited[MaxVertexNum] = { false };

bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W] < INFINITY ? true : false;
}

void BFS(MGraph Graph, Vertex S, void(*Visit)(Vertex))
{
	Queue Q;
	Vertex V, W;

	Q = CreateQueue(Graph->Nv);
	Visit(S);
	Visited[S] = true;
	AddQ(Q, S);

	while (!IsEmpty(Q)) {
		V = DeleteQ(Q);
		for (W = 0; W < Graph->Nv; ++W) {
			if (IsEdge(Graph, V, W) && !Visited[W]) {
				Visit(W);
				Visited[W] = true;
				AddQ(Q, W);
			}
		}
	}
}

bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
{

}