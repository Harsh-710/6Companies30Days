class ThroneInheritance {
public:
    unordered_map<string,vector<string>>mp;
    unordered_set<string>dead;
    string king;
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    void dfs(string s, vector<string>& res)
    {
        if(dead.find(s)==dead.end()) res.push_back(s);
        for(auto x:mp[s])
            dfs(x,res);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string>res;
        dfs(king,res);
        return res;
    }
};