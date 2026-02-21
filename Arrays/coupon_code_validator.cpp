/*
    File: coupon_code_validator.cpp
    Author: Saurabh Singh
    Problem: Coupon Code Validator
    Platform: LeetCode

    ------------------------------------------------------------
    🧩 Problem Summary:
    You are given:
        - vector<string> code          -> coupon codes
        - vector<string> businessLine  -> business category
        - vector<bool> isActive        -> coupon active status

    A coupon is VALID if:
        1. It is active (isActive[i] == true)
        2. businessLine belongs to:
              - electronics
              - grocery
              - pharmacy
              - restaurant
        3. code contains ONLY:
              - Alphanumeric characters (a-z, A-Z, 0-9)
              - Underscore (_)
        4. code is not empty

    Output:
        Return valid coupon codes sorted by:
            1. Business priority:
                electronics -> 0
                grocery     -> 1
                pharmacy    -> 2
                restaurant  -> 3
            2. Lexicographically by coupon code (default pair sorting)

    ------------------------------------------------------------
    ⏱ Time Complexity: O(n log n)
        - O(n) filtering
        - O(n log n) sorting

    🗂 Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
        Function: checkValidCode
        ------------------------
        Checks whether a coupon code is valid.

        Rules:
        - Must not be empty
        - Must contain only:
            * Letters (a-z, A-Z)
            * Digits (0-9)
            * Underscore (_)

        Returns:
            true  -> valid
            false -> invalid
    */
    bool checkValidCode(string &code) {

        // Empty string is invalid
        if (code.empty())
            return false;

        for (char &ch : code) {
            if (!isalnum(ch) && ch != '_') {
                return false;
            }
        }

        return true;
    }


    /*
        Function: validateCoupons
        --------------------------
        Filters and sorts valid coupons.

        Steps:
        1. Create priority mapping for business lines.
        2. Iterate through input arrays.
        3. Validate each coupon:
            - Must be active
            - Must belong to valid business category
            - Must pass checkValidCode()
        4. Store as pair<priority, code>
        5. Sort pairs
        6. Extract sorted codes

        Returns:
            vector<string> of valid sorted coupon codes
    */
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        // Business line priority mapping
        unordered_map<string, int> mp = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<int, string>> temp;

        for (int i = 0; i < code.size(); i++) {

            if (isActive[i] &&
                mp.count(businessLine[i]) &&
                checkValidCode(code[i])) {

                temp.push_back({mp[businessLine[i]], code[i]});
            }
        }

        sort(begin(temp), end(temp));

        vector<string> result;

        for (auto &it : temp) {
            result.push_back(it.second);
        }

        return result;
    }
};


/*
    --------------------------
    🔎 Example Usage
    --------------------------

    int main() {
        Solution sol;

        vector<string> code = {"SAVE20", "grocery_10", "pharma#50", "REST_5"};
        vector<string> businessLine = {"electronics", "grocery", "pharmacy", "restaurant"};
        vector<bool> isActive = {true, true, true, false};

        vector<string> result = sol.validateCoupons(code, businessLine, isActive);

        for (auto &c : result) {
            cout << c << endl;
        }

        return 0;
    }

    Expected Output:
        SAVE20
        grocery_10
*/
