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
				if (!Maze[NextRow][NextCol] && !Mark[NextRow][NextCol]) {	//下一位置可通且未走过
					Mark[NextRow][NextCol] = 1;
					P.Row = Row;
					P.Col = Col;
					P.Dir = Dir + 1;		//下一个方向: 如果不是下一方向,退栈时又沿错误方向走一次错误路径
					Push(S, P);
					Row = NextRow; Col = NextCol; Dir = 0;
				}
				else ++Dir;
		}
	}

	if (Found) {
		cout << "找到路径如下" << endl;
		cout << "行 列" << endl;
		cout << "1	1" << endl;
		cout << Row << "	" << Col << endl;
		while (!IsEmpty(S)) {
			P = Pop(S);
			cout << P.Row << "	" << P.Col << endl;
		}
	}
	else
		cout << "该迷宫无解" << endl;
}