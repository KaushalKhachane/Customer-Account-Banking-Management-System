#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void menu();
void new_ac();
void modify_account();
void transaction();
void del_account(void);
void list();
void search();
void delay(int);

struct date
{
    int month, day, year;
};

struct node
{
    int ac_num, age;
    char name[20];
    char address[40];
    char actype[20];
    int phone;
    float amt;
    struct date deposit;
    struct date dob;
    struct node *next;
};

struct node *start = NULL;

int main()
{
    char pass[11], password[11] = "dsuproject";
    int i = 0;
    int main_exit;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s", pass);

    if (strcmp(pass, password) == 0)
    {
        printf("\n\nPassword Match!\nLOADING");
        for (i = 0; i <= 3; i++)
        {
            delay(1);
            printf(".");
        }
        system("cls");
        menu();
    }
    else
    {
        printf("\n\nWrong password!!\a\a\a");
    add_invalid:
        printf("\nEnter 1 to try again and 0 to exit:");
        scanf("%d", &main_exit);
        if (main_exit == 1)
        {

            system("cls");
            main();
        }

        else if (main_exit == 0)
        {
            system("cls");
            exit(0);
        }
        else
        {
            printf("\nInvalid!");
            delay(1);
            system("cls");
            goto add_invalid;
        }
    }
    return 0;
    while (1)
    {
        menu();
    }
}

// Function To Add Record Into Bank
void new_ac()
{
    system("cls");
    printf("\n\n\n\t\t\t\t ADD RECORD \n");
    struct node *newnode, *ptr;
    ptr = start;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\n\t\t\t     Enter today's date (dd mm yyyy):");
    scanf("%d%d%d", &newnode->deposit.day, &newnode->deposit.month, &newnode->deposit.year);
    printf("\t\t\t     Enter account number: ");
    scanf("%d", &newnode->ac_num);
    printf("\t\t\t     Enter Name: ");
    scanf("%s", &newnode->name);
    printf("\t\t\t     Enter the date of birth (dd mm yyyy):");
    scanf("%d%d%d", &newnode->dob.day, &newnode->dob.month, &newnode->dob.year);
    printf("\t\t\t     Enter the phone Number: ");
    scanf("%d", &newnode->phone);
    printf("\t\t\t     Enter the Address: ");
    scanf("%s", &newnode->address);
    printf("\t\t\t     Enter the amount to deposit:$");
    scanf("%f", &newnode->amt);
    printf("\t\t\t     Type of account:\n\t\t\t     #Saving\n\t\t\t     #Current\n\t\t\t     #Fixed1(for 1 year)\n\t\t\t     #Fixed2(for 2 years)\n\t\t\t     #Fixed3(for 3 years)\n\t\t\t     Enter your choice:");
    scanf("%s", &newnode->actype);

    if (start == NULL)
    {
        newnode->next = NULL;
        start = newnode;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = NULL;
    }
}

// Function To Modify Account Details
void modify_account()
{
    system("cls");
    printf("\n\t\t MODIFY RECORD ");
    list();
    struct node *ptr;

    int record, flag = 0, ch;

    if (start == NULL)
    {
        printf("\n\tTheir is No Bank Account To Modify!!!");
    }
    else
    {
        printf("\n\tEnter Account No.. To Modify: ");
        scanf("%d", &record);

        ptr = start;

        while (ptr != NULL)
        {
            if (ptr->ac_num == record)
            {
                printf("\n\t1 - To Change Name\n");
                printf("\t2 - To Change Address\n");
                printf("\n\tEnter your choice: ");
                scanf("%d", &ch);

                switch (ch)
                {
                case 1:
                    printf("\tEnter New Name: ");
                    scanf("%s", &ptr->name);
                    flag = 1;
                    printf("\n\t\tName Updated to %s", ptr->name);
                    break;
                case 2:
                    printf("\tEnter New Address: ");
                    scanf("%s", &ptr->address);
                    flag = 1;
                    printf("\n\t\tAddress Updated to %s", ptr->address);
                    break;
                default:
                    printf("\tEnter Valid Details!!!\n");
                    break;
                }
            }
            else
            {
                ptr = ptr->next;
            }
            if (flag == 1)
            {
                break;
            }
        }
        if(flag==0)
        {
            printf("\n\tEnter valid Bank Account No!!!");
            delay(2);
            modify_account();
        }
    }
}

// Function To Manage Transaction
void transaction()
{
    system("cls");
    printf("\n\n\n\t\tMANAGE TRANSACTION\n");
    list();
    struct node *ptr;
    int ac, ch, flag = 0;
    float w, d;

    if (start == NULL)
    {
        printf("Their is no bank Account!!!");
    }
    else
    {
        printf("Enter Account No.. For transaction: ");
        scanf("%d", &ac);
        ptr = start;
        while (ptr != NULL)
        {
            if (ptr->ac_num == ac)
            {
                printf("\n\t1.Withdrawal\n\t2.Deposite\n");
                printf("\n\tEnter your choice: ");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                    printf("\n\tTotal Balance in %d Account before Withdrawal = %f", ptr->ac_num, ptr->amt);
                    printf("\n\tEnter Amount to withdrawal: ");
                    scanf("%f", &w);
                    ptr->amt = ptr->amt - w;
                    printf("\n\tTotal Balance in %d Account after Withdrawal = %f", ptr->ac_num, ptr->amt);
                    flag = 1;
                    break;
                case 2:
                    printf("\tTotal Balance in %d Account before Deposite = %f", ptr->ac_num, ptr->amt);
                    printf("\n\tEnter Amount to Deposite: ");
                    scanf("%f", &d);
                    ptr->amt = ptr->amt + d;
                    printf("\nTotal Balance in %d Account after Deposite = %f", ptr->ac_num, ptr->amt);
                    flag = 1;
                    break;
                default:
                    printf("\n\tEnter proper choice!!");
                    break;
                }
            }
            else
            {
                ptr = ptr->next;
            }
            if (flag == 1)
            {
                break;
            }
        }
         if(flag==0)
            {
                printf("\n\tEnter valid Bank Account No!!!");
                delay(2);
                transaction();
            }
    }
}

