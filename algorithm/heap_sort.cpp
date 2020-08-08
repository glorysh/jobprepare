#include <vector>
#include <iostream>
using namespace std;

// 时间复杂度 O(nlogn)
// 空间复杂度 O(1)
// 不稳定排序
inline int left(int i) {
    return (i << 1) + 1; 
}

inline int right(int i) {
    return (i << 1) + 2;
}

inline int parent(int i) {
    return (i - 1) >> 1;
}

// O(logn)
void maxHeapify(vector<int>& a, int i, int sz) {
    int l = left(i);
    int r = right(i);
    int largest;
    if (l < sz && a[l] > a[i]) largest = l;
    else largest = i;
    if (r < sz && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        maxHeapify(a, largest, sz);
    }
}

// O(n) 建堆的时间复杂度为线性
void buildMaxHeap(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        maxHeapify(a, i, n);
    }
}

// O(nlogn)
void heapSort(vector<int>& a) {
    buildMaxHeap(a);
    int n = a.size();
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);
        maxHeapify(a, 0, i);
    }
}

int main() {
    vector<int> a = {2, 1, 3, 4, 1, 2, 3, 6, 7, 8, 1, 1, 3, 3, 5, 9, 0, 1, 4, 6}; 
    // buildMaxHeap(a);
    heapSort(a);
    for (int& i : a) 
        cout << i << " ";
    cout << endl;
}