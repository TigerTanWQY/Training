#include <iostream>
#include <bitset>
using namespace std;

constexpr const int N = 103;
bitset<N> vis;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int id; m--; cout.put('\n')) {
		char sex;
		cin >> id >> sex;
		if(sex == 'F' || vis[id])
			cout << "No";
		else {
			cout << "Yes";
			vis[id] = true;
		}
	}
	cout.flush();
	return 0;
}