Instead of updating every leaf immediately,

Store the update at the current node.

Update children only when they are actually needed.

This postponement is called

Lazy Propagation



Along with Segment Tree

vector<int> seg(4*n);

Maintain

vector<int> lazy(4*n,0);

Initially

lazy[i]=0

Meaning

No pending update.
Whenever we visit a node

First check

lazy[node]!=0 ?

If yes,

Current node has some pending work.

Apply it first.

  if(lazy[node]!=0){

    seg[node] += (high-low+1)*lazy[node];

    // If not leaf
    if(low!=high){

        lazy[2*node+1]+=lazy[node];
        lazy[2*node+2]+=lazy[node];

    }

    lazy[node]=0;
}


class SegmentTree{

public:

    vector<int> seg;
    vector<int> lazy;

    SegmentTree(int n){

        seg.resize(4*n);

        lazy.assign(4*n,0);
    }

    //-----------------------------------------

    void build(int node,int low,int high,
               vector<int>&arr){

        if(low==high){

            seg[node]=arr[low];
            return;
        }

        int mid=(low+high)/2;

        build(2*node+1,low,mid,arr);

        build(2*node+2,mid+1,high,arr);

        seg[node]=seg[2*node+1]+seg[2*node+2];
    }

    //-----------------------------------------

    void updateRange(int node,
                     int low,
                     int high,
                     int l,
                     int r,
                     int val){

        // Resolve pending updates
        if(lazy[node]!=0){

            seg[node]+=(high-low+1)*lazy[node];

            if(low!=high){

                lazy[2*node+1]+=lazy[node];
                lazy[2*node+2]+=lazy[node];

            }

            lazy[node]=0;
        }

        // No overlap
        if(high<l || low>r)
            return;

        // Complete overlap
        if(low>=l && high<=r){

            seg[node]+=(high-low+1)*val;

            if(low!=high){

                lazy[2*node+1]+=val;
                lazy[2*node+2]+=val;

            }

            return;
        }

        // Partial overlap
        int mid=(low+high)/2;

        updateRange(2*node+1,
                    low,
                    mid,
                    l,
                    r,
                    val);

        updateRange(2*node+2,
                    mid+1,
                    high,
                    l,
                    r,
                    val);

        seg[node]=seg[2*node+1]+seg[2*node+2];
    }

};

leetcode 3721

leetcode 2179

  leftcmtcnt=qsegt
  leftnotcmncnt=i-leftcmncnt;
elementafteridxnums2=(n-1)-idx
  rightcmncnt=eleafteridx-leftnotcmncnt

  
