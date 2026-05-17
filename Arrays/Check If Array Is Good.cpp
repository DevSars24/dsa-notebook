# Check If Array Is Good — C++ Documentation

## Problem Link

[https://leetcode.com/problems/check-if-array-is-good/](https://leetcode.com/problems/check-if-array-is-good/)

---

# Problem Statement

An array `nums` is called **good** if:

* It contains every integer from:

```text
1 to n - 1
```

exactly once.

* And the number:

```text
n - 1
```

appears exactly twice.

Where:

```text
n = nums.size()
```

We need to return:

```cpp
true
```

if the array is good,
otherwise:

```cpp
false
```

---

# Example 1

Input:

```cpp
nums = [2,1,3]
```

Output:

```cpp
false
```

Explanation:

For size `3`, a good array should contain:

```text
1, 2, 2
```

But given array is:

```text
1, 2, 3
```

So answer is false.

---

# Example 2

Input:

```cpp
nums = [1,3,3,2]
```

Output:

```cpp
true
```

Explanation:

Size:

```text
n = 4
```

A valid good array should contain:

```text
1, 2, 3, 3
```

which matches.

---

# Intuition

A good array follows this structure:

```text
[1, 2, 3, ..., n-1, n-1]
```

So:

* Maximum element must be:

```text
n - 1
```

* Largest number should appear twice.
* All remaining numbers should appear exactly once.

---

# Approach Used

## Step 1

Find maximum element.

If:

```cpp
max_element + 1 != size
```

then array cannot be good.

---

## Step 2

Sort the array.

After sorting:

```text
largest number should appear at last two indices
```

---

## Step 3

Check duplicate condition.

Only the last number should repeat.

If any other duplicate exists:

```cpp
return false;
```

---

# Dry Run

Input:

```cpp
nums = [1,3,3,2]
```

---

## Step 1: Find Maximum

Maximum:

```cpp
3
```

Size:

```cpp
4
```

Check:

```cpp
3 + 1 == 4
```

Valid.

---

## Step 2: Sort Array

Sorted array:

```cpp
[1,2,3,3]
```

---

## Step 3: Check Last Two Elements

```cpp
nums[2] == nums[3]
```

True.

---

## Step 4: Check Other Duplicates

```text
1 != 2
2 != 3
```

No unwanted duplicates.

Return:

```cpp
true
```

---

# Your C++ Solution

```cpp
class Solution {
public:

    int maxi = INT_MIN;

    int highestno(vector<int> nums) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }

        return maxi;
    }


    bool isGood(vector<int>& nums) {

        int n = nums.size();

        int x = highestno(nums);

        int y = nums.size();

        // Maximum should be n-1
        if((x + 1) != y)
            return false;

        sort(nums.begin(), nums.end());

        // Largest number should repeat twice
        if(nums[y - 2] != nums[y - 1])
            return false;


        // No other duplicates allowed
        for(int i = 0; i < n - 2; i++) {

            if(nums[i] == nums[i + 1]) {
                return false;
            }
        }

        return true;
    }
};
```

---

# Small Optimization

Instead of using global variable:

```cpp
int maxi = INT_MIN;
```

we can make it local.

Optimized version:

```cpp
int highestno(vector<int>& nums) {

    int maxi = INT_MIN;

    for(int num : nums) {
        maxi = max(maxi, num);
    }

    return maxi;
}
```

This is safer and cleaner.

---

# Time Complexity

Sorting dominates.

```text
O(n log n)
```

---

# Space Complexity

```text
O(1)
```

Ignoring sorting internal memory.

---

# Key Learning

This problem teaches:

* Pattern observation
* Sorting based validation
* Duplicate checking
* Edge case handling

---

# Important Edge Cases

## Case 1

```cpp
[1,1]
```

Valid good array.

---

## Case 2

```cpp
[1,2,2,4]
```

Invalid because maximum should be:

```text
n-1 = 3
```

---

## Case 3

```cpp
[1,2,3,3,3]
```

Invalid because only one duplicate allowed.

---

# Final Summary

A good array must:

✔ contain numbers from `1` to `n-1`

✔ contain maximum element twice

✔ contain all others exactly once

✔ have maximum equal to `n-1`

Your solution correctly validates all these conditions.
