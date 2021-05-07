#include<iostream>
using namespace std;

#define MAXSIZE 10
typedef struct LNode* List;
typedef int ElementType;
struct LNode {
	ElementType Data[MAXSIZE];
	int Last;
};


int main()
{

}

List MakeEmpty()
{
	List PtrL;
	PtrL = (List)malloc(sizeof(struct LNode));
	PtrL->Last = -1;
	return PtrL;
}

int Find(ElementType X, List PtrL)
{
	int i = 0;
	while (i <= PtrL->Last && PtrL->Data[i] != X) {
		i++;
	}
	if (i > PtrL->Last) return -1;
	else return i;
}

void Insert(ElementType X, int i, List PtrL)
{
	if (i<1 || i>PtrL->Last + 2) {
		cout << "位置不合法" << endl;
		return;
	}
	if (PtrL->Last == MAXSIZE - 1) {
		cout << "满表" << endl;
		return;
	}
	for (int j = PtrL->Last; j >= i; j--) {
		PtrL->Data[j + 1] = PtrL->Data[j];
	}
	PtrL->Data[i] = X;
	PtrL->Last++;
	return;
}

void Delete(int i, List PtrL)
{
	if (i<1 || i>PtrL->Last + 1) {
		cout << "不存在第" << i << "个元素";
		return;
	}
	for (int j = i; j < PtrL->Last; j++) {
		PtrL->Data[j - 1] = PtrL->Data[j];
	}
	PtrL--;
	return;
}

