#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <tuple>
using namespace std;

typedef vector<tuple<int, int, int, int> > input_t;

int Star1(const input_t& input)
{
    bool floor[1000][1000];
    for(auto & i : floor)
        for(bool & j : i)
            j=false;
    bool overlap[1000][1000];
    for(auto & i : overlap)
        for(bool & j : i)
            j=false;
    int result=0;

    for(auto [i,j,k,l] : input)
        if (i == k)
        {
            if (j < l)
                for (int q = j; q <= l; q++)
                {
                    if (floor[i][q])
                        overlap[i][q] = true;
                    floor[i][q] = true;
                }
            if (l < j)
                for (int q = l; q <= j; q++)
                {
                    if (floor[i][q])
                        overlap[i][q] = true;
                    floor[i][q] = true;
                }
        }
        else if (j == l)
        {
            if (i < k)
                for (int q = i; q <= k; q++)
                {
                    if (floor[q][j])
                        overlap[q][j] = true;
                    floor[q][j] = true;
                }
            if (k < i)
                for (int q = k; q <= i; q++)
                {
                    if (floor[q][j])
                        overlap[q][j] = true;
                    floor[q][j] = true;
                }
        }
    for(auto & i : overlap)
        for(bool j : i)
            result+=j;
    return result;
}

int Star2(const input_t& input)
{
    bool floor[1000][1000];
    for(auto & i : floor)
        for(bool & j : i)
            j=false;
    bool overlap[1000][1000];
    for(auto & i : overlap)
        for(bool & j : i)
            j=false;
    int result=0;

    for(auto [i,j,k,l] : input)
        if (i == k)
        {
            if (j < l)
                for (int q = j; q <= l; q++)
                {
                    if (floor[i][q])
                        overlap[i][q] = true;
                    floor[i][q] = true;
                }
            if (l < j)
                for (int q = l; q <= j; q++)
                {
                    if (floor[i][q])
                        overlap[i][q] = true;
                    floor[i][q] = true;
                }
        }
        else if (j == l)
        {
            if (i < k)
                for (int q = i; q <= k; q++)
                {
                    if (floor[q][j])
                        overlap[q][j] = true;
                    floor[q][j] = true;
                }
            if (k < i)
                for (int q = k; q <= i; q++)
                {
                    if (floor[q][j])
                        overlap[q][j] = true;
                    floor[q][j] = true;
                }
        }
        else if((i-k) == (j-l))
        {
            if(i < k)
                for(int q=0; q<=k-i; q++)
                {
                    if (floor[i+q][j+q])
                        overlap[i+q][j+q] = true;
                    floor[i+q][j+q] = true;
                }
            if(k < i)
                for(int q=0; q<=i-k; q++)
                {
                    if (floor[i-q][j-q])
                        overlap[i-q][j-q] = true;
                    floor[i-q][j-q] = true;
                }
        }
        else if((i-k) == (l-j))
        {
            if(i < k)
                for(int q=0; q<=k-i; q++)
                {
                    if (floor[i+q][j-q])
                        overlap[i+q][j-q] = true;
                    floor[i+q][j-q] = true;
                }
            if(k < i)
                for(int q=0; q<=i-k; q++)
                {
                    if (floor[i-q][j+q])
                        overlap[i-q][j+q] = true;
                    floor[i-q][j+q] = true;
                }
        }
    for(auto & i : overlap)
        for(bool j : i)
            result+=j;
    return result;
}

int main()
{
    ifstream is("input.txt");
    input_t input;
    string line;
    int index;
    int in[4];
    while(getline(is,line))
    {
        stringstream ss(line);
        index=0;
        for (int i; ss >> i; index++)
        {
            in[index]=i;
            if (ss.peek() == ',')
                ss.ignore();
        }
        input.push_back(tuple<int, int, int, int>(in[0], in[1], in[2], in[3]));
    }
    cout<<"First star:" << Star1(input) << endl;
    cout<<"Second star:" << Star2(input) << endl;
    return 0;
}
