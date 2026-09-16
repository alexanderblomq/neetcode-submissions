class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> startDates;
        vector<int> result(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); ++i) {
            while(!startDates.empty() && temperatures[i] > temperatures[startDates.top()]) {
                int date = startDates.top();
                startDates.pop();
                result[date] = i - date;
            }
            startDates.push(i);
        }
        return result;
    }
};
