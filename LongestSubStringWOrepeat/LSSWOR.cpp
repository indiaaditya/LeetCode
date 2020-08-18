#include <iostream>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int iTraverse = s.length();
        return iTraverse;
    }
};


int main()
{
    string inputString = "ASDFGHKKLGZ";
    Solution s1;
    int maxLength = s1.lengthOfLongestSubstring(inputString);
    cout << "\n This is the max. Length:" << maxLength;
    cout << "\nComplete\n";
}