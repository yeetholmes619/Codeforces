
#include<stdio.h>

int main()
{
	 int minimum, maximum, flag, count=0, i, j;
	 /* Inputs */
	 printf("Enter minimum number: ");
	 scanf("%d", &minimum);
	 printf("Enter maximum number: ");
	 scanf("%d", &maximum);
	 
	 /* Generating and counting prime numbers */
	 for(i=minimum; i<=maximum; i++)
	 {
		  flag = 0;
		  for(j=2; j <= i/2; j++)
		  {
			   if(i%j==0)
			   {
				    flag=1;
				    break;
			   }
		  }
		  if(flag==0 && i>=2)
		  {
//		   	printf("%d\t",i);
		   	count++;
		  }
	 }
	 printf("\n Prime Count = %d", count);
	 return(0);
}
