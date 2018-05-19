class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    vector<int> stack;
    if(heights.empty())
      return 0;
    
    heights.push_back(0);
    int area = 0;
    stack.push_back(-1);
    for(int i = 0; i < heights.size(); i++) {
      while(!stack.empty() && heights[i] < heights[stack.back()]) {
        int hi = stack.back();
        stack.pop_back();
        int new_area = heights[hi] * (i - stack.back() - 1);
        if(new_area > area)
          area = new_area;
      }
      stack.push_back(i);
    }
    return area;
  }
};

