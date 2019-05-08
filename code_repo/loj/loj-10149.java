/*

区间dp

dp[l][r] 表示顶点编号为l,l+1,⋯,r的凸多边形权值乘积和的最小值

一个凸多边形可以由两个小的凸多边形和两个小凸多边形中间空隙构成的三角形组成

dp[l][r]=min(dp[l][k]+dp[k][r]+a[l]×a[r]×a[k])
l+1<=k<=r-1

并且要用高精度qwq，这里直接用了java

*/
import java.math.*;
import java.util.*;

public class Main{
	private static final int N=55;
	public static void main(String[]args){
		Scanner cin=new Scanner(System.in);
		
		int n;
		BigInteger dp[][]=new BigInteger[N][N];
		BigInteger a[]=new BigInteger[N];
		
		n=cin.nextInt();
		for(int i=1;i<=n;i++)a[i]=cin.nextBigInteger();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=new BigInteger("1000000000000000000000000000000");
			}
		}
		for(int i=1;i<n;i++)dp[i][i+1]=new BigInteger("0");
		for(int i=3;i<=n;i++){
			for(int j=1;j+i-1<=n;j++){
				int L=j,R=j+i-1;
				for(int k=L+1;k<R;k++){
					BigInteger tmp=a[L].multiply(a[R]).multiply(a[k]);
					tmp=tmp.add(dp[L][k]).add(dp[k][R]);
					if(tmp.compareTo(dp[L][R])<0){
						dp[L][R]=tmp;
					}
				}
			}
		}
		System.out.print(dp[1][n]);
	}
}