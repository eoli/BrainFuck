#include <stdio.h>
#include <stdlib.h>

#define MAX 5000

int p,q;/* arr_pointer, mem_pointer*/

char mem[MAX];/*code memory*/
char arr[MAX];/*machine memory*/
char b,c;

void interpret(char *mem)
{
	while((c=mem[q++])&&q<MAX){
		switch(c){
			case '>': 	p++;									break;
			case '<':	p--;									break;
			case '+':	arr[p]++;								break;
			case '-':	arr[p]--;								break;
			case '.':	putchar(arr[p]);fflush(stdout);			break;
			case ',':  	arr[p]=getchar();						break;
			case '[':	if(!arr[p]){while(mem[q++]!=']');} 		break;
			case ']': 	while(mem[--q]!='['&&q>=0);				break;
			case '#':  	printf("\nHATL\n");exit(0);				break;
			default :	printf("\nError code:%c\n",c);exit(1);	break;
		}
	}


}

int main(int argc, char *argv[])
{	
	FILE *code;
	int i=0;


	if(argc!=2){	
		printf("Usage: bf code\n");
		exit(0);
	}

	
	code = fopen(argv[1],"r");	
	while((b=getc(code))>0)
		/*ignore chars*/
		if(b!=' '   &&\
		   b!='\n'  &&\
 		   b!='\t')
						mem[i++]=b;

	interpret(mem);
	printf("\n");

	return 0;
}
