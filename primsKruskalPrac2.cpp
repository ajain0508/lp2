#include<bits/stdc++.h>
using namespace std;


class graph{
    public:
    int N;
    int adj[20][20];
    int par[20];
    
    int weightPrims= 0;
    int weightKruskal = 0;

    graph(int n){
        N = n;

        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                adj[i][j] = 0;
            }
        }

        for(int i = 0;i<N;i++) par[i] = 0;
    }

    void create(int a,int b,int c){
        adj[a][b] = c;
        adj[b][a] = c;
    }

    void Prims(int start){
        vector<int>vis(N,0);
        vis[start] = 1;
        int edges = 0;
        while(edges < N-1){
            int min = 1e9; 
            int x = start;
            int y = start;
        
            for(int i = 0;i<N;i++){
                if(vis[i]){
                    for(int j = 0;j<N;j++){
                        if(!vis[j] && adj[i][j]!=0 && min>adj[i][j]){
                            x = i;
                            y = j;
                            min = adj[i][j];
                        }
                    }
                }
            }
            cout<<x <<" "<<y<<" "<<min<<endl;
            edges++;
            weightPrims+= adj[x][y];
            vis[y] = 1;
        }
    }

    int find_par(int i){
        if(par[i] == i) return i;
        return par[i] = find_par(par[i]);
    }
    void union_set(int i,int j){
        int x = find_par(i);
        int y = find_par(j);

        par[x] = y;
    }

    void kruskal(){
        int edges = 0;
        for(int i = 0 ;i<N;i++) par[i] = i;

        while(edges<N-1){
            int x = 0;
            int y = 0;
            int min = 1e9;

            for(int i = 0;i<N;i++){
                for(int j = 0;j<N;j++){
                    if(find_par(i)!=find_par(j) && adj[i][j]!=0 && min>adj[i][j]){
                        x = i;
                        y = j;
                        min = adj[i][j];
                    }
                }
            }
            cout<<x <<" "<<y<<" "<<min<<endl;
            weightKruskal+=adj[x][y];
            edges++;
            union_set(x,y);
        }
    }

};

int main(){
    graph obj(5);
    obj.create(1,2,1);
    obj.create(3,4,1);
    obj.create(0,1,1);
    obj.create(3,2,3);
    obj.create(1,4,2);
    obj.create(2,0,2);
    cout<<"\nAccording to Prims algorithm "<<endl;
    obj.Prims(0);
    cout<<"Weight for Prims is "<<obj.weightPrims<<endl;
    cout<<"\nAccording to Kruskal algorithm "<<endl;
    obj.kruskal();
    cout<<"Weight for Kruskal is "<<obj.weightKruskal<<endl;
}