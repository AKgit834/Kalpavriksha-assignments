#include<stdio.h>
#include<stdlib.h>
#define range_for_numbers(a) (48 <= a && a <= 57)
#define operator_checker(a) (a == '+' || a == '-' || a == '*' || a == '/')

struct stack{
    char data[30];
    int val[30];
    int top;
};

int size_finder(char exp[]); //finds the size of an expression.
int checker(char exp[],int n); //checks if any invalid character are present.
int space_remover(char exp[],char* processed_exp,int n); // removes the whitespaces.
int multiple_operator_checker(char processed_exp[],int size_of_processed_exp); //checks that +* is not present.
void postfix_converter(char processed_exp[],char *postfix,int n); // converts expression into postfix. 
int precedence(char c);// return the precedence according to DMAS rule.
int calculate(char exp[],int n); // calculates the postfix expression.

int main()
{
    char exp[30],processed_exp[30],postfix[30];
    int neg_or_not[30],size_of_exp,size_of_processed_exp;

    //taking expression.
    printf("Enter expression : ");
    gets(exp);

    //getting size of expression.
    size_of_exp=size_finder(exp); 

    //removing spaces and getting the size of processed expression.
    size_of_processed_exp=space_remover(exp,processed_exp,size_of_exp);
    // printf("\ngiven exp is : %s\nprocessed exp is : %s\n",exp,processed_exp);

    //checking for invalid characters.
    if(checker(processed_exp,size_of_processed_exp) && multiple_operator_checker(processed_exp,size_of_processed_exp)){
        // printf("Expression is valid\n");
        postfix_converter(processed_exp,postfix,size_of_processed_exp); //postfix conversion.
        // printf("\nPOSTFIX expr is : %s and its size is : %d",postfix,size_finder(postfix));
        printf("\nevaluated value is : %d\n",calculate(postfix,size_finder(postfix)));
    }
    else   
        printf("\aInvalid character present !!");
    return 0;
}


int size_finder(char exp[]){
    char* c=exp;
    int n=0;
    while (*c != '\0'){
        c++;n++;
    }
    // printf("\nSize of exp is : %d\n",n);
    return n;
}

int space_remover(char exp[],char* processed_exp,int n){
    int size_of_processed_exp=0;
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i] != ' ') {
            processed_exp[size_of_processed_exp]=exp[i];
            size_of_processed_exp++;
        }
    }
    processed_exp[size_of_processed_exp]='\0';
    return size_of_processed_exp;
}

int checker(char exp[],int n){
    for(int i=0;i<n;i++){
        if(!range_for_numbers(exp[i]) && !operator_checker(exp[i])) return 0;
    }
    return 1;
}

int multiple_operator_checker(char processed_exp[],int size_of_processed_exp){
    for(int i=0;i<size_of_processed_exp-1;i++){
        if(operator_checker(processed_exp[i]) && (processed_exp[i+1] != '-' && !range_for_numbers(processed_exp[i+1]))){
            printf("\n\aMultiple operators in a row\n");
            exit(0);
        }
    }
    return 1;
}

//if operator is not encountered push the operand into stack. else if operator is found and precedence of
//operator is higher push it onto stack. else empty the stack and put the values into postfix expression 
//till the precendence of opertaor at top of stack is not less.
void postfix_converter(char processed_exp[],char *postfix,int n){
    struct stack stk;
    int j=0; //index for postfix array.
    stk.top=-1;

    //scanning the expression.
    for(int i=0;i<n;i++){
        if(range_for_numbers(processed_exp[i]) || (processed_exp[i] == '-' && (i == 0 || operator_checker(processed_exp[i-1])))){
            if(processed_exp[i] == '-' && range_for_numbers(processed_exp[i+1])){
                postfix[j++]=processed_exp[i++];
                while(i<n && !operator_checker(processed_exp[i])){
                    postfix[j++]=processed_exp[i++];
                }
                postfix[j++]=' ';
                i--; //because after i-- i will point to next operator. 
            }
            else{
                while(i<n && !operator_checker(processed_exp[i])){
                    postfix[j++]=processed_exp[i++];
                }
                postfix[j++]=' ';
                i--;
            }
        }
        else{
            while (stk.top > -1 && precedence(stk.data[stk.top]) >= precedence(processed_exp[i])) {
                postfix[j++] = stk.data[stk.top--];
                postfix[j++]=' ';
            }
            stk.data[++stk.top] = processed_exp[i];
        }
    }
    //after scanning empty the stack
    while(stk.top > -1){
        postfix[j++]=stk.data[stk.top--];
    }
    postfix[j]='\0'; //putting the terminating character at end of postfix string.
    // printf("\n\nsize of postfix : %d",size_finder(postfix));
}

int precedence(char c){
    //DMAS rule
    switch(c){
        case '+':
            return 1;
        case '-':
            return 0;
        case '*':
            return 2;
        case '/':
            return 3;
        default:
            return -1;
    }
}

int calculate(char exp[],int n){
    struct stack stk;
    stk.top=-1;
    for(int i = 0; exp[i]!='\0'; i++){
        // if operator is not present.
        if(range_for_numbers(exp[i]) || (exp[i] == '-'  && range_for_numbers(exp[i+1]))){
            int temp=0;
            int sign=1;
            if(exp[i] == '-'){
                 sign=-1;i++;
            }
            // making a whole digit.
            while(i<n && exp[i] != ' '){
                temp=temp*10+exp[i++]-'0';
            }
            // printf("\nVAR : %d\n",temp);
            stk.val[++stk.top]=temp*sign;
            
        }
        // if operator is encountered.
        else if(operator_checker(exp[i])){
            int which_op=precedence(exp[i]);
            int var1=stk.val[stk.top--];
            int var2=stk.val[stk.top--];
            // printf("\nvar1 : %d , var2 : %d\n",var1,var2);
            switch (which_op)
            {
                case 0:
                    stk.val[++stk.top]=var2-var1;
                    break;
                case 1:
                    stk.val[++stk.top]=var2+var1;
                    break;
                case 2:
                    stk.val[++stk.top]=var2*var1;
                    break;
                case 3:
                    if(var1 == 0){
                        printf("\n\aDivision By Zero Error !!");
                        exit(0);
                    }
                    stk.val[++stk.top]=var2/var1;
                    break;
            }
            // printf("\nValue at top of stack : %d",stk.val[stk.top]);
        }
    }
    return stk.val[stk.top];
}
