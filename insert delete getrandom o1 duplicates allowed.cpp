
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() : gen_(random_device()()) {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool has = used_.count(val);

        list_.emplace_back(val, used_[val].size());
        used_[val].emplace_back(list_.size() - 1);

        return !has; 
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!used_.count(val)) {
            return false;
        }

        used_[list_.back().first][list_.back().second] = used_[val].back();
        swap(list_[used_[val].back()], list_.back());

        used_[val].pop_back();
        if (used_[val].empty()) {
            used_.erase(val);
        }
        list_.pop_back();

        return true;  
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        uniform_int_distribution<int> dist(0, list_.size() - 1);
        return list_[dist(gen_)].first;
    }

private:
    vector<pair<int, int>> list_;
    unordered_map<int, vector<int>> used_;
    default_random_engine gen_;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
 
