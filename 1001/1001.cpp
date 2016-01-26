#include <stdio.h>
#include <math.h>
int main(){
	int a,b,sum,l,i,j;
	int string[8]={0};
	scanf("%d%d",&a,&b);
	sum=a+b;
	l=fabs(sum);
    	if (sum>=0) {
    		for (j=1;j<8;j++) {
    			string[j]=l%10;
				if (string[j]==l) break;
    			l=l/10;	
			}
		}
		if (sum<0) {
			printf("-");
			for (j=1;j<8;j++) {
    			string[j]=l%10;
    			if (string[j]==l) break;
    			l=l/10;
			}		
		}
		for (j=j;j>0;j--) { 
		   printf("%d",string[j]);
		   if (j==4 || j==7) printf(",");
		}
	return 0;
} 
