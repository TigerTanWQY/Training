#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	int L = 0, R = 1, ans = 0;
	for(char sd; q--; ) {
		int pos, cnt1 = 0, cnt2 = 0;
		cin >> sd >> pos;
		pos = (pos - 1 + n) % n;
		bool flag = true;
		if(sd == 'L') {
			// 尝试顺时针: cnt1
			for(int i = L; flag && i != pos; i = (i + 1) % n)
				if(i == R)
					flag = false;
				else
					++cnt1;
			if(!flag)
				cnt1 = 0x3f3f3f3f;
			// 尝试逆时针: cnt2
			flag = true;
			for(int i = L; flag && i != pos; i = (i - 1 + n) % n)
				if(i == R)
					flag = false;
				else
					++cnt2;
			if(!flag)
				cnt2 = 0x3f3f3f3f;
			L = pos;
		} else {
			// 尝试顺时针: cnt1
			for(int i = R; flag && i != pos; i = (i + 1) % n)
				if(i == L)
					flag = false;
				else
					++cnt1;
			if(!flag)
				cnt1 = 0x3f3f3f3f;
			// 尝试逆时针: cnt2
			flag = true;
			for(int i = R; flag && i != pos; i = (i - 1 + n) % n)
				if(i == L)
					flag = false;
				else
					++cnt2;
			if(!flag)
				cnt2 = 0x3f3f3f3f;
			R = pos;
		}
		ans += min(cnt1, cnt2);
	}
	cout << ans << endl;
	return 0;
}