// Function To Display All Records
void list() //display record in bank
{
    struct node *ptr;
    ptr = start;

    if (start == NULL)
    {
        printf("\n\tTheir is no acccount to display!!!");
    }
    else
    {
        printf("\n\nAccountNo\tName\tBank Balance\tAccount type\n");
        printf("-------------------------------------------------------\n");
        do
        {
            printf("%-15d", ptr->ac_num);
            printf("%-10s", ptr->name);
            printf(" %-17f", ptr->amt);
            printf(" %-10s\n", ptr->actype);
            ptr = ptr->next;
        } while (ptr != NULL); //end of do-while
        printf("-------------------------------------------------------\n");
    }
} //end of list fun

// Function To Delete Record From Bank
void del_account(void) //DELETE ACCOUNT FUNCTION
{
    system("cls");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DELETE RECORD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    list();
    int record, flag = 0;
    struct node *previous, *ptr;

    if (start == NULL)
    {
        printf("\n\tTheir is No Account!!!");
        return;
    }

    printf("\n\tEnter Account number to delete: ");
    scanf("%d", &record);

    ptr = start;

    while (ptr != NULL)
    {
        if (ptr->ac_num == record)
        {
            if (ptr == start)
            {
                start = ptr->next;
            }
            else
            {
                previous->next = ptr->next;
            }
            free(ptr);
            flag = 1;
            printf("\n\t%s Account Removed From Bank!!!", ptr->name);
            return;
        }
        else
        {
            previous = ptr;
            ptr = ptr->next;
        }

        if (flag == 1)
        {
            break;
        }
    }
    if(flag==0)
        {
            printf("\n\tEnter valid Bank Account No!!!");
            delay(2);
            del_account();
        }
} // end of delete function

//Function To Search Existing Account
void search()
{
    system("cls");

    printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SEARCH RECORD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    struct node *ptr;
    int record, flag = 0;

    if (start == NULL)
    {
        printf("Their is no Account");
    }
    else
    {
        printf("Enter Account Number Which Details you Want to display: ");
        scanf("%d", &record);

        ptr = start;
        while (ptr != NULL)
        {
            if (ptr->ac_num == record)
            {
                printf("\n\t\tACCOUNT DETAILS\n\n");
                printf("\n----------------------------------------------\n");
                printf("\nAccount No: %d", ptr->ac_num);
                printf("\nName: %s", ptr->name);
                printf("\nPhone No: %d", ptr->phone);
                printf("\nAddress: %s", ptr->address);
                printf("\nCreated on (mm dd yyyy): %d %d %d", ptr->deposit.day, ptr->deposit.month, ptr->deposit.year);
                printf("\nDOB (mm dd yyyy): %d %d %d", ptr->dob.day, ptr->dob.month, ptr->dob.year);
                printf("\nBank Balance: %f", ptr->amt);
                printf("\nAccount Type: %s\n", ptr->actype);
                printf("----------------------------------------------");
                flag = 1;
                break;
            }
            else
            {
                ptr = ptr->next;
            }
            if (flag == 1)
            {
                break;
            }
        }
         if(flag==0)
            {
                printf("\n\tEnter valid Bank Account No!!!");
                delay(2);
                search();
            }
    }
} //end of search function

void menu() //Driven function
{
    int ch, key = 0, main_exit;

    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t   \xB2\xB2\xB2\xB2\xB2\xB2\xB2  WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t     ===============================");
    printf("\n\t\t\t     1. Create new account ");
    printf("\n\t\t\t     2. Update information of existing account");
    printf("\n\t\t\t     3. For transactions");
    printf("\n\t\t\t     4. Check a details of existing account");
    printf("\n\t\t\t     5. Remove existing account");
    printf("\n\t\t\t     6. view customer's list");
    printf("\n\t\t\t     7. Exit");
    printf("\n\t\t\t     ===============================\n");

    printf("\n\tEnter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        new_ac();
        printf("\n\t\t\t Account added succesfully...");
        // delay(2);
        // system("cls");
        goto add_invalid;
        break;
    case 2:
        modify_account();
        // delay(3);
        // system("cls");
        goto add_invalid;
        break;
    case 3:
        transaction();
        // delay(3);
        goto add_invalid;
        break;
    case 4:
        // system("cls");
        search();
        // delay(3);
        break;
    case 5:
        del_account();
        // delay(3);
        // system("cls");
        goto add_invalid;
    case 6:
        list();
        // delay(2);
        goto add_invalid;
        break;
    case 7:
        exit(0);
        break;
    default:
        printf("\n\t\t\t     Enter proper choice!!!");
        goto add_invalid;
        break;
    }

add_invalid: //lable
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    if (main_exit == 1)
    {
        menu();
    }
    else if (main_exit == 0)
    {
        exit(0);
    }
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}

//Function To Add Delay
void delay(int num_of_sec)
{
    int milli_sec = 1000 * num_of_sec;
    clock_t start_time = clock();
    while (clock() < start_time + milli_sec)
        ;
}