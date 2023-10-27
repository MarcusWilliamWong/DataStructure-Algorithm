#include <map>
#include <iostream>
#include <cstdlib>

int main() {
	std::map<int, int> m;
	for (int i = 0; i < 5; ++i) {
		m.insert(std::make_pair(i, i+1));
	}

	for (auto& e : m) {
		std::cout << e.first << " : " << e.second << std::endl;
	}

	std::system("pause");

	return 0;
}