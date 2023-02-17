#include<iostream>
#include<vector>
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
}

bool check1(Board& b,int x,int y){
    int x1 = x-1;
    int y1 = y-1;
    for(int i=y1;i>=0;i--){
        if(b[x][i]==1) return false;
    }
    for(int i=x1;i>=0;i--){
        if(b[i][y]==1) return false;
    }
    for(int i=x1,j=y1;i>=0 && j>=0;i--,j--){
        if(b[i][j]==1) return false;
    }
    for(int i=x1,j=y1;i>=0 && j<N;i--,j++){
        if(b[i][j]==1) return false;
    }
    return true;
}
void solve(Board& b,int numberOfQueens){
    if(numberOfQueens==0){
        cout<<"Solution is: "<<endl;
        inBoard(b);
        return;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(check1(b,i,j)){
                b[i][j]=1;
                numberOfQueens-=1;
                solve(b,numberOfQueens);
            }else{
                b[i][j]=0;
            }
        }
    }
}
int main(){
    Board b(N,vector<int>(N,0));
    inBoard(b);
    solve(b,6);
    return 0;
}