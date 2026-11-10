#include<stdio.h>

char st[20],inp[100];

int top=-1;
int i=0;

void pop(){
    st[top--]='\0';
}

void push(char c){
    st[++top]=c;
    st[top+1]='\0';
}

int reduce(){
    //E->i
    if(top>=0 &&st[top]=='i'){
        pop();
        push('E');
        return 1;
    }
    // E->E+E
    else if(top>=2 && st[top]=='E' && st[top-1]=='+' && st[top-2]=='E'){
        pop();
        pop();
        pop();
        push('E');
        return 1;
    }
    // E->E-E
    else if(top>=2 && st[top]=='E' && st[top-1]=='-' && st[top-2]=='E'){
        pop();
        pop();
        pop();
        push('E');
        return 1;
    }
    // E->E*E
    else if(top>=2 && st[top]=='E' && st[top-1]=='*' && st[top-2]=='E'){
        pop();
        pop();
        pop();
        push('E');
        return 1;
    }
    // E->(E)
    else if(top>=2 && st[top]=='(' && st[top-1]=='E' && st[top-2]==')'){
        pop();
        pop();
        pop();
        push('E');
        return 1;
    }
    return 0;

}

int main(){

    printf("Enter expression:");
    scanf("%s",inp);

    printf("STACK\tINPUT\tACTION\n");
    while(inp[i]!='\0'){
        push(inp[i]);
        i++;

        printf("%s\t%s\tSHIFT\n",st,inp+i);
        while(reduce()){
            printf("%s\t%s\tREDUCE\n",st,inp+i);
        }
    }

    while(reduce()){
        printf("%s\t%s\tREDUCE\n",st,inp+i);
    }

    if(st[top]=='E' && top==0){
        printf("Accepted\n");
    }
    else{
        printf("Rejected\n");
    }

    return 0;
}