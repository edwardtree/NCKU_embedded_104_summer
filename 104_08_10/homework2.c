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
    	
		return *pHead;
        }
	pHead = pHead->pNext;
    }
	
   struct PhoneBook *ptr3 = (struct PhoneBook*)malloc(sizeof(struct PhoneBook ));
   
   sprintf( ptr3 -> LastName, "Nothing find") ; 
     
    return *ptr3;
}

PhoneBook Create_PhoneBook(void){

	struct PhoneBook *ptr = (struct PhoneBook*)malloc(sizeof(struct PhoneBook ) * 100);
	
	int i,j,k=0;
	
	//先建立一個一維指標陣列	
	for( i=0 ; i<10 ; i++)
	{
		for( j=0 ; j<10 ; j++ )
		{
			sprintf( (ptr+k ) -> LastName, "N%c%c" ,'a'+ i, 'a'+j) ;
			(ptr+k) -> pNext = NULL;
			k++;
		}
	}
	
	//把陣列裡面的每個entry串連起來
	for( i=0 ; i<100 ; i++ )
	{
		if( i != 99 )
			(ptr+i) -> pNext = ptr+i+1;
	}

return *ptr;
}




int main(void)
{
	
	struct PhoneBook *ptr = (struct PhoneBook*)malloc(sizeof(struct PhoneBook ) * 100);	
	struct PhoneBook *ptr1 = (struct PhoneBook*)malloc(sizeof(struct PhoneBook ));
	struct PhoneBook *ptr2 = (struct PhoneBook*)malloc(sizeof(struct PhoneBook ));
	
	int i,j;

	*ptr = Create_PhoneBook();//Default 
	
	sprintf( ptr1 -> LastName, "Nea");
	
	*ptr2 = FindName( ptr1 -> LastName ,ptr );			
	
		
	for( j=0 ; j<16 ; j++)
		printf("%c\n", ptr2 -> LastName[j]);
	
	return 0 ;
	
}
