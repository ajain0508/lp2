#include<bits/stdc++.h>
using namespace std;

int g= 0;

void Display(int arr[]){
    for(int i = 0;i<9;i++){
        if(i%3 == 0) cout<<endl;
        if(arr[i] == -1) cout<<"_ ";
        else cout<< arr[i]<<" ";
    }
    cout<<endl;
}

void moveLeft(int arr[],int position){
    swap(arr[position-1],arr[position]);
}
void moveRight(int arr[],int position){
    swap(arr[position+1],arr[position]);
}
void moveUp(int arr[],int position){
    swap(arr[position-3],arr[position]);
}
void moveDown(int arr[],int position){
    swap(arr[position+3],arr[position]);
}

void copy(int arr[],int brr[]){
    for(int i =0;i<9;i++){
        arr[i] = brr[i];
    }
}
int heuristic(int start[],int goal[]){
    int h = 0;
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(start[i] == goal[j] && start[i]!=-1 ){
                h+=(abs(j-i)/3 + abs(j-i)%3);
            }
        }
    }
    return h+g;
}

void moveTile(int start[],int goal[]){

    int missingTile = 0;
    for(int i = 0;i<9;i++){
        if(start[i] == -1) {
            missingTile = i;
            break;
        }
    }
    int t1[9],t2[9],t3[9],t4[9],f1 = INT_MAX,f2 = INT_MAX,f3 = INT_MAX,f4 = INT_MAX;

    copy(t1,start);
    copy(t2,start);
    copy(t3,start);
    copy(t4,start);

    int row = missingTile/3;
    int col = missingTile%3;

    if(col-1>=0){
        moveLeft(t1,missingTile);
        f1 = heuristic(t1,goal);
    }
    if(col+1<3){
        moveRight(t2,missingTile);
        f2 = heuristic(t2,goal);
    }
    if(row-1>=0){
        moveUp(t3,missingTile);
        f3 = heuristic(t3,goal);
    }
    if(row+1<3){
        moveDown(t4,missingTile);
        f4 = heuristic(t4,goal);
    }

    if(f1<=f2 && f1<=f3 && f1<=f4){
        moveLeft(start,missingTile);
    }
    if(f2<=f1 && f2<=f3 && f2<=f4){
        moveRight(start,missingTile);
    }
    if(f3<=f1 && f3<=f2 && f3<=f4){
        moveUp(start,missingTile);
    }
    if(f4<=f1 && f4<=f2 && f4<=f3){
        moveDown(start,missingTile);
    }
    
}

void solveEight(int start[],int goal[]){
    g++;
    moveTile(start,goal);
    Display(start);

    int f = heuristic(start,goal);
    if(f == g) {
        cout<<"Goal state reached in "<<g<<"moves"<<endl;
        return;
    }
    solveEight(start,goal);
}

bool solvable(int start[]){
    int c = 0;
    for(int i = 0;i<9;i++){
        for(int j = i+1;j<9;j++){
            if(start[i] > start[j] && start[i]!=-1 && start[j]!=-1) c++;
        }
    }
    if(c%2 == 0) return true;
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
    Display(start);
    if(!solvable(start)){
        cout<<"Can't solve"<<endl;
    }
    else {
        solveEight(start,goal);
    }
}