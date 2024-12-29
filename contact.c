/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>*/
#include "contact.h"
#include "file.h"
// #include "populate.h"
// #include "utils.c"

// void listContacts(AddressBook *addressBook, int sortCriteria)
void listContacts(AddressBook *addressBook)
{
    // Sort contacts based on the chosen criteria
    int count = addressBook->contactCount;
    if (count != 0)
    {

        printf("Listing Contacts:\n");
        printf("..........................\n");

        int i;
        for (i = 0; i < count; i++)
        {
            printf("..........................\n");
            printf("Entry No: %d\n", i + 1);
            printf("Name:%s\n", addressBook->contacts[i].name);
            printf("Phone No:%s\n", addressBook->contacts[i].phone);
            printf("Phone No:%s\n", addressBook->contacts[i].email);
            printf("..........................\n");
            printf("\n");
        }
    }
    else
    {
        printf("No entries as of now!\n");
    }
}

void initialize(AddressBook *addressBook)
{
    // addressBook->contactCount = 0;
    loadContactsFromFile(addressBook);

    // Load contacts from file during initialization (After files)
    // loadContactsFromFile(addressBook);
}

/*void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}*/

void createContact(AddressBook *addressBook)
{
/* Define the logic to create a Contacts */
// char name[50];
// static int count=0;
name:
    printf("Enter the name:");

    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);
    // scanf("%s",addressBook->contacts[addressBook->contactCount].name);
    // getchar();
    if (isnamevalid(addressBook->contacts[addressBook->contactCount].name))
    {
        if (addressBook, addressBook->contacts[addressBook->contactCount].name)
        {
            goto ph;
        }
        else
        {
            printf("This Name is already present...Enter a unique Name\n");
            goto name;
        }
    }
    else
    {
        printf("Enter a valid name!\n");
        goto name;
    }
ph:
    printf("Enter mobile no:");
    scanf("%s", addressBook->contacts[addressBook->contactCount].phone);
    // fgets(addressBook->contacts[addressBook->contactCount].phone,20,stdin);
    if (ismobvalid(addressBook->contacts[addressBook->contactCount].phone))
    {
        if (isunique(addressBook, addressBook->contacts[addressBook->contactCount].phone, 2))
        {
            goto mail;
        }
        else
        {
            printf("This Phone No is already present...Enter a unique Phone No\n");
            goto ph;
        }
    }
    else
    {
        printf("Enter a valid mobile no\n");
        goto ph;
    }

    // count++;

mail:
    printf("Enter your email Id:");
    scanf("%s", addressBook->contacts[addressBook->contactCount].email);
    if (isemailvalid(addressBook->contacts[addressBook->contactCount].email))
    {

        if (isunique(addressBook, addressBook->contacts[addressBook->contactCount].email, 3))
        {
            printf("New Entry Created\n");
        }
        else
        {
            printf("This Email ID is already present...Enter a unique Email ID\n");
            goto mail;
        }
        // printf("The name is %s,mobile no is %s and email is %s\n",addressBook->contacts[addressBook->contactCount].name,addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[addressBook->contactCount].email);
    }
    else
    {
        printf("Enter a valid email\n");
        goto mail;
    }

    addressBook->contactCount += 1;
}

int searchContact(AddressBook *addressBook, int func)
{
    /* Define the logic for search */
    int choice;
    printf("Search Menu:\n");
    printf("1. Search by Name\n");
    printf("2. Search by mobile no\n");
    printf("3. Search by Email Id\n");
    printf("4. Exit\n");
scan:
    printf("Enter your choice: ");
    // scanf("%d", &choice);
    int ret = scanf("%d", &choice);
    if (ret == 0)
    {
        // printf("")
        while (getchar() != '\n')
            ;
        goto scan;
    }

    switch (choice)
    {
    case 1:
        return searchByName(addressBook, func);
        break;
    case 2:
        return searchByPhone(addressBook);
        break;
    case 3:
        return searchByMail(addressBook);
        break;
    case 4:
        printf("Exiting without Searching...\n");
        return -1;
        break;
    default:
        printf("Invalid Input....Exiting Search\n");
        return -1;
        break;
    }
}

void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
    int entry, choice;
    int count = addressBook->contactCount;

    // searchContact(addressBook);
    if (count > 0)
    {
        printf("Search the Contact to Edit:\n");
        entry = searchContact(addressBook, 1);
        // listContacts(addressBook);
        // printf("Enter the entry No to edit:");
        // scanf("%d", &entry);
        // entry = entry - 1;
        if (entry != -1)
        {
            // entry=num;
            // printf("Entry is %d\n", entry);
            printf("Edit Menu:\n");
            printf("1. Edit by Name\n");
            printf("2. Edit by mobile no\n");
            printf("3. Edit by Email Id\n");
            printf("4. Exit\n");
            scan1:
            printf("Enter your choice: ");
            //scanf("%d", &choice);
            int ret = scanf("%d", &choice);
            if (ret == 0)
            {
                printf("Invalid Choice...Enter Again\n");
                while(getchar() != '\n');
                goto scan1;
            }
            switch (choice)
            {
            case 1:
                editByName(addressBook, entry);
                break;
            case 2:
                editByPhone(addressBook, entry);
                break;
            case 3:
                editByMail(addressBook, entry);
                break;
            case 4:
                printf("Exiting without Editing...\n");
                break;
            default:
                printf("Invalid Input....Exiting Edit\n");
                break;
            }
        }
        else
        {
            printf("Exiting Edit....\n");
        }
    }
    else
    {
        printf("No entries to edit!\n");
    }
}

void deleteContact(AddressBook *addressBook)
{
    /* Define the logic for deletecontact */
    int count = addressBook->contactCount;
    int entry;

    if (count > 0)
    {
        printf("Search the Contact to delete:\n");
        entry = searchContact(addressBook, 1);
        // listContacts(addressBook);
        // printf("Enter the entry No to delete:");
        // scanf("%d", &entry);
        // entry = entry - 1;
        if (entry != -1)
        {
            for (int i = entry; i < count; i++)
            {
                if (entry == count - 1)
                {
                    addressBook->contactCount -= 1;
                    break;
                }
                else if (i + 1 != count)
                {
                    // strcpy(addressBook->contacts[i],addressBook->contacts[i+1]);
                    addressBook->contacts[i] = addressBook->contacts[i + 1];
                }
            }
            if (addressBook->contactCount == count)
            {
                addressBook->contactCount -= 1;
            }
            printf("Contact deleted Successfully!");
        }
        else
        {
            printf("Exiting Delete....\n");
        }
    }
    else
    {
        printf("No Entries to delete!");
    }
}
