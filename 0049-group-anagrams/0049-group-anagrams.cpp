class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>m;
        vector<vector<string>>res;
        for(auto it : strs){
            string temp= it ;
            sort(temp.begin(),temp.end());
            m[temp].push_back(it);
            
        }
        for(auto it : m ){
            res.push_back(it.second);
        }
        return res;
        
    }
};