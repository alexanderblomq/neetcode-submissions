class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<vector<int>> buckets(nums.size() + 1);
        vector<int> output;

        for(const int num : nums) {
            ++freq[num];
        }

        for(auto &[key, val] : freq) {
            buckets[val].push_back(key);
        }

        for(int i = nums.size(); i >= 0; --i) {
            const auto& bucket = buckets[i];
            for(int val : bucket) {
                if(k == 0) return output;
                output.push_back(val);
                --k;
            }
        }
        return output;
    }
};
