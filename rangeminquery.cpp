class SegmentTree {

public:

    vector<int> tree;

    SegmentTree(vector<int>& arr) {

        int n = arr.size();

        tree.resize(4 * n);

        build(0, 0, n - 1, arr);
    }

    //---------------------------------------------------

    void build(int node,
               int start,
               int end,
               vector<int>& arr) {

        // Leaf node
        if (start == end) {

            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(2 * node + 1,
              start,
              mid,
              arr);

        build(2 * node + 2,
              mid + 1,
              end,
              arr);

        // Store minimum
        tree[node] =
            min(tree[2 * node + 1],
                tree[2 * node + 2]);
    }


int query(int node,
          int start,
          int end,
          int l,
          int r) {

    // No overlap
    if (end < l || start > r)
        return INT_MAX;

    // Complete overlap
    if (l <= start && end <= r)
        return tree[node];

    // Partial overlap
    int mid = (start + end) / 2;

    int left =
        query(2 * node + 1,
              start,
              mid,
              l,
              r);

    int right =
        query(2 * node + 2,
              mid + 1,
              end,
              l,
              r);

    return min(left, right);
}

leetcode 307

};
