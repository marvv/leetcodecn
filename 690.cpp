/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int calc(map<int, Employee*>&mp,int id) {
        int score = 0;
        if (mp.find(id) != mp.end()) {
            Employee* p = mp[id];
            score = p->importance;
            for (int i=0;i<p->subordinates.size(); i++) {
                score += calc(mp, p->subordinates[i]);
            }
        }
        return score;
    }
    int getImportance(vector<Employee*> employees, int id) {
        map<int ,Employee*> mp;
        for (int i=0; i<employees.size(); i++) {
            int id = employees[i]->id;
            mp[id] = employees[i];
        }
        
        return calc(mp, id);
    }
};