class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left = 0;
        int right = numbers.size()-1;
        while(left < right)
        {
            if(numbers.at(left) + numbers.at(right) == target)
            {
                return {left+1, right+1};
            }
            else if(numbers.at(left) + numbers.at(right) > target)
            {
                right--;
            }
            else{
                left++;
            }
        }
    }
};
