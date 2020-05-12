/*
All numbers can be converted into their corresponding representations in any base 
using the same principle when we convert a number into binary.

Making a function called representation() which takes a number and the base it has to be
converted into, the process is similar to what we do to convert decimal to binary.

Rest of the code is implementation. 
*/
#include<bits/stdc++.h>
const int maxn = 100000 + 100;
using namespace std;

string nums[10] = { "0","1","2","3","4","5","6","7","8","9"};
string representation(int num,int base)
{   string rep = "";
    if(num==0){ rep = "0" ; }
    while(num!=0)
    {
    int x = num%base;
    rep = nums[x] + rep;
    //since x is an integer, converting it into a string using nums array
    num = num / base;
    }
    return rep;
}

int main()
{   string s;
    cin>>s;int base=1;
    for(int i=0;i<s.size();i+=2)
    {   base++;
        
        /* Taking the numbers at index i and i+1,and converting them into original number since they are characters */
        int num = (s[i]-'0')*10 + (s[i+1]-'0');

        cout<<representation(num,base);
    }
    return 0;
}
