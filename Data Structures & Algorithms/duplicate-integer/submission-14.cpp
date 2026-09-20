class Solution 
{
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        std::unordered_set<int> duplicates;
        for(int i = 0; i < nums.size(); i++)
        {
           if(duplicates.count(nums.at(i)) > 0)
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
