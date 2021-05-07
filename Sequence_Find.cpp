#include<iostream>
using namespace std;
#define MaxSize 10
typedef int ElementType;
typedef struct LNode* List;
struct LNode {
	ElementType Data[MaxSize]; 
	int Length;
};

int SequentialSearch(List Tbl, ElementType K)
{
	int i;
	Tbl->Data[0] = K;
	for (i = Tbl->Length; Tbl->Data[i] != K; i--);
	return i;
}

int BinarySearch(List Tbl, ElementType K)
{
	int left, right, mid, NotFound = -1;
	left = 1;
	right = Tbl->Length;
	while (left < right) {
		mid = (left + right) / 2;
		if (Tbl->Data[mid] < K) left = mid + 1;
		else if (Tbl->Data[mid] > K) right = mid - 1;
		else return mid;
	}
	return NotFound;
}