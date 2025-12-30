class Solution {
public:
    bool isPalindrome(int x) {
        long long y=0;
        for(long long  i=x;i>0;i=i/10){
             y= y*10+(i%10);
        }
        if(y==x){
            return true;
        }
        else{
            return false;
        }
        
    }
};