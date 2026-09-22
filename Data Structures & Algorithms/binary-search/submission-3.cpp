class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0; int right = nums.size();

        while(right - left > 1) {
            int middle = left + (right - left) / 2;

            if(nums[middle] == target) {
                return middle;
            }
            else if(target > nums[middle]) {
                left = middle + 1;
            }
            else if(target < nums[middle]) {
                right = middle - 1;
            }
        }
        if(nums[left] == target) return left;
        return -1;
    }
};
