#include<bits/stdc++.h>
using namespace std;

// bool checkIsValid(int n1,int n2){
//     string s1=to_string(n1);
//     string s2=to_string(n2);
//     for(int i=0;i<s1.size();i++){
//         for(int j=0;j<s2.size();j++){
//             if(s1[i]==s2[j]) return true;
//         }
//     }
//     return false;
// }

// int countpairs(vector<int>v){
//     int n=v.size();
//     int numberPair=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if (checkIsValid(v[i],v[j])) numberPair++;            
//         }
//     }
//     return numberPair;
// }
// void calculateMaskFrequencies(vector<int> arr, int n,
//                  unordered_map<int, int>& freq)
// {
//     // Iterate over the array
//     for (int i = 0; i < n; i++) {
 
//         int num = arr[i];
 
//         // Creating an empty mask
//         int mask = 0;
 
//         // Extracting every digit of the number
//         // and updating corresponding bit in the
//         // mask
//         while (num > 0) {
//             mask = mask | (1 << (num % 10));
//             num /= 10;
//         }
 
//         // Update the frequency array
//         freq[mask]++;
//     }
// }
 
// // Function return the number of valid pairs
// int countPairs(vector<int> arr)
// {
//     int n=arr.size();
//     // Store the mask frequencies
//     unordered_map<int, int> freq;
 
//     calculateMaskFrequencies(arr, n, freq);
 
//     long long int numberOfPairs = 0;
 
//     // Considering every possible pair of masks
//     // and calculate pairs according to their
//     // frequencies
//     for (int i = 0; i < 1024; i++) {
//         numberOfPairs += (freq[i] * (freq[i] - 1)) / 2;
//         for (int j = i + 1; j < 1024; j++) {
 
//             // if it contains a common digit
//             if (i & j)
//                 numberOfPairs += (freq[i] * freq[j]);
//         }
//     }
//     return numberOfPairs;
// }


//ChatGpt
#include <vector>
#include <algorithm>

// Function to check if two numbers have at least one common digit
bool hasCommonDigit(int num1, int num2) {
    int digits1 = 0, digits2 = 0;

    // Set the corresponding bits for the digits in the numbers
    while (num1 > 0) {
        digits1 |= (1 << (num1 % 10));
        num1 /= 10;
    }

    while (num2 > 0) {
        digits2 |= (1 << (num2 % 10));
        num2 /= 10;
    }

    // If there is a common digit, the bitwise AND will be non-zero
    return (digits1 & digits2) != 0;
}

int solution(vector<int> numbers, int N) {
    int maxElements = 1; // At least one element can be chosen

    // Sort the array for efficient checking of common digits
    std::sort(numbers.begin(),numbers.end());

    // Dynamic programming table to store the maximum number of elements that can be chosen
    std::vector<int> dp(N, 1);

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            // Check if numbers[i] and numbers[j] have at least one common digit
            if (hasCommonDigit(numbers[i], numbers[j])) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }

        // Update the maximum number of elements that can be chosen
        maxElements = std::max(maxElements, dp[i]);
    }

    return maxElements;
}
//Not fully correct below one
// #include <algorithm>

// // Function to check if two numbers have at least one common digit
// bool hasCommonDigit(int num1, int num2) {
//     int digits1 = 0, digits2 = 0;

//     // Set the corresponding bits for the digits in the numbers
//     while (num1 > 0) {
//         digits1 |= (1 << (num1 % 10));
//         num1 /= 10;
//     }

//     while (num2 > 0) {
//         digits2 |= (1 << (num2 % 10));
//         num2 /= 10;
//     }

//     // If there is a common digit, the bitwise AND will be non-zero
//     return (digits1 & digits2) != 0;
// }

// int solution(vector<int> numbers, int N) {
//     // Sort the array for efficient checking of common digits
//     sort(numbers.begin(),numbers.end());

//     int currentCount = 1; // At least one element can be chosen
//     int maxCount = 1;

//     for (int i = 1; i < N; i++) {
//         if (hasCommonDigit(numbers[i], numbers[i - 1])) {
//             currentCount++;
//         } else {
//             currentCount = 1;
//         }

//         maxCount = std::max(maxCount, currentCount);
//     }

//     return maxCount+1;
// }

int main(){
    vector<int>v={50,30,15,51,10,20,15};
    cout<<solution(v,7);
}