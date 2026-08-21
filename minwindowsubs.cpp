class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int bestLen = INT_MAX, bestStart = -1;

        int right = 0;
        while (right < n) {
            int j = 0;

            // forward scan: try to match t
            while (right < n && j < m) {
                if (s[right] == t[j]) j++;
                right++;
            }

            if (j < m) break;  // no subsequence possible

            // backward shrink
            int left = right - 1;
            j = m - 1;
            while (left >= 0 && j >= 0) {
                if (s[left] == t[j]) j--;
                left--;
            }
            left++;

            if (right - left < bestLen) {
                bestLen = right - left;
                bestStart = left;
            }

            // restart search
            right = left + 1;
        }

        return bestStart == -1 ? "" : s.substr(bestStart, bestLen);
    }
};
