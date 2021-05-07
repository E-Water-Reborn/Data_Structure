#include<iostream>
#include"Stack.cpp"
using namespace std;

typedef int ElementType;
typedef struct TreeNode* BinTree;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void InOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreateStack();
	while (T || !IsEmpty(S)) {
		while (T) {
			Push(S, T);
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S);
			cout << T->Data;
			T = T->Right;
		}
	}
}

void PreOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreateStack(100);
	while (T || !IsEmpty(S)) {
		while (T) {
			Push(S, T);
			cout << T->Data;
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S);
			T = T->Right;
		}
	}
}

void PostOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreateStack(100);
	while (T || !IsEmpty(S)) {
		while (T) {
			Push(S, T);
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = T->Right;
			T = Pop(S);
			cout << T->Data;
		}
	}
}