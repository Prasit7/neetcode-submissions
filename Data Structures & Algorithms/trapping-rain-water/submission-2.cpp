class Solution {
public:
    int trap(vector<int>& height) {
        //Base case if no height
        if (height.empty()) 
        {
            return 0;
        }
        //left and right pointers 
        int l = 0, r = height.size() - 1;
        //start with left and right vectors
        int leftMax = height[l], rightMax = height[r];
        //solution
        int res = 0;
        //if left is smaller than right
        while (l < r) 
        {
            //if left is smaller update left pointer
            if (leftMax < rightMax) 
            {
                //move left pointer
                l++;
                //update left max with current height right now
                leftMax = max(leftMax, height[l]);
                //update solution
                res += leftMax - height[l];
            } 
            else 
            {
                //update right
                r--;
                //update right max with current height
                rightMax = max(rightMax, height[r]);
                // update solution
                res += rightMax - height[r];
            }
        }
        return res;
    }
};
