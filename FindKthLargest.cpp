#include<iostream>
using namespace std;

typedef int ElementType;
void Swap(ElementType* X, ElementType* Y) {
	ElementType tmp;
	tmp = *X;
	*X = *Y;
	*Y = tmp;
}

ElementType FIndKthLargest(ElementType S[], int K, int Left, int Right)
{
	ElementType e = S[Left];
	int L = Left, R = Right;

	while (1) {
		while ((Left <= Right) && (e <= S[Left])) Left++;
		while ((Left < Right) && (e > S[Right])) Right++;
		if (Left < Right)
			Swap(&S[Left], &S[Right]);
		else break;
	}

	Swap(&S[Left - 1], &S[L]);

	if ((Left - L - 1) >= K)
		return FIndKthLargest(S, K, L, Left - 2);
	else if ((Left - L - 1) < K - 1)
		return FIndKthLargest(S, K - (Left - L - 1), Left, R);
	else
		return e;

}