class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       heights.push_back(0);

        // Stack to store indices of bars
        stack<int> stk;

        // Variable to track the maximum area found
        int maxArea = 0;

        // Iterate through each bar in the histogram
        for (int i = 0; i < heights.size(); ++i) {

            // Process all bars that are taller than the current one
            while (!stk.empty() && heights[i] < heights[stk.top()]) {

                // Get the height of the last bar in the stack
                int height = heights[stk.top()];
                stk.pop();

                // Compute width
                int width;
                if (stk.empty()) {
                    width = i;  // No smaller bar to the left
                } else {
                    width = i - stk.top() - 1;  // Width between bars
                }

                // Compute area and update maxArea
                int area = height * width;
                if (area > maxArea) {
                    maxArea = area;
                }
            }

            // Push current index onto the stack
            stk.push(i);
        }

        // Return the maximum area found
        return maxArea;
    }
};