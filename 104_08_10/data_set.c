#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    FILE *fptr;
    fptr = fopen("Address.txt","w");
    int i,j;
    	
    srand(time(NULL));
    for(i=0; i<1000; ++i)
    {
	j = rand();
	fprintf(fptr,"%d\t\t",j%100);    
	fprintf(fptr,"%d\t\t", j%4);
	fprintf(fptr, "%d\n",rand()%8);
    }
    fclose(fptr);
 return 0;
}
