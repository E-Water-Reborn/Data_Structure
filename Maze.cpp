#include<iostream>
#include"Stack.cpp"
using namespace std;

#define MAXMATRIXSIZE 100
#define MAXSTACKSIZE 100

struct Offsets {
	short int Vert;
	short int Horiz;
};

struct MazePosition {
	short int Row;
	short int Col;
	short int Dir;
};
typedef struct MazePosition ElementType;

void Path(int Maze[][MAXMATRIXSIZE], int EXITROW, int EXITCOL)
{
	struct Offsets Move[8] =
	{ {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };
	int Mark[MAXMATRIXSIZE][MAXMATRIXSIZE];
	Stack S;
	struct MazePosition P;
	short int Row, Col, NextRow, NextCol, Dir;
	bool Found = false;

	S = CreateStack(MAXSTACKSIZE);

	Mark[EXITROW][EXITCOL] = 1;
	P.Row = EXITROW;
	P.Col = EXITCOL;
	P.Dir = 0;
	Push(S, P);

	while (!IsEmpty(S) && !Found) {
		P = Pop(S);
		Row = P.Row;
		Col = P.Col;
		Dir = P.Dir;

		while (Dir < 8 && !Found) {
			NextRow = Row + Move[Dir].Vert;
			NextCol = Col + Move[Dir].Horiz;
			if (NextRow == 1 && NextCol == 1)
				Found = true;
			else
				if (!Maze[NextRow][NextCol] && !Mark[NextRow][NextCol]) {	//��һλ�ÿ�ͨ��δ�߹�
					Mark[NextRow][NextCol] = 1;
					P.Row = Row;
					P.Col = Col;
					P.Dir = Dir + 1;		//��һ������: ���������һ����,��ջʱ���ش�������һ�δ���·��
					Push(S, P);
					Row = NextRow; Col = NextCol; Dir = 0;
				}
				else ++Dir;
		}
	}

	if (Found) {
		cout << "�ҵ�·������" << endl;
		cout << "�� ��" << endl;
		cout << "1	1" << endl;
		cout << Row << "	" << Col << endl;
		while (!IsEmpty(S)) {
			P = Pop(S);
			cout << P.Row << "	" << P.Col << endl;
		}
	}
	else
		cout << "���Թ��޽�" << endl;
}