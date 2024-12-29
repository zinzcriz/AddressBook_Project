#include "file.h"
#include "contact.h"
void saveContactsToFile(AddressBook *addressBook) {
    FILE *fptr;
    if((fptr=fopen("contacts.csv","w"))==NULL)
    {   
        printf("File Opening not successfull!...\n");
        return;
    }
    /*if (fwrite(addressBook, sizeof(*addressBook), 1, fptr) != 1) {
        printf("Error writing to file.\n");
    }*/
    //fwrite(addressBook,sizeof(*addressBook),1,fptr);
    int count=addressBook->contactCount;
    fprintf(fptr,"#%d\n",addressBook->contactCount);
    for(int i=0;i<count;i++)
    {
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    //rewind(fptr);
    fclose(fptr);
  
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fptr;
    
    if((fptr=fopen("contacts.csv","rb"))==NULL)
    {   
        printf("File Opening not successfull!...\n");
        return;
    }
    /*if (fread(addressBook, sizeof(*addressBook), 1, fptr) != 1) {
        printf("Error reading from file.\n");
    }*/
    //fwrite(addressBook->contactCount,sizeof((addressBook->contactCount)),1,fptr);
    //fread(addressBook->contactCount,sizeof(*(addressBook->contactCount)),1,fptr);
    //rewind(fptr);
    fscanf(fptr,"#%d\n",&addressBook->contactCount);
    int count=addressBook->contactCount;
    //printf("%d\n",count);
    for(int i=0;i<count;i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    //fread(addressBook,sizeof(*addressBook),1,fptr);
    //rewind(fptr);
    fclose(fptr);
    
}
