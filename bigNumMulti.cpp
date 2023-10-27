#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 字符串反转
string reverStr(string s) {
    string s_r;
    for (int i = s.size() - 1; i >= 0; i--) {
        s_r += s[i];
    }

    return s_r;
}

// 获得小数点在数字中的位置，返回-1则说明没有小数点
int getPointPos(string s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '.')
            return i;
    }

    return 0;
}

// 处理整数部分无意义的0
string cutIntZero(string s) {
    string result;
    int flag = 1; // 需要处理无效0
    for (auto& e : s) {
        if (e != '0') {
            flag = 0;
            result += e;
        } else {
            if (flag == 0) {
                result += e;
            }
        }
    }

    return result;
}

// 处理小数部分无意义的0
string cutFloatZero(string s) {
    string result;
    int flag = 1; // 需要处理
    int i;
    for (i = s.size() - 1; i >= 0; i--) {
        if (flag && s[i] != '0') break;
    }

    for (int j = 0; j <= i; j++) {
        result += s[j];
    }

    return result;
}

// 处理字符串数字的无意义0
string getValidStr(string s) {
    string result;
    string intPart;
    string floatPart;
    int flag = 1; // 小数点前为1，小数点后为0
    for (auto& e : s) {
        if (e == '.') {
            flag = 0;
            continue;
        }
        if (flag) {
            intPart += e;
        } else {
            floatPart += e;
        }
    }

    string intPart_valid = cutIntZero(intPart);
    string floatPart_valid = cutFloatZero(floatPart);
    if (floatPart_valid == "") {
        result = intPart_valid;
    } else {
        result = intPart_valid + "." + floatPart_valid;
    }
    
    return result;
}


vector<int> stov(string s) {
    vector<int> num;
    int point_pos = getPointPos(s);
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] != '.') {
            num.push_back(s[i] - '0');
        }
    }

    return num;
}

string multiple(string s1, string s2) {
    string s1_valid = getValidStr(s1);
    string s2_valid = getValidStr(s2);
    // cout << s1_valid << endl;
    // cout << s2_valid << endl;

    int point_pos1 = getPointPos(reverStr(s1_valid));
    int point_pos2 = getPointPos(reverStr(s2_valid) );
    int result_point_pos = point_pos1 + point_pos2;
    vector<int> num1 = stov(s1_valid);
    vector<int> num2 = stov(s2_valid);

    // for (auto& e : num1) cout << e;
    // cout << endl;
    // for (auto& e : num2) cout << e;
    // cout << endl;
    cout << point_pos1 << " " << point_pos2;

    string result;
    vector<int> result_num(num1.size() + num2.size());


    return result;
}

int main() {
    string s1;
    string s2;

    cin >> s1 >> s2;
    // cout << multiple(s1, s2);
    // cout << isPoint(s1);
    // cout << reverStr(s2);
    // cout << cutIntZero(s2);
    // cout << cutFloatZero(s1);
    // cout << getValidStr(s1);
    cout << multiple(s1, s2);

		
		return 0;
}
// 64 位输出请用 printf("%lld")