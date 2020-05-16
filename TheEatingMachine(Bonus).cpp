/*
I assume you have seen the [editorial](https://www.hackerrank.com/contests/algoeasy/challenges/theeatingmachine/editorial) 
of original problem TheEatingMachine.


Consider the array 1 2 -2 -1 3 -3 3 0, lets add zero to the beginning of array.
Original Array -----------------> 0 1 2 -2 -1 3 -3 3 0
Prefix Sum Array----------------> 0 1 3  1  0 3  0 3 3


- It can be see easily that if index i and j have same value in prefix sum array, then array extending from index i+1 to j in original array gives sum 0.
- We have 4 prefix sums with values 3,3 prefix sums with value 0 and 2 prefix sums with value 1.
- Consider 4 prefix sums with values 3, i.e at indices 2,5,7 and 8.Every pair of these indices gives us a subarray with sum zero.
- Like pair [2,5] gives subarray with end indices 3 to 5 i.e [-2 -1 3] in original array.
- Pair [2,8] gives us [-2 -1 3 -3 3 0] in original array.

- Hence if there are x indices with same prefix sum, then all the pairs formed from these indices give us a subarray of sum 0.
- Choosing 2(a pair) from x indices gives us xChoose2 or xC2 pairs or x*(x-1)/2 pairs.


-In short we can say for above example,

4 prefix sums with same value '3' ----> 4*(4-1)/2 pairs ---> 6 pairs.
3 prefix sums with same value '0' ----> 3*(3-1)/2 pairs ---> 3 pairs.
2 prefix sums with same value '1' ----> 2*(2-1)/2 pairs ---> 1 pair.

Answer = 6 + 3 + 1 = 10
*/
#include<iostream>
#include<algorithm> // for sorting 
const int maxn = 10000000 + 100;
using namespace std;

int a[maxn],pre[maxn],n;
int cnt=0;
long long int ans = 0;
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}
pre[0] = 0;
pre[1] = a[1];

for(int i=2;i<=n;i++)
{
    pre[i] = pre[i-1] + a[i];
}
sort(pre,pre+n+1); 
/*
Sorting so that we can accumulate all prefix sums of same value and counting will be easier. 
*/

int i=0;
while(i<n)
{
  int cnt = 1;
  while(pre[i] == pre[i+1] && i<n)
  { 
    cnt++;
    i++;
  }
  //we have cnt values of type a[i] 
  ans = ans + (cnt)*(cnt-1)/2;
  i++;
}
cout<<ans<<endl;
}



