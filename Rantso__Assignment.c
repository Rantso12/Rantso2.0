//Rants'o Kananelo 202000057
//kananelorantso12@gmail.com
//CS3520 Assignment1

#include<stdio.h>
#include<math.h>

int detPrimes();
int SqaureOfPrime();
int detReverse();
int detPalindrome();
int detSquareRootReversed();

int Primes[900];
int SquarePrimes[900];
int Reversed[900];
int notPalindrome[900];
int ReversedRoots[900];

int k = 0;
//This function determines prime numbers, stores them in an array of Primes  and keeps the count of prime numbers between 0 and 2500
int detPrimes()
{ 
    int counter = 0;
	int notPrimes[10];
	int primes,notprimes;
	
	for( int i = 0; i <= 2500; i++) //for loop searches for prime numbers
	{
		if((i != 0)&&( i != 1 )&&(i < 10)) // This if statement determines prime numbers less than 10
		{
			if((( i % 2) == 0)||(( i % 3) == 0)) 
			{
				notprimes= i;
			}
			else
			{  	
				
				Primes[k] = i;
				k++;
			}
		}
		else if( i > 10) //This branch of an if statement determines prime  numbers greater than 10
		{
			if((i % 2 == 0)||(i % 3 == 0)||(i % 5 == 0)||(i % 7 == 0))//If a number is either divisible by 2,3,5 or 7 it is not 
																	//prime hence a number not divisible by those numbers is a prime number
			{
				notprimes = i;
			}
			else
			{
				
				Primes[k] = i; //Prime numbers greater than 10 a added to this list henceforth they are determined
				k++;					
			}
		}
	}
}
//This function finds the square of prime numbers stored in an array
int SquareOfPrime()
{
	detPrimes();
	for(int m = 0 ; m < k ; m++ )
	{
	    int number = Primes[m];
		int square = number*number;
		SquarePrimes[m] = square; 
	}		
}
//This function determined the reverse of each prime square
int detReverse()
{
	int reverse, remainder , square ;
		
	SquareOfPrime();
	for(int d = 0; d < k ; d++ )
	{
		reverse = 0;
		square = SquarePrimes[d];
		//reverse function
		for( ; square != 0; )
		{
			remainder = square % 10;
			reverse = reverse*10 + remainder;
			square = square/10;
		}
		
		Reversed[d] = reverse;	 //Reversed prime squares are stored in this array	
	}
				
}

//This function determines if the square and its reverse are equal and those that are not equal in an array of notPalindrome
int ind = 0;
int detPalindrome()
{
	int counter = 0;	
	detReverse();
	int Palindrome[1000];
	for(int p = 0; p < k ; p++)
	{
		
		if(SquarePrimes[p] !=   Reversed[p] )//If statements get a number from Squareprimes and compares it with the corresponding number from Reversed
		{
			notPalindrome[ind] = Reversed[p];
			//An array of notPalindrome is populated
			ind++;
			counter++;
		}
		else
		{
			Palindrome[p] = Reversed[p];
		}
	}
}

//This function determines the square roots of values that are palindromes
int detSquareRootReversed()
{
	
	int counter = 0;
	int index = 0;
	int failedroots[900];
	
	detPalindrome();
	for( int d = 0; d < ind ; d++)
	{ 	
		int sRoot = notPalindrome[d];
		int Root = sqrt(sRoot);
		if( notPalindrome[d] == Root*Root )
		{
			//if statement determines the divisibility of roots(whether the square root is divisible or not)
			if((Root % 2 != 0)&&(Root % 3 != 0)&&(Root % 5 != 0)&&(Root % 7 != 0))
			{
               
				ReversedRoots[index] = notPalindrome[d];
				
				index++;
				counter++;					
			}
			else
			{
			    
				failedroots[d] = notPalindrome[d];
			}

		}
		else
		{
		    
			failedroots[d] = notPalindrome[d];
		}			
		
	}	
	printf("\nPrime Squares\n");
	if ( counter = 10)
	{
 		for(int m = 0; m < counter ; m ++)
 		{	
			printf("%d\n",ReversedRoots[m]);
 		}			
	}
	
}
int main()
{
	//since the second function calls the first and third calls the second and so on, only one function call is made.
	 
	detSquareRootReversed();
	
	return 0;
}

