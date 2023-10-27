#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int>& sort(vector<int>& array) {
    if (array.empty()) return array;

    int maxId;
    int temp;
    for (int i = 0; i < array.size(); ++i) {
        maxId = i;
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j] > array[maxId]) {
                maxId = j;
            }
        }
        if (maxId != i) {
            temp = array[i];
            array[i] = array[maxId];
            array[maxId] = temp;
        }
    }

    return array;
}

int main() {
    int n, b;
    cin >> n;
    int temp;
    vector<int> array;
    double res;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        array.push_back(temp);
    }

		sort(array);
		for (int i = 0; i < array.size(); ++i) {
			cout << array[i] << "";
		}

    if (array.size() % 2) {
        res = array[array.size() / 2];
        
    } else {
        res = (array[array.size() / 2 - 1] + array[array.size() / 2]) / 2;
    }
    // cout << res;
		system("pause");
    return 0;
}  