#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>


char *lookahead;

void first(){
    return;
}

void second(){
    return;
}

void third(){
    return;
}

void fourth(){
    return;
}

void init(){    
    fourth();third();second();first();
} 

void iserror(char c){
    printf("something wrong with %c\n",c);
    exit(1);
}

void match(const char t){
    if(*lookahead == t) lookahead++; 
    else iserror(*lookahead);
    return;
}



int main(int argc, char **argv){
    
    for (int n=1;n<argc;n++){
        //  loop for all arguments
        lookahead = argv[n];
        init(argv[n]);
    }

    return 0;
}