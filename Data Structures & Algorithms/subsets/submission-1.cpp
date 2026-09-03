class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        vector<int> currSet(0);
        backtrack(sets, currSet, nums, 0);
        return sets;
    }

    void backtrack(vector<vector<int>>& output, vector<int>& currSet, vector<int>& nums, int currIndex) {
        output.push_back(currSet);
        if(currIndex >= nums.size()) {
            return;
        }
        for(; currIndex < nums.size(); currIndex++) {
            currSet.push_back(nums[currIndex]);
            backtrack(output, currSet, nums, currIndex + 1);
            currSet.pop_back();
        }
    }
};
