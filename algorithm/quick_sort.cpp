#include <iostream>
#include <vector>
using namespace std;

// 平均时间复杂度 O(nlogn)
// 最坏时间复杂度 O(n^2)
// 空间复杂度 O(1)
// 不稳定排序
int partition(vector<int>& nums, int l, int r) {
    int pivot = nums[r];
    int i = l - 1;
    for (int j = l; j < r; ++j) {
        if (nums[j] < pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[r]);
    return i + 1;
}

int randomized_partiton(vector<int>& nums, int l, int r) {
    int i = rand() % (r - l + 1) + l;
    swap(nums[i], nums[r]);
    return partition(nums, l, r);
}

void quickSort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int pos = randomized_partiton(nums, l, r);
    quickSort(nums, l, pos - 1);
    quickSort(nums, pos + 1, r);
}

int main() {
    vector<int> nums = {1, 4, -1, 4, 2, 6, 2, 4, 0, 9, 6, 7, 5, 8};
    quickSort(nums, 0, nums.size() - 1);
    for (int& i : nums) 
        cout << i << " ";
    cout << endl;
}