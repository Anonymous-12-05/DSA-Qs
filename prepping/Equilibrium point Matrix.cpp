//Mine
#include <bits/stdc++.h>
using namespace std;

#include <vector>

int solution(vector<std::vector<int>>& A) {
    int N = A.size();
    int M = A[0].size();

    vector<int> rowSums(N, 0);
    vector<int> colSums(M, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            rowSums[i] += A[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            colSums[i] += A[j][i];
        }
    }
    // for (int i = 0; i < N; i++) {
    //         cout<<rowSums[i]<<" ";
    // }
    // cout<<endl;
    // for (int i = 0; i < M; i++) {
    //         cout<<colSums[i]<<" ";
    // }
    // cout<<endl;
    vector<int>Usum(N,0),Dsum(N,0),Lsum(M,0),Rsum(M,0);
    //Upsum
    for(int i=0;i<N;i++){
        if(i==0){
            Usum[i]=0;
        }
        else{
            for(int j=1;j<i+1;j++){
                Usum[i]+=rowSums[j-1];
            }
        }
    }
    //DownSum
    for(int i=N-1;i>=0;i--){
        if(i==N-1){
            Dsum[i]=0;
        }
        else{
            for(int j=i;j<N-1;j++){
                Dsum[i]+=rowSums[j+1];
            }
        }
    }
    //Left sum
    for(int i=0;i<M;i++){
        if(i==0){
            Lsum[i]=0;
        }
        else{
            for(int j=1;j<i+1;j++){
                Lsum[i]+=colSums[j-1];
            }
        }
    }
    //Right Sum
    for(int i=M-1;i>=0;i--){
        if(i==M-1){
            Rsum[i]=0;
        }
        else{
            for(int j=i;j<M-1;j++){
                Rsum[i]+=colSums[j+1];
            }
        }
    }
    // for(int i=0;i<N;i++){
    //     cout<<Usum[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<N;i++){
    //     cout<<Dsum[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<M;i++){
    //     cout<<Lsum[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<M;i++){
    //     cout<<Rsum[i]<<" ";
    // }
    // cout<<endl;
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Usum[i]==Dsum[i] && Lsum[j]==Rsum[j]){
                cnt++;
            }
        }
    }
    
    return cnt;

    
}

int main(){
    vector<vector<int>>A={{2,7,5},{3,1,1},{2,1,-7},{0,2,1},{1,6,8}};
    cout<<solution(A);
}
//ChatGpt
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>>& A) {
    int N = A.size();
    int M = A[0].size();

    vector<int> rowSums(N, 0);
    vector<int> colSums(M, 0);

    // Calculate row sums and column sums
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            rowSums[i] += A[i][j];
            colSums[j] += A[i][j];
        }
    }

    vector<int> Usum(N, 0), Dsum(N, 0), Lsum(M, 0), Rsum(M, 0);

    // Calculate prefix sums for Usum and Dsum
    Usum[0] = 0;
    for (int i = 1; i < N; i++) {
        Usum[i] = Usum[i - 1] + rowSums[i - 1];
    }

    Dsum[N - 1] = 0;
    for (int i = N - 2; i >= 0; i--) {
        Dsum[i] = Dsum[i + 1] + rowSums[i + 1];
    }

    // Calculate prefix sums for Lsum and Rsum
    Lsum[0] = 0;
    for (int i = 1; i < M; i++) {
        Lsum[i] = Lsum[i - 1] + colSums[i - 1];
    }

    Rsum[M - 1] = 0;
    for (int i = M - 2; i >= 0; i--) {
        Rsum[i] = Rsum[i + 1] + colSums[i + 1];
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Usum[i] == Dsum[i] && Lsum[j] == Rsum[j]) {
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    vector<vector<int>> A = { {2, 7, 5}, {3, 1, 1}, {2, 1, -7}, {0, 2, 1}, {1, 6, 8} };
    cout << solution(A);
}
