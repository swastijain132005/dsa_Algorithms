Bit manipulation
Sieve of eratothenesis
(For finding no. Of prime nos which are less than n)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isprime(n+1,true);
        isprime[0]=isprime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(isprime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isprime[j]=false;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(isprime[i]){
                cnt++;
            }
        }
        return cnt;
 
    }
};
Time complexity o(nloglogn)
