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
		cout << "堆已满" << endl;
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
		cout << "堆已空" << endl;
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
{ /* 下滤：将H中以H->Data[p]为根的子堆调整为最大堆 */
	int Parent, Child;
	ElementType X;

	X = H->Elements[p]; /* 取出根结点存放的值 */
	for (Parent = p; Parent * 2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
			Child++;  /* Child指向左右子结点的较大者 */
		if (X >= H->Elements[Child]) break; /* 找到了合适位置 */
		else  /* 下滤X */
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = X;
}

void BuildHeap(MaxHeap H)
{ /* 调整H->Data[]中的元素，使满足最大堆的有序性  */
  /* 这里假设所有H->Size个元素已经存在H->Data[]中 */

	int i;

	/* 从最后一个结点的父节点开始，到根结点1 */
	for (i = H->Size / 2; i > 0; i--)
		PercDown(H, i);
}