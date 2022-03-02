#include <bits/stdc++.h>
using namespace std;

int max_sequence(int n){
    int count= 0;
    while(n > 0){
        if(n&1)
            count++;
        else 
            count = 0;
        n = n >> 1;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int temp = n;
    int count = 0;
    int maximum = -1;
    while(temp > 0){
        if(!(temp & 1)){
            cout<<"Found a zero \n";
            int t = max_sequence(n^(1<<count));
            maximum = t > maximum ? t : maximum;
        }
        temp = temp >> 1;
        count++;
    }
    cout<<maximum;
    return 0;
}