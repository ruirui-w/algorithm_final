#include<bits/stdc++.h>
using namespace std;
double climbRecursive(double n)
{
  if (n < 3)    
  	return n;
  return climbRecursive(n - 1) + climbRecursive(n - 2);
}
int main()
{
   int n;
   cin>>n;
   cout<<climbRecursive(n);
   return 0;
}

