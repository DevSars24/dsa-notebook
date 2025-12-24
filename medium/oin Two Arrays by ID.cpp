// =====================================================
// LeetCode 2722 : Join Two Arrays by ID
// Language : C++
// =====================================================
//
// INTUITION:
// ----------
// We have two arrays of objects. Each object has a unique `id`.
// If same id appears in both arrays, we MERGE them.
// - Same key  -> arr2 value overrides arr1
// - Extra key -> should NOT be lost
// Result must be sorted by id.
//
// We show TWO approaches:
// 1) HashMap (preferred)
// 2) Two Pointer
//
// =====================================================

#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// Object structure
// -----------------------------------------------------
struct Obj {
    int id;
    map<string, int> fields;
};

// =====================================================
// APPROACH 1 : HASHMAP (PREFERRED)
// =====================================================
//
// WHY HASHMAP?
// ------------
// - Arrays may not be sorted
// - Easy merging
// - No key loss
// - Cleaner logic
//
vector<Obj> joinUsingHashMap(vector<Obj>& arr1, vector<Obj>& arr2) {

    unordered_map<int, Obj> mp;

    // STEP 1: Insert all objects from arr1
    for (auto &obj : arr1) {
        mp[obj.id] = obj;
    }

    // STEP 2: Merge arr2 objects
    for (auto &obj : arr2) {
        int id = obj.id;

        // override only the keys present in arr2
        for (auto &kv : obj.fields) {
            mp[id].fields[kv.first] = kv.second;
        }
    }

    // STEP 3: Convert map to vector
    vector<Obj> result;
    for (auto &it : mp) {
        result.push_back(it.second);
    }

    // STEP 4: Sort by id
    sort(result.begin(), result.end(),
         [](const Obj &a, const Obj &b) {
             return a.id < b.id;
         });

    return result;
}

// =====================================================
// APPROACH 2 : TWO POINTER
// =====================================================
//
// WHEN TO USE?
// ------------
// - Only when arrays are already sorted by id
// - Otherwise sorting is required
//
vector<Obj> joinUsingTwoPointer(vector<Obj>& arr1, vector<Obj>& arr2) {

    // sort both arrays
    sort(arr1.begin(), arr1.end(),
         [](const Obj &a, const Obj &b) {
             return a.id < b.id;
         });

    sort(arr2.begin(), arr2.end(),
         [](const Obj &a, const Obj &b) {
             return a.id < b.id;
         });

    vector<Obj> result;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {

        if (arr1[i].id == arr2[j].id) {
            // merge objects
            Obj merged;
            merged.id = arr1[i].id;

            merged.fields = arr1[i].fields; // take arr1
            for (auto &kv : arr2[j].fields) // override by arr2
                merged.fields[kv.first] = kv.second;

            result.push_back(merged);
            i++; j++;
        }
        else if (arr1[i].id < arr2[j].id) {
            result.push_back(arr1[i]);
            i++;
        }
        else {
            result.push_back(arr2[j]);
            j++;
        }
    }

    // add remaining elements
    while (i < arr1.size()) result.push_back(arr1[i++]);
    while (j < arr2.size()) result.push_back(arr2[j++]);

    return result;
}
