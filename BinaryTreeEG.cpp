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
		if (!BT->Left && !BT->Left) cout << BT->Data;
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}

int PostOrderTraversal(BinTree BT)
{
	int HL, HR, Max;
	if (BT) {
		HL = PostOrderTraversal(BT->Left);
		HR = PostOrderTraversal(BT->Right);
		Max = HL > HR ? HL : HR;
		return (Max + 1);
	}
	else return 0;
}