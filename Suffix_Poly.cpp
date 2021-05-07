#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

typedef int Position;
struct SNode {
    ElementType* Data; /* 存储元素的数组 */
    Position Top;      /* 栈顶指针 */
    int MaxSize;       /* 堆栈最大容量 */
};
typedef struct SNode* Stack;

#define MAXOP 100
#define INFINITY 1e9
typedef double ElementType;
typedef enum { num, opr, End }Type;

ElementType PostfixExp(char* Expr);

int main()
{
    char Expr[MAXOP];
    ElementType f;

    gets_s(Expr);
    f = PostfixExp(Expr);
    if (f < INFINITY)
        cout << f << endl;
    else
        cout << ("表达式错误") << endl;

    return 0;
}



Stack CreateStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

bool IsFull(Stack S)
{
    return (S->Top == S->MaxSize - 1);
}

bool Push(Stack S, ElementType X)
{
    if (IsFull(S)) {
        printf("堆栈满");
        return false;
    }
    else {
        S->Data[++(S->Top)] = X;
        return true;
    }
}

bool IsEmpty(Stack S)
{
    return (S->Top == -1);
}

ElementType Pop(Stack S)
{
    if (IsEmpty(S)) {
        printf("堆栈空");
        return -1; /* ERROR是ElementType的特殊值，标志错误 */
    }
    else
        return (S->Data[(S->Top)--]);
}

Type GetOp(char* Expr, int* start, char* str)
{
    int i = 0;
     
    while ((str[0] = Expr[(*start)++]) == ' ');

    while (str[i] != ' ' && str[i] != '\0')
        str[++i] = Expr[(*start)++];
    if (str[i] == '\0')
        (*start)--;
    str[i] = '\0';

    if (i == 0) return End;
    else if (isdigit(str[0]) || isdigit(str[1]))
        return num;
    else return opr;
}

ElementType PostfixExp(char* Expr)
{
    Stack S;
    Type T;
    ElementType Op1, Op2;
    char str[MAXOP];
    int start = 0;

    S = CreateStack(MAXOP);

    Op1 = Op2 = 0;
    while ((T = GetOp(Expr, &start, str))!= End) {
        if (T == num)
            Push(S, atof(str));
        else {
            if (!IsEmpty(S)) Op2 = Pop(S);
            else Op2 = INFINITY;
            if (!IsEmpty(S)) Op1 = Pop(S);
            else Op2 = INFINITY;
            switch (str[0]) {
            case '+': Push(S, Op1 + Op2); break;
            case '*': Push(S, Op1 * Op2); break;
            case '-': Push(S, Op2 - Op2); break;
            case '/':
                if (Op2 != 0.0)
                    Push(S, Op1 / Op2);
                else {
                    cout << "错误:除法分母为0" << endl;
                    Op2 = INFINITY;
                }
                break;
            default:
                cout << "错误:未知运算符" << str << endl;
                Op2 = INFINITY;
                break;
            }
            if (Op2 >= INFINITY) break;

        }
    }
    if (Op2 < INFINITY)
        if (!IsEmpty(S))
            Op2 = Pop(S);
        else Op2 = INFINITY;
    free(S);
    return Op2;
}