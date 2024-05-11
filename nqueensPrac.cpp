#include<bits/stdc++.h>
using namespace std;

class nqueen {
    public:
    int N;
    
    // backtracking
    int matrix1[100][100];
    int arr[4] = {1,-1,1,-1};
    int brr[4] = {1,-1,-1,1};
    
    // branch and bound
    int matrix2[100][100];
    int column[205];
    int fsdiagonal[205];
    int bsdiagonal[205];

    nqueen(int n){
        this->N = n;

        for(int i =0;i<N;i++){
            for(int j = 0;j<N;j++){
                matrix1[i][j] = 0;
            }
        }

        for(int i =0;i<N;i++){
            for(int j = 0;j<N;j++){
                matrix2[i][j] = 0;
            }
        }

        for(int i = 0;i<N;i++){
            column[i] = 0;
        }

        for(int i = 0;i<N+N;i++){
            fsdiagonal[i] = 0;
        }

        for(int i =0;i<N+N;i++){
            bsdiagonal[i] = 0;
        }
    }

    // ------------------------------BACKTRACK---------------------------------------
    void display_backtrack(){
        cout<<"Displaying Backtrack soulution"<<endl;
        for(int i = 0;i<N;i++){
            for(int j = 0 ;j<N;j++){
                cout<<matrix1[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void backtrack(){
        cout<<"Generating the matrix...."<<endl;
        vector<vector<int>>visited(N+1,vector<int>(N+1,0));

        backtrack_solve(0,visited);

        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                matrix1[i][j] = visited[i][j];
            }
        }

    }

    bool backtrack_check(int row,int col,vector<vector<int>>visited){
        // check if there is queen placed in that coulumn
        for(int k = 0;k<N;k++){
            if(visited[k][col] == 1) return false;
        }

        // check for diagonals
        for(int k = 0;k<N;k++){
            for(int h = 0;h<4;h++){
                int x = (arr[h]*k) + row;
                int y = (brr[h]*k) + col;

                if(x>=0 && y>=0 && x<N && y<N){
                    if(visited[x][y] == 1) return false;
                }
            }
        }

        return true;
    }

    bool backtrack_solve(int row,vector<vector<int>>&visited){
        if(row == N) return true;
        for (int col = 0;col<N;col++){
            if(backtrack_check(row,col,visited)){
                visited[row][col] = 1;
                if(backtrack_solve(row+1,visited) == true) return true;
                visited[row][col] = 0;
            }
        }
        return false;
    }

    // ----------------------------------Branch and Bound--------------------------------------
    void display_branch_bound(){
        cout<<"\nDisplaying BranchBound soulution...."<<endl;
        for(int i =0;i<N;i++){
            for(int j = 0;j<N;j++){
                cout<<matrix2[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void branchBound(){
        vector<vector<int>>visited(N,vector<int>(N,0));
        branchBound_solve(0,visited);

        // assigning values to matrix2
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                matrix2[i][j] = visited[i][j];
            }
        }

    }

    bool branchBound_check(int row,int col){
        if(column[col] == 1 || fsdiagonal[row-col+N] == 1 || bsdiagonal[row+col] == 1){
            return false;
        }
        return true;
    }

    bool branchBound_solve(int row,vector<vector<int>>&visited){
        if(row == N) return true;

        for(int col = 0;col < N;col++){
            if(branchBound_check(row,col)){
                visited[row][col] = 1;
                column[col] = 1;
                fsdiagonal[row-col+N] = 1;
                bsdiagonal[row+col] = 1;
                if(branchBound_solve(row+1,visited)) return true;
                visited[row][col] = 0;
                column[col] = 0;
                fsdiagonal[row-col+N] = 0;
                bsdiagonal[row+col] = 0;
            }
        }
        return false;
    }

};

int main(){
    int N = 1;

    while(N!=0 ){
        cout<<"Enter size of matrix  (Enter 0 to exit): ";
        cin>>N;
        nqueen obj(N);
        obj.backtrack();
        obj.display_backtrack();
        obj.branchBound();
        obj.display_branch_bound();
    }
    
}