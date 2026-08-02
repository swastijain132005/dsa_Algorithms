A Segment Tree is a binary tree used to answer range queries efficiently.

Examples:

Range Sum Query
Range Minimum Query
Range Maximum Query

it also supports updates much faster than prefix sums.

  O(N × Q)-> (log N*Q)

  Root stores

[0,4]

Left child

[0,2]

Right child

[3,4]

Continue dividing until

Leaf Nodes

Each leaf stores exactly one element.

Example

[0,0]
[1,1]
[2,2]
...
Important Observation

Leaf nodes

Represent single array elements.

Internal nodes

Represent ranges.
Height of Segment Tree

Height is approximately

log2(N)

Hence

Query = O(logN)

Update = O(logN)
Is Segment Tree Balanced?

Yes.

Difference between heights of left and right subtree is at most 1.

So height remains

O(logN)
Number of Nodes

Suppose

N = 8

Leaves

8

Internal nodes

7

Total

15

which is

2*N - 1

For convenience we allocate

vector<int> seg(4*n);

instead of

2*n-1

because it works for every value of N.

Segment Tree Representation in Array

If current node index is

i

Then

Left Child

2*i+1

Right Child

2*i+2

Parent

(i-1)/2
Build Segment Tree (Range Sum)

Suppose

arr = [1,2,3,4]

Initially

build(0,0,n-1)

Parameters

(node,start,end)

where

node -> index inside seg[]

start -> left boundary

end -> right boundary
Base Case

When

start==end

We reached a leaf.

Store

seg[node]=arr[start];

Return.

Recursive Case

Find

mid=(start+end)/2;

Build left subtree

build(2*node+1,start,mid);

Build right subtree

build(2*node+2,mid+1,end);

Merge

seg[node]=seg[2*node+1]+seg[2*node+2];
Complete Build Code (Sum Segment Tree)
class SegmentTree {

public:

    vector<int> seg;

    SegmentTree(int n){
        seg.resize(4*n);
    }

    // node -> current node in segment tree
    // low,high -> range represented by this node
    void build(int node,int low,int high,vector<int> &arr){

        // Leaf node
        if(low==high){
            seg[node]=arr[low];
            return;
        }

        int mid=(low+high)/2;

        // Build left subtree
        build(2*node+1,low,mid,arr);

        // Build right subtree
        build(2*node+2,mid+1,high,arr);

        // Merge
        seg[node]=seg[2*node+1]+seg[2*node+2];
    }

};
Complexity
Time
O(N)


Point Update

Suppose

arr

3 2 1 7

Update

index = 1

value = 5

We don't rebuild the entire tree.

Instead

Go from root
Reach that leaf
Update value
While returning update all ancestors

Only one path is visited.

Hence

O(logN)
Point Update Code
void update(int idx, int val,
            int node,
            int low,
            int high) {

    // Reached the leaf
    if (low == high) {
        seg[node] = val;
        return;
    }

    int mid = (low + high) / 2;

    // Go to left child
    if (idx <= mid)
        update(idx, val,
               2 * node + 1,
               low,
               mid);

    // Go to right child
    else
        update(idx, val,
               2 * node + 2,
               mid + 1,
               high);

    // Update current node after child is updated
    seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}
Complexity

Update

O(logN)

because only one root-to-leaf path is traverse

This page covers the basics, build, and point update. The next page in your notes starts with the Range Sum Query implementation, which we'll cover next.
