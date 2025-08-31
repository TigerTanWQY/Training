#include <bits/stdc++.h>
using namespace std;
const int n = 512, N = n + 10;
void multiply (int c[N][N], int a[N][N], int b[N][N]) {
	for(int l = 0; l < n; ++l)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				c[i][j] += a[i][l] * b[l][j];
}
int c[N][N], a[N][N], b[N][N];
int main() {
	int seedA, seedB;
	scanf("%d%d", &seedA, &seedB);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = ((i | j) + j) ^ seedA;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			b[i][j] = ((i & j) + i) ^ seedB;
	multiply(c, a, b);
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) sum ^= c[i][j];
		printf("%d\n", sum);
	}
	return 0;
}
