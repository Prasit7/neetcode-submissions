class Solution {
public:
    int trap(vector<int>& height) 
    {
         int n = height.size();
        int l = 0, r = n - 1;
        int ml = 0, mr = 0;
        int water = 0;
        
        while (l <= r) {
            if (height[l] < height[r]) {
                // left side is the bottleneck
                if (height[l] >= ml) {
                    ml = height[l];
                } else {
                    water += ml - height[l];
                }
                ++l;
            } else {
                // right side is the bottleneck
                if (height[r] >= mr) {
                    mr = height[r];
                } else {
                    water += mr - height[r];
                }
                --r;
            }
        }
        
        return water;
    }
};
