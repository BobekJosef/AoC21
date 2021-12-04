#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

bool check(const bool board_b[25])
{
    for(int i=0; i<5; i++)//0-4,5-9,10-14,15-19,20-24
        if(board_b[i*5] && board_b[i*5+1] && board_b[i*5+2] && board_b[i*5+3] && board_b[i*5+4])
            return true;
    for(int i=0; i<5; i++)//(0,5,10,15,20), (1,6,11,16,21)...
        if(board_b[i] && board_b[1*5+i] && board_b[2*5+i] && board_b[3*5+i] && board_b[4*5+i])
            return true;
    return false;
}

int check_win(const vector<int>& win, const int board[25])
{
    bool board_b[25];
    for (bool & i : board_b) i=false;
    for(int i=0; i<win.size(); i++)
    {
        for(int j=0; j<25; j++)
            if(win[i]==board[j])
                board_b[j]=true;
        if(check(board_b))
            return i;
    }
    return win.size();
}

int Star(const vector<int> win, const int board[25], const int win_i)
{
    bool board_b[25];
    int sum=0;
    for (bool & i : board_b) i=false;
    for(int i=0; i<=win_i; i++)
        for(int j=0; j<25; j++)
            if(win[i]==board[j])
                board_b[j]=true;
    for(int i=0; i<25; i++)
        if(!board_b[i])
            sum+=board[i];
    return sum*win[win_i];
}

int main() {
    ifstream is("input.txt");
    string line;
    vector<int> win;
    int board[25], board_min[25], board_max[25];
    int min=1000, max=0, rounds;
    getline(is,line);
    stringstream ss(line);
    for (int i; ss >> i;)
    {
        win.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    for(int k=0; k<100; k++)
    {
        for(int & i : board)
            is>>i;
        rounds=check_win(win, board);
        if(rounds<min)
        {
            min=rounds;
            for(int i=0; i<25; i++)
                board_min[i]=board[i];
        }
        if(rounds>max)
        {
            max=rounds;
            for(int i=0; i<25; i++)
                board_max[i]=board[i];
        }
    }
    cout<<"First star: " << Star(win, board_min, min) << endl;
    cout<<"Second star: " << Star(win, board_max, max) << endl;
    return 0;
}
