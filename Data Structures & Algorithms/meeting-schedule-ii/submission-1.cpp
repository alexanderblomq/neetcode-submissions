/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> minimumEndTime;
        int maximumRoomsAtTime = 0;

        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){return a.start < b.start;});

        for(Interval& interval : intervals) {
            while(minimumEndTime.size() > 0 && minimumEndTime.top() <= interval.start) {
                minimumEndTime.pop();
            }

            minimumEndTime.push(interval.end);
            if(minimumEndTime.size() > maximumRoomsAtTime) maximumRoomsAtTime = minimumEndTime.size();
        }

        return maximumRoomsAtTime;
    }
};
