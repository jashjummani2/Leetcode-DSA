class Solution {
public:
int dp[1001][1001];
int rec(int i,int j,string &s1, string &s2){
    if(i<0||j<0){
        return 0;
    }
    if (dp[i][j]!=-1) return dp[i][j];
    // int result = 0;
    if(s1[i]==s2[j]){
        return dp[i][j] = 1+rec(i-1,j-1,s1,s2);
        //  = result;
    }
    
    return dp[i][j] = max(rec(i-1,j,s1,s2),rec(i,j-1,s1,s2));
}
    int longestCommonSubsequence(string text1, string text2) {
        
        memset(dp,-1,sizeof(dp));
        int len1 = text1.size(),len2 = text2.size();
        return rec(len1-1,len2-1,text1,text2);
    }
};