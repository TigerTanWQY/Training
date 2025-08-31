#include <iostream>
using namespace std;

int main() {
	for(int req = 0x3f3f3f3f, L = 1, R = 1e9, M = (L + R) >> 1; ; cin >> req, M = (L + R) >> 1) {
		if(!req)
			break;
		else if(req == -1)
			L = M + 1;
		else if(req == 1)
			R = M - 1;
		else
			cout << "I AK IOI! ------ JCer\n";
		cout << M << endl;
	}
	return 0;
}