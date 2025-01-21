class Solution {
public:
    #define ll long long

    ll check(vector<ll>adj[],vector<ll>&path,int n){
        unordered_set<ll>ss(path.begin(),path.end());
        ll answer=INT_MIN,m=path.size();
        for(ll i=0;i<m;i++){
            ll mayank=path[i],length=0;
            vector<bool>visited(n);
            visited[mayank]=true;

            queue<ll>q;q.push(mayank);
            while(!q.empty()){
                ll size=q.size();
                while(size--){
                    ll temp=q.front();q.pop();
                    for(ll &x:adj[temp]){
                        if(ss.find(x)!=ss.end() && visited[x]==false){
                            visited[x]=true;
                            q.push(x);
                        }
                    }
                }
                length++;
            }
            ll count=0;
            for(ll j=0;j<n;j++){
                if(visited[j]==true){
                    count++;
                }
            }
            if(count!=path.size()){
                return -1;
            }
            else{
                answer=max(answer,length-1);
            }
        }
        return answer;
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<ll>adj[n];
        vector<int>answer(n-1,0);

        for(auto &x:edges){
            adj[x[0]-1].push_back(x[1]-1);
            adj[x[1]-1].push_back(x[0]-1);
        }

        for(ll i=0;i<(1LL<<n);i++){
            vector<ll>path;
            for(ll j=0;j<n;j++){
                if(i&(1LL<<j)){
                    path.push_back(j);
                }
            }
            if(path.size()<=1){
                continue;
            }
            ll temp=check(adj,path,n);
            if(temp!=-1){
                answer[temp-1]++;
            }
        }

        return answer;
    }
};