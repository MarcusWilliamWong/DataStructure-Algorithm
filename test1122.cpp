#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	double m;
	cin >> m;
	int core = m * 10;
	int ret = m * 10;
	while (core >= 3) {
		ret += core / 3;
		core = core % 3 + core / 3;
		cout << "core : " << core << " ";
	}
	cout << "total : " << ret;
	system("pause");

	return 0;
}