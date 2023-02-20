#include<bits/stdc++.h>
#define N 6


using namespace std;
typedef vector<vector<int>> Board;

//pair<int> position; 

void inBoard(Board& b){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<b[i][j]<<"  ";
        }
        cout<<endl;
    }
}
/*
bool check(Board& b,int x,int y){
    for(int i=0;i<N;i++){
        if(b[x][i]==1) return false;
        if(b[i][y]==1) return false;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if((i+j)==(x+y) && b[i][j]==1) return false;
            if((i-j)==(x-y) && b[i][j]==1) return false;
        }
    }
    return true;
}*/
bool isSafe(Board b,int row,int col){
    for(int i=0;i<col;i++){
        if(b[row][i]==1) return false;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(b[i][j]==1) return false;
    }
    for(int i=row,j=col;i<N && j>=0;i++,j--){
        if(b[i][j]==1) return false;
    }
    return true;
}

/*
bool check1(Board& b,int x,int y){
    int x1 = x-1;
    int y1 = y-1;
    for(int i=y1;i>=0;i--){
        if(b[x][i]==1) return false;
    }
    for(int i=x1;i>=0;i--){
        if(b[i][y]==1) return false;
    }
    for(int i=x1,j=y1; i>=0 && j>=0; i--,j--){
        if(b[i][j]==1) return false;
    }
    for(int i=x1,j=y1;i>=0 && j<N;i--,j++){
        if(b[i][j]==1) return false;
    }
    return true;
}*/
/*
void solve(Board& b,int numberOfQueens){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(check1(b,i,j)){
                b[i][j]=1;
                solve(b,numberOfQueens-1);
            }
        }
    }
}*/
bool solve (Board& b,int col){
    if(col>=N) return true;
    for(int i=0;i<N;i++){
        if(isSafe(b,i,col)){
            b[i][col]=1;
            if(solve(b,col+1)) return true;
            b[i][col]=0;
        }
    }
    return false;
}
bool solveNQ(){

    
    Board b(N,vector<int>(N,0));
    if(solve(b,0)==false){
        cout<<"No solution"<<endl;
        return false;
    }
    inBoard(b);
    return true;
}
int main(){
    clock_t s,e;
    s = clock();
    solveNQ();
    e = clock();
    cout<<"Time taken: "<<(double)(e-s)/CLOCKS_PER_SEC<<endl;
    
    return 0;
}