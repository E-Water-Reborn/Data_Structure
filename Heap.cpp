#include<iostream>
using namespace std;

typedef struct HeapStruct* MaxHeap;
typedef int ElementType;
struct HeapStruct {
	ElementType* Elements;
	int Size;
	int Capacity;
};

MaxHeap Create(int MaxSize)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
	H->Elements = (ElementType*)malloc((MaxSize + 1) * sizeof(ElementType));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Elements[0] = 1000;
	
	return H;
}

bool IsFull(MaxHeap H)
{
	return (H->Size == H->Capacity);
}

void Insert(MaxHeap H, ElementType item)
{
	int i;
	if (IsFull(H)) {
		cout << "������" << endl;
		return;
	}
	i = ++H->Size;
	for (; H->Elements[i / 2] < item; i /= 2)
		H->Elements[i] = H->Elements[i/2];
	H->Elements[i] = item;
}

bool IsEmpty(MaxHeap H)
{
	return (H->Size==0);
}

ElementType DeleteMax(MaxHeap H)
{
	int Parent, Child;
	ElementType MaxItem, temp;

	if (IsEmpty(H)) {
		cout << "���ѿ�" << endl;
		return;
	}
	MaxItem = H->Elements[1];
	temp = H->Elements[H->Size--];
	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
			Child++;
		if (temp >= H->Elements[Child]) break;
		else H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	return MaxItem;
}

void PercDown(MaxHeap H, int p)
{ /* ���ˣ���H����H->Data[p]Ϊ�����Ӷѵ���Ϊ���� */
	int Parent, Child;
	ElementType X;

	X = H->Elements[p]; /* ȡ��������ŵ�ֵ */
	for (Parent = p; Parent * 2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
			Child++;  /* Childָ�������ӽ��Ľϴ��� */
		if (X >= H->Elements[Child]) break; /* �ҵ��˺���λ�� */
		else  /* ����X */
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = X;
}

void BuildHeap(MaxHeap H)
{ /* ����H->Data[]�е�Ԫ�أ�ʹ�������ѵ�������  */
  /* �����������H->Size��Ԫ���Ѿ�����H->Data[]�� */

	int i;

	/* �����һ�����ĸ��ڵ㿪ʼ���������1 */
	for (i = H->Size / 2; i > 0; i--)
		PercDown(H, i);
}