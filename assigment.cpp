// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

vector<int> v[100001];

void dfs(int x,vector<int>&vis)
{
    vis[x]=1;
    for(auto child:v[x])
    {
        if(!vis[child])
        {
            dfs(child,vis);
        }
    }
}
int solve(int n,vector<vector<int>>c)
{
    int cables=c.size();
    if(cables<n-1)
    {
        return -1;
    }
    for(auto ed:c)
    {
        v[ed[0]].push_back(ed[1]);
        v[ed[1]].push_back(ed[0]);
    }
    int cnt=0;
    vector<int>vis(n,0);
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            dfs(i,vis);
            cnt++;
        }
    }
    int ans=cnt-1;
    return ans;
    
}

int main() {
    // Write C++ code here
    
    
    int n;
    vector<vector<int>>c(3);
    cin>>n;
    
    for(int i=0;i<3;i++){
        int a;
        int b;
        cin>>a>>b;
        c[i].push_back(a);
        c[i].push_back(b);
        cout<<endl;
    }
int ans=solve(n,c);
cout<<ans;
    return 0;
}



