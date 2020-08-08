#include <vector>
#include <iostream>
using namespace std;

// 时间复杂度 O(nlogn)
// 空间复杂度 O(n)
// 稳定排序
vector<int> t;

void mergeSort(int l, int r, vector<int>& a) {
    if (r - l <= 1) return;
    int m = (l + r) >> 1;
    mergeSort(l, m, a);
    mergeSort(m, r, a);
    int p = l, q = m, s = l;
    while (s < r) {
        if (p >= m || q < r && a[p] > a[q]) {
            t[s++] = a[q++];
        } 
        else {
            t[s++] = a[p++];
        }
    }
    for (int i = l; i < r; ++i) a[i] = t[i];
}

int main() {
    t.resize(100);
    vector<int> a = {5, 4, 1, 3, 2};
    mergeSort(0, 5, a);
    for (int &i : a) 
        cout << i << " ";

    cout << endl;
}