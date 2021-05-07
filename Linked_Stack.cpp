#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct SNode* Stack;
struct SNode {
	ElementType Data;
	Stack Next;
};

Stack CreateStack()
{
	Stack s;
	s = (Stack)malloc(sizeof(struct SNode));
	s->Next = NULL;
	return s;
}

int IsEmpty(Stack s)
{
	return (s->Next == NULL);
}

void Push(ElementType item, Stack s)
{
	Stack TmpCell;
	TmpCell = (Stack)malloc(sizeof(struct SNode));
	TmpCell->Data = item;
	TmpCell->Next = s->Next;
	s->Next = TmpCell;
}

ElementType Pop(Stack s)
{
	Stack FirstCell;
	ElementType TopElem;
	if (IsEmpty(s)) {
		cout << "¶ÑÕ»¿Õ" << endl;
		return NULL;
	}
	else {
		FirstCell = s->Next;
		s->Next = FirstCell->Next;
		TopElem = FirstCell->Data;
		free(FirstCell);
		return TopElem;
	}
}