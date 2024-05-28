#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited; // To keep track of visited rooms
        stack<int> toVisit; // Stack for DFS
        toVisit.push(0); // Start from room 0
        
        while (!toVisit.empty()) {
            int current = toVisit.top();
            toVisit.pop();
            
            if (visited.find(current) == visited.end()) {
                visited.insert(current);
                
                for (int key : rooms[current]) {
                    if (visited.find(key) == visited.end()) {
                        toVisit.push(key);
                    }
                }
            }
        }
        
        return visited.size() == rooms.size();
    }
};
