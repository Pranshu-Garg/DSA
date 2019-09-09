#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void push_op(char op,char stk[100],int *top){       //Pushing operator in the stack

    *top=*top+1;
    stk[*top] = op;
}


char pop_op(char stk[100],int *top){                //Poping out the operator in the stack
    char temp;
    temp=stk[*top];
    *top = *top-1;
    return temp;
}

void push_digit(int value,int stk[100], int *top){          //Pushing the number in the stack
      *top = *top+1;
      stk[*top] = value;
}

int pop_digit(int stk[100], int *top){                  //poping out the number from the stack
     int temp;
     temp=stk[*top];
      *top = *top - 1;
      return temp;    
}


int doublecharconvert(char ar[100]){                //Coverting the double operator into single for easy push and pop
    for(int i=0;ar[i]!='\0';i++){
        if(ar[i-1]=='<' && ar[i] =='<'){
         ar[i-1] = 'x'; ar[i]= ' ';
        }

        if(ar[i-1]=='>' && ar[i] =='>'){
         ar[i-1] = 'y'; ar[i]= ' ';
           
        }
        if(ar[i-1]=='<' && ar[i] =='='){
         ar[i-1] = 'z'; ar[i]= ' ';
        }
        if(ar[i-1]=='>' && ar[i] =='='){
         ar[i-1] = 'p'; ar[i]= ' ';
        }
        if(ar[i-1]=='=' && ar[i] =='='){
         ar[i-1] = 'q'; ar[i]= ' ';
        }
        if(ar[i-1]=='!' && ar[i] =='='){
         ar[i-1] = 'r'; ar[i]= ' ';
         }  
        }

    }
int evaluate(int a,int b,char c){                   // Evaluating the operations on two numbers
	if(c=='+')
		return a+b;
	if(c=='-')
		return b-a;
	if(c=='*')
		return a*b;
    if(c=='/')
        return b / a;
    if(c=='%')
        return b%a;
    if(c=='^')
        return b^a;
    if(c=='&')
        return b&a;
    if(c=='|')
        return b|a;
    if(c=='x')
        return b<<a;
    if(c=='y')
        return b>>a;
    if(c=='z')
        return b <= a;
    if(c=='p')
        return b >= a;
    if(c=='q')
        return b == a;
    if(c=='r')
        return b != a;
    if(c=='<')
        return b < a;
    if(c=='>')
        return b > a;

}


int op_precedence(char op)              // Setting the precedence of operators
{
    if(op == '*' || op == '/' || op == '%')
        return 1;

    else if(op == '+' || op == '-')
        return 2;

    else if(op == 'x' || op == 'y' )
        return 3;

    else if(op == '<' || op == '>' || op =='z' || op == 'p')
        return 4;

    else if(op == 'q' || op == 'r')
        return 5;

    else if(op == '&')
        return 6;

    else if(op == '^')
        return 7;

    else if(op == '|')
        return 8;
}
int input_valid(char ar[]){   //Input validation function
    
    int i=0;
    int count=0;
    while(ar[count]!='#')
        count++;
    for(i=0;i<count;i++){
        if(ar[i]>='0' && ar[i]<='9'){
            if(ar[i+1]==' '){

                if(ar[i+2]>='0' && ar[i+2]<='9'){
                        return -1;
                    }
            }
        }


        else if(ar[i]=='+'||ar[i]=='-'||ar[i]=='*'||ar[i]=='/'||ar[i]=='%'||ar[i]=='<'||ar[i]=='>'||ar[i]=='&'||ar[i]=='^'||ar[i]=='|'){
            if(ar[i+2]<'0'||ar[i+2]>'9'){
                        return -1;
                    }

        else if(ar[i]=='x'||ar[i]=='y'||ar[i]=='z'||ar[i]=='p'||ar[i]=='q'||ar[i]=='r'){
            if(ar[i+3]<'0'||ar[i+3]>'9'){
                        return -1;
                    }

        }
        }
    }
    return 1;
}


int main()              // The main driver function
{
	int nums[100];
	char ops[100];

	int t;
    printf("Enter Number of Test Cases: \n");
    scanf("%d",&t);
    printf("Enter The Expression for Evaluation:\n");
    while(t>0){
    	int nums_top = -1;
    	int ops_top = -1;

    	char ar[1000];
		char c;
		int p=0;
		while((c=getchar())!='#')
		{	if(c!='\n'){
			ar[p]=c;
			p++;
		}
			
		}
		ar[p]='#';
		ar[p+1]='\0';
    	

        
        doublecharconvert(ar); // Calling conversion function

        if(input_valid(ar) !=1){ //The Input Validating
            printf("Error\n");
            return 0;
        }


    	for(int i=0;i<p;i++){
    		if(ar[i]==' ')
    			continue;
    		
    		else if(isdigit(ar[i])){
    			int val = 0; 

      		 while(ar[i]!='\0'&& isdigit(ar[i])){ 
                val = (val*10) + (ar[i]-'0'); 
                i++; 
            } 
            push_digit(val,nums,&nums_top);
            i--;
    		}

    		else{
    			while(op_precedence(ar[i]) >= op_precedence(ops[ops_top]) && ops_top!=-1){
    				int n1=nums[nums_top];
    				pop_digit(nums,&nums_top);
    				int n2=nums[nums_top];
    				pop_digit(nums,&nums_top);
    				char p;
    				p = ops[ops_top];
    				push_digit(evaluate(n1,n2,p),nums,&nums_top);
    				pop_op(ops,&ops_top);
    			}
    			push_op(ar[i],ops,&ops_top);
    		}
    	}

		while(ops_top!=-1){
			int n1=nums[nums_top];
    				pop_digit(nums,&nums_top);
    				int n2=nums[nums_top];
    				pop_digit(nums,&nums_top);
    				char p;
    				p = ops[ops_top];
    				push_digit(evaluate(n1,n2,p),nums,&nums_top);
    				pop_op(ops,&ops_top);
		}					


		printf("%d\n",nums[nums_top]);
    	
    	t--;	
    }


}
