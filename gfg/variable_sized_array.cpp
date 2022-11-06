#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q;
    cin>>n;
    cin>>q;
    int*arr[n];
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
    
        int next_arr[l];
        
        for(int j=0;j<l;j++){
            cin>>next_arr[j];
        }
        
        arr[i]=next_arr;
    }

    for(int p=0;p<q;p++){
          int i,j;
          cin>>i;
          cin>>j;
          cout<<(*(arr[i]+j)) << " ";
        
     }
    return 0;
}
