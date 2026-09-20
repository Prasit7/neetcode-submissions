class Solution 
{
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        std::unordered_set<int> counter;
        for(int x : nums)
        {
            if(counter.count(x))
            {
                return true;
            }
            else
            {
                counter.insert(x);
            }
        }
        return false;
    }
};
