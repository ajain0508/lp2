#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int N;
    vector<int>graph[100005];
    Graph(int n){
        N=n;
    }
    void addEdges(int sorce,int dest){
        for(auto edges: graph[sorce]){
            if(dest==edges){
                cout<<"This node is already present"<<endl;
                return ;
            }
        }
        graph[sorce].push_back(dest);
        graph[dest].push_back(sorce);
    }

    void printadjlist(){
        for(int i=1;i<=N;i++){
            cout<<" node connected to "<<i << " nodes are :"<<endl;
            for(auto edges:graph[i]){
                cout<< edges << " ";
            }
            cout<<endl;
        }
    }

    void dfs_traversel(int node){
        vector<int>vis(N+1,0);
        int flag = 0;
        dfs(node,vis,-1,flag);
        if(flag == 1) cout<<"Cycle is detected"<<endl;
        cout<<endl;
        vector<int>l(N+1,0);
        dfsnr(node,l);
        cout<< "NULL"<<endl;
    }

    void dfsnr(int node,vector<int>&vis){
        vis[node]=1;
        stack<int>qt;
        qt.push(node);
        while(!qt.empty()){
            int temp = qt.top();
            qt.pop();
            cout<<temp<<" ==> ";
            for(auto child: graph[temp]){
                if(vis[child]==0){
                    vis[child]=1;
                    qt.push(child);
                }
            }
        }
    }

    void dfs(int node,vector<int>&vis,int par,int& flag){
        vis[node]=1;
        cout<<node<< " ==> ";
        for(auto edges:graph[node]){
            if(par == edges) continue; 
            if(vis[edges]==0){
                dfs(edges,vis,node,flag);
            }
            else if(vis[edges] == 1) {
                flag = 1;
            }
        }
    }

        void bfs_traversel(int node){
            vector<int>vis(N+1,0);
            bfs(node,vis);
            cout<<endl;
            queue<int>qt;
            vector<int>l(N+1,0);
            qt.push(node);
            l[node]=1;
            bfsr(qt,l);
            cout<< "NULL"<<endl;
    }

    void bfsr(queue<int>&qt,vector<int>&vis){
        if(qt.empty()) return;
        int temp=qt.front();
        qt.pop();
        cout<<temp<< "=>";
        for(auto child:graph[temp]){
            if(vis[child]==0){
                vis[child]=1;
                qt.push(child);
            }
        }
        bfsr(qt,vis);
    }

    void bfs(int node ,vector<int>&vis){
        vis[node] = 1;
        int flag = 0;
        int par = -1;
        queue<pair<int,int>>qt;
        qt.push({node,-1});
        while(!qt.empty()){
            pair<int,int> temp = qt.front();
            qt.pop();
            cout<<temp.first<<" ==> ";
            par = temp.second;
            for(auto child: graph[temp.first]){
                if (par == child) continue;
                if(vis[child]==0){
                    vis[child]=1;
                    qt.push({child,temp.first});
                }
                else flag = 1;
            }
        }
        if(flag == 1) cout<<"Cycle is detected"<<endl;
    }
};

int main(){
    cout<<"hello"<<endl;
    Graph obj(7);
    obj.addEdges(1,2);
    obj.addEdges(1,3);
    obj.addEdges(2,4);
    obj.addEdges(3,5);
    obj.addEdges(4,6);
    obj.addEdges(4,7);
    obj.addEdges(5,7);
    obj.addEdges(3,5);
    obj.printadjlist();
    obj.dfs_traversel(1);
    obj.bfs_traversel(1);

}
