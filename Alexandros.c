#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>


char *lookahead;


void iserror(char c){
    puthcar('?');
    printf("\nsomething wrong with %c\n",c);
    exit(1);
}

void match(const char t){
    if(*lookahead == t) lookahead++; 
    else iserror(*lookahead);
    return;
}

void first_ddd(){
    switch(*lookahead){
        case 'I':match('I');
    }
    return;
}

void first_dd(){
    switch(*lookahead){
        case 'I':match('I');first_ddd();
    }
    return;
}

void first_d(){
    switch(*lookahead){
        case 'I':   match('I');first_dd();break;
        default:    break;
    }
    return;
}

void first(){
    switch(*lookahead){
        case 'I':   match('I');
            switch (*lookahead) {
                case 'X':   match('X');break;
                case 'V':   match('V');break;
                default:    first_d();
            } 
        
        break;

        case 'V':   match('V'); first_d();
    }
    return;
}

void second_ddd(){
    switch(*lookahead){
        case 'X':match('X');
    }
    return;
}

void second_dd(){
    switch(*lookahead){
        case 'X':match('X');second_ddd();
    }
    return;
}

void second_d(){
    switch(*lookahead){
        case 'X':   match('X');second_dd();break;
        default:    break;
    }
    return;
}

void second(){
    switch(*lookahead){
        case 'X':   match('X');
            switch (*lookahead) {
                case 'C':   match('C');break;
                case 'L':   match('L');break;
                default:    second_d();
            } 
        break;

        case 'L':   match('L'); second_d();
    }
    return;
}

void third_ddd(){
    switch(*lookahead){
        case 'C':match('C');putchar('3');
    }
    return;
}

void third_dd(){
    switch(*lookahead){
        case 'C':   match('C');third_ddd();break;
        default:    putchar('2');
    }
    return;
}

void third_d(){
    switch(*lookahead){
        case 'C':   match('C');third_dd();break;
        default:    putchar('1');break;
    }
    return;
}

void third(){
    switch(*lookahead){
        case 'C':   match('C');
            switch (*lookahead) {
                case 'M':   match('M');putchar('9');break;
                case 'D':   match('D');putchar('4');break;
                default:    second_d();
          } 
        break;

        case 'D':   match('D'); third_d();break;

        default:    putchar('0');
    }
    return;
}

void fourth_dd(){
    switch(*lookahead){
        case 'M':   match('M');putchar('3');break;
        default:    putchar('2');break;
    }
    return;
}

void fourth_d(){
    switch(*lookahead){
        case 'M':   match('M');fourth_dd();break;
        default:    putchar('1');break;
    }
    return;    
}

void fourth(){
    int i=0;
    switch(*lookahead){
        case 'M':   match('M');fourth_d();break;
        default:    break;
    }
    return;
}

void init(){    
    fourth();third();second();first();
} 

int main(int argc, char **argv){
    
    for (int n=1;n<argc;n++){
        //  loop for all arguments
        lookahead = argv[n];
        init(argv[n]);
    }

    if(*lookahead != '\0') printf("?\nsomething wrong with %c\n",*lookahead);
    return 0;
}