class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> currSet;
        
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, output, currSet, 0, 0, target);
        return output;
    }

    void backtrack(vector<int>& candidates, vector<vector<int>>& output, vector<int>& currSet, int currSum, int currIndex, int target) {
        if(currSum == target) {
            output.push_back(currSet);
            return;
        }
        unordered_set<int> used;
        for(; currIndex < candidates.size(); currIndex++) {
            int num = candidates[currIndex];
            if(currSum + num > target) break;
            if(!used.contains(num)) {
                currSet.push_back(num);
                used.insert(num);
                backtrack(candidates, output, currSet, currSum + num, currIndex + 1, target);
                currSet.pop_back();
            }
        }
    }
};
