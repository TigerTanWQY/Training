#include <iostream>
using namespace std;

struct TreeNode
{ int L, R, w; }
a[1003];

void LTR(const int &p) {
	if(a[p].L)
		LTR(a[p].L);
	cout << a[p].w << ' ';
	if(a[p].R)
		LTR(a[p].R);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].w;
	for(int i = 2; i <= n; ++i)
		for(int p = 1; ; )
			if(a[i].w >= a[p].w)
				if(a[p].L)
					p = a[p].L;
				else {
					a[p].L = i;
					break;
				}
			else if(a[p].R)
				p = a[p].R;
			else {
				a[p].R = i;
				break;
			}
	LTR(1);
	return 0;
}