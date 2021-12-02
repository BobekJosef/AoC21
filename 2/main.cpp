#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
using namespace std;

struct input_var
{
    string command;
    int value;
};

int main() {
    ifstream is("input.txt");
    vector<input_var> input;
    input_var tmp_input;
    string line;
    int depth=0, forward=0, aim=0;
    string tmp="";
    int q=0;
    while(getline(is,line))
    {
        while(line[q] != ' ')
        {
            tmp+=line[q];
            q++;
        }
        tmp_input.command=tmp;
        q++;
        tmp="";

        tmp_input.value = stoi(line.substr(q));
        input.push_back(tmp_input);
        q=0;
    }

    for(input_var i : input)
    {
        if(i.command=="down")
            depth+=i.value;
        if(i.command=="up")
            depth-=i.value;
        if(i.command=="forward")
            forward+=i.value;
    }
    cout<<"First star:"<<forward*depth<<endl;
    forward=0;
    depth=0;
    for(input_var i : input)
    {
        if(i.command=="down")
            aim+=i.value;
        if(i.command=="up")
            aim-=i.value;
        if(i.command=="forward")
        {
            forward+=i.value;
            depth+=aim*i.value;
        }
    }
    cout<<"Second star:"<<forward*depth<<endl;

    return 0;
}
