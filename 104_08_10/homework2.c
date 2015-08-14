#include <stdio.h>
#include <stdlib.h>

#define MAX_LAST_NAME_SIZE 16

typedef struct PhoneBook{
    char LastName[MAX_LAST_NAME_SIZE];
    char FirstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct PhoneBook *pNext;
} PhoneBook;

PhoneBook FindName(char Last[], PhoneBook *pHead) {
    
    int i,j,k;
    
    while (pHead != NULL) {
        if (strcmp(Last, pHead->LastName) == 0) 
	{
    		int k;
		for( k=0 ; k<16 ; k++ )
		printf("%c\n", pHead->LastName[k]);      				
		
		return *pHead;
        }
	pHead = pHead->pNext;
    }
	
   struct PhoneBook *ptr3 = (struct PhoneBook*)malloc(sizeof(struct PhoneBook ));
   
   sprintf( ptr3 -> LastName, "Nothing find") ; 
     
    return *ptr3;
}

int main(void)
{
	
	struct PhoneBook *ptr = (struct PhoneBook*)malloc(sizeof(struct PhoneBook ) * 10);
	
	int i,j;
	
	struct PhoneBook *ptr1 = (struct PhoneBook*)malloc(sizeof(struct PhoneBook ));
	struct PhoneBook *ptr2 = (struct PhoneBook*)malloc(sizeof(struct PhoneBook ));
	
	sprintf( ptr1 -> LastName, "aa") ; 

	
	//先建立一個一維指標陣列	
	for( i=0 ; i<10 ; i++)
	{
		sprintf( (ptr+i) -> LastName, "N%c" ,'a'+ i) ;
		(ptr+i) -> pNext = NULL;
	}
	
	//把陣列裡面的每個entry串連起來
	for( i=0 ; i<10 ; i++ )
	{
		if( i != 9 )
			(ptr+i) -> pNext = ptr+i+1;
	}	
	
	*ptr2 = FindName( ptr1 -> LastName ,ptr );			
	
	
	for( j=0 ; j<16 ; j++)
		printf("%c ", ptr2 -> LastName[j]);
	/*		
	//印出	
	while( ptr != NULL )
	{ 
		for( j=0 ; j<16 ; j++)
		printf("%c ", ptr -> LastName[j]);
		printf("\n");
		ptr = ptr -> pNext;
	}
	*/
	return 0 ;
	
}
