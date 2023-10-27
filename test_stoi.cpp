#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> nums;
		string num;
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] != ',') {
            num += s[i];
        } else {
            nums.push_back(stoi(num));
						num = "";
        }
    }
    for (auto& i : nums) {
        cout << i << " ";
    }
		system("pause");
    return 0;
}