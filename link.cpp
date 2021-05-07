#include<iostream>
using namespace std;

typedef struct LNode* List;
typedef int ElementType;
struct LNode {
	ElementType Data;
	List Next;
};
List PtrL;
int Length(List PtrL)
{
	int i = 0;
	List p = PtrL;
	while (p) {
		p = p->Next;
		i++;
	}
	return i;
}

List FindKth(int K, List PtrL)
{
	int i = 1;
	List p = PtrL;
	while (p != NULL && i < K) {
		p = p->Next;
		i++;
	}
	if (i == K) return p;
	else return NULL;
}

List Find(ElementType X, List PtrL)
{
	List p = PtrL;
	while (X != p->Data && p != NULL) {
		p = p->Next;
	}
	return p;
}

List Insert(ElementType X, int i, List PtrL)
{
	List p, s;
	if (i == 1) {
		s = (List)malloc(sizeof(struct LNode));
		s->Next = PtrL;
		s->Data = X;
		return s;
	}
	p = FindKth(i-1, PtrL);
	if (p == NULL) {
		cout << "参数错误" << endl;
		return NULL;
	}
	else {
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = p->Next;
		p->Next = s;
		return PtrL;
	}
}

List Delete(int i, List PtrL)
{
	List s, p;
	if (i == 1) {
		s = PtrL;
		if (PtrL != NULL) PtrL = PtrL->Next;
		else return NULL;
		free(s);
		return PtrL;
	}
	p = FindKth(i - 1, PtrL);
	if (p == NULL) {
		cout << "第" << i - 1 << "个节点不存在";
	}
	else if (p->Next == NULL) {
		cout << "第" << i << "个节点不存在";
	}
	else {
		s = p->Next;
		p->Next = s->Next;
		free(s);
		return PtrL;
	}
}