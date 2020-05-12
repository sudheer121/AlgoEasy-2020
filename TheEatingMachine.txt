/*
We can generate all subarrays of an array using a O(N*N) loop.
Before we do that, one thing to observe is how the values change when we take prefix sums.
Prefix sum in an array at index i is sum of all numbers till index i.
Example:
Array             : 1 2 3  4  5
Prefix Sum Array  : 1 3 6 10 15

Array --------------> 1 3 2 4
Prefix Sum  --------> 1 4 6 10 

Now, lets look at an array with subarrays that have zero sum 

Array : 1 2 -2 -1 3 -3---------->(Here we can see 4 arrays with zero sum,one of which is the whole array).
Now, lets look at Prefix Sum Array.

Original Array -----------------> 1 2 -2 -1 3 -3
Prefix Sum Array----------------> 1 3  1  0 3  0 

Thing to observe : If a subarray from index i to j from original array has zero sum then the numbers at index i-1 and j in
prefix sum array will have duplicates. 
But if i is 0,then i-1 will be -1,so lets add 0 in the beginnning of Original Array

Original Array -----------------> 0 1 2 -2 -1 3 -3
Prefix Sum Array----------------> 0 1 3  1  0 3  0 
In Prefix Sum Array we have duplicates at index 0 and 4, means subarray from index 1 to 4 in original array has sum 0.
In Prefix Sum Array we have duplicates at index 0 and 6, means subarray from index 1 to 6 in original array has sum 0.
In Prefix Sum Array we have duplicates at index 1 and 3, means subarray from index 2 to 3 in original array has sum 0.
In Prefix Sum Array we have duplicates at index 2 and 5, means subarray from index 3 to 5 in original array has sum 0.
In Prefix Sum Array we have duplicates at index 4 and 6, means subarray from index 5 to 6 in original array has sum 0.

Remember we added 0 in the beginning, so all our indices are shifted by one to the right, hence we have to decrease all by 1 in 
the answer. 
 
*/

#include<bits/stdc++.h>
const int maxn = 100000 + 100;
using namespace std;

// Storing prefix sums in pre[] array.
int a[maxn],pre[maxn],n;
int l[maxn],r[maxn]; //we will store the answer in these arrays, the l values in l and r values in r.
int cnt=0;
int main()
{ 
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}//taking input array from index one, will compensate this by subtracting l and r values each by 1 in the end.

//storing prefix sums in array pre
pre[0] = 0;
pre[1] = a[1];
for(int i=2;i<=n;i++)
{
    pre[i] = pre[i-1] + a[i];
}

// if pre[i-1] and pre[j] have same value then the subarray starting from i and ending at j must have the sum 0.
// we can find all pairs of i and j using O(n*n)loop.
for(int i=1;i<=n;i++)
{
    for(int j=i;j<=n;j++)
    {
        if(pre[j] == pre[i-1])
        {   //storing the l and r values
            l[cnt] = i;
            r[cnt] = j;
            cnt++;
        }
    }
}
cout<<cnt<<endl;
for(int i=0;i<cnt;i++)
{
    cout<<l[i]-1<<" "<<r[i]-1<<endl;
}

return 0;
}
