#include <iostream>
#include <bitset>
using namespace std;

int a[4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	if(n == 1)
		if(a[0])
			cout << "BitLGM";
		else
			cout << "BitAryo";
	else if(n == 2) {
		auto f = new bitset<303>[303];
		f[0][0] = false;
		for(int x = 0; x <= 300; ++x)
			for(int y = 0; y <= 300; ++y)
				if(!f[x][y]) {
					for(int k = 1; x + k <= 300; ++k)
						f[x + k][y] = true;
					for(int k = 1; y + k <= 300; ++k)
						f[x][y + k] = true;
					for(int k = 1; x + k <= 300 && y + k <= 300; ++k)
						f[x + k][y + k] = true;
				}
		if(f[a[0]][a[1]])
			cout << "BitLGM";
		else
			cout << "BitAryo";
		delete[] f;
	} else {
		auto f = new bitset<303>[303][303];
		f[0][0][0] = false;
		for(int x = 0; x <= 300; ++x)
			for(int y = 0; y <= 300; ++y)
				for(int z = 0; z <= 300; ++z)
					if(!f[x][y][z]) {
						for(int k = 1; x + k <= 300; ++k)
							f[x + k][y][z] = true;
						for(int k = 1; y + k <= 300; ++k)
							f[x][y + k][z] = true;
						for(int k = 1; z + k <= 300; ++k)
							f[x][y][z + k] = true;
						for(int k = 1; x + k <= 300 && y + k <= 300 && z + k <= 300; ++k)
							f[x + k][y + k][z + k] = true;
					}
		if(f[a[0]][a[1]][a[2]])
			cout << "BitLGM";
		else
			cout << "BitAryo";
		delete[] f;
	}
	cout.flush();
	return 0;
}