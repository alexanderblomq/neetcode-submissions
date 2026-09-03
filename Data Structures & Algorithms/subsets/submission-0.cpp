class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        sets.push_back({});
        backtrack(sets, {}, nums, 0);
        return sets;
    }

    void backtrack(vector<vector<int>>& output, vector<int> currSet, vector<int>& nums, int currIndex) {
        if(currIndex >= nums.size()) {
            return;
        }

        backtrack(output, currSet, nums, currIndex + 1);
        currSet.push_back(nums[currIndex]);
        output.push_back(currSet);
        backtrack(output, currSet, nums, currIndex + 1);
    }
};
