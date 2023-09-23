/***
 * @Author       : Eureke
 * @Date         : 2022-05-27 21:34:22
 * @LastEditors  : Marcus Wong
 * @LastEditTime : 2022-05-27 23:18:47
 * @Description  : 二分查找，前提条件：数组有序，且数组无重复元素
 * 解法：
 * 二分法，要注意搜索区间是左闭右闭，还是左闭右开
 */
#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>

class Solution {
  public:
    int search(vector<int>& nums, int target) {
      // 设置初始搜索区间左闭右闭[left, right]
      int left = 0;
      int right = nums.size() - 1;

      while (left <= right) { // 当 left == right 时，[left, right]依然有效
        // 注意细节：防止数组过大，两数之和溢出 等同于(left + right) / 2
        // 涉及乘除时，可采用左移右移运算符，提高运算速度
        // 注意移位运算符的优先级小于加减优先级
        int middle = left + ((right - left) >> 2); 
        if (nums[middle] > target) { // target在左区间
          right = middle - 1;  // 在新区间[left, middle - 1]搜索
        } else if (nums[middle] < target) { // target在右区间
          left = middle + 1;  // 在新区间[middle + 1, right]搜索
        } else { // nums[middle] == target, 找到目标
          return middle;
        }
      }
      // 未找到目标值
      return -1;
    }
};

int main() {
  Solution demo;
  vector<int> array = {1, 3, 4, 6, 30, 70, 130, 890};
  int target;
  int pos;

  while (cin >> target) {
    if (-1 != (pos = demo.search(array, target)))
      cout << target << " is at " << pos << endl;
    else
      cout << "We didn't find " << target << " in the array." << endl;
  }
  system("pause");

  return 0;
}