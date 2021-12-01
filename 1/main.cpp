#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
using namespace std;

int main() {
    ifstream is("input.txt");
    istream_iterator<int> start(is), end;
    vector<int> input(start, end);
    int result=0,A,B;
    int val = input[0];
    for(int i : input)
    {
        if(i>val)
            result++;
        val=i;
    }
    cout<<"First star:"<<result<<endl;
    result=0;
    for(int i=3; i<input.size(); i++)
    {
        A=input[i-3]+input[i-2]+input[i-1];
        B=input[i-2]+input[i-1]+input[i];
        if(B>A)
            result++;
    }
    cout<<"Second star:"<<result<<endl;
}

