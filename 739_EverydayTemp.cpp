#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// 寻找比当前位置元素大的元素的位置
vector<int> monoStak(vector<int>& m) {
	vector<int> result(m.size(), 0);
	vector<int> stack;
	for (int i = 0; i < m.size(); ++i) {
		// 如果遍历的当前元素小于栈顶元素，说明没找到符合条件的元素，
		// 因此加入当前遍历的元素，
		if (stack.empty() || m[i]  <= m[stack.back()]) {
			stack.push_back(i);
		} else {
			// 如果当前遍历的元素大于栈顶元素，说明找到了符合条件的，大于栈顶元素的元素位置，
			// 则为栈顶元素记录结果，并弹出栈顶元素，因为栈顶元素已经完成计算，不再需要参与之后的比较了
			// 弹出栈顶元素后，需要用当前便利的元素与下一个栈顶元素进行比较，如此往复
			// 直到不再符合条件
			result[stack.back()] = i - stack.back();
			stack.pop_back();
			--i;
		}
	}

	return result;
}

int main() {
	int n;
	cin >> n;

	vector<int> m;
	int temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		m.push_back(temp);
	}

	for (auto &e : m) {
		cout << e << " ";
	}
	cout << endl;

	vector<int> result = monoStak(m);
	cout << "Result: ";
	for (auto &e : result) {
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}