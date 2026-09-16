class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;
        if (position.size() <= 1) return position.size();

        for(int i = 0; i < position.size(); ++i) {
            double timeToEnd = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], timeToEnd});
        }

        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b)
        { return a.first < b.first; });

        double timeToCatchUp = cars.back().second;
        int numFleets = 1;

        for(int i = cars.size() - 2; i >= 0; --i) {
            if(cars[i].second > timeToCatchUp) {
                numFleets++;
                timeToCatchUp = cars[i].second;
            }
        }
        return numFleets;
    }
};
