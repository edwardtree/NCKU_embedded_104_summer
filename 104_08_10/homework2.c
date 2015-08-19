test222222
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LAST_NAME_SIZE 16
#define PHONEBOOK_SIZE 100
#define CACHE_TAG_SIZE 7
#define CACHE_SIZE 4
#define ADDRESS_NUMBER 6

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


typedef struct Direct_Mapped_Cache{
	char index[1];
	int tag;
	char data[MAX_LAST_NAME_SIZE];
	struct Direct_Mapped_Cache *Next;
}Direct_Mapped_Cache;

PhoneBook Create_PhoneBook(void){

	struct PhoneBook *ptr = (struct PhoneBook*)malloc(sizeof(struct PhoneBook ) * PHONEBOOK_SIZE);
	
	int i,j,k=0;
	
	//Constuct a pointer array	
	for( i=0 ; i<sqrt(PHONEBOOK_SIZE) ; i++)
	{
		for( j=0 ; j<sqrt(PHONEBOOK_SIZE)  ; j++ )
		{
			sprintf( (ptr+k ) -> LastName, "N%c%c" ,'a'+ i, 'a'+j) ;
			(ptr+k) -> pNext = NULL;
			k++;
		}
	}
	
	//Connect each array entry
	for( i=0 ; i<PHONEBOOK_SIZE ; i++ )
	{
		if( i != PHONEBOOK_SIZE-1 )
			(ptr+i) -> pNext = ptr+i+1;
	}

	return *ptr;
}

Direct_Mapped_Cache Create_Cache(void){

	struct Direct_Mapped_Cache *ptr = (struct Direct_Mapped_Cache*)malloc(sizeof(struct Direct_Mapped_Cache) * CACHE_SIZE);
	
	int i;
	
	for( i=0 ; i<CACHE_SIZE ; i++)
	{
		sprintf( (ptr+i ) -> index, "%c" ,'0') ;
		(ptr+i) -> Next = NULL;
	}
	
	for( i=0 ; i< CACHE_SIZE ; i++ )
	{
		if( i != CACHE_SIZE-1 )
			(ptr+i) -> Next = ptr+i+1;
	}
	return *ptr;	
}


int main(void)
{
	
	struct PhoneBook *ptr = (struct PhoneBook*)malloc(sizeof(struct PhoneBook ) *PHONEBOOK_SIZE );	
	struct Direct_Mapped_Cache *ptr3 = (struct Direct_Mapped_Cache*)malloc(sizeof(struct Direct_Mapped_Cache)*CACHE_SIZE);
	struct Direct_Mapped_Cache *ptr3_front = (struct Direct_Mapped_Cache*)malloc(sizeof(struct Direct_Mapped_Cache)*CACHE_SIZE);

	FILE *fptr_output;
	fptr_output = fopen("Address.txt","r");	

	int i,j;

	*ptr = Create_PhoneBook();//Default phonebook size is 100. 
	*ptr3 = Create_Cache();// Default Cache size is 4.
	
	ptr3_front  = ptr3;// Record the address of first cache

	int Address_tag, Address_index, Address_byte_offset;// CPU byte address : tage, index, byte offset.
		
	//Testing the number of CPU address 
	for( i = 0 ; i < ADDRESS_NUMBER ; i++ )
	{
		fscanf( fptr_output, "%d %d %d " , &Address_tag, &Address_index, &Address_byte_offset);
		
		/* 106 ~ 110 : record which cache need to detect.*/
		while( Address_index > 0 )
		{
			ptr3 = ptr3 -> Next;
			Address_index--;
		}
		
		printf("index[0] = %c 	tag = %d	Address_tag = %d\n",ptr3->index[0] , ptr3->tag , Address_tag);
			
		/* 113 ~ 118 : Record which phonebook need to replace when cache miss. */
		int point_to_which_phonebook_entry = Address_tag;
		while( point_to_which_phonebook_entry > 0 )
		{
			ptr = ptr -> pNext;	
			point_to_which_phonebook_entry--;	
		}

		if( ptr3->index[0] == '0' )
		{

			printf("Compulsory Miiss\n");
			sprintf( ptr3 -> index, "%c" ,'1');			
			ptr3 -> tag = Address_tag;
			for( j=0 ; j<16 ; j++)
                             ptr3 -> data[j] = ptr -> LastName[j]; 
		}
		else if( (ptr3->index[0] == '1') &&  (ptr3 -> tag  != Address_tag))
		{
			printf("Conflict Miss\n");
			ptr3 -> tag = Address_tag;
			for( j=0 ; j<16 ; j++)
                             ptr3 -> data[j] = ptr -> LastName[j]; 
		}
		else
		{
			printf("Cache Hit\n");
		}
	
		ptr3 = ptr3_front;		
	}
	
	fclose(fptr_output);		
	
	return 0 ;
	
}
