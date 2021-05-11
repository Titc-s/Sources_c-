#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000], tmp_arr[1000];
int get_MaxSum(int arr[],int col){
	int max_sum = 0, tmp = 0;
	for (int i = 0; i < col;i++){
		if(tmp>0){
			tmp += arr[i];
		}
		else{
			tmp = arr[i];
		}
		if(tmp>max_sum){
			max_sum = tmp;
		}
	}
	return max_sum;
}
int main(){
	int cas;
	while(cin>>cas){
		for (int i = 0; i < cas;i++){
			for (int j = 0; j < cas;j++)
				cin >> dp[i][j];
		}
		long int max_sum = 0, tmp_sum;
		for (int i = 0; i < cas;i++){
			memset(tmp_arr, 0, sizeof(tmp_arr));
			for(int j = i; j < cas;j++){
				for (int k = 0; k < cas;k++){
					tmp_arr[k] += dp[j][k];
				}
				tmp_sum = get_MaxSum(tmp_arr, cas);
				if(tmp_sum>max_sum){
					max_sum = tmp_sum;
				}
			}
		}
		cout << max_sum << endl;
	}
	cout << endl;
	return 0;
}