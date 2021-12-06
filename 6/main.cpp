#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

unsigned long long int Star(int days, unsigned long long int timer[9])
{
    unsigned long long int tmp;
    for(int day=0; day<days; day++)
    {
        tmp=timer[0];
        for(int i=0; i<8; i++)
            timer[i]=timer[i+1];
        timer[8]=tmp;
        timer[6]+=tmp;
    }
    tmp=0;
    for(int i=0; i<9; i++)
        tmp+=timer[i];
    return tmp;
}

int main() {
    ifstream is("input.txt");
    string line;
    getline(is,line);
    stringstream ss(line);
    unsigned long long int timer[9];
    for(unsigned long long int &i : timer)
        i=0;
    for (int i; ss >> i;)
    {
        timer[i]++;
        if (ss.peek() == ',')
            ss.ignore();
    }
    cout<<"First star: "<<Star(80, timer)<<endl;
    cout<<"Second star: "<<Star(256-80, timer)<<endl;

    return 0;
}
