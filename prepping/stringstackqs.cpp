#include <iostream>
#include <string>
using namespace std;
int count(string s,char c){
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==c){
            cnt++;
        }
    }
    return cnt;
}

int longestSymmetricSubstring(string& S) {
    int N = S.length();
    int maxSymmetricLen = 0;

    for (int center = 0; center < 2 * N - 1; center++) {
        int left = center / 2;
        int right = left + center % 2;

        while (left >= 0 && right < N && (S[left] == S[right] || S[left] == '=' || S[right] == '=')) {
            if (S[left] != '=' && S[right] != '=') {
                maxSymmetricLen = max(maxSymmetricLen, right - left + 1);
            }
            left--;
            right++;
        }
    }
    int cnt=count(S,'=');
    if(count(S,'=')==S.size()){
        if(cnt%2==0){
            maxSymmetricLen=cnt;
        }
        else{
            maxSymmetricLen=cnt-1;
        }
    }

    return maxSymmetricLen;
}

int main() {
    string S1 = "<<<<==>>";
    cout << longestSymmetricSubstring(S1) << endl; // Output: 4

    string S2 = "======";
    cout << longestSymmetricSubstring(S2) << endl; // Output: 6

    string S3 = "<<=";
    cout << longestSymmetricSubstring(S3) << endl; // Output: 2

    return 0;
}

// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// int solution(string& S) {
//     int N = S.length();
//     int left = 0, right = 0;
//     int open_count = 0, close_count = 0;
//     int max_sym_len = 0;

//     while (right < N) {
//         if (S[right] == '<') {
//             open_count++;
//         } else if (S[right] == '>') {
//             close_count++;
//         } else { // S[right] == '='
//             // Try replacing "=" with "<"
//             open_count++;
//             // Try replacing "=" with ">"
//             close_count++;
//         }

//         while (open_count > right - left + 1 || close_count > right - left + 1) {
//             if (S[left] == '<') {
//                 open_count--;
//             } else if (S[left] == '>') {
//                 close_count--;
//             }
//             left++;
//         }

//         max_sym_len = max(max_sym_len, right - left + 1);
//         right++;
//     }

//     return max_sym_len;
// }

// int main() {
//     string S1 = "<><==>>";
//     cout << solution(S1) << endl; // Output: 4

//     string S2 = "======";
//     cout << solution(S2) << endl; // Output: 6

//     string S3 = "<<=";
//     cout << solution(S3) << endl; // Output: 2

//     return 0;
// }