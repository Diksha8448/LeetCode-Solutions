
#include<bits/stdc++>
int editDistanceHelper(string s1,string s2,int **a){
    int m=s1.size(), n=s2.size();
    if(m<=0 || n<=0){
        return max(n,m);
    }
    if(a[m][n]!=-1){
        return a[m][n];
    }
    else{
        if(s1[0]==s2[0]){
            int x=editDistanceHelper(s1.substr(1),s2.substr(1),a);
            a[m-1][n-1]=x;
            a[m][n]=x;
        }
        else{
            a[m][n-1]=editDistanceHelper(s1,s2.substr(1),a);
            a[m-1][n-1]=editDistanceHelper(s1.substr(1),s2.substr(1),a);
            a[m][n]=min(a[m][n-1],min(a[m-1][n-1],a[m-1][n])+1;)
        }
    }
    return a[m][n];
}
int editDistance(string s1,string s2){
    int m=s1.size()+1,n=s2.size()+1;
    int **ans=new int*[m];
    for(int i=0;i<m;i++){
        ans[i]=new int[n];
        for(int j=0;j<n;j++){
            ans[i][j]=-1;
        }
    }
    return editDistanceHelper(s1,s2,ans);
}