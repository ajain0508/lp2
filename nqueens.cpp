#include <bits/stdc++.h>
using namespace std;



    class nqueen{
        public:
        int count = 0;
        int N;
    //  for checking diagonals
        int arr[4]={1,-1,1,-1};
        int brr[4]={1,-1,-1,1};
        
        // bounding for col and front and back diagonal
        int coloum[205];
        int fsdiagonal[205];
        int bsdiagonal[205];
        
        
        nqueen(int n){
            N=n;

            // assigning the 0 to every cell 
            for(int i=0;i<N;i++){
                coloum[i]=0;
            }
            for(int i=0;i<N+N;i++){
                fsdiagonal[i]=0;
            }
            for(int i=0;i<N+N;i++){
                bsdiagonal[i]=0;
            }
        }

        // ------------------------------------- BACKTRACK-------------------------------------

        void solve_problem_backtrak(){
            cout<<endl;
            cout<<"generating valid matrix ......"<<endl;
            cout<<endl;
            vector<vector<int>>vis(N+1,vector<int>(N+1,0));
            // call for 0th row for solving nqueen problem
            solver(0,vis);
        }
        
        bool check(int i,int j,vector<vector<int>>&vis){
            // checking any queen is present in j th coloum or not        
            for (int k = 0; k < N; k++){
                if(vis[k][j]==1) return false;
            }

            // checking any queen is present in xth row and y th coloum or not  
            for(int k=0;k<N;k++){
                for(int h=0;h<4;h++){
                    int x=(arr[h]*k)+i;
                    int y=(brr[h]*k)+j;
                    if( x>=0 && y>=0 && x<N && y<N){
                        if(vis[x][y]==1)return false;
                    }
                }
            }
            return true;
            
        }

        void solver(int row,vector<vector<int>>&vis){
            if(row==N) {
                count++;
                for(int i=0;i<N;i++){
                    for(int j=0;j<N;j++){
                        cout<<vis[i][j]<<" ";
                    }
                    cout<<endl;
                }
                return;
            }
            for(int col=0;col<N;col++){
                // checking if on for nth row and ith col is valid cell or not 
                if(check(row,col,vis)){
                    vis[row][col]=1;
                    // by keeping queen on nth row and ith col moving next row(n+1) to check weather there is valid cell 

                    solver(row+1,vis);
                    vis[row][col]=0;
                }
            }
        }


    // ---------------------------- BRANCH AND BOUND------------------------------------

        bool branchandbound(){
            cout<<endl;
            cout<<"generating valid matrix by branch and bound......"<<endl;
            cout<<endl;
            vector<vector<int>>vis(N+1,vector<int>(N+1,0));
            
            // call for 0th row for solving nqueen problem
            bbsolver(0,vis);

            // assigning the answer to matrix 
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    matrix1[i][j]=vis[i][j];
                }
            }
        }

        bool check_for_branch_and_bound(int row,int col){
            if( coloum[col] == 1 || fsdiagonal[ row - col + N] == 1 || bsdiagonal[ row + col ]==1){
                return false;
            }
            return true;
        }
        void bbsolver(int row,vector<vector<int>>&vis){
            if(row==N){
                for(int i=0;i<N;i++){
                    for(int j=0;j<N;j++){
                        cout<<vis[j][i]<<" ";
                    }
                    cout<<endl;
                }
                return ;
            }
            for(int col=0;col<N;col++){
                if(check_for_branch_and_bound(row,col)){
                    vis[row][col]= 1;
                    coloum[col]= 1;
                    fsdiagonal[ row - col + N] = 1;
                    bsdiagonal[ row + col ] = 1;
                    bbsolver(row + 1,vis);
                    vis[row][col]= 0;
                    coloum[col]= 0;
                    fsdiagonal[ row - col + N] = 0;
                    bsdiagonal[ row + col ] = 0;
                }
            }
        }
    };

    int main(){
        
        cout<< " ------  SOLVERIN N QUEEN PROBLEM ---------"<<endl;
        while (true)
        {
            int n;
            cout<<" size of matrix : ";cin>>n;
            if(n==0)break ;
            nqueen obj(n);
            obj.solve_problem_backtrak();
            cout<<obj.count<<endl;
            cout<<endl;
            obj.branchandbound(); 
        }
        


        // 2 3 4 5
        // 3 4 5 6
        // 4 5 6 7 
        // 5 6 7 8

        // 0 -1 -2 -3
        // 1  0 -1 -2
        // 2  1  0 -1 
        // 3  2  1  0
}