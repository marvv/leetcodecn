class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        hash<string> hasher;
        set<size_t> hashset;
        set<string> resset;
        if (s.empty() || s.size() <10) return res;
        for (int i =0; i <= s.size()-10;i++) {
            string tmp = s.substr(i, 10);
            size_t hash = hasher(tmp);
            if (hashset.find(hash) == hashset.end()) {
                hashset.insert(hash);
            } else {
                resset.insert(tmp);
            }
        }
        
        
        for (auto i=resset.begin(); i!= resset.end();i++) {
            res.push_back(*i);
        }
        
        return res;
    }
};