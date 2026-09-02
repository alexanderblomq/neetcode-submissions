class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> differenceMap;

        for(int i = 0; i < nums.size(); ++i) {
            int difference = target - nums[i];
            if(differenceMap.contains(difference)) {
                return {differenceMap[difference], i};
            }
            differenceMap[nums[i]] = i;
        }
        return {};
    }
};
