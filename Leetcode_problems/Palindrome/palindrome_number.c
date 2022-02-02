#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int isPalindrome(int x);

int main(void)
{
    int number=0;
    printf("\n\rEnter the number");
    scanf("%d",&number);
    int result=isPalindrome(number);
    if(result)
      printf("\nThe number is a palindrome\n");
    else
        printf("\nThe number is not a palindrome\n");
    return 0;
}

int isPalindrome(int x)
{
    unsigned int y=x;
    unsigned int temp=0;
    unsigned int reversed = 0;
    if(x<0)
    {
        return 0;
    }
    while(y!=0)
    {
        temp=(y%10);
        reversed = reversed * 10 + temp;
        y = y/10;         
        
    }
    printf("%d",reversed);
    return x == reversed;
}