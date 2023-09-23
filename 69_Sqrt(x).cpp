/***
 * @Author       : Eureke
 * @Date         : 2022-05-29 13:57:48
 * @LastEditors  : Marcus Wong
 * @LastEditTime : 2022-05-29 21:14:16
 * @Description  : 给出一个32位正整数，求算数平方根
 * 输入32位int类型可表示的最大值：2147483647
 * 输出：46340
 * 解法：
 * 1、牛顿迭代法（x = x0 - f(x0) / f'(x0)），设置一个初始值 x0，不断带入前边公式中，求出一定精度的x，即为函数f(x)的零点
 * 2、
 */
#include <iostream>
#include <cstdlib>
#include <cmath>

class Solution {
  int s;
  public:
    int sqrt(int x) {
      if (x <= 1)
        return 1;
      s = x;
      double ans = (double)s;
      while (fabs(ans - newTon(ans)) > 1e-6)
        ans = newTon(ans);
      
      return (int)ans;
    }

  private:
    double newTon(double x0) {
      return (x0 + (double)s / x0) / 2;
    }
};

int main() {
  Solution demo;
  int val;
  std::cin >> val;
  std::cout << demo.sqrt(val) << std::endl;
  std::system("pause");

  return 0;
}