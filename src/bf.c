#include <stdio.h>
#include <stdlib.h>

#define MAX (1024*64)

#define DEBUG
#undef DEBUG


int pd = 0;	// data_pointer
int pc = 0; // mem_pointer
char code[MAX]; // code memory
char data[MAX]; // machine memory
char b,c;

#define BF_FETCH(pc) do{ \
		c = code[pc]; \
		pc++; \
}while(0);

#define BF_DISPATCH(c) switch(c)
#define BF_CASE(c) case c


void interpreter(char *code)
{
    for(;;){
        BF_FETCH(pc);
        #ifdef DEBUG
        printf("%d %c\r\n", c, c);
        #endif
        if(c==0 || pc>=MAX){break;}

        BF_DISPATCH(c){
            BF_CASE('>'): {
                pd++; 
            break;}
            BF_CASE('<'): {
                pd--;
            break;}
            BF_CASE('+'): {
                data[pd]++;
            break;}
            BF_CASE('-'): {
                data[pd]--;
            break;}
            BF_CASE('.'): {
                putchar(data[pd]);
                fflush(stdout);
            break;}
            BF_CASE(','): {
                data[pd]=getchar(); 
            break;}
            BF_CASE('['): {
                #ifdef DEBUG
                printf("DEBUG");
                #endif
                int pair = 0;
                char cl = 0;
                if(data[pd]==0){
                    // skip current loop
                    while(cl=code[pc++]){
                        if(pc>MAX){
                            printf("error pc pointer\r\n");
                            exit(-1);
                        }

                        if(cl==']'){
                            if(pair==0){
                                break;
                            }else{
                                pair--;
                            }
                        }else if(cl=='['){
                            pair++;
                        }
                    }
                }
            break;}
            BF_CASE(']'): {
                int pair = 0;
                char cl = 0;

                #ifdef DEBUG
                printf("CASE ] pc=%d pair=%d", pc, pair);
                #endif
                --pc;
                while(cl=code[--pc]){
                    #ifdef DEBUG
                    printf("-pc=%d pair=%d %c\r\n", pc, pair, cl);
                    #endif
                    if(pc<0){
                        printf("error pc pointer\r\n");
                        exit(-1);
                    }

                    if(cl=='['){
                        if(pair==0){
                            break;
                        }else{
                            pair--;
                        }
                    }else if(cl==']'){
                        pair++;
                    }
                }
            break;} 
            default: {
                printf("\nError code:%c (%d)\n",c, c);exit(1);
            break;} 
        }
    }
}

int main(int argc, char *argv[])
{    
    FILE *f;
    int i=0;

    if(argc!=2){    
        printf("Usage: %s code\n", argv[0]);
        exit(0);
    }

    for(int i=0; i<MAX; i++){
        data[i]=0;
        code[i]=0;
    }

    f = fopen(argv[1],"r");    
    while( (b=getc(f)) > 0 ){
        if(i>MAX){
            printf("[Error] index %d out of range\r\n", i);
            exit(-1);
        }
        if( b==' ' ||  b=='\n' || b=='\t' ){
			continue;
		}else{
            code[i++]=b;
		}
    }
    fclose(f);

    interpreter(code);

    return 0;
}
