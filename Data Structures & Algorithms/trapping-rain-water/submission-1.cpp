using namespace std;
#include <vector>

class Solution {
  public:
    int trap(vector<int>& height) {
      int left { 0 };
      int right = height.size() - 1;
      int total { 0 };
      int maxLeft = height[left]; int maxRight = height[right];

      while(left < right) {
        if(maxLeft < maxRight) {
          ++left;
          maxLeft = max(maxLeft, height[left]);
          total += maxLeft - height[left];
        }
        else {
          --right;
          maxRight = max(maxRight, height[right]);
          total += maxRight - height[right];
        }
      }
      return total;
    }
};
