class Solution {
public:
    int helper(int x, unordered_map<int, int>& m){
        if(x==1)return 1;
        if(m.find(x)!=m.end())return m[x];
        int even = 0, odd = 0;
        if(x%2==0){
            even = 1+helper(x/2, m);
        }
        else{
            odd = 1+helper((3*x)+1, m);
        }
        return m[x] = even+odd;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>>ans;
        unordered_map<int, int>m;
        for(int i = lo; i<=hi; i++){
            int result = helper(i, m);
            ans.push_back({result, i});
        }
        sort(ans.begin(), ans.end());
        return ans[k-1].second;
    }
};