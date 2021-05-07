#include<iostream>
using namespace std;

void Move(int n, int start, int goal, int temp)
{
	if (n >= 1) {
		Move(n - 1, start, temp, goal);
		cout << "From" << start << "To" << goal;
		Move(n - 1, temp, goal, start);
	}
}