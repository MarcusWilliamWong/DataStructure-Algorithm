/***
 * @Author       : Eureke
 * @Date         : 2022-05-27 23:18:12
 * @LastEditors  : Marcus Wong
 * @LastEditTime : 2022-05-28 23:15:13
 * @Description  : 移除数组中的特定元素：提供一个数组nums和一个值val，需要原地移除所有数值等于val的元素，
 * 并返回移除后数组的新长度。不要使用额外的数组空间，必须仅使用O(1)额外空间
 * 并原地修改输入数组。
 * 解法：
 * 1、暴力破解，双循环；
 * 2、双指针，一个循环下完成两个循环的工作；
 * （双指针法在链表和数组的操作中非常常见，一定要掌握）
 */
#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>

class Solution {
  public:
    // 方法一：暴力破解，双循环嵌套
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    int removeElement1(vector<int>& nums, int val) {
      int size = nums.size(); // 随着“删减元素”，数组大小在减小
      for (int i = 0; i < size; i++) {
        if (nums[i] == val) { // 如果找到了val，则该数组后续元素覆盖前边元素
          for (int j = i + 1; j < size; j++)
            nums[j - 1] = nums[j];
          i--; // 易错点一：因为下标i以后的数值都前移了一位，所以i也要向前移动一位5
          size--; // 易错点而：数组大小减一
        }
      }

      return size;
    }

    //方法二：双指针法，快慢指针法
    int removeElement2(vector<int>& nums, int val) {
      // 快指针用来扫描整个数组，慢指针用来记录删除特定元素的数组，因此只有在遇到不为特定元素时，才赋值并自增
      int  slowIndex = 0;
      for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
        if (val != nums[fastIndex])
          nums[slowIndex++] = nums[fastIndex];
      }
      return slowIndex;
    }
};

int main() {
  Solution demo;
  vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  int val;
  cin >> val;
  int k = demo.removeElement1(nums, val);
  for (int i = 0; i < k; i++)
      cout << nums[i] << " ";
  cout << "|| k = " << k << endl;
  system("pause");

  return 0;
}