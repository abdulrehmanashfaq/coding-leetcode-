class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        if(m>n) return -1;
        int ind;
        
        for(int i=0;i<=n-m;i++){
            int j=0;
        
            while(j<m ){
                if(haystack[i+j]==needle[j]){
                        ind =i;
                        j++;
                }
                else{
                    ind =-1;
                    break;
                }
            }
            if(ind!=-1 && j==m){
                return ind;
            }

        }
        return ind ;
    }
};