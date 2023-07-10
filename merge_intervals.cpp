class CountIntervals{
    set<pair<int, int>> st;
    int cnt;
public:
    CountIntervals(){
        cnt = 0;
    }

    void add(int left, int right){
        auto start = st.lower_bound({left, right});

        if (start != st.begin()){
            auto prev = start;
            prev--;
            if (prev->second >= left) start--;
        }

        vector<pair<int, int>> to_rmv;
        auto end = start;
        while (end != st.end()){
            if (end->first > right) break;

            left = min(left, end->first);
            right = max(right, end->second);

            cnt -= (end->second - end->first + 1);
            to_rmv.push_back(*end); // cannot erase here as it will not point to next

            end++;
        }

        // rmv overlapping
        for (auto &it : to_rmv) st.erase(it);

        st.insert({left, right});
        cnt += right - left + 1;
    }

    int count(){
        return cnt;
    }
};