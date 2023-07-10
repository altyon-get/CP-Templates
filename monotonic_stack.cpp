vector<int> findNextAndPreviousGreaterIndexes(vector<int>& arr) {
    stack<int> stack;
    vector<int> previousGreater(arr.size(), -1);
    vector<int> nextGreater(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++) {
        //<= (next greater or equal index) or (prev greater index)
        //<  (next greater index) or (prev greater or equal index)
        while (!stack.empty() && arr[stack.top()] < arr[i]) {
            int stackTop = stack.top();
            stack.pop();
            nextGreater[stackTop] = i;
        }
        if (!stack.empty()) previousGreater[i] = stack.top();
        stack.push(i);
    }
    return nextGreater;
    // return previousGreater;
}


vector<int> findNextAndPreviousSmallerIndexes(vector<int>& arr) {
    stack<int> stack;//monotonic increasing stack
    vector<int> previousSmaller(arr.size(), -1);
    vector<int> nextSmaller(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++) {
        //>= (next smaller or equal) or (previous smaller)
        //>  (next smaller ) or (previous smaller or equal)
        while (!stack.empty() && arr[stack.top()] >= arr[i]) {
            int stackTop = stack.top();
            stack.pop();
            nextSmaller[stackTop] = i;
        }
        if (!stack.empty()) {
            previousSmaller[i] = stack.top();
        }
        stack.push(i);
    }
    return nextSmaller;
    return previousSmaller;
}
