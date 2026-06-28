A heap is a complete binary tree
//max-heap
parent>=child
//min-heap
parent<=child
  
for any index i
  Parent = (i-1)/2

Left Child = 2*i+1

Right Child = 2*i+2

  Number of nodes

2^h ≤ n

Height

O(log n)

#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
public:

    vector<int> arr;

    void insert(int val){

        arr.push_back(val);

        int index=arr.size()-1;

        while(index>0){

            int parent=(index-1)/2;

            if(arr[parent]<arr[index]){

                swap(arr[parent],arr[index]);
                index=parent;
            }
            else
                break;
        }
    }

    void print(){

        for(int x:arr)
            cout<<x<<" ";

        cout<<endl;
    }
};


Insert = O(log n)

Space = O(1)



Delete from Max Heap

Delete always removes the root.

Steps

Replace root with last node
Remove last node
Heapify from root



void heapifyDown(int index){

    int n=arr.size();

    while(true){

        int largest=index;

        int left=2*index+1;
        int right=2*index+2;

        if(left<n && arr[left]>arr[largest])
            largest=left;

        if(right<n && arr[right]>arr[largest])
            largest=right;

        if(largest==index)
            break;

        swap(arr[index],arr[largest]);
        index=largest;
    }
}

void deleteRoot(){

    if(arr.empty())
        return;

    arr[0]=arr.back();

    arr.pop_back();

    if(!arr.empty())
        heapifyDown(0);
}


O(log n)

//recursive heapify
void heapify(vector<int>& arr,int index,int n){

    int largest=index;

    int left=2*index+1;
    int right=2*index+2;

    if(left<n && arr[left]>arr[largest])
        largest=left;

    if(right<n && arr[right]>arr[largest])
        largest=right;

    if(largest!=index){

        swap(arr[index],arr[largest]);

        heapify(arr,largest,n);
    }
}


O(log n)


7. Build Max Heap

Start from last non-leaf node.

Formula

Last non-leaf = n/2 -1
void buildHeap(vector<int>& arr){

    int n=arr.size();

    for(int i=n/2-1;i>=0;i--){

        heapify(arr,i,n);
    }
}

Complexity

Time = O(n)
NOT O(nlogn)

Why is Build Heap O(n) and not O(n log n)?

Because most nodes are near the leaves and require very little heapification work. Summing the work over all nodes gives O(n)

8. Heap Sort

Steps

Build Max Heap

↓

Swap root with last

↓

Decrease heap size

↓

Heapify

Repeat.


void heapify(vector<int>& arr,int index,int n){

    int largest=index;

    int left=2*index+1;
    int right=2*index+2;

    if(left<n && arr[left]>arr[largest])
        largest=left;

    if(right<n && arr[right]>arr[largest])
        largest=right;

    if(largest!=index){

        swap(arr[index],arr[largest]);

        heapify(arr,largest,n);
    }
}

void heapSort(vector<int>& arr){

    int n=arr.size();

    for(int i=n/2-1;i>=0;i--)
        heapify(arr,i,n);

    for(int i=n-1;i>0;i--){

        swap(arr[0],arr[i]);

        heapify(arr,0,i);
    }
}

Build Heap = O(n)

Heapify n times = O(nlogn)

Overall = O(nlogn)

Space = O(1)


