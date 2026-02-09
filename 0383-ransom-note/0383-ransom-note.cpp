class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char , int>m;
        for(auto it : ransomNote){
                m[it]++;
        }
        for(auto it : magazine){

            m[it]--;
        }
        for(auto it : m){
            if(it.second>0){
                return false ;
            }
        }
        return true ;
    }
};