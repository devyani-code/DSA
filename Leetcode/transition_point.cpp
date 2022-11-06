// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code here
    int l=0;
    int h=n-1;
    while(h-l>0){
        int mid = (h+l)/2;
        if(arr[mid]==0 && arr[mid+1]==0){
            l=mid+1;
        }
        else{
            h=mid;
        }
    }
    if(arr[l]==0 && arr[l+1]==1){
        return l+1;
    }
    else if(arr[l]==1 && arr[l-1]==0){
        return l;
    }
    else if(arr[h]==0 && arr[h+1]==1){
        return h+1;
    }
    else if(arr[h]==1 && arr[h-1]==0){
        return h;
    }
    else{
        return -1;
    }
    
}