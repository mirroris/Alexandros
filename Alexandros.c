#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

char *lookahead;
int dig4=0;
int dig3=0;
int dig2=0;
int dig1=0;
int num;

void iserror(char c){
    printf("?(perhaps not roman numerals)\nsomething wrong with %c\n",c);
    exit(1);
}

void match(const char t){
    if(*lookahead == t) lookahead++; 
    else iserror(*lookahead);
    return;
}

void first_ddd(){
    switch(*lookahead){
        case 'I':match('I');dig1++;
    }
    return;
}

void first_dd(){
    switch(*lookahead){
        case 'I':match('I');dig1++;first_ddd();
    }
    return;
}

void first_d(){
    switch(*lookahead){
        case 'I':   match('I');dig1++;first_dd();break;
        default:    break;
    }
    return;
}

void first(){
    dig1=0;
    switch(*lookahead){
        case 'I':   match('I');dig1++;
            switch (*lookahead) {
                case 'X':   match('X');dig1=9;break;
                case 'V':   match('V');dig1=4;break;
                default:    first_dd();
            } 
        
        break;

        case 'V':   match('V');dig1+=5; first_d();
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
        case 'X':match('X');dig2++;second_ddd();
    }
    return;
}

void second_d(){
    switch(*lookahead){
        case 'X':   match('X');dig2++;second_dd();break;
        default:    break;
    }
    return;
}

void second(){
    dig2=0;
    switch(*lookahead){
        case 'X':   match('X');dig2++;
            switch (*lookahead) {
                case 'C':   match('C');dig2=9;break;
                case 'L':   match('L');dig2=4;break;
                default:    second_dd();
            } 
        break;

        case 'L':   match('L'); dig2+=5;second_d();
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
        case 'C':   match('C');dig3++;third_ddd();break;
        default:    break;
    }
    return;
}

void third_d(){
    switch(*lookahead){
        case 'C':   match('C');dig3++;third_dd();break;
        default:    break;
    }
    return;
}

void third(){
    dig3=0;
    switch(*lookahead){
        case 'C':   match('C');
            switch (*lookahead) {
                case 'M':   match('M');dig3=9;break;
                case 'D':   match('D');dig3=4;break;
                default:    dig3++;third_dd();
          } 
        break;

        case 'D':   match('D');dig3+=5; third_d();break;

        default:    ;
    }
    return;
}

void fourth_dd(){
    switch(*lookahead){
        case 'M':   match('M');dig4++;break;
        default:    break;
    }
    return;
}

void fourth_d(){
    switch(*lookahead){
        case 'M':   match('M');dig4++;fourth_dd();break;
        default:    break;
    }
    return;    
}

void fourth(){
    dig4=0;
    switch(*lookahead){
        case 'M':   match('M');dig4++;fourth_d();break;
        default:    break;
    }
    return;
}

void init(){    
    fourth();third();second();first();
    num = ((dig4*10+dig3)*10+dig2)*10+dig1;
    printf(" --> %d\n",num);
} 

int main(int argc, char **argv){
    
    if(argc!=1){
        for (int n=1;n<argc;n++){
            //  loop for all arguments
            lookahead = argv[n];
            init(argv[n]);
                    
            /* if wrong numver stop this program */
            if(*lookahead != '\0') printf("?\nsomething wrong with %c\n",*lookahead);
            return 0;
        }
    }

    char buf[10]="hello\n";
    int buflen=0;
    if(argc==1){

        printf("This program is published by @mirroris!\nThis scheme translate Roman numeral into Arabian one.\n");

        while (1){
            while(fgets(buf,10,stdin)!=NULL){
                lookahead = buf;
                init(buf);

                if(*lookahead != '\n') printf("?(perhaps not roman numerals)\nsomething wrong with %c\n",*lookahead);
            }
        }
        return 0;
    }
}