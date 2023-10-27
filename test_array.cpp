#include <iostream>
#include <array>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
	array<int, 4> nums{2};
	// vector<int> nums;
	// for (auto& e : nums) cout << e << " ";
	cout << *(nums.data()+1);
	char* p = "pause";
	*p = 'd';
	cout << *p;
	system("pause");
	return 0;
}