# include<stdio.h>
#include<stdlib.h>
#include<string.h>

int num=0;
int top=-1;

int totalpermutation(int n){            // Recursive function for finding 2nCn/n+1 (Total permutation)
    if (n <= 1)
        return 1;  

    long int ans = 0; 
    for (int i=0; i<n; i++){
        ans = ans + totalpermutation(i)*totalpermutation(n-i-1); 
    }
    return ans;
}

void push_digit(int value,int stack[100]){      //Push function for pushing the digit in the stack
      top = top+1;
      stack[top] = value;
}
int pop_digit(int stack[100]){                  //Pop function for kicking out the digit from the stack
          int temp;
          temp=stack[top];
            top = top - 1;
           return temp;
}

void magic(char array[100],int n){           //Where the magic happens
    int i=0;
    int stk[100];
    for(i=0;i<n;i++){
        if(array[i]=='{'){
            num++;
            push_digit(num,stk);
        }
        else{
            printf("%d ",pop_digit(stk));
        }
    }
}

int cnt=0;
void balancebracket(int locn, int n, int start, int end,int k)      //analogous bracket balancing function
{
    static char str[100];

     
    if(end == n){
        if(cnt!=k){
        cnt=cnt+1;
        if(cnt==k){
            magic(str,2*n);
            return;
            }
            return;
        }
}
    else{
        if(start > end)  
        {  
            str[locn] = '}';
            balancebracket(locn+1, n, start, end+1,k);
        }
         if(start < n)
        {
        str[locn] = '{';
        balancebracket(locn+1, n, start+1, end,k);
        }
         
       
    }
}
 
int main()              // Main (driver) function
{
    int t;
    printf("Enter Number of Test Cases: \n");
    scanf("%d",&t);
    while(t--){
        top=-1;
        num=0;
        cnt=0;
        int n,k;
        printf("Enter n,k: \n");
        scanf("%d %d",&n,&k);
        printf("%d ", totalpermutation(n));
        balancebracket(0, n, 0, 0,k);
        printf("\n");
    }
    return 0;
} 