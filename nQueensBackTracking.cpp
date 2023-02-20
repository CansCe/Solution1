#include<bits/stdc++.h>

using namespace std;

#define n 6

typedef vector<vector<string>> Board;

void inBoard(Board& b){
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b.size();j++){
            cout<<b[i][j]<<"  ";
        }
        cout<<endl;
    }
}

bool safe(int row,int col,Board& b){
    for(int i=0;i<col;i++){
        if(b[row][i]=="Q") return false;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(b[i][j]=="Q") return false;
    }
    for(int i=row,j=col;i<b.size() && j>=0;i++,j--){
        if(b[i][j]=="Q") return false;
    }
    return true;
}

void recS(Board b,int row){
    if(row==b.size()){
        inBoard(b);
        cout<<endl;
        return;
    }
    for(int i=0;i<b.size();i++){
        if(safe(i,row,b)){
            b[i][row]="Q";
            recS(b,row+1);
            b[i][row]="-";
        }
    }
}

Board solveNQueens(int A) {
    Board b;
    for(int i=0;i<A;i++){
        vector<string> v;
        for(int j=0;j<A;j++){
            v.push_back("-");
        }
        b.push_back(v);
    }
    recS(b,0);
    return b;
}
int main(){
    
    clock_t  s,e;
    s = clock();
    
    Board b = solveNQueens(n);
    e=clock();
    cout<<"Time taken: "<<(double)(e-s)/CLOCKS_PER_SEC<<endl;
    return 0;
}