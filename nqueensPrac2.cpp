#include<bits/stdc++.h>
using namespace std;

class nqueens{
    public:
    int N;
    int count1 = 0;
    int count2 = 0;
    int arr[4] = {1,-1,1,-1};
    int brr[4] = {1,-1,-1,1};

    int column[100];
    int fsdiagonal[100];
    int bsdiagonal[100];

    nqueens(int n){
        this->N = n;

        for(int i =0;i<N;i++){
            column[i] = 0;
        }
        for(int i =0;i<N+N;i++){
            fsdiagonal[i] = 0;
            bsdiagonal[i] = 0;
        }
    }

    // ---------------------------BackTrack---------------------------------

    void solve_problem_backtrack(){
        cout<<"Generating solutions uisng backtracking"<<endl;
        vector<vector<bool>>visited(N+1,vector<bool>(N+1,0));
        backtrack_solver(0,visited);
    }

    bool check_backtrack(int row,int col,vector<vector<bool>>&visited){
        // col check
        for(int k = 0;k<N;k++){
            if(visited[k][col] == 1) return false;
        }

        // diagonal checking
        for(int i = 0;i<N;i++){
            for(int h = 0;h<4;h++){
                int x = (i*arr[h]) + row;
                int y = (i*brr[h]) + col;
                if(x>=0 && y>=0 && x<N && y<N){
                    if(visited[x][y] == 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    void backtrack_solver(int row,vector<vector<bool>>&visited){
        if(row == N){
            count1++;
            for(int i =0;i<N;i++){
                for(int j = 0;j<N;j++){
                    cout<<visited[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            return;
        }
        for(int col = 0;col<N;col++){
            if(check_backtrack(row,col,visited)){
                visited[row][col] = 1;
                backtrack_solver(row+1,visited);
                visited[row][col] = 0;
            }
        }
    }

    // --------------------------Branch and Bound---------------------------
    void solve_brachAndBound(){
        vector<vector<bool>>visited(N+1,vector<bool>(N+1,0));
        branchAndBound_solver(0,visited);
    }

    bool branchAndBound_check(int row,int col){
        if(column[col] == 1 || fsdiagonal[row-col+N] == 1 || bsdiagonal[row+col] == 1){
            return false;
        }
        return true;
    }
    void branchAndBound_solver(int row,vector<vector<bool>>&visited){
        if(row==N){
            count2++;
            for(int i = 0;i<N;i++){
                for(int j = 0;j<N;j++){
                    cout<<visited[i][j]<<" ";
                }
                cout<<endl; 
            }
            cout<<endl; 
            return;
        }

        for(int col = 0;col<N;col++){
            if(branchAndBound_check(row,col)){
                visited[row][col] = 1;
                column[col] = 1;
                fsdiagonal[row-col+N] = 1;
                bsdiagonal[row+col] = 1;
                branchAndBound_solver(row+1,visited);
                visited[row][col] = 0;
                column[col] = 0;
                fsdiagonal[row-col+N] = 0;
                bsdiagonal[row+col] = 0;
            }
        }       
    }
};

int main(){
    int n;

    while(n!=0){
        cout<<"Enter size of matrix (0 to exit): ";
        cin>>n;

        nqueens obj(n);
        obj.solve_problem_backtrack();
        cout<<"Total No. of matrix are : "<<obj.count1<<endl;
        obj.solve_brachAndBound();
        cout<<"Total No. of matrix are : "<<obj.count2<<endl;
    }
}