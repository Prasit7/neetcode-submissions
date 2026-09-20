class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int area = 0;
        int left = 0;
        int right = heights.size()-1;
        while (left < right)
        {
            int new_area = (right - left) * min(heights.at(left), heights.at(right));
            area = max(area, new_area);
            if(heights.at(left) < heights.at(right))
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return area;
    }
};
