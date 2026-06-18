```cpp
/*
====================================================================
LeetCode 373. Find K Pairs with Smallest Sums
Link:
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

Difficulty: Medium

Topics:
Heap (Priority Queue), BFS-like Expansion, Arrays

====================================================================
Problem Statement
====================================================================

Given two sorted arrays nums1 and nums2 and an integer k.

Return the k pairs (u, v) such that:

u belongs to nums1
v belongs to nums2

and the pair sums are the smallest possible.

====================================================================
Example
====================================================================

Input:
nums1 = [1,7,11]
nums2 = [2,4,6]
k = 3

All Pairs:

(1,2) = 3
(1,4) = 5
(1,6) = 7
(7,2) = 9
(7,4) = 11
(7,6) = 13
(11,2)= 13
(11,4)= 15
(11,6)= 17

Smallest 3:

[[1,2],[1,4],[1,6]]

====================================================================
Intuition
====================================================================

Since both arrays are sorted:

For a fixed i:

nums1[i] + nums2[0]
nums1[i] + nums2[1]
nums1[i] + nums2[2]

will also be sorted.

Instead of generating all m*n pairs,
we generate only the necessary pairs using
a Min Heap.

Treat matrix:

           nums2
        2   4   6

1       3   5   7
7       9  11  13
11     13  15  17

Start from (0,0).

Whenever a cell is popped,
explore:

(i, j+1)
(i+1, j)

This guarantees smallest sums are processed first.

====================================================================
Approach
====================================================================

Use:

Min Heap:
(sum, {i, j})

Visited Set:
to avoid duplicate insertions.

Steps:

1. Insert (0,0)

2. While heap not empty and k > 0

      Pop smallest pair

      Store answer

      Push right neighbor:
      (i, j+1)

      Push bottom neighbor:
      (i+1, j)

3. Return result

====================================================================
Dry Run
====================================================================

nums1 = [1,7,11]
nums2 = [2,4,6]
k = 3

Heap:
(3,{0,0})

--------------------------------

Pop:

(1,2)

Answer:
[[1,2]]

Push:

(1,4)
(7,2)

Heap:

5
9

--------------------------------

Pop:

(1,4)

Answer:

[[1,2],[1,4]]

Push:

(1,6)

Heap:

7
9

--------------------------------

Pop:

(1,6)

Answer:

[[1,2],[1,4],[1,6]]

k reached

Return answer

====================================================================
Edge Cases
====================================================================

1. Empty Arrays

nums1 = []
nums2 = []

Output:
[]

------------------------------------------------

2. k = 0

Output:
[]

------------------------------------------------

3. Single Element Arrays

nums1 = [1]
nums2 = [2]
k = 1

Output:
[[1,2]]

------------------------------------------------

4. k > total pairs

nums1 = [1,2]
nums2 = [3]

k = 10

Only 2 pairs exist.

Return all pairs.

------------------------------------------------

5. Duplicate Values

nums1 = [1,1,2]
nums2 = [1,2,3]

Works correctly.

====================================================================
Complexity Analysis
====================================================================

Let:

m = nums1.size()
n = nums2.size()

At most k states are processed.

Time Complexity:

O(k log k)

Heap operations dominate.

Space Complexity:

O(k)

Heap + Visited Set

====================================================================
Accepted Solution
====================================================================
*/

class Solution {
public:

    vector<vector<int>> kSmallestPairs(
        vector<int>& nums1,
        vector<int>& nums2,
        int k
    ) {

        vector<vector<int>> result;

        int m = nums1.size();
        int n = nums2.size();

        if (m == 0 || n == 0 || k == 0)
            return result;

        typedef pair<int, pair<int,int>> Node;

        priority_queue<
            Node,
            vector<Node>,
            greater<Node>
        > pq;

        set<pair<int,int>> visited;

        pq.push({nums1[0] + nums2[0], {0,0}});
        visited.insert({0,0});

        while (!pq.empty() && k--) {

            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            result.push_back(
                {nums1[i], nums2[j]}
            );

            // Right neighbour
            if (j + 1 < n &&
                visited.find({i, j + 1}) == visited.end()) {

                pq.push({
                    nums1[i] + nums2[j + 1],
                    {i, j + 1}
                });

                visited.insert({i, j + 1});
            }

            // Down neighbour
            if (i + 1 < m &&
                visited.find({i + 1, j}) == visited.end()) {

                pq.push({
                    nums1[i + 1] + nums2[j],
                    {i + 1, j}
                });

                visited.insert({i + 1, j});
            }
        }

        return result;
    }
};
```
