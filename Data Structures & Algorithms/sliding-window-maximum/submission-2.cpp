class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int lastValue;
        priority_queue<pair<int,int>> heap;
        vector<int> maximums;

        for(int i = 0; i < k; i++) {
            heap.push({ nums[i], i });
        }

        maximums.push_back(heap.top().first);

        for(int i = k; i < nums.size(); i++) {
            heap.push({nums[i], i});

            while(heap.top().second <= i - k) {
                heap.pop();
            }
            maximums.push_back(heap.top().first);
        }
        return maximums;
    }
};
