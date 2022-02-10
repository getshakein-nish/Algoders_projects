/*credit card project*/
//C language

#include<stdio.h>
int check_luhn(long long,int);
int main()
{
	int series=1;
	while(series--)
	{
	long long n; //n is the card no.
	printf("....CARD CHECKING PROGRAM....\n");
	printf(":::::::::::::::::::::::::::::::::::::::::\n");
	printf("....ENTER CARD NO. TO CHECK\n");
    scanf("%lld",&n);
	long long t=n;
	int count=0;
	while(t!=0)
	{
		t=t/10;
		count++;//counting digits in given card no.
	}
	int b;
	//if digits possible for any card do this-
	if(count==13 || count==15 || count ==16)
	{
		b=check_luhn(n,count);
		if(b==1)
   	{
    		if(count==13){printf("VISA\n");}
	    	else if((count==15)&& ((n/ 100000000000000==34)|| (n/100000000000000==37)))
	    	{printf("AMEX\n");}
    		else if(count==16)
	   	{
	   		if(n/1000000000000000==4)
		   	printf("VISA\n");
		   	else if((n/100000000000000==51) || 
		   	(n/100000000000000==52)  ||
		   	(n/100000000000000==53)  ||
		   	(n/100000000000000==54) ||
		   	(n/100000000000000==55)
		   	)
	   		printf("Mastercard\n");
   		}
   	}
	else printf("INVALID\n"); //executes if b==0
}
else 
printf("INVALID\n");//if digits< or > than required for card.
printf("Do you want to check another card number ?\n");
printf("1. YES \n 2. NO");
int uchoice;
scanf("%d",&uchoice);
if(uchoice==1)
series++;
else if(uchoice==2)
series=0;
else
printf("Error Occured....\n INVALID CHOICE");
}
}
//function to check a card for luhn algorithm.
int check_luhn(long long n,int count)
{
		int arr[count],i=0;
        while(n!=0)   //loop for convert n to array
    	{
	        arr[i++]=n%10;
	        n=n/10;
     	}
     	for(int j=1;j<count;j+=2) // even places *2
     	{
     		arr[j]=2*arr[j];
     	}
     	int sum=0;
     	for(int j=0;j<count;j++)
     	{   int z=0;
     		while(arr[j]!=0)
     		{
     			 z+=arr[j]%10;
     		 	arr[j]=arr[j]/10;
			 }
			 sum+=z;            //sum the digits.
     	}
     	if(sum%10==0)
     	return 1;
     	else 
     	return 0;
}//4003600000000014