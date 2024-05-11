#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    int adj[20][20];
    int par[20];
    int nodes;
    int weight1 = 0;
    int weight = 0;

    graph(int nodes){
        this->nodes = nodes;

        for (int i = 0;i<nodes;i++){
            for(int j = 0;j<nodes;j++){
                adj[i][j] = 0;
            }
        }

    }

    void display(){
        for(int i = 0;i<nodes;i++){
            for(int j = 0;j<nodes;j++){
                if(adj[i][j]!=0){
                    cout<<i<<" "<<j<<" "<<adj[i][j]<<endl;
                }
            }
        }
    }

    void create(int a,int b,int c){
        adj[a][b] = c;
        adj[b][a] = c;
    }

    void prims(){
        int edge = 0;
        int vis[nodes];
        for(int i =0;i<nodes;i++) vis[i] = 0;
        vis[0] = 1;   //start with node 0
        cout<<"X"<<" "<<"Y"<<" "<<"Weight"<<endl;
        while(edge < nodes-1){
            int x = 0;
            int y = 0;
            int min = 1e9;
            for(int i =0;i<nodes;i++){
                if(vis[i]){
                    for(int j = 0;j<nodes;j++){
                        if(vis[j] == 0 && adj[i][j]!=0 && min>adj[i][j]){
                            min = adj[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
            edge++;
            weight+=min;
            cout<<x<<" "<<y<<" "<<min<<endl;
            vis[y] = 1;
        }
    }

    int find_par(int x){
        if(par[x] == x) return x;
        return par[x] = find_par(par[x]);
    }
    
    void union_set(int x,int y){
        int p = find_par(x);
        int q = find_par(y);

        par[p] = q;
    }

    void kruskal(){
        int edge = 0;
        for (int i = 0;i<nodes;i++){
            par[i] = i;
        }
        cout<<"X"<<" "<<"Y"<<" "<<"Weight"<<endl;
        while(edge<nodes-1){
            int x = 0;
            int y = 0;
            int min = 1e9;
            for(int i = 0;i<nodes;i++){
                for(int j = 0;j<nodes;j++){
                    if(find_par(i)!=find_par(j) && adj[i][j]!=0 && min>adj[i][j]){
                        min = adj[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
            edge++;
            cout<<x<<" "<<y<<" "<<min<<endl;
            weight1+=min;
            union_set(x,y);
        }
    }
};

int main(){
    graph obj(5);
    obj.create(1,2,1);
    obj.create(3,4,1);
    obj.create(0,1,3);
    obj.create(3,2,3);
    obj.create(1,4,2);
    obj.create(2,0,2);
    obj.display();
    obj.prims();
    obj.kruskal();
}