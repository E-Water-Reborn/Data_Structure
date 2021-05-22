#include<iostream>
#include<queue>
using namespace std;

#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;


//边
typedef struct ENode* PtrToENode;
struct ENode {
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

//邻接点
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjVNode Next;
};

//顶点表头结点
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;
	DataType Data;
} AdjList[MaxVertexNum];

//图节点
typedef struct GNode* PtrToGNode;
struct GNode {
	int Nv;
	int Ne;
	AdjList G;
};
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum)
{
	Vertex V;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
	LGraph Graph;
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
		cin >> Graph->G[V].Data;

	return Graph;
}

Vertex Visited[MaxVertexNum] = { false };

void Visit(Vertex V)
{
	cout << "正在访问顶点" << V << endl;
}

void DFS(LGraph Graph, Vertex V, void (*Visit)(Vertex))
{
	PtrToAdjVNode W;

	Visit(V);
	Visited[V] = true;
	
	for (W = Graph->G[V].FirstEdge; W; W = W->Next)
		if (!Visited[W->AdjV])
			DFS(Graph, W->AdjV, Visit);
}

void Unweighted(LGraph Graph, int dist[], int path[], Vertex S)
{
	queue<int> Q;
	Vertex V;
	PtrToAdjVNode W;

	Q.push(S);
	dist[S] = 0;

	while (!Q.empty()) {
		V = Q.front();
		Q.pop();
		for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
			if (dist[W->AdjV] == -1) {
				Q.push(W->AdjV);
				dist[W->AdjV] = dist[V] + 1;
				path[W->AdjV] = V;
			}
		}
	}
}
