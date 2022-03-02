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
        cout << binaryNum[j];
    cout<<"\n";
}
 

int max_sequence(int n){
    decToBinary(n);
    int max_count = 0;
    int count= 0;
    while(n > 0){
        if(n&1)
            count++;
        else 
            count = 0;
        max_count = max(max_count,count);
        n = n >> 1;
    }
    return max_count;
}


int solve(int n){
    int currentLength = 0;
    int previousLength = 0;
    int maximum = 1;
    while(n!=0){
        if(n&1 == 1){ //current bit is 1
            currentLength++;
        }else{   //current bit is 0
            previousLength = (n&2) == 0 ? 0 : currentLength;
            currentLength = 0; 
        }
        maximum = max(currentLength+previousLength+1,maximum); 
        n = n >> 1; 
    }
    return maximum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<"Answer by optimal method: ";
    cout<<solve(n)<<"\n";
    int temp = n;
    int count = 0;
    int maximum = -1;
    while(temp > 0){
        if(!(temp & 1)){
            cout<<"Found a zero \n";
            int t = max_sequence(n^(1<<count));
            cout<<t<<"\n";
            maximum = t > maximum ? t : maximum;
        }
        temp = temp >> 1;
        count++;
    }
    cout<<maximum;
    return 0;
}