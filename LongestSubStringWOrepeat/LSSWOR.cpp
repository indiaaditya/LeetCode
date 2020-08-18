#include <iostream>
#include <array>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int iTraverse = s.length();
        std::array<int, 256> charArr;
        int isTraverseComplete = 0;
        int traverseStartPoint = 0;
        int maxLength = 0;
        int lengthCntr = 0;
        while(isTraverseComplete == 0){
            lengthCntr = 0;
            charArr.fill(0);
            for(int i = traverseStartPoint; i < iTraverse ; i++){
                lengthCntr++;
                charArr[s[i]]++;
                if(charArr[s[i]] > 1){
                   charArr[s[i]]--; 
                   if(lengthCntr > maxLength)
                    maxLength = lengthCntr;
                   i = iTraverse + 1;      
                }
            }
            traverseStartPoint++;
            if(maxLength >= (iTraverse - traverseStartPoint))
                isTraverseComplete = 1;
        }
        return maxLength;
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