class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int>vec(1,1);
        if(rowIndex==0){
            return vec;
        }
        
        for(int j=0;j<rowIndex;j++){
            vector<int>vecn(vec.size()+1,1);
            int n=vec.size()-1;
        for(int i=1;i<=n;i++){


            vecn[i]=vec[i-1]+vec[i];   
            

        
        }
        vec=vecn;
        }
        return vec;
    }
};