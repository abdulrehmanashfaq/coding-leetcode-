class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size() ;
        vector<vector<int>>graph(n+1);

        for (auto edge : edges) {

            int u =  edge[0];
            int v = edge[1];


            vector<int>visited(n+1,false);
            queue<int>q;

            int start = u ;
            int dest  = v ;
            visited[u]  = true ;
            bool found = false;
            q.push(u);

            while (!q.empty()){


                int ne = q.front() ;
                if(ne == v){
                    found = true ;
                    break ;
                }

                q.pop();

                for (auto i : graph[ne]){

                    if(!visited[i]){

                        q.push(i);
                        visited[i] = true ;


                    }

                }


            }

            if (found){
                return edge;
            }


            graph[u].push_back(v);
            graph[v].push_back(u);

        }


        return {} ;

    


        
    }
};