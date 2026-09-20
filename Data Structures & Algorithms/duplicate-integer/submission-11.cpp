class Solution 
{
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        std::unordered_set<int> duplicates;
        for(int i = 0; i < nums.size(); i++)
        {
           if(duplicates.count(nums.at(i)))
           {
            return true;
           }
           else
           {
            duplicates.insert(nums.at(i));
           }
        }
        return false;
    }
};
