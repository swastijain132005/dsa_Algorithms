Difference Array is used when there are many range updates and only one final output is required.

Instead of updating every element in the range, we update only the boundaries.

  #include<bits/stdc++.h>
using namespace std;

int main(){

    int n=7;

    vector<int> diff(n+1,0);

    //------------------------
    // Update
    //------------------------

    int L=1;
    int R=5;
    int val=2;

    diff[L]+=val;

    if(R+1<n)
        diff[R+1]-=val;

    //------------------------
    // Prefix Sum
    //------------------------

    for(int i=1;i<n;i++)
        diff[i]+=diff[i-1];

    //------------------------
    // Print
    //------------------------

    for(int x:diff)
        cout<<x<<" ";

}
