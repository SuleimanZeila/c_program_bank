#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int i,j;
int main_exit;
void menu();
struct date{
    int month,day,year;

    };
struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
void records()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    clear_screen();
    printf("\n\n\n\n\t\t\t\t\t\t\t\xB1\xB1\xB1\xB1\ CLIENTS RECORD \xB1\xB1\xB1\xB1");
    printf("\n\n\t\t\t\tACC. NO.\t\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n\t\t\t\t%6d\t\t %10s\t\t%10s\t\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {
            clear_screen();
            printf("\n\n\n\t\t\t\t\tNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

void new_acc()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    clear_screen();
    printf("\n\n\n\t\t\t\t\t\t\t\xB1\xB1\xB1\ ADD RECORD  \xB1\xB1\xB1\xB1");
    printf("\n\n\t\tEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\n\t\tEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    add.acc_no=check.acc_no;
    clear_screen();
    printf("\n\n\n\t\tEnter the name:");
    scanf("%s",add.name);
    printf("\n\t\tEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\n\t\tEnter the age:");
    scanf("%d",&add.age);
    printf("\n\t\tEnter the address:");
    scanf("%s",add.address);
    printf("\n\t\tEnter the citizenship number:");
    scanf("%s",add.citizenship);
    printf("\n\t\tEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\n\t\tEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    printf("\n\t\tType of account:\n\t\t\t\t\tSaving\n\t\t\t\t\tCurrent\n\t\t\t\t\tFixed1(for 1 year)\n\t\t\t\t\tFixed2(for 2 years)\n\t\t\t\t\tFixed3(for 3 years)\n\t\tEnter your choice:");
    scanf("%s",add.acc_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\n\t\tAccount created successfully!");
    add_invalid:
    printf("\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        restart();
    else if(main_exit==0)
            close();
    else
        {
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\nInvalid!\a");
            goto add_invalid;
        }
}

    void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void restart(void){
    menu();
}
int choice;
void clear_screen(void){
    system("cls");
    printf("\n\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO FIRST COMMUNITY BANK \xB2\xB2\xB2\xB2\xB2\xB2");

}
void balance(void){
    int blc;
    int s;
    blc = 1000000;
    clear_screen();
    printf("\n\n\t\t\t\t\t\tYOUR BALANCE IS $ %d", blc);
    printf("\n\n\t\t\t\TO CONTINUE WITH MAIN MENU PRESS 1, TO EXIT PRESS ANY KEY");
    scanf("%d",&s);
    if (s==1){
        menu();
    }
    else{
    clear_screen();
    printf("\n\n\t\t\t\t\t\t\tTHANK YOU!");
    fordelay(100000000000);
    system("cls");
    }
    }
    void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    clear_screen();
    printf("\n\n\n\n\t\tEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\n\n\n\n\t\tWhich information do you want to change?\n\t\t\t1.Address\n\t\t\t2.Phone\n\n\t\tEnter your choice(1 for address and 2 for phone): ");
            scanf("%d",&choice);
            clear_screen();
            if(choice==1)
                {printf("\n\n\t\tEnter the new address: ");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                clear_screen();
                printf("\n\n\n\t\t\t\t\t\t\tChanges saved!\n\n");
                }
            else if(choice==2)
                {
                printf("\n\n\t\tEnter the new phone number: ");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                clear_screen();
                printf("\n\n\n\t\t\t\t\t\t\tChanges saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {   clear_screen();
            printf("\n\n\n\n\t\t\t\t\t\t\tRecord not found!!\a\a\a");
            edit_invalid:
              printf("\n\n\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              clear_screen();
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\n\n\n\n\t\t\t\t\t\t\tInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        clear_screen();
        if (main_exit==1)
            menu();
        else
            close();
        }
}
void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    clear_screen();
    printf("\n\n\n\t\t\tEnter the account no. of the customer: ");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\n\t\tYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    clear_screen();
                    menu();

                }
                printf("\n\n\t\tDo you want to\n\t\t\t1.Deposit\n\t\t\t2.Withdraw?\n\n\t\tEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("\n\n\t\tEnter the amount you want to deposit:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    clear_screen();
                    printf("\n\n\n\n\t\t\t\t\t\tDeposited successfully!");
                }
                else
                {
                    printf("\n\n\t\tEnter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    clear_screen();
                    printf("\n\n\n\t\t\t\t\t\tWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\n\n\t\t\t\t\t\t\tRecord not found!!");
       transact_invalid:
      printf("\n\n\n\t\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      clear_screen();
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\n\n\n\t\t\t\t\t\t\tInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        clear_screen();
        if (main_exit==1)
            menu();
        else
            close();
   }

}
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    clear_screen();
    printf("\n\n\n\t\tEnter the account no. of the customer you want to delete: ");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            clear_screen();
            printf("\n\n\n\t\t\t\t\t\tRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\n\n\n\t\t\t\t\t\t\t\tRecord not found!!\a\a\a");
            erase_invalid:
              printf("\n\n\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\n\n\n\t\t\t\t\t\t\tInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        clear_screen();
        if (main_exit==1)
            menu();
        else
            close();
        }

}
void close(void)
{
    clear_screen();
    printf("\n\n\n\n\t\t\t\t\t\t\tTHANK YOU, BUILT BY SULEIMAN ZEILA!");
    }


void menu(){
        clear_screen();
        printf("\n\n\n\n\t\t\t\t\t\t\tMAIN MENU");
        printf("\n\n\t\t\t\t\t\tPRESS 1: TO CHECK YOUR BALANCE");
        printf("\n\t\t\t\t\t\tPRESS 2: TO CREATE A NEW ACCOUNT");
        printf("\n\t\t\t\t\t\tPRESS 3: TO CHECK CLIENTS RECORD");
        printf("\n\t\t\t\t\t\tPRESS 4: TO UPDATE A RECORD");
        printf("\n\t\t\t\t\t\tPRESS 5: TO MAKE A TRANSACTION");
        printf("\n\t\t\t\t\t\tPRESS 6: TO DELETE AN ACCOUNT");
        printf("\n\n\n\t\t\t\t\t\t\tWHAT IS YOUR CHOICE? ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            balance();
            break;

        case 2:
            new_acc();
            break;
        case 3:
            records();
            break;
        case 4:
            edit();
            break;
        case 5:
            transact();
            break;
        case 6:
            erase();
        }
}
void loading(void){
        clear_screen();
        printf("\n\n\n\t\t\t\t\t\tYOU ENTERED THE CORRECT PIN!");
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPLEASE WAIT");
        int x=0;
        while(x<3){
            fordelay(100000000*1.1);
            printf(".");
            fordelay(100000000*1.9);
            x++;
        }
}
int main(){
    int pin;
    char correct_pin = 0000;
    system("color 9B");
    printf("\n\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO FIRST COMMUNITY BANK \xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t\t\t\t\tPLEASE ENTER YOUR PIN NUMBER: ");
    scanf("%d",&pin);
    if(pin == correct_pin){
        system("cls");
        printf("\n\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO FIRST COMMUNITY BANK \xB2\xB2\xB2\xB2\xB2\xB2");
        fordelay(100000000);
        printf("\n\n\n\t\t\t\t\t\tYOU ENTERED THE CORRECT PIN!");
        fordelay(100000000*0.8);
        loading();
        loading();
        loading();
        menu();
    }
    else{
        clear_screen();
        printf("\n\n\n\t\t\t\t\t\tYOU ENTERED A WRONG PIN!!!");
    }
    return 0;
}
