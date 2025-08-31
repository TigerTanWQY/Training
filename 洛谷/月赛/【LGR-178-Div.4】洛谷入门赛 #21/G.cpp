#include <iostream>
using namespace std;

const int N = 1003;
int a[5][N], b[5][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 1; j <= 4; ++j)
			cin >> a[j][i];
	for(int i = 0; i < n; ++i)
		for(int j = 1; j <= 4; ++j)
			cin >> b[j][i];
	for(int x = 0; x < n; ++x) { // 开始
		int tot = 0;
		for(int i = 0, j = x; i < n; ++i, j = (j + 1) % n) { // 判题
			int flag = 2;
			for(int k = 1; k <= 4 && flag; ++k) // 选项
				if(!a[k][i] && b[k][j])
					flag = 0;
				else if(a[k][i] && !b[k][j])
					flag = 1;
			if(flag == 2)
				tot += 6;
			else if(flag == 1)
				tot += 3;
		}
		cout << tot << ' ';
	}
	return 0;
}