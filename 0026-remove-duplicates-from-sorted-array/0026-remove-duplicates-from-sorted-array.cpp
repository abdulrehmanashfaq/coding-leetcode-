class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
        else if(n==0){
            return 0;
        }
        int i=0;
        while(i<n-1){
            
                if(nums[i]==nums[i+1] ){
                    if(n==1){
                        return 1;
                    }
                    for(int k=i+1;k<n-1;k++){
                        int temp=nums[k];
                        nums[k]=nums[k+1];
                        nums[k+1]=temp;
                    
                }
                    
                   n--;
            }
            else{
                i++;
            }
        }


         return n;
    }
   
};