#include "contact.h"
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"*/

int isnamevalid(const char *str)
{
    while (*str)
    {
        if (!isalpha(*str) && *str != ' ')
        {
            return 0; // Not an alphabetic string
        }
        str++;
    }
    return 1;
}

/*int isemailvalid(const char *str)
{
    int flag = 0;
    while (*str)
    {
        if (*str == '@')
        {
            flag = 1;
            if (!isalpha(*(str - 1)))
            {
                return 0;
            }
        }
        str++;
    }
    if (flag == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}*/


int isemailvalid(const char *str)
{
    int flag = 0,i=0,alnum_flag=0;
    int k=0,j=0;
    int com_flag=0;
    char arr[3] = {'c', 'o', 'm'};
    while (str[i]!='\0')
    {
        if (str[i] == '@')
        {   
            flag=1;
            for(k=0;k<i;k++)
            {   
                if(!isalnum(str[k]) && str[k]!='.')
                {
                   return 0;
                }
                else if(isalnum(str[k]))
                {
                    alnum_flag=1;
                }
            }
        }
        if(str[i]=='.' && str[i+4]=='\0')
        {   
            for(j=k+1;j<i;j++)
            {   
                if(!isalpha(str[j]))
                {
                   return 0;
                }
                else if(isalpha)
                {
                   com_flag=1;
                }
            }
            for (j = 0; j < 3; j++)
                {
                    if (str[i+j+1] == arr[j])
                    {
                        flag++;
                    }
                }
        }
        i++;
        //str++;
    }
    if (flag == 4 && alnum_flag==1 && com_flag==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int ismobvalid(const char *str)
{
    int i = 0;
    while (*str)
    {
        if (!isdigit(*str))
        {
            return 0;
        }
        i++;
        str++;
    }
    if (i == 10)
        return 1;
}

int searchByName(AddressBook *addressBook,int func)
{
    char name[50];
    int flag = 0,num;
    int count_flag=0;
    int count = addressBook->contactCount;
    scout_name:
    printf("Enter the name:\n");
    scanf(" %[^\n]", name);
    if(!isnamevalid(name))
    {
       printf("Invalid Input...Enter a valid name!\n");
       goto scout_name;
    }

    for (int i = 0; i < count; i++)
    {
        if (strcmp(addressBook->contacts[i].name, name) == 0)
        {
            flag = 1;
            if(count_flag==0)
            {
                printf("Details Found:\n");
                printf("..........................\n");
            }
            count_flag++;
            printf("..........................\n");
            printf("Entry No: %d\n", i + 1);
            printf("Name:%s\n", addressBook->contacts[i].name);
            printf("Phone No:%s\n", addressBook->contacts[i].phone);
            printf("Email ID:%s\n", addressBook->contacts[i].email);
            printf("..........................\n");
            printf("\n");
            //return i;
            num=i;
        }
    }
    if(count_flag>1 && func==1)
    {
        printf("%d contacts found with same name.\nSearch with Phone No...\n",count_flag);
        return searchByPhone(addressBook);
    }
    else if(count_flag!=0)
    {
        return num;
    }
    if (flag == 0)
    {
        printf("Name not found!\n");
        return -1;
    }
}

int searchByMail(AddressBook *addressBook)
{
    char mail[50];
    int flag = 0;
    int count = addressBook->contactCount;
    scout_mail:
    printf("Enter the email:\n");
    scanf(" %[^\n]", mail);
    if(!isemailvalid(mail))
    {
       printf("Invalid Input...Enter a valid email!\n");
       goto scout_mail;
    }

    for (int i = 0; i < count; i++)
    {
        if (strcmp(addressBook->contacts[i].email, mail) == 0)
        {
            flag = 1;
            printf("Details Found:\n");
            printf("..........................\n");
            printf("..........................\n");
            printf("Entry No: %d\n", i + 1);
            printf("Name:%s\n", addressBook->contacts[i].name);
            printf("Phone No:%s\n", addressBook->contacts[i].phone);
            printf("Email ID:%s\n", addressBook->contacts[i].email);
            printf("..........................\n");
            printf("\n");
            return i;
        }
    }
    if (flag == 0)
    {
        printf("Email not found!\n");
        return -1;
    }
}

int searchByPhone(AddressBook *addressBook)
{
    char phone[50];
    int flag = 0;
    int count = addressBook->contactCount;
    scout_ph:
    printf("Enter the phone no:\n");
    scanf(" %[^\n]", phone);
    if(!ismobvalid(phone))
    {
       printf("Invalid Input...Enter a valid phone no!\n");
       goto scout_ph;
    }

    for (int i = 0; i < count; i++)
    {
        if (strcmp(addressBook->contacts[i].phone, phone) == 0)
        {
            flag = 1;
            printf("Details Found:\n");
            printf("..........................\n");
            printf("..........................\n");
            printf("Entry No: %d\n", i + 1);
            printf("Name:%s\n", addressBook->contacts[i].name);
            printf("Phone No:%s\n", addressBook->contacts[i].phone);
            printf("Email ID:%s\n", addressBook->contacts[i].email);
            printf("..........................\n");
            printf("\n");
            return i;
        }
    }
    if (flag == 0)
    {
        printf("Phone No not found!\n");
        return -1;
    }
}

void editByName(AddressBook *addressBook, int entry)
{
    char name[50];
    int flag = 0;
name:
    printf("Enter the name:\n");
    scanf(" %[^\n]", name);
    if (isnamevalid(name))
    {
        
        if(1)
        {
          strcpy(addressBook->contacts[entry].name, name);
          printf("Contact Edited Successfully!");
        }
        else
        {   
            printf("This Name is already present...Enter a unique Name\n");
            goto name;
        }
    }
    else
    {
        printf("Invalid name!\n");
        goto name;
    }
}

void editByPhone(AddressBook *addressBook, int entry)
{
    char ph[50];
    int flag = 0;
phone:
    printf("Enter the Phone No:\n");
    scanf(" %[^\n]", ph);
    if (ismobvalid(ph))
    {
        
        if(isunique(addressBook,ph,2))
        {
          strcpy(addressBook->contacts[entry].phone, ph);
          printf("Contact Edited Successfully!");
        }
        else
        {   
            printf("This Phone No is already present...Enter a unique Phone No\n");
            goto phone;
        }
        
    }
    else
    {
        printf("Invalid mobile no!\n");
        goto phone;
    }

    // strcpy(addressBook->contacts[entry].phone,ph);
}

void editByMail(AddressBook *addressBook, int entry)
{
    char email[50];
mail:
    printf("Enter the email:\n");
    scanf(" %[^\n]", email);
    if (isemailvalid(email))
    {
        strcpy(addressBook->contacts[entry].email, email);
        if(isunique(addressBook,email,3))
        {
          strcpy(addressBook->contacts[entry].email, email);
          printf("Contact Edited Successfully!");
        }
        else
        {   
            printf("This Email ID is already present...Enter a unique Email ID\n");
            goto mail;
        }
    }
    else
    {
        printf("Invalid Mail!\n");
        goto mail;
    }
}

int isunique(AddressBook *addressbook, const char *str, int ch)
{
    int i, count = addressbook->contactCount;
    switch (ch)
    {
    case 1:
        for (i = 0; i < count; i++)
        {
            if (strcmp(addressbook->contacts[i].name, str) == 0)
            {
                return 0;
            }
        }
        return 1;
    case 2:
        for (i = 0; i < count; i++)
        {
            if (strcmp(addressbook->contacts[i].phone, str) == 0)
            {
                return 0;
            }
        }
        return 1;
    case 3:
        for (i = 0; i < count; i++)
        {
            if (strcmp(addressbook->contacts[i].email, str) == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}