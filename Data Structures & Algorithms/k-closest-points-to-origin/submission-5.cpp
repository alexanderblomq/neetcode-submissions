class Solution {
    struct Compare {
        bool operator()(const vector<int>& point1, const vector<int>& point2) const {
            return distanceFromOrigin(point1) < distanceFromOrigin(point2);
        }
    };
public:
    static int distanceFromOrigin(const vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> max_heap;

        for(auto& point : points) {
            if(max_heap.size() < k) {
                max_heap.push(point);
            }
            else {
                if(distanceFromOrigin(max_heap.top()) > distanceFromOrigin(point)) {
                    max_heap.pop();
                    max_heap.push(point);
                }
            }
        }

        vector<vector<int>> output;

        while(!max_heap.empty()) {
            output.push_back(max_heap.top());
            max_heap.pop();
        }
        return output;
    }
};
