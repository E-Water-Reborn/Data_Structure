#include<iostream>
using namespace std;

typedef int ElementType;
struct SetType {
	ElementType Data;
	int Parent;
};

int Find(SetType S[], ElementType X)
{
	int i;
	for (i = 0; i < MaxSize && S[i].Data != X; i++);
	if (i >= MaxSize) return -1;
	for (; S[i].Parent >= 0; i = S[i].Parent);
	return i;
}

void Union(SetType S[], ElementType X1, ElementType X2)
{
	int Root1, Root2;
	Root1 = Find(S, X1);
	Root2 = Find(S, X2);
	if (Root1 != Root2) S[Root2].Parent = Root1;
}