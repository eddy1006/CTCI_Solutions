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