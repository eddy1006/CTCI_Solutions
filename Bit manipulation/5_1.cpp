/*--------------------- Question ----------------------------------------------------
Insertion: You are given two 32-bit numbers, N and M, and two bit positions, i and 
j. Write a method to insert M into N such that M starts at bit j and ends at bit i. You
can assume that the bits j through i have enough space to fit all of M. That is, if
M = 10011, you can assume that there are at least 5 bits between j and i. You would not, for
example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.
EXAMPLE 
Input: N 10000000000, M 
Output: N = 10001001100 
-------------------------------------------------------------------------------------*/



#include <bits/stdc++.h>
using namespace std;

void decToBinary(int n)
    {
        // array to store binary number
        int binaryNum[32];
 
        // counter for binary array
        int i = 0;
        while (n > 0) {
            // storing remainder in binary array
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }
 
        // printing binary array in reverse order
        for (int j = i - 1; j >= 0; j--)
            cout<<(binaryNum[j]);
        cout<<"\n";
    }

void solve(){
    int n,m,i,j;
    cout<<"Enter two integers\n";
    cin>>n>>m;
    cout<<"Enter the bit positions\n";
    cin>>i>>j;
    decToBinary(n);
    decToBinary(m);
    // for(int k=i;k<=j;k++){
    //     int mask = ~(1<<k);
    //     n = n&mask;
    // }
    // decToBinary(n);
    // m = m << i;
    // decToBinary(n|m);
    //or
    int mask1 = ~((1<<(j+1)) - 1);
    int start = n & mask1;
    int mask2 = (1<<i) -1;
    int end = n& mask2;
    m = m << i;
    decToBinary(start);
    decToBinary(m);
    decToBinary(end);
    int  ans = start|m|end;
    decToBinary(ans);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}