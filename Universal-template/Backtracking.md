void solve(arguments..., string& current_state, vector<string>& ans) {
    // 1. BASE CASE (Kahaan rukna hai?)
    if (stop_condition) {
        ans.push_back(current_state);
        return;
    }

    // 2. CHOICE 1 (Pehli option try karo)
    if (choice1_is_valid) {
        current_state.push_back(option1); // Do (Step lelo)
        solve(..., current_state, ans);    // Recurse (Aage badho)
        current_state.pop_back();          // Undo (Backtrack - rasta saaf karo)
    }

    // 3. CHOICE 2 (Doosri option try karo)
    if (choice2_is_valid) {
        current_state.push_back(option2); // Do
        solve(..., current_state, ans);    // Recurse
        current_state.pop_back();          // Undo
    }
}
