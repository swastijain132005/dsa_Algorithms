//lis (binary search)
int LIS(vector<int>& arr) {
    vector<int> s;

    for (int x : arr) {
        auto it = lower_bound(s.begin(), s.end(), x);

        if (it == s.end()) {
            s.push_back(x);
        } else {
            *it = x;
        }
    }

    return s.size();
}
