#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define N 3
using namespace std;
typedef vector<vector<int>> Board;

struct State{
    int x,y;
    Board board;
    vector<char> history_actions;
    int g;

    vector<char> getAction(){
        // {'l','r','u','d'}
        vector<char> actions = {'l','r','u','d'};
        if (x == 0){
            actions.erase(remove(actions.begin(), actions.end(), 'd'), actions.end()); // xoa 'd' trong actions
        } else if (x == N - 1){
            actions.erase(remove(actions.begin(), actions.end(), 'u'), actions.end()); // xoa 'u' trong actions
        }

        if (y == 0){
            actions.erase(remove(actions.begin(), actions.end(), 'r'), actions.end()); // xoa 'r' trong actions
        } else if (y == N - 1){
            actions.erase(remove(actions.begin(), actions.end(), 'l'), actions.end()); // xoa 'l' trong actions
        }
        return actions;
    }

    void do_action(char ac){
        history_actions.push_back(ac);
        if (ac == 'r'){
            swap(board[x][y], board[x][y-1]);
            y--;
        } else if (ac == 'l'){
            swap(board[x][y], board[x][y+1]);
            y++;
        } else if (ac == 'u'){
            swap(board[x][y], board[x+1][y]);
            x++;
        } else { // 'd'
            swap(board[x][y], board[x-1][y]);
            x--;
        }
    }

    string getString(){
        string s;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; ++j){
                s += to_string(board[i][j]);
            }
        }
        return s;
    }
};

int getH(State s,State goal){
    int h = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (s.board[i][j] != goal.board[i][j])
                h++;
        }
    }
    return h;
}

State taoStateCon(State s, char action){
    State stateCon = s; // tao copy
    stateCon.do_action(action); // perform action len state
    stateCon.g = s.g + 1;
    return stateCon;
}
void inset_to_queue(State& state, vector<State>& pending_states){
    int i = 0;
    for (i = 0; i < pending_states.size(); i++){
        if (pending_states[i].g + getH(pending_states[i], state) > state.g + getH(state, state))
            break;
    }
    pending_states.insert(pending_states.begin() + i, state);
}
bool found_in_memory(unordered_set<string>& memory, State& con){
    string s = con.getString();
    if (memory.find(s) == memory.end())
        return false;
    else
        return true;
}

void solve(Board start, Board goal){
    State startState = {2,2,start};
    vector<State> pending_states = {startState};

    while (pending_states.size() > 0){
        auto state = pending_states[0];
        if (state.board == goal){
            cout << "OK" << endl;
            for (auto a : state.history_actions)
                cout << a << endl;
            return;
        }
        vector<char> actions = state.getAction();
        unordered_set<string> memory;
        for (char action : actions){
            State stateCon = taoStateCon(state, action);
            if (found_in_memory(memory, stateCon))
                continue;
            pending_states.push_back(stateCon);
        }
        pending_states.erase(pending_states.begin());
    }
}

int main(int argc, char* argv[])
{
    Board start = {
        {1,2,3},
        {4,5,6},
        {7,8,0}
    };

    Board goal = {
        {1,2,3},
        {4,0,5},
        {7,8,6}
    };

    solve(start, goal);
    return 0;
}