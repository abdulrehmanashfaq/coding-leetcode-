class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='I'){
                sum=sum+1;
            }
            else if(s[i]=='V'){
                if(i>0 && s[i-1]=='I'){
                    sum=sum+3;
                }
                else{
                sum=sum+5;
                }
            }
            else if(s[i]=='X'){
                if(i>0 &&s[i-1]=='I'){
                    sum=sum+8;
                }
                else{
                sum=sum+10;
                }
            }
              else if(s[i]=='L'){
                if(i>0 && s[i-1]=='X'){
                    sum=sum+30;
                }
                else{
                sum=sum+50;
                }
            }  else if(s[i]=='C'){
                if(i>0 && s[i-1]=='X'){
                    sum=sum+80;
                }
                else
                sum=sum+100;
            }
              else if(s[i]=='D'){
                if(i>0 && s[i-1]=='C'){
                    sum=sum+300;
                }
                else{
                sum=sum+500;
                }
            }
              else if(s[i]=='M'){
                if(i>0 && s[i-1]=='C'){
                    sum=sum+800;
                }
                else{
                sum=sum+1000;

                }
            }
        }
        return sum;
    }
};