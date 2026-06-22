# DP Pick / Skip Template

## Core Idea

At every index, we have only 2 choices:

1. **Pick Current Element**
2. **Skip Current Element**

Take the best answer among them.

---

# Universal Recursion Template

```cpp
int solve(int i, vector<int>& nums) {

    // Base Case
    if(i >= nums.size())
        return 0;

    // Choice 1 : Skip
    int skip = solve(i + 1, nums);

    // Choice 2 : Pick
    int pick = nums[i] + solve(i + k, nums);

    return max(skip, pick);
}
```

---

# Universal Memoization Template

```cpp
int solve(int i,
          vector<int>& nums,
          vector<int>& dp) {

    if(i >= nums.size())
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int skip = solve(i + 1, nums, dp);

    int pick = nums[i] + solve(i + k, nums, dp);

    return dp[i] = max(skip, pick);
}
```

---

# DP Thinking Pattern

At every state:

```cpp
Current Index i
```

Ask:

```cpp
Can I take this?
Can I leave this?
```

---

# Generic Formula

```cpp
Answer =
max(
    Skip Current,
    Pick Current
)
```

---

# State Template

```cpp
State = i
```

Meaning:

```cpp
Best answer possible from index i onwards
```

---

# Base Case Template

```cpp
if(i >= n)
    return 0;
```

or

```cpp
if(i == n)
    return 0;
```

---

# Memoization Template

```cpp
if(dp[i] != -1)
    return dp[i];
```

---

# Common Variations

## House Robber

```cpp
pick = nums[i] + solve(i+2)
skip = solve(i+1)
```

---

## Stickler Thief

```cpp
pick = nums[i] + solve(i+2)
skip = solve(i+1)
```

---

## Delete and Earn

```cpp
pick = points[i] + solve(i+2)
skip = solve(i+1)
```

---

## Weighted Decisions

```cpp
pick = value[i] + solve(nextValidIndex)
skip = solve(i+1)
```

---

# Recognition Pattern

If question says:

✅ Take or Leave

✅ Select Non Adjacent

✅ Maximum Profit

✅ Maximum Sum

✅ Rob Houses

✅ Attend / Skip Event

✅ Job Scheduling

Think:

```cpp
Pick
OR
Skip
```

---

# Master Template

```cpp
int solve(int i) {

    if(base_case)
        return answer;

    if(dp[i] != -1)
        return dp[i];

    int skip = solve(next1);

    int pick = value + solve(next2);

    return dp[i] = max(skip, pick);
}
```

---

# Golden Formula

```cpp
Choice

1. Pick
2. Skip

Answer = max(Pick, Skip)
```

This single template solves a huge category of 1-D DP problems.
