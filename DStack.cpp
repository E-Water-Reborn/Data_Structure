#include <iostream>
using namespace std;

#define MaxSize 10
typedef int ElementType;
struct DStack {
	ElementType Data[MaxSize];
	int Top1;
	int Top2;
} S;

void Push(struct DStack* PtrS, ElementType item, int Tag)
{
	if (PtrS->Top2 - PtrS->Top1 == 1) {
		cout << "¶ÑÕ»Âú" << endl;
		return;
	}
	else {
		if (Tag == 1)
			PtrS->Data[++(PtrS->Top1)] = item;
		else
			PtrS->Data[--(PtrS->Top2)] = item;
	}
}

ElementType Pop(struct DStack* PtrS, int Tag)
{
	if (Tag == 1) {
		if (PtrS->Top1 == -1) {
			cout << "¶ÑÕ»1¿Õ" << endl;
			return NULL;
		}
		else {
			return (PtrS->Data[(PtrS->Top1)--]);
		}
	}
	else {
		if (PtrS->Top2 == MaxSize) {
			cout << "¶ÑÕ»2¿Õ" << endl;
			return NULL;
		}
		else {
			return (PtrS->Data[(PtrS->Top2)++]);
		}
	}
}