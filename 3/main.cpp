#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
using namespace std;

int b_to_d(string binary)
{
    int decimal=0;
    int tmp=1;
    for(int i=binary.size()-1; i>=0; i--)
    {
        if(binary[i]=='1')
            decimal+=tmp;
        tmp*=2;
    }
    return decimal;
}

char decide(const vector<string>& input, int pos, bool option)
{
    int count0=0, count1=0;
    for(string i : input)
        if(i[pos]=='0')
            count0++;
        else
            count1++;
    if(option)
    {
        if(count0>count1)
            return '0';
        else
            return '1';
    }
    if (count0 <= count1)
        return '0';
    else
        return '1';
}

string Star2(vector<string> input, bool option) {
    char D;
    for (int i = 0;input.size()>1; i++)
    {
        D=decide(input, i, option);
        for (int j = input.size() - 1; j >= 0; j--)
            if (input[j][i] != D)
                input.erase(input.begin()+j);
    }
    return input[0];
}

int main() {
    ifstream is("input.txt");
    string line;
    string binary1, binary2;
    vector<string> input;
    while(getline(is,line))
        input.push_back(line);
    for(int j=0; j<12; j++)
        binary1 += decide(input, j, true);
    for(int j=0; j<12; j++)
        binary2 += decide(input, j, false);
    cout << "First star: " << b_to_d(binary1)*b_to_d(binary2) << endl;
    cout << "Second star: " << b_to_d(Star2(input, true))*b_to_d(Star2(input, false)) << endl;
    return 0;
}