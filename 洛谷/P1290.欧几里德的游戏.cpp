#include <bits/stdc++.h>
using namespace std;

bool dfs(int a, int b) {
	if(b == a)
		return true;
	else if(b / a >= 2)
		return true;
	else
		return true ^ dfs(b - a, a);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
    for(int n, m; _T--; cout.put('\n')) {
		cin >> n >> m;
        if(n > m)
			swap(n, m);
        if(dfs(n, m))
			cout << "Stan wins";
        else
			cout << "Ollie wins";
    }
    cout.flush();
    return 0;
}
