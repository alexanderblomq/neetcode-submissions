class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> output;
        vector<int> currSet(0);
        sort(nums.begin(), nums.end());
        backtrack(output, currSet, nums, target, 0, 0);
        return output;
    }

    void backtrack(vector<vector<int>>& output, vector<int>& currSet, vector<int>& nums, int target, int currSum, int currIndex) {
        if(currSum == target) {
            output.push_back(currSet);
            return;
        }
        else if(currSum > target) {
            return;
        }

        for(; currIndex < nums.size(); currIndex++) {
            int num = nums[currIndex];
            if(currSum + num > target) {
                break;
            }
            currSet.push_back(num);
            backtrack(output, currSet, nums, target, currSum + num, currIndex);
            currSet.pop_back();
        }
    }
};
