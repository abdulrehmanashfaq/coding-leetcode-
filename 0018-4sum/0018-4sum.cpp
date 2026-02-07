class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>vec;
        sort(nums.begin(),nums.end());
        int n= nums.size();
        for(int i=0; i<n ; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue ;
            }
            for(int j=i+1;j<n;j++){
                 if (j > i+1 && nums[j] == nums[j - 1]) continue;
                int p=j+1 ;
                int q=n-1;
                while(p<q){
                    long long sum= (long long )nums[i]+(long long )nums[j]+(long long )nums[p]+(long long )nums[q];
                    if(sum==target){
                        vec.push_back({nums[i],nums[j],nums[p],nums[q]});
                        p++;
                         while(p<q && nums[p-1]==nums[p]){
                            p++;
                        }
                        q--;
                        
                    }
                    else if(target>sum){
                        p++;
                     
                            
                    }
                    else{
                            q--;
                    }

                }
               

            }
        }
        return vec;


    }
};