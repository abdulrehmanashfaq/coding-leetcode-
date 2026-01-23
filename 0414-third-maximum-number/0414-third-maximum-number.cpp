class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int>vec;
        int n=nums.size();
        for(int i=0;i<n;i++){
            bool flag=true;
            if(i==0){
                vec.push_back(nums[i]);
            }
            else{
            for(int j=0;j<vec.size();j++){
                if(nums[i]!=vec[j]){
                    flag=true;
                }
                else{
                    flag=false;
                    break;
                }

            }
            if(flag==true){
                vec.push_back(nums[i]);
            }
            }
        }
        sort(vec.begin(),vec.end());
        if(vec.size()>=3){
            return vec[vec.size()-1-2];
        }
        else{
            return vec[vec.size()-1];
        }

    }
};