Square Root Decomposition (√ Decomposition) is much easier than Segment Trees. It's a technique to answer range queries in O(√N) instead of O(N).

  The main idea is:

Divide the array into blocks of size √N.

Instead of processing every element during a query, process whole blocks whenever possible.

  int blockSize = sqrt(n);

vector<int> block(blockSize+1,0);

for(int i=0;i<n;i++){

    block[i/blockSize]+=arr[i];

}




#include <bits/stdc++.h>
using namespace std;

class SqrtDecomposition {
public:
    vector<int> arr;
    vector<int> block;
    int n;
    int blockSize;

    SqrtDecomposition(vector<int>& nums) {
        arr = nums;
        n = arr.size();

        blockSize = sqrt(n) + 1;
        block.assign(blockSize + 1, 0);

        // Build block sums
        for (int i = 0; i < n; i++) {
            block[i / blockSize] += arr[i];
        }
    }

    // Range Sum Query
    int query(int l, int r) {
        int sum = 0;

        while (l <= r) {
            // Use whole block if possible
            if (l % blockSize == 0 &&
                l + blockSize - 1 <= r) {

                sum += block[l / blockSize];
                l += blockSize;
            } else {
                sum += arr[l];
                l++;
            }
        }

        return sum;
    }

    // Point Update
    void update(int idx, int val) {
        block[idx / blockSize] += (val - arr[idx]);
        arr[idx] = val;
    }
};

//range update 

for(int i=l;i<=r;i++){

    block[i/blockSize] += val;

    arr[i] += val;

}
