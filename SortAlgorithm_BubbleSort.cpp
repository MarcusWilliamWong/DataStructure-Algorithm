#include <vector>
#include <cstdlib>
#include <random>
#include <iostream>

using namespace std;

vector<int> generateNums() {
	vector<int> nums;
	// 正确的定义方法是 将随机数引擎和关联的分布对象定义为 static
	// 由于 e 和 u 都是 static 的，因此它们在函数调用之间会保持住状态。
	// 第一次调用会使用 u(e) 生成的序列中的前 n 个随机数，第二次调用会获得接下来 n 个。
	// 因为随机数种子是固定的，所以每次运行整个程序的结果都是一样的，对于实际应用是不行的
	// 但是对于测试是非常方便的，每次可以使用相同的测试用例
	static default_random_engine e;
	// 可以给随机数引擎传入时间作为随机数种子
	// default_random_engine e(static_cast<unsigned int>(time(nullptr)));
	static uniform_int_distribution<int> u(0, 100); // [0, 9]
	for (int i = 0; i < 20; ++i)
		nums.push_back(u(e));

	return nums;
}

void printVector(vector<int>& nums) {
	for (auto& e : nums)
		cout << e << " ";
	cout << endl;

	return;
}

void bubbleSort(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 0; j < nums.size() - i; ++j) {
			if (nums[i] > nums[j]) {
				int temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
			}
			cout << "i = " << i <<", j = " << j << " : ";
			printVector(nums);
		}
	}
}

int main() {
	vector<int> nums = generateNums();

	printVector(nums);
	bubbleSort(nums);
	printVector(nums);
	
	system("pause");
	return 0;
}