class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int j=1;
        while(i<=nums.size()-1 && j <=nums.size()-1){
            if(nums[i]==0){
                if(nums[j]==0){
                    j++;

                }
                else{
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                i++;
                j++;
                }
            }
            else{
                i++;
                j++;
            }
        }
    }
};