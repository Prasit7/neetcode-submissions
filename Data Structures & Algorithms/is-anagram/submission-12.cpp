class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, int> stringMap;
        unordered_map<char, int> stringMap2;
        for(int i = 0; i < s.size(); i++)
        {
            if(stringMap.count(s.at(i)))
            {
                stringMap.at(s.at(i))+=1;
                //stringMap[s.at(i)]+=1;
            }
            else 
            {
                stringMap.insert({s.at(i), 1});
                //stringMap[s.at(i)] = 1
            }
        }
        for(int i = 0; i < t.size(); i++)
        {
            if(stringMap2.count(t.at(i)))
            {
                stringMap2.at(t.at(i))+=1;
                //stringMap[s.at(i)]+=1;
            }
            else 
            {
                stringMap2.insert({t.at(i), 1});
                //stringMap[s.at(i)] = 1
            }
        }
        return stringMap == stringMap2;
        // for(int i = 0; i < t.size(); i++)
        // {
        //     if(stringMap.count(t.at(i)))
        //     {
        //         stringMap.at(t.at(i))-=1;
        //         if(stringMap.at(t.at(i)) < 0)
        //         {
        //             return false;
        //         }
        //     }
        //     else
        //     {
        //         return false;
        //     }
        // }

    }
};
