#include<iostream>
#include"Queue.cpp"
#include"Stack.cpp"
using namespace std;

typedef int ElementType;
typedef struct TreeNode* BinTree;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void LevelOrderTraversal(BinTree BT)
{
	BinTree T;
	Queue Q;
	if (!BT) return;
	Q = CreateQueue(100);
	AddQ(Q, BT);
	while (!IsEmpty(Q)) {
		T = DeleteQ(Q);
		cout << T->Data;
		if (T->Left) AddQ(Q, T->Left);
		if (T->Right) AddQ(Q, T->Right);
	}
}

void LevelOrderTraversal(BinTree BT)
{
	BinTree T;
	Stack S;
	if (!BT) return;
	S = CreateStack(100);
	Push(S, T);
	while (!IsEmpty(S)) {
		T = Pop(S);
		cout << T->Data;
		if (T->Right) Push(S, T->Right);
		if (T->Left) Push(S, T->Left);
	}
}