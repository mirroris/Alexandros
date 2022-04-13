#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>


char *lookahead;


void iserror(char c){
    printf("something wrong with %c\n",c);
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
        case 'C':match('C');
    }
    return;
}

void third_dd(){
    switch(*lookahead){
        case 'C':match('C');third_ddd();
    }
    return;
}

void third_d(){
    switch(*lookahead){
        case 'C':   match('C');third_dd();break;
        default:    break;
    }
    return;
}

void third(){
    switch(*lookahead){
        case 'C':   match('C');
            switch (*lookahead) {
                case 'M':   match('M');break;
                case 'D':   match('D');break;
                default:    second_d();
            } 
        break;
        break;

        case 'D':   match('D'); third_d();
    }
    return;
}

void fourth_dd(){
    switch(*lookahead){
        case 'M':   match('M');
        default:    break;
    }
    return;
}

void fourth_d(){
    switch(*lookahead){
        case 'M':   match('M');fourth_dd();
        default:    break;
    }
    return;    
}

void fourth(){
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

    if(*lookahead != '\0') printf("something wrong with %c\n",*lookahead);
    return 0;
}