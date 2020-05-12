/*
One thing we can do is iterate over the string and skip the Fibonacci positions.

Here isFibo[] is a boolean array which tells whether the number is a Fibonacci number or not. 

*/
#include<iostream>
const int maxn = 100000 + 100;
using namespace std;

bool isFibo[maxn];
void fillfibo()
{
    isFibo[0] = 1;
    isFibo[1] = 1;
    int f0=1,f1=1,temp;
    while(f1 < maxn)
    {
      isFibo[f1] = 1;
      temp = f1;
      f1 = f1 + f0;
      f0 = temp;
    }
}

int main()
{   string s;
    cin>>s;
    fillfibo();
    if(s.size()<4) { cout<<-1; return 0; }
    for(int i=0;i<s.size();i++)
    {   
        //letter at index i has position i+1, eg: letter at index 0 is 1st letter
        //if the letter at index i is not at Fibonacci position(i+1), print that letter
        if(!isFibo[i+1]){ cout<<s[i]; }
    }
}
