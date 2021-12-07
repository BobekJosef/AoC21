#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int Star1(const vector<int>& input, int max)
{
    int fuel[max];
    for(int &i : fuel)
        i=0;
    int min_fuel=100000000;

    for(int i=0; i<max; i++)
        for(int j : input)
            fuel[i]+=abs(j-i);
    for(int i : fuel)
        if(i<min_fuel)
            min_fuel=i;
    return min_fuel;
}

int Star2(const vector<int>& input, int max)
{
    int fuel[max];
    for(int &i : fuel)
        i=0;
    int min_fuel=100000000;
    int tmp=0;

    for(int i=0; i<max; i++)
        for(int j : input)
        {
            for(int k=1; k<=abs(j-i); k++)
                tmp+=k;
            fuel[i]+=tmp;
            tmp=0;
        }

    for(int i : fuel)
        if(i<min_fuel)
            min_fuel=i;
    return min_fuel;
}

int main(){
    ifstream is("input.txt");
    string line;
    getline(is,line);
    stringstream ss(line);
    vector<int> input;
    int max=0;
    for (int i; ss >> i;)
    {
        input.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    for(int i: input)
        if(i>max)
            max=i;
    cout<<input.size()<<endl;
    cout<<"First star:"<<Star1(input, max)<<endl;
    cout<<"Second star:"<<Star2(input, max)<<endl;
    return 0;
}
