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
        for(int i = currIndex; i < candidates.size(); i++) {
            int num = candidates[i];
            if(currSum + num > target) break;
            if (i > currIndex && num == candidates[i - 1]) continue;
            currSet.push_back(num);
            backtrack(candidates, output, currSet, currSum + num, i + 1, target);
            currSet.pop_back();
        }
    }
};
