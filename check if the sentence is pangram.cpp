
class Solution {
public:
    bool checkIfPangram(string sentence) {
        return size(unordered_set<int>(cbegin(sentence), cend(sentence))) == 26;
    }
};
