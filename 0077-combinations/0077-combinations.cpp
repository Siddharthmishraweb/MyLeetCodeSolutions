class Solution {
public:
vector<vector<int>> combine(int n, int k) {
        if (k == 0)
            return {};
        vector <vector <int>> ret, ans;
        for (int i = n; i >= k; i--) {
            ans = combine(i - 1, k - 1);
            for (auto &x : ans) 
                x.push_back(i);
            if (ans.size() == 0)
                ret.push_back({i});
            else
                ret.insert(ret.end(), 
                    make_move_iterator(ans.begin()), 
                    make_move_iterator(ans.end())
                );
        }
        return ret; // RVO std::move(ret);
    }
};