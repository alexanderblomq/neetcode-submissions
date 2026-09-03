class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> currSet;

        unordered_set<int> numsAvailable;

        for(int num : nums) {
            numsAvailable.insert(num);
        }

        sort(nums.begin(), nums.end());
        
        backtrack(output, nums, currSet, 0, numsAvailable);
        return output;
    }

    void backtrack(vector<vector<int>>& output, vector<int>& nums, vector<int>& currSet, int currIndex, unordered_set<int>& numsAvailable) {
        if(currIndex == nums.size()) {
            output.push_back(currSet);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(!numsAvailable.contains(num)) continue;
            currSet.push_back(num);
            numsAvailable.erase(num);
            backtrack(output, nums, currSet, currIndex + 1, numsAvailable);
            numsAvailable.insert(num);
            currSet.pop_back();
        }
    }
};
