#include "stdio.h"
#include "math.h"
#include "string.h"


float square_root(int n)
{
    int start = 0, end = n,mid;
 
    float ans;
 
    while (start <= end) {
      
        mid = (start + end) / 2;
 
        if (mid * mid == n) {
            ans = mid;
            break;
        }
       
        if (mid * mid < n) {
          
            ans=start;
            start = mid + 1;
        }
     
        else {
            end = mid - 1;
        }
    }
 

    float increment = 0.1;
    for (int i = 0; i < 5; i++) {

        while (ans * ans <= n) {
            ans += increment;
        }
 
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}
 

void main()
{
 
    int n;
    printf("\nEnter number: ");
    scanf("%d",&n);
    
    printf("\nSquare root = %.3f ", square_root(n));
    
}