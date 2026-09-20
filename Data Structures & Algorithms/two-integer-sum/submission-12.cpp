class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> numberTracker;
        vector<int> solution;
        for(int i = 0; i < nums.size(); i++)
        {
            if(numberTracker.count(target - nums.at(i)))
            {
                solution.push_back(numberTracker.at(target-nums.at(i)));
                solution.push_back(i);
                return solution;
                
            }
            else
            {
                numberTracker[nums.at(i)] = i;
            }
        }
    }
};
