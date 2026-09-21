class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> freq; 
        for(int num : nums)
        {
            freq[num]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for(auto& counter : freq)
        {
            buckets[counter.second].push_back(counter.first);
        }
        vector<int> result;
        for(int i = buckets.size()-1; i >= 0; i--)
        {
            if(buckets[i].size() > 0)
            {
                for(int num : buckets[i])
                {
                    result.push_back(num);
                }
            }
            else
            {
                continue;
            }
            if(result.size() == k)
            {
                return result;
            }
        }
        return result;
    }
};
