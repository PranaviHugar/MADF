#include <stdio.h>
#include <string.h>

int bruteForce(char[], char[]);      //function declaration

int bruteForce(char string[50], char pattern[50]) //bruteforce logic
{
        int i,j,k,n,m;
        n=strlen(string);
        m=strlen(pattern);
        for(i=0;i<=n-m;i++)
        {
            j=0;
             while(j<m && pattern[j]==string[i+j])
            {
                j++;
                if(j==m)
                    return i;
            }
        }
       return -1;
  }

int main() //main function
{
    char string[50],pattern[50];
    int r;
    printf("Enter the string:");
    gets(string);
    printf("Enter Pattern to be searched:");
    gets(pattern);
    r=bruteForce(string,pattern);
    if (r== -1)
        {
            printf("Search pattern is not available\n");
        }
        else
        {
            printf("Search pattern available at the location %d\n", r+1);
        }
        return 0;
}
