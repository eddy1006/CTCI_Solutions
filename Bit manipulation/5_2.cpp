/*------------------------- Question ---------------------------
Binary to String: Given a real number between O and 1 (e.g., 0.72) that is passed in as a double, print 
the binary representation. If the number cannot be represented accurately in binary with at most 32 
characters, print  "ERROR:' 
------------------------------------------------------------------*/


#include <bits/stdc++.h>
using namespace std;

void solve(){
    double num;
    cin>>num;
    string s=".";
    int count = 0;
    while(count<32 && num!=0.0){
        count++;
        num = num*2;
        if(num >= 1){
            s = s+"1";
            num = num -1;
        }else{
            s = s+"0";
        }
    }
    if(count==32 && num!=0){
        cout<<"ERROR";
    }else{
        cout<<s;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}