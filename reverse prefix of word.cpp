
class Solution {
public:
    string reversePrefix(string word, char ch) {
        reverse(begin(word), begin(word) + 1 + word.find(ch));
        return word;
    }
};
