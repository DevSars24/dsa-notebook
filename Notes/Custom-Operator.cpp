/*
========================================================
        CUSTOM COMPARATOR / CUSTOM OPERATOR NOTES
========================================================

🔹 WHY CUSTOM COMPARATOR?
-----------------------------------------
Default priority_queue:
- MAX HEAP hota hai
- pair mein sirf "first" element compare karta hai
- complex rules handle nahi kar sakta

Isliye jab problem bole:
- frequency ke basis pe sort
- distance ke basis pe
- 2-level ordering (tie-breaker)
- lexicographical order

👉 CUSTOM COMPARATOR LAGANA PADTA HAI


========================================================
        IMPORTANT RULE (INTERVIEW GOLD)
========================================================

priority_queue comparator mein:

    return true  → a has LOWER priority than b
    return false → a has HIGHER priority than b

⚠️ Ye sorting jaisa nahi hota
⚠️ Ye sirf priority decide karta hai


========================================================
        GENERIC COMPARATOR TEMPLATE
========================================================

pair<X, Y> a, b

auto cmp = [](const pair<X,Y>& a, const pair<X,Y>& b) {

    // Rule 1 (Primary condition)
    if (a.Y == b.Y) {
        // tie-breaker condition
        return a.X > b.X;
    }

    // Rule 2 (Secondary condition)
    return a.Y < b.Y;
};


========================================================
        EXAMPLE 1: Top K Frequent Words
========================================================

Rules:
1) Higher frequency first
2) Same frequency → lexicographically smaller word first

pair<string, int> → (word, frequency)

Comparator:

auto cmp = [](const pair<string,int>& a,
              const pair<string,int>& b) {

    if (a.second == b.second)
        return a.first > b.first;   // lexicographically smaller first

    return a.second < b.second;     // higher frequency first
};


========================================================
        EXAMPLE 2: Top K Frequent Elements (Numbers)
========================================================

pair<int, int> → (element, frequency)

Only frequency matters

auto cmp = [](const pair<int,int>& a,
              const pair<int,int>& b) {
    return a.second < b.second;   // max frequency on top
};


========================================================
        EXAMPLE 3: K Closest Points to Origin
========================================================

pair<int, vector<int>> → (distance, point)

Smaller distance first

auto cmp = [](const pair<int,vector<int>>& a,
              const pair<int,vector<int>>& b) {
    return a.first > b.first;     // min distance priority
};


========================================================
        EXAMPLE 4: Sort Characters By Frequency
========================================================

pair<char, int> → (character, frequency)

Higher frequency first

auto cmp = [](const pair<char,int>& a,
              const pair<char,int>& b) {
    return a.second < b.second;
};


========================================================
        priority_queue SYNTAX WITH CUSTOM COMPARATOR
========================================================

priority_queue<
    pair<T1, T2>,                 // data type
    vector<pair<T1, T2>>,          // container
    decltype(cmp)                  // comparator type
> pq(cmp);


========================================================
        QUESTIONS WHERE CUSTOM COMPARATOR IS USED
========================================================

1️⃣ Top K Frequent Elements          (LC 347)
2️⃣ Top K Frequent Words             (LC 692)
3️⃣ K Closest Points to Origin       (LC 973)
4️⃣ Sort Characters By Frequency     (LC 451)
5️⃣ Kth Largest / Smallest (Custom)
6️⃣ Merge K Sorted Lists (Heap)
7️⃣ Reorganize String
8️⃣ Task Scheduler
9️⃣ Huffman Encoding
🔟 Meeting Rooms / Intervals (advanced)


========================================================
        COMMON MISTAKES (VERY IMPORTANT)
========================================================

❌ Using default priority_queue for complex rules
❌ Confusing sort comparator with heap comparator
❌ Writing pair<int,string> but pushing {string,int}
❌ Forgetting lexicographical condition
❌ Wrong return true / false logic


========================================================
        ONE-LINE INTERVIEW REMEMBER RULE
========================================================

"Heap comparator decides PRIORITY, not ORDER"

========================================================
*/
