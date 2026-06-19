Recursion
Binary exponentiation
Pow (x,n)
class Solution {
    double f(double x, long long n, double ans) {
        if (n == 0) return ans;
        // binary exponentiation
        if (n % 2 == 1) {
            ans = ans * x;
        }
        return f(x * x, n / 2, ans);
    }
public:
    double myPow(double x, int n) {
        if (x == 1) return 1;
        long long N = n;   // avoid INT_MIN overflow
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return f(x, N, 1);
    }
};


//sieve of eratosthenesis \\
tc (o(nloglongn))

#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = false;
    if (n >= 1)
        isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main() {
    int n;
    cin >> n;

    vector<int> primes = sieve(n);

    for (int p : primes) {
        cout << p << " ";
    }
}

//segmented sieve 

#include <bits/stdc++.h>
using namespace std;

vector<int> simpleSieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;

    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

vector<int> segmentedSieve(long long L, long long R) {

    long long limit = sqrt(R);

    vector<int> primes = simpleSieve(limit);

    vector<bool> isPrime(R - L + 1, true);

    for (int p : primes) {

        long long start = max(1LL * p * p,
                              ((L + p - 1) / p) * 1LL * p);

        for (long long j = start; j <= R; j += p) {
            isPrime[j - L] = false;
        }
    }

    if (L == 1)
        isPrime[0] = false;

    vector<int> ans;

    for (long long i = L; i <= R; i++) {
        if (isPrime[i - L]) {
            ans.push_back(i);
        }
    }

    return ans;
}

int main() {

    long long L = 10, R = 50;

    vector<int> primes = segmentedSieve(L, R);

    for (int x : primes) {
        cout << x << " ";
    }

    return 0;
}

