#include <iostream>
using namespace std;

typedef int ElementType;
struct Node {
	ElementType Data;
	struct Node* Next;
};
struct QNode {
	struct Node* rear;
	struct Node* front;
};
typedef struct QNode* Queue;

void AddQ(ElementType item, Queue Q)
{
	struct Node* RearCell = (struct Node*)malloc(sizeof(struct Node));
	RearCell->Data = item;
	RearCell->Next = NULL;
	Q->rear->Next = RearCell;
	Q->rear = RearCell;
}

ElementType DeleteQ (Queue Q)
{
	if (Q->front == NULL) {
		cout << "╤сап©у" << endl;
		return -1;
	}
	struct Node* FrontCell;
	ElementType FrontElem;
	FrontCell = Q->front;
	if (Q->front == Q->rear)
		Q->front = Q->rear = NULL;
	else 
		Q->front = Q->front->Next;
	FrontElem = FrontCell->Data;
	free(FrontCell);
	return FrontElem;
}