Strings
Rabin karo algorithm for string matching
class Solution {
public:
    bool rabinKarp(string text, string pattern) {
        int n = text.size();
        int m = pattern.size();
 
        if (m > n) return false;

        int base = 256;          // number of characters
        int mod = 1e9 + 7;

        long long patternHash = 0;
        long long windowHash = 0;
        long long power = 1;

        // Compute base^(m-1)
        for (int i = 0; i < m - 1; i++) {
            power = (power * base) % mod;
        }

        // Initial hash
        for (int i = 0; i < m; i++) {
            patternHash = (patternHash * base + pattern[i]) % mod;
            windowHash = (windowHash * base + text[i]) % mod;
        }

        // Sliding window
        for (int i = 0; i <= n - m; i++) {

            // Check hash match
            if (patternHash == windowHash) {
                if (text.substr(i, m) == pattern)
                    return true;
            }

            // Slide window
            if (i < n - m) {
                windowHash = (windowHash - text[i] * power % mod + mod) % mod;
                windowHash = (windowHash * base + text[i + m]) % mod;
            }
        }

        return false;
    }
};

/Kmp and lps
class Solution {
public:

void lpsfind(vector<int>&lps,string &s) {
    int n = s.size();

    int pre = 0, suf = 1;

    while (suf < n) {
        if (s[pre] == s[suf]) {
            lps[suf] = pre + 1;
            pre++;
            suf++;
        }
        else {
            if (pre == 0) {
                lps[suf] = 0;
                suf++;
            }
            else {
                pre = lps[pre - 1];
            }
        }
    }

}
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        vector<int>lps(n,0);
        lpsfind(lps,needle);
        int first=0;
        int sec=0;
        while(sec<n&&first<m){
            if(needle[sec]==haystack[first]){
                sec++;
                first++;
            }
            else {
                if(sec==0){
                    first++;
                }
                else{
                    sec=lps[sec-1];
                }
            }

        }

        if(sec==n){
            return first-sec;
        }
        return -1;
 
    }
};
