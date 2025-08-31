#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	unordered_map<int, int> cnt;
	for(int i = s1; i; --i)
		for(int j = s2; j; --j)
			for(int k = s3; k; --k)
				++cnt[i + j + k];
	cout <<
		max_element(cbegin(cnt), cend(cnt),
		[](const pair<int, int>& A, const pair<int, int>& B)
		{ return A.second != B.second? A.second < B.second:
			A.first > B.first; })->first << endl;
	return 0;
}
