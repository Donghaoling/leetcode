#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


char ch[110][110];

int dp[110][110][2];

int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		scanf("%s",ch[i]);
	if (ch[0][0]=='b') dp[0][0][0]=1;
		else dp[0][0][0]=0;
	if (m==1 || ch[0][1]=='b') dp[0][0][1]=0;
		else dp[0][0][1]=1;
	for (int i=1;i<m;i++){
		dp[0][i][0]=dp[0][i-1][0]+(ch[0][i] == 'b');
		dp[0][i][1]=dp[0][i][0]+(i<m-1 && ch[0][i+1]=='.');
	}
	for (int i=1;i<n;i++){
		dp[i][0][1]=dp[i-1][0][1]+(ch[i][0] == 'b');
		dp[i][0][0]=dp[i][0][1]+(i<n-1 && ch[i+1][0]=='.');
	}
	for (int i=1;i<n;i++)
		for (int j=1;j<m;j++){
			int x=1,y=1;
			if (i==n-1 || ch[i+1][j]=='b') x=0;
			if (j==m-1 || ch[i][j+1]=='b') y=0;
			dp[i][j][0]=(ch[i][j] == 'b')+ min(dp[i][j-1][0], dp[i-1][j][1] + x);
			dp[i][j][1]=(ch[i][j] == 'b')+ min(dp[i-1][j][1], dp[i][j-1][0] + y);
		}
	printf("%d\n",min(dp[n-1][m-1][0],dp[n-1][m-1][1]));
	return 0;
}
