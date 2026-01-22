class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0;
        sort(nums1.begin(),nums1.end());
        vector<int>result;

        while(i<n1){
            if(i>0 && nums1[i]==nums1[i-1]){
                i++;
                continue;
            }
            int j=0;
            while(j<n2){
                if(nums1[i]==nums2[j]){
                    result.push_back(nums1[i]);
                    j++;
                    break;
                }
                else{
                    j++;
                }
            }
            i++;
        }
        return result;
    }
};