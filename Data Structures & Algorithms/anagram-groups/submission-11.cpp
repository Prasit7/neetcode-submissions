class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> solution;
        for(int i = 0; i < strs.size(); i++)
        {
            vector<int> character (26, 0);
            for(int j = 0; j < strs.at(i).size(); j++)
            {
                character.at((int)(strs.at(i).at(j)) - (int)('a'))++;
            }
            string array_to_string = "";
            for(int x = 0; x < character.size(); x++)
            {
                array_to_string += character.at(x);
            }
            solution[array_to_string].push_back(strs.at(i));
            
        }

        vector<vector<string>> finalSolution;
        for(auto& pair : solution)
        {
            finalSolution.push_back(pair.second);
        }
        return finalSolution;
    }
};
