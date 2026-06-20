class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, std::move(value));
    }
    
    string get(string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) {
            return "";
        }
        
        auto& values = it->second;
        int l = 0, r = values.size();
        string result = "";

        while (l < r) {
            int mid = (l + r) / 2;
            if (values[mid].first > timestamp) {
                r = mid;
            } else if (values[mid].first <= timestamp) {
                result = values[mid].second;
                l = mid + 1;
            }
        }
        return result;
    }

    std::unordered_map<string, vector<std::pair<int, string>>> store;
};
