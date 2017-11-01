//https://leetcode.com/problems/top-k-frequent-elements/discuss/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int,int> cnt;
        vector<int> res;
        for(auto num:nums){
            cnt[num]++;
        }
        for(auto kv: cnt){
            pq.push(pair<int,int>(kv.second,kv.first));
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            res.push_back( pq.top().second );
            pq.pop();
        }
        return res;
    }
};