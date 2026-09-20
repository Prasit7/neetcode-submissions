class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        unordered_set<int> numbers;
        for(int i = 0; i < nums.size(); i++)
        {
            if(numbers.count(nums.at(i)))
            {
                return true;
            }
            numbers.insert(nums.at(i));
        }
        return false;
    }
};
