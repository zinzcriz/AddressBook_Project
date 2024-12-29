#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdio_ext.h>
#define MAX_CONTACTS 100
//extern int num;
//FILE *fptr;
typedef struct {
    char name[50]; 
    char phone[20];
    char email[50];
} Contact; 

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;


/*void saveContactsToFile(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook);
*/
void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook,int func);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
int isnamevalid(const char *str);
int isemailvalid(const char *str);
int ismobvalid(const char *str);
int isunique(AddressBook *addressbook,const char *str,int ch);

int searchByName(AddressBook *addressBook,int func);
int searchByMail(AddressBook *addressBook);
int searchByPhone(AddressBook *addressBook);
//void saveContactsToFile(AddressBook *AddressBook);

void editByName(AddressBook *addressBook,int entry);
void editByPhone(AddressBook *addressBook,int entry);
void editByMail(AddressBook *addressBook,int entry);



#endif
