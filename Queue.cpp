#include <iostream>
using namespace std;

typedef int ElementType;
typedef int Position;
struct QNode {
    ElementType* Data;     /* �洢Ԫ�ص����� */
    Position Front, Rear;  /* ���е�ͷ��βָ�� */
    int MaxSize;           /* ����������� */
};
typedef struct QNode* Queue;

Queue CreateQueue(int MaxSize)
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType*)malloc(MaxSize * sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool IsFull(Queue Q)
{
    return ((Q->Rear + 1) % (Q->MaxSize) == Q->Front);
}

void AddQ(Queue Q, ElementType item)
{
    if (IsFull(Q)) {
        cout << "������" << endl;
        return;
    }
    else {
        Q->Rear = (Q->Rear + 1) % Q->MaxSize;
        Q->Data[Q->Rear] = item;
    }
}

bool IsEmpty(Queue Q)
{
    return (Q->Front == Q->Rear);
}

ElementType DeleteQ(Queue Q)
{
    if (IsEmpty(Q)) {
        cout << "���п�" << endl;
        return -1;
    }
    else {
        Q->Front = (Q->Front + 1) % Q->MaxSize;
        return Q->Data[Q->Front];
    }
}