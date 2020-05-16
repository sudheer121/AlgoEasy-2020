/*
So here we need to do 2 things,
Task 1 --> Find all factors of a number 
Task 2 --> Separate out the prime and composite factors.

How to do task 1 ? 

Basically iterate from 1 to sqrt(n).
If a number i between 1 and sqrt(n) divides n, then we have two factors i and n/i. 
The first one i.e i, is less than sqrt(n) and second one i.e, n/i is more than sqrt(n).
In this way we get all factors in sqrt(n) time. 

*Pseudocode below*
int allfactorsarray[]; 
for(int i=1;i<=sqrt(n);i++)
{
    if(i%n==0)
    {
        factor_1 = i;
        factor_2 = n/i;
    }
    //now just add factor_1 and factor_2 to allfactorsarray[] 
}
So we get all factors of a number in O(sqrt(n)) time this way.


Example:
n = 60.
sqrt(60) = 7.

Iterate from 1 to 7. 
Factors are in pairs.

1 and 60/1 ---> 1 and 60
2 and 60/2 ---> 2 and 30
3 and 60/3 ---> 3 and 20
4 and 60/4 ---> 4 and 15
5 and 60/5 ---> 5 and 12
6 and 60/6 ---> 6 and 10
7 Doesn't divide 60.

Hence we can see we get 12 factors.
**Precaution** : For a perfect square number the last factor pair will have same factors,take care you don't add same factors twice.
Task 1 complete

How to do task 2 ?
We need to separate out prime and composite factors.One thing for sure is 1 is neither prime nor composite,so discard 1.
We need a fast way to know if a number is prime, the fastest way is using an algorithm called Sieve of Eratosthenes.


Below are the resources for the algorithm.
https://www.youtube.com/watch?v=Xxu95iiVcPI&t=141s
https://www.geeksforgeeks.org/sieve-of-eratosthenes/
https://www.youtube.com/watch?v=eKp56OLhoQs

In short we can create a boolean array of size n, name it isprime[] which tells if a number is prime or not.
If isprime[x] = 1, then x is prime.
Sieve of Eratosthenes helps us fill that isprime[]  array with information.


*/
#include<iostream>
#include<math.h> 
using namespace std;
#define ll long long

const int maxn = 1e7 + 10;
ll n;
bool isprime[maxn];
void sieve()//Sieve of Eratosthenes
{
  for(int i=2;i<maxn;i++){ isprime[i] = 1 ; }
  for(ll i=2;i*i<maxn;i++)
  {
      for(ll j=i*i;j<maxn;j+=i)
      {
      isprime[j] = 0;
      }
  }
}
void factorize(ll n) // Task 1 done here.
{
ll x = sqrtl(n);
ll p=0,c=0; //p stores sum of all prime factors, c stores sum of all composite factors.

if(isprime[n]){ p+=n; }
else {c+=n;}

for(int i=2;i<=x;i++)
{
if(n%i==0)
{
if(isprime[i]){ p+=i; } else {c+=i;}
if(isprime[n/i]){ p+=n/i; } else {c+=n/i;}
}
}

if(x*x == n) //removing duplicates if number is perfect square
{
if(isprime[x]) { p-=x; }
else { c-=x; }
}

cout<<p*c<<endl;
}
int main()
{ 
  sieve();
  int t;cin>>t;
  while(t--)
  {
  cin>>n;
  factorize(n);
  }
  return 0;
}
 
