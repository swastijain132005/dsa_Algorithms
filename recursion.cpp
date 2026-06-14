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

//permutations 1 and 2
