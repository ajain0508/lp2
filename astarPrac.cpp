#include<bits/stdc++.h>
using namespace std;

int g = 0;

void print(int puzzle[]){
    
    for(int i =0;i<9;i++){
        if(i%3 == 0) cout<<endl;

        if(puzzle[i] == -1) cout<<"_ ";
        else cout<<puzzle[i]<<" ";
    }
    cout<<"\n\n";

}

void moveLeft(int puzzle[],int position){
    swap(puzzle[position-1],puzzle[position]);
}

void moveRight(int puzzle[],int position){
    swap(puzzle[position+1],puzzle[position]);
}

void moveUp(int puzzle[],int position){
    swap(puzzle[position-3],puzzle[position]);
}

void moveDown(int puzzle[],int position){
    swap(puzzle[position+3],puzzle[position]);
}

void copy(int temp[],int real[]){
    for(int i =0;i<9;i++){
        temp[i] = real[i];
    }
}

int heuristic(int start[],int goal[]){
    int h = 0;
    for(int i =0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(start[i] == goal[j] && start[i]!= -1){
                h+=((abs(i-j)/3) + (abs(i-j)%3));
            }
        }
    }
    return h+g;
}

void moveTile(int start[],int goal[]){
    int blankTilePos = 0;
    for(int i =0;i<9;i++){
        if(start[i] == -1) {
            blankTilePos=i;
            break;
        }
    }

    int row = blankTilePos/3;
    int col = blankTilePos%3;

    int t1[9],t2[9],t3[9],t4[9],f1 = INT_MAX, f2 = INT_MAX, f3 = INT_MAX, f4 = INT_MAX;

    copy(t1,start);
    copy(t2,start);
    copy(t3,start);
    copy(t4,start);

    if(col-1 >= 0){
        moveLeft(t1,blankTilePos);
        f1 = heuristic(t1,goal);
    }

    if(col+1 <3){
        moveRight(t2,blankTilePos);
        f2 = heuristic(t2,goal);
    }

    if(row - 1>=0 ){
        moveUp(t3,blankTilePos);
        f3 = heuristic(t3,goal);
    }

    if(row+1<3){
        moveDown(t4,blankTilePos);
        f4 = heuristic(t4,goal);
    }

    if(f1<=f2 && f1<=f3 && f1<=f4){
        moveLeft(start,blankTilePos);
    }

    else if(f2<=f1 && f2<=f3 && f2<=f4){
        moveRight(start,blankTilePos);
    }

    else if(f3<=f1 && f3<=f2 && f3<=f4){
        moveUp(start,blankTilePos);
    }

    else {
        moveDown(start,blankTilePos);
    }
}

void solveEight(int start[],int goal[]){
    g++;

    moveTile(start,goal);
    print(start);
    int f = heuristic(start,goal);

    if(f==g) {
        cout<<"Game completed in "<<f<< " moves"<<endl;
        return;
    }

    solveEight(start,goal);
}

bool solvable(int start[]){
    int greaterThan = 0;

    for(int i = 0;i<9;i++){
        for(int j  = i+1;j<9;j++){
            if(start[i] > start[j] && start[j]!=-1){
                greaterThan++;
            }
        }
    }

    if(greaterThan%2 == 0) return true;
    return false;
}

int main(){
    int start[9];
    int goal[9];
    cout << "Enter the start state:(Enter -1 for empty):";
    for(int i = 0; i < 9; i++){
        cin >> start[i];
    }
    cout << "Enter the goal state:(Enter -1 for empty):";
    for(int i = 0; i < 9; i++){
        cin >> goal[i];
    }

    if(solvable(start)){
        print(start);
        solveEight(start,goal);
    }
    else cout<<"Reaching Goal State is not possible"<<endl;
}