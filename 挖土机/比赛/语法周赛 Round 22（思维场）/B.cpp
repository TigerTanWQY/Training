#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string res = "000", ans = "000";
	for(int x = 111; x < 1000; x += 111) {
		cout << x << endl;
		cin >> res[0] >> res[1] >> res[2];
		for(int i = 0; i < 3; ++i)
			if(res[i] == '2')
				ans[i] = to_string(x)[i];
		if(res == "222")
			break;
	}
	cout << ans << endl;
	return 0;
}