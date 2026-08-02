Unlike a normal Segment Tree, we store the index of the maximum element, not the value itself.

  Many interview questions ask for the position instead of the value.
  class SegmentTree{

public:

    vector<int> tree;
    vector<int> arr;

    SegmentTree(vector<int>& nums){

        arr=nums;

        int n=arr.size();

        tree.resize(4*n);

        build(0,0,n-1);
    }

    //------------------------------------------------

    void build(int node,int low,int high){

        // Leaf
        if(low==high){

            tree[node]=low;
            return;
        }

        int mid=(low+high)/2;

        build(2*node+1,low,mid);

        build(2*node+2,mid+1,high);

        int leftIndex=tree[2*node+1];
        int rightIndex=tree[2*node+2];

        if(arr[leftIndex]>=arr[rightIndex])

            tree[node]=leftIndex;

        else

            tree[node]=rightIndex;
    }

int query(int node,
          int low,
          int high,
          int l,
          int r){

    //-----------------------
    // No overlap
    //-----------------------

    if(high<l || low>r)
        return -1;

    //-----------------------
    // Complete overlap
    //-----------------------

    if(low>=l && high<=r)
        return tree[node];

    int mid=(low+high)/2;

    int leftIndex=query(2*node+1,
                        low,
                        mid,
                        l,
                        r);

    int rightIndex=query(2*node+2,
                         mid+1,
                         high,
                         l,
                         r);

    //-----------------------
    // One side absent
    //-----------------------

    if(leftIndex==-1)
        return rightIndex;

    if(rightIndex==-1)
        return leftIndex;

    //-----------------------
    // Compare values
    //-----------------------

    if(arr[leftIndex]>=arr[rightIndex])

        return leftIndex;

    return rightIndex;
}

};
