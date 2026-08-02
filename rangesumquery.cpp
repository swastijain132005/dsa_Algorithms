class SegmentTree {

public:

    vector<int> seg;

    SegmentTree(int n) {
        seg.resize(4 * n);
    }

    //-------------------------------------------------------
    // Build Segment Tree
    //-------------------------------------------------------

    void build(int node, int low, int high, vector<int>& arr) {

        // Leaf node
        if (low == high) {
            seg[node] = arr[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2 * node + 1, low, mid, arr);
        build(2 * node + 2, mid + 1, high, arr);

        // Merge
        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    //-------------------------------------------------------
    // Range Sum Query
    //-------------------------------------------------------

    int query(int node, int low, int high,
              int l, int r) {

        // Case 1 : No Overlap
        if (high < l || low > r)
            return 0;

        // Case 2 : Complete Overlap
        if (low >= l && high <= r)
            return seg[node];

        // Case 3 : Partial Overlap
        int mid = (low + high) / 2;

        int left =
            query(2 * node + 1,
                  low,
                  mid,
                  l,
                  r);

        int right =
            query(2 * node + 2,
                  mid + 1,
                  high,
                  l,
                  r);

        return left + right;
    }

};
