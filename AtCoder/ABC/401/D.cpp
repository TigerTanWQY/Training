#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int N, K;
	string S;
	cin >> N >> K >> S;
	int original_o = count(cbegin(S), cend(S), 'o');
	vector<int> pos;
	for (int i = 0; i < N; ++i)
		if (S[i] == '?') {
			bool left_ok = true;
			if (i > 0 && S[i-1] == 'o') left_ok = false;
			bool right_ok = true;
			if (i < N-1 && S[i+1] == 'o') right_ok = false;
			if (left_ok && right_ok)
				pos.push_back(i);
		}
	int x = K - original_o;
	string T = S;
	for (int i = 0; i < N; ++i)
		if (S[i] == '?')
			if (find(cbegin(pos), cend(pos), i) == cend(pos))
				T[i] = '.';
	if (x == 0)
		for (int p : pos)
			T[p] = '.';
	else if (x > 0) {
		int m = pos.size();
		for (int j = 0; j < m; ++j) {
			int i_pos = pos[j];
			bool left_available = false;
			if (j > 0)
				if (pos[j-1] == pos[j] - 1)
					left_available = true;
			bool right_available = false;
			if (j < m - 1)
				if (pos[j+1] == pos[j] + 1)
					right_available = true;
			int m_remaining = (m - 1) - (left_available ? 1 : 0) - (right_available ? 1 : 0);
			int max_after_include = (m_remaining + 1) / 2;
			bool can_include = (max_after_include >= x - 1);
			int max_after_exclude = (m - 1 + 1) / 2;
			bool can_exclude = (max_after_exclude >= x);
			if (can_include && can_exclude)
				T[i_pos] = '?';
			else if (can_include)
				T[i_pos] = 'o';
			else
				T[i_pos] = '.';
		}
	}
	cout << T << endl;
	return 0;
}
