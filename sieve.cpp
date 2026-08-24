//for finding prime numbers till n 
vector<int> primes;

vector<bool> isprime(n + 1, true);

isprime[0] = isprime[1] = false;

for(int i = 2; i * i <= n; i++) {

    if(isprime[i]) {

        for(int j = i * i; j <= n; j += i) {
            isprime[j] = false;
        }
    }
}

for(int i = 2; i <= n; i++) {
    if(isprime[i]) {
        primes.push_back(i);
    }
}

//for finding prime factors of n 
main//
vector<int>isprime;
isprime.resize(mx + 1, true);
        isprime[0] = isprime[1] = false;

        for(int i = 2; i * i <= mx; i++){
            if(isprime[i]){
                for(int j = i * i; j <= mx; j += i){
                    isprime[j] = false;
                }
            }
        }

void primeno(int n){
        if(mp.count(n)){
            return;
        }

        int x = n;

        for(int i = 2; i * i <= x; i++){
            if(isprime[i] && x % i == 0){

                mp[n].push_back(i);

                while(x % i == 0){
                    x /= i;
                }
            }
        }

        if(x > 1){
            mp[n].push_back(x);
        }
    }
