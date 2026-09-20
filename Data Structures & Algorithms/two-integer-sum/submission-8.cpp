class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> numbers;
        for(int i = 0; i < nums.size(); i++)
        {
            numbers[nums.at(i)] = i;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums.at(i);
            if(numbers.count(diff) && numbers.at(diff) != i)
            {
                return {i, numbers.at(diff)};
            }
        }
        return {}; 
    }
};
