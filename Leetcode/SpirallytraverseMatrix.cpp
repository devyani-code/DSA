// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int top=0;
        int right=c-1;
        int bottom=r-1;
        int left=0;
        while(top<=bottom && right>=left){
            for(int j=left;j<=right;j++){
                cout<<matrix[top][j];
            }
            top++;
            for(int i=top;i<=bottom;i++){
                cout<<matrix[i][right];
            }
            right--;
            if(top<=bottom){
            for(int i=right;i>=left;i--){
                cout<<matrix[bottom][i];
            }
            bottom--;
            }
            if(right>=left){
            for(int i=bottom;i>=top;i--){
                cout<<matrix[i][left];
            }
            left--;
            }
        }

    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends