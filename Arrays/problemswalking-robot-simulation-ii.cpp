/*
    🔗 Problem Link:
    https://leetcode.com/problems/walking-robot-simulation-ii/

    🧠 Approach:
    - Precompute all perimeter positions of the grid.
    - Store (x, y, direction) for each boundary cell.
    - Use modulo to simulate circular movement.
    - Handle special edge case for (0,0) after movement → "South".

    ⏱ Time Complexity:
    - Constructor: O(perimeter)
    - step(): O(1)
    - getPos(): O(1)
    - getDir(): O(1)

    📦 Space Complexity:
    - O(perimeter)
*/

#include <bits/stdc++.h>
using namespace std;

class Robot {
public:
    int idx = 0;
    bool moved = false;

    // Stores {x, y, direction}
    // direction: 0=East, 1=North, 2=West, 3=South
    vector<vector<int>> pos;

    Robot(int width, int height) {

        // Bottom row (left → right)
        for(int x = 0; x < width; x++) {
            pos.push_back({x, 0, 0}); // East
        }

        // Right column (bottom → top)
        for(int y = 1; y < height; y++) {
            pos.push_back({width - 1, y, 1}); // North
        }

        // Top row (right → left)
        for(int x = width - 2; x >= 0; x--) {
            pos.push_back({x, height - 1, 2}); // West
        }

        // Left column (top → bottom)
        for(int y = height - 2; y > 0; y--) {
            pos.push_back({0, y, 3}); // South
        }
    }

    void step(int num) {
        moved = true;
        idx = (idx + num) % pos.size();
    }

    vector<int> getPos() {
        return {pos[idx][0], pos[idx][1]};
    }

    string getDir() {
        if(!moved)
            return "East";

        // 🔥 Important edge case
        if(idx == 0)
            return "South";

        int d = pos[idx][2];

        if(d == 0) return "East";
        else if(d == 1) return "North";
        else if(d == 2) return "West";
        return "South";
    }
};


/*
    🧪 Example Usage:

    int main() {
        Robot* obj = new Robot(8, 2);

        obj->step(17);
        vector<int> pos1 = obj->getPos();
        cout << pos1[0] << "," << pos1[1] << endl;
        cout << obj->getDir() << endl;

        return 0;
    }
*/
