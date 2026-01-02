class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        int n=nums.size();
        int i=0;
        while(i<n-k){
            if(nums[i]==val){
                int temp=nums[i];
                nums[i]=nums[n-1-k];
                nums[n-1-k]=temp;
                k++;
            }
            else{
                i++;
            }
        }
        return n-k;
        
    }
};