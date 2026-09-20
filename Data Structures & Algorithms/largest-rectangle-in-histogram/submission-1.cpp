class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> stk;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int height = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            stk.push(i);
        }

        return maxArea;
    }
};