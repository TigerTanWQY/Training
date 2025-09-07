#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	scanf("%d-%d", &a, &b);
	if(b == 8)
		printf("%d-%d", a+1, 1);
	else
		printf("%d-%d", a, b+1);
	putchar('\n'); return 0;
}
