class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0; int right = nums.size() - 1;

        while(left <= right) {
            int middle = left + (right - left) / 2;
            int middleVal = nums[middle];

            if(middleVal == target) {
                return middle;
            }
            else if(target > middleVal) {
                left = middle + 1;
            }
            else if(target < middleVal) {
                right = middle - 1;
            }
        }
        return -1;
    }
};
