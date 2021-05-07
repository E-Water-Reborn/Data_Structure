#include<iostream>
using namespace std;

typedef int ElementType;
typedef struct TreeNode* BinTree;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreOrderTraversal(BinTree BT)
{
	if (BT) {
		cout << BT->Data;
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}

void InOrderTraversal(BinTree BT)
{
	if (BT) {
		InOrderTraversal(BT->Left);
		cout << BT->Data;
		InOrderTraversal(BT->Right);
	}
}

void PostOrderTraversal(BinTree BT)
{
	if (BT) {
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		cout << BT->Data;
	}
}

