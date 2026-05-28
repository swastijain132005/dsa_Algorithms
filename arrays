Sorting
Merge sort
#include <iostream>
#include <vector>
using namespace std;
// Merge two sorted halves
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= high) temp.push_back(arr[j++]);
    for (int k = 0; k < temp.size(); k++)
        arr[low + k] = temp[k];
}
// Recursive merge sort
void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    mergeSort(arr, 0, arr.size() - 1);
    for (int x : arr) cout << x << " ";
    return 0;
}
Quick sort
#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[i]);
    return i;
}
void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int p = partition(arr, low, high);
    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
}
int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    quickSort(arr, 0, arr.size() - 1);
    for (int x : arr) cout << x << " ";
    return 0;
}

Kadanes algorithm (max subarray sum)

#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int>& nums) {
    int currSum = 0, maxSum = nums[0];
    for (int x : nums) {
        currSum = max(x, currSum + x);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}
int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums);
    return 0;
}
Moores voting algorithm (majority element)
#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0, candidate = 0;

    for (int x : nums) {
        if (count == 0)
            candidate = x;

        if (x == candidate) count++;
        else count--;
    }
    return candidate;   // majority element always exists
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums);
    return 0;
}
Dutch national flag
#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0)
            swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1)
            mid++;
        else
            swap(nums[mid], nums[high--]);
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);

    for (int x : nums) cout << x << " ";
    return 0;
}
