#include<iostream>
using namespace std;

typedef int ElementType;
typedef struct TreeNode* BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

Position Find(ElementType X, BinTree BST)
{
	if (!BST) return NULL;
	if (BST->Data > X)
		Find(X, BST->Left);
	else if (BST->Data < X)
		Find(X, BST->Right);
	else
		return BST;
}

Position IterFind(ElementType X, BinTree BST)
{
	while (BST) {
		if (BST->Data > X) 
			BST = BST->Left;
		else if (BST->Data < X) 
			BST = BST->Right;
		else 
			return BST;
	}
	return NULL;
}

Position FindMin(BinTree BST)
{
	if (!BST) return NULL;
	else if (!BST->Left) return BST;
	else FindMin(BST->Left);
}

Position FindMax(BinTree BST)
{
	if (BST)
		while (BST->Right) BST = BST->Right;
	return BST;
}

BinTree Insert(ElementType X, BinTree BST)
{
	if (!BST) {
		BST = (BinTree)malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else {
		if (X < BST->Data) {
			BST->Left = Insert(X, BST->Left);
		}
		else {
			BST->Right = Insert(X, BST->Right);
		}
	}
	return BST;
}

BinTree Delete(ElementType X, BinTree BST)
{
	Position Tmp;
	if (!BST) cout << "要删除的元素未找到" << endl;
	else if (X < BST->Data)
		BST->Left = Delete(X, BST->Left);
	else if (X > BST->Data)
		BST->Right = Delete(X, BST->Right);
	else {
		if (BST->Left && BST->Right) {
			Tmp = FindMin(BST->Right);
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Data, BST->Right);
		}
		else {
			Tmp = BST;
			if (!BST->Left)
				BST = BST->Right;
			if (!BST->Right)
				BST = BST->Left;
			free(Tmp);
		}
	}
	return BST;
}
