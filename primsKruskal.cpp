#include <bits/stdc++.h>
using namespace std;

    class graph{
        public:
        int adj[20][20];
        int par[20];
        int nodes;
        int edges;
        int weight1=0;
        int weight = 0;
        graph(int nodes,int edges){
            this->nodes=nodes;
            this->edges=edges;
            for(int i=0;i<nodes;i++){
                for(int j=0;j<nodes;j++)adj[i][j]=0;
            }
        }

        void display(){
            for(int i=0;i<nodes;i++){
                for(int j=0;j<nodes;j++){
                    if(adj[i][j]!=0){
                        cout<<i<<" "<<j<<" "<<adj[i][j]<<endl;
                    }
                }
            }
        }

        void create(int a,int b,int c){
            adj[a][b]=c;
            adj[b][a]=c;
        }

        void prims(){
            int vis[nodes+1];
            for(int i=0;i<nodes+1;i++)vis[i]=0;
            vis[0]=1;
            int edges=0;
            while(edges<nodes-1){
                int x=0,y=0;
                int mi=1e9;
                for(int i=0;i<nodes;i++){
                    if(vis[i]){
                        for(int j=0;j<nodes;j++){
                            if( !vis[j] && adj[i][j]!= 0 &&  mi > adj[i][j]){
                                    mi = adj[i][j];
                                    x=i;
                                    y=j;
                            }
                        }
                    }
                }
                edges++;
                cout<<x<<" -- "<<y<< " "<<adj[x][y]<<endl;
                weight+=adj[x][y];
                vis[y]=1;
            }
        }

        int find_par(int x){
            if(par[x]==x)return x;
            return par[x]=find_par(par[x]);
        }

        int union_set(int x,int y){
            int p=find_par(x);
            int q=find_par(y);
            par[p]=q;
        }

        void kruskal(){
            int edge=0;
            for(int i=0;i<nodes;i++)par[i]=i;
            while(edge < nodes-1){
                int mx=1e9;
                int x=0,y=0;
                for(int i=0;i<nodes;i++){
                    for(int j=0;j<nodes;j++){
                        if (find_par(i)!=find_par(j) && adj[i][j]  && mx > adj[i][j]){
                            x=i,y=j;
                            mx=adj[i][j];
                        }
                    }
                }
                cout<<x<< ' '<<y<<endl;
                edge++;
                weight1+=mx;
                union_set(x,y);
            }
            
        }

    };

    int main(){
        graph obj(5,8);
        obj.create(1,2,1);
        obj.create(3,4,1);
        obj.create(0,1,3);
        obj.create(3,2,3);
        obj.create(1,4,2);
        obj.create(2,0,2);
        obj.display();
        obj.prims();
        obj.kruskal();
        cout<<obj.weight1<<endl;
        cout<<obj.weight<<endl;
    }