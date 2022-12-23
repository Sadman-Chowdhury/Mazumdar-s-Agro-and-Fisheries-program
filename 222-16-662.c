/*This C program is for Mazumdar's Agro and Fisheries business to automate their basic record keeping and report generation.
It can keep record of the various information like project details, utility bill, conveyance bill, feed purchase and feeding history, employee wages, fish and poultry selling info etc.
and it can generate project report.

Author:---- Sadman Chowdhury---ID: 222-16-662------SECTION: A--------DEPARTMENT: CIS----BATCH: 15*/

#include<stdio.h>
#include<string.h>

//Global Definition Section

void menu();
int authentication();
//All manage Project function declaration
void project_menu();
void create_project();
void save_project();
void view_project();
void update_project();
void delete_project();
//All manage Expenses function declaration
void expense_menu();
void create_expense();
void save_expense();
void view_expense();
void update_expense();
void delete_expense();
//All manage Feed function declaration
void feed_menu();
void create_feed();
void save_feed();
void view_feed();
void update_feed();
void delete_feed();
//All manage Salary function declaration
void salary_menu();
void create_salary();
void save_salary();
void view_salary();
void update_salary();
void delete_salary();
//All manage Selling function declaration
void sell_menu();
void create_sell();
void save_sell();
void view_sell();
void update_sell();
void delete_sell();
//report generation function declaration
void report_generate();


//Structure for manage project
struct project{
    char id[20],name[30],type[12],descrip[50],start_date[12],end_date[12];
    float est_budget;
};
//Structure for manage expenses
struct expense{
    char p_id[20],id[20],date[30],type[12],name[50],supplier[12];
    float amount;
};
//Structure for manage feeding
struct feed{
    char p_id[20],id[20],catagory[30],name[12],date[12],time[10];
    float quantity;
};
//Structure for manage salary
struct employee{
    char p_id[20],id[20],name[30],address[40],phone[15],email[30];
    float salary;
};
//Structure for manage selling
struct sell{
    char p_id[20],id[20],sell_name[20],date[12],buyer[40];
    float quantity,unit_price,total_amount;
};

//Declaring variable of custom data structures
struct project info;
struct expense detail;
struct feed history;
struct employee salary;
struct sell record;

//Declaring file pointers
FILE *file_to_operate, *temp_file;

// Main function of the program
int main(){

    system("cls");// screen clear
    int choice;
    printf("\n\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*= W E L C O M E *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n\n========================MAZUMDAR'S AGRO & FRISHARIES==========================\n Do you want to login?\n 1. Yes\n 2. No\n Please enter your choice (1/2):");
    lbl4:scanf("%d",&choice);
    if(choice==1){
        lbl3:if(authentication()==0){
            menu();
        }else{
        printf("Your password is incorrect. Please enter again:");
        goto lbl3;
        }
    }else if(choice==2){
        exit(0);
    }else{
        printf("Invalid choice. Choose again:");
        goto lbl4;
        }
    return 0;
}

//Main menu of the Agro farm and Fisheres
void menu(){
    system("cls");
    lbl6:printf("\n\n\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*= WELCOME *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n\n\n---------Mazumdar's Agro Fisheries Admin panel---------\n\n 1.Manage projects\n 2.Manage expenses.\n 3.Manage Feeding History.\n 4.Manage employee salary.\n 5.Manage selling information.\n 6.Generate reports.\n 7.Back to Home page.\n 8.Exit\n Choose the option what you want to do (1/2/3/4/5/6/7/8): ");
    int user_choice;
    lbl2:scanf("%d",&user_choice);
        switch(user_choice){
            case 1:project_menu();
            break;
            case 2:expense_menu();
            break;
            case 3:feed_menu();
            break;
            case 4:salary_menu();
            break;
            case 5:sell_menu();
            break;
            case 6:report_generate();
            break;
            case 7://sub_menu();
            break;
            case 8:exit(0);
            break;
            default:
                printf("\nINVALID INPUT. Please enter a valid input: ");
            goto lbl2;
        }
}

//function for password protected login
int authentication(){

char fix_password[15]="12345";
char user_password[15];
printf("\nEnter password: ");
fflush(stdin);
gets(user_password);
return strcmp(user_password,fix_password);
}


//Functions for manage project option
//Sub menu function for manage project
void project_menu(){
    system("cls");
    int choice;
    printf("\n\n\n---------Mazumdar's Agro & Frisharies Admin Panel---------\n");
    printf("1. Create New Project \n");
    printf("2. View all project info\n");
    printf("3. Update existing project\n");
    printf("4. Delete a project info\n");
    printf("5. Return to Main Menu\n");
    lbl5: printf("Choose the Option(1/2/3/4/5):");

    fflush(stdin);
    scanf("%d", &choice);
    choice = toupper(choice);
     switch (choice)
    {
    case 1:
        create_project();
        break;
    case 2:
        view_project();
        break;
    case 3:
        update_project();
        break;
    case 4:
        delete_project();
        break;
    case 5:
        printf("\nBack Successfully\n");
        menu();
        break;
    default:
        printf("\nInvalid Input!\nPlease try again!!\n");
        goto lbl5;
    }
}

//Create a new project
void create_project(){


    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n");

    printf("\nProvide all necessary information about the project\n\n");

    printf("Enter Project ID:");
    fflush(stdin);
    gets(info.id);
    printf("Enter Project name:");
    fflush(stdin);
    gets(info.name);
    printf("Enter Project type:");
    fflush(stdin);
    gets(info.type);
    printf("Enter Project description:");
    fflush(stdin);
    gets(info.descrip);
    printf("Enter Project starting date:");
    fflush(stdin);
    gets(info.start_date);
    printf("Enter Project ending date:");
    fflush(stdin);
    gets(info.end_date);
    printf("Enter the estimated budget:");
    fflush(stdin);
    scanf("%f",&info.est_budget);

    save_project();

    add_record: printf("\n\t\t\t 1.Do You Want To Add Another new Project?\n\t\t\t 2.Return to project Menu");
    printf("\n\t\t\tEnter your choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        create_project();
    }else if (choice==2){
       project_menu();
    }else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto add_record;
    }

return 0;
}

//Save project information in a file
void save_project(){

    file_to_operate = fopen("projectinformation.txt", "a");
    fwrite(&info, sizeof(struct project), 1, file_to_operate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(file_to_operate);
}

//View all project details
void view_project()
{
    system("cls");
    file_to_operate = fopen("projectinformation.txt", "r");
    printf("\n---All Project Information---\n\n");
    printf(" Project ID \tProject name \tProject type \tProject description \tProject starting date \tProject ending date \tEstimated budget");
    while (fread(&info, sizeof(struct project), 1, file_to_operate))
    {
        printf("\n\n%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t\t\t%s\t\t\t%f\n",info.id,info.name,info.type,info.descrip,info.start_date,info.end_date,info.est_budget);
    }
    fclose(file_to_operate);

    add_record1: printf("\n\t\t\t 1.Manage Project Menu\n\t\t\t 2.Main Menu\n\t\t\t 3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
       project_menu();
    }else if (choice==2){
      menu();
    }else if(choice==3){
        exit(0);
    }
    else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto add_record1;
    }
}

//Update a project info from the file
void update_project(){
    system("cls");
    printf("\nUpdate Project Information \n");

    printf("Please enter project id you want to modify: ");
    char p_id[20];
    fflush(stdin);
    gets(p_id);
    file_to_operate = fopen("projectinformation.txt", "r+");
    int found = 0;
    while (fread(&info, sizeof(struct project), 1, file_to_operate))
    {
        if (strcmp(info.id,p_id)==0)
        {
            found = 1;
            printf("\nProvide all necessary information about the project\n\n");
            printf("Enter Project ID:");
            fflush(stdin);
            gets(info.id);
            printf("Enter Project name:");
            fflush(stdin);
            gets(info.name);
            printf("Enter Project type:");
            fflush(stdin);
            gets(info.type);
            printf("Enter Project description:");
            fflush(stdin);
            gets(info.descrip);
            printf("Enter Project starting date:");
            fflush(stdin);
            gets(info.start_date);
            printf("Enter Project ending date:");
            fflush(stdin);
            gets(info.end_date);
            printf("Enter the estimated budget:");
            fflush(stdin);
            scanf("%f",&info.est_budget);
            fseek(file_to_operate, -sizeof(info), SEEK_CUR);
            fwrite(&info, sizeof(struct project), 1, file_to_operate);
            break;
        }
    }
    fclose(file_to_operate);
    if (found == 1)
    {
        printf("\Project information updated\n");
    }
    else
    {
        printf("\nProject with the given ID  not found in file\n");
    }

    updateproject: printf("\n\t\t\t1.Do You Want To Modify Another  Project info?\n\t\t\t2.Project Menu\n\t\t\t3.Main Menu");
    printf("\n\t\t\tEnter Your Choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        update_project();
    }else if (choice==2){
       project_menu();
    }else if(choice==3){
        menu();
    }else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto updateproject;
    }

}

//Delete project info from the file
void delete_project(){

    system("cls");
    printf("\n\tDelete Project Information \n");

    FILE  *remove_file;
    char p_id[20];
    printf("\nEnter The project id :");
    fflush(stdin);
    gets(p_id);

    file_to_operate = fopen("projectinformation.txt", "r+");

    remove_file = fopen("temp.txt", "a+");
    if (file_to_operate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&info, sizeof(struct project), 1, file_to_operate))
    {
        if (strcmp(info.id,p_id)!=0)
        {
            fwrite(&info, sizeof(struct project), 1, remove_file);
        }
    }

    fclose(file_to_operate);
    fclose(remove_file);

    remove("projectinformation.txt");
    rename("temp.txt", "projectinformation.txt");

         printf("\Project Info  Successfully Deleted\n");

    deleterecord: printf("\n\t\t\t1.Do You Want To delete Another  Project info?\n\t\t\t2.Project Menu\n\t\t\t3.Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        delete_project();
    }else if (choice==2){
       project_menu();
    }else if(choice==3){
        menu();
    }else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto deleterecord;
    }

}

//Functions for manage expense option
//Sub menu of manage expense
void expense_menu(){
    system("cls");
    int choice;
    printf("\n\n\n---------Mazumdar's Agro & Frisharies Admin Panel---------\n");
    printf("1. Create New Expense record\n");
    printf("2. View all expense info\n");
    printf("3. Update existing expense record\n");
    printf("4. Delete an expense record\n");
    printf("5. Return to Main Menu\n");
    lbl5: printf("Choose the Option(1/2/3/4/5):");

    fflush(stdin);
    scanf("%d", &choice);
     switch (choice)
    {
    case 1:
        create_expense();
        break;
    case 2:
        view_expense();
        break;
    case 3:
        update_expense();
        break;
    case 4:
        delete_expense();
        break;
    case 5:
        printf("\nBack Successfully\n");
        menu();
        break;
    default:
        printf("\nInvalid Input!\nPlease try again!!\n");
        goto lbl5;
    }
}

//Create new expense record
void create_expense(){


    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n");

    printf("\nProvide all necessary information about the expense\n\n");

    printf("Enter Project ID:");
    fflush(stdin);
    gets(detail.p_id);
    printf("Enter Expense ID:");
    fflush(stdin);
    gets(detail.id);
    printf("Enter the date of Expense:");
    fflush(stdin);
    gets(detail.date);
    printf("Enter Expense type:");
    fflush(stdin);
    gets(detail.type);
    printf("Enter Expense item name:");
    fflush(stdin);
    gets(detail.name);
    printf("Enter supplier info:");
    fflush(stdin);
    gets(detail.supplier);
    printf("Enter the amount:");
    fflush(stdin);
    scanf("%f",&detail.amount);

    save_expense();

    add_record: printf("\n\t\t\t 1.Do You Want To Add Another new Expense record?\n\t\t\t 2.Return to Expenses Menu");
    printf("\n\t\t\tEnter your choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        create_expense();
    }else if (choice==2){
       expense_menu();
    }else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto add_record;
    }

return 0;
}

//Save expense info in a file
void save_expense(){

    file_to_operate = fopen("expenseinformation.txt", "a");
    fwrite(&detail, sizeof(struct expense), 1, file_to_operate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(file_to_operate);
}

//View all expense details
void view_expense()
{
    system("cls");
    file_to_operate = fopen("expenseinformation.txt", "r");
    printf("\n---All Expense Information---\n\n");
    printf(" Project ID \tExpense ID \tExpense date \tExpense type \tExpense item name \tSupplier info \tAmount");
    while (fread(&detail, sizeof(struct expense), 1, file_to_operate))
    {
        printf("\n\n\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t%f\n",detail.p_id,detail.id,detail.date,detail.type,detail.name,detail.supplier,detail.amount);
    }
    fclose(file_to_operate);

    add_record2: printf("\n\t\t\t 1.Manage Expenses Menu\n\t\t\t 2.Main Menu\n\t\t\t 3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
       expense_menu();
    }else if (choice==2){
      menu();
    }else if(choice==3){
        exit(0);
    }
    else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto add_record2;
    }
}

// Update a expense info from the file
void update_expense(){
    system("cls");
    printf("\nUpdate Expense Information \n");

    printf("Please enter project id you want to modify: ");
    char p_id[20];
    fflush(stdin);
    gets(p_id);
    file_to_operate = fopen("expenseinformation.txt", "r+");
    int found = 0;
    while (fread(&detail, sizeof(struct expense), 1, file_to_operate))
    {
        if (strcmp(detail.id,p_id)==0)
        {
            found = 1;
            printf("\nProvide all necessary information about the Expense\n\n");
                printf("Enter Project ID:");
                fflush(stdin);
                gets(detail.p_id);
                printf("Enter Expense ID:");
                fflush(stdin);
                gets(detail.id);
                printf("Enter the date of Expense:");
                fflush(stdin);
                gets(detail.date);
                printf("Enter Expense type:");
                fflush(stdin);
                gets(detail.type);
                printf("Enter Expense item name:");
                fflush(stdin);
                gets(detail.name);
                printf("Enter supplier info:");
                fflush(stdin);
                gets(detail.supplier);
                printf("Enter the amount:");
                fflush(stdin);
                scanf("%f",&detail.amount);
                fseek(file_to_operate, -sizeof(detail), SEEK_CUR);
                fwrite(&detail, sizeof(struct expense), 1, file_to_operate);
                break;
        }
    }
    fclose(file_to_operate);
    if (found == 1)
    {
        printf("\Expense information updated\n");
    }
    else
    {
        printf("\nProject with the given ID  not found in file\n");
    }

    update: printf("\n\t\t\t1.Do You Want To Modify Another Expense info?\n\t\t\t2.Manage Expense Menu\n\t\t\t3.Main Menu");
    printf("\n\t\t\tEnter Your Choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        update_expense();
    }else if (choice==2){
       expense_menu();
    }else if(choice==3){
        menu();
    }else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto update;
    }

}

//Delete a expense info from the file
void delete_expense(){

    system("cls");
    printf("\n\tDelete Expense Information \n");

    FILE  *remove_file;
    char p_id[20];
    printf("\nEnter The project id :");
    fflush(stdin);
    gets(p_id);

    file_to_operate = fopen("expenseinformation.txt", "r+");

    remove_file = fopen("temp.txt", "a+");
    if (file_to_operate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&detail, sizeof(struct expense), 1, file_to_operate))
    {
        if (strcmp(detail.id,p_id)!=0)
        {
            fwrite(&detail, sizeof(struct expense), 1, remove_file);
        }
    }

    fclose(file_to_operate);
    fclose(remove_file);

    remove("expenseinformation.txt");
    rename("temp.txt", "expenseinformation.txt");

         printf("\Expense Info  Successfully Deleted\n");



    deleterecord: printf("\n\t\t\t1.Do You Want To delete Another expense info?\n\t\t\t2.Manage Expense Menu\n\t\t\t3.Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        delete_expense();
    }else if (choice==2){
       expense_menu();
    }else if(choice==3){
        menu();
    }else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto deleterecord;
    }

}

//Functions for manage feed option
//Sub menu for manage feed
void feed_menu(){
    system("cls");
    int choice;
    printf("\n\n\n---------Mazumdar's Agro & Frisharies Admin Panel---------\n");
    printf("1. Create New Feeding record\n");
    printf("2. View all Feeding history\n");
    printf("3. Update existing Feeding history\n");
    printf("4. Delete a Feeding history\n");
    printf("5. Return to Main Menu\n");
    lbl5: printf("Choose the Option(1/2/3/4/5):");

    fflush(stdin);
    scanf("%d", &choice);
     switch (choice)
    {
    case 1:
        create_feed();
        break;
    case 2:
        view_feed();
        break;
    case 3:
        update_feed();
        break;
    case 4:
        delete_feed();
        break;
    case 5:
        printf("\nBack Successfully\n");
        menu();
        break;
    default:
        printf("\nInvalid Input!\nPlease try again!!\n");
        goto lbl5;
    }
}

//Create a new feed record
void create_feed(){

    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n");

    printf("\nProvide all necessary information about the Feeding session\n\n");

    printf("Enter Project ID:");
    fflush(stdin);
    gets(history.p_id);
    printf("Enter Feeding ID:");
    fflush(stdin);
    gets(history.id);
    printf("Enter the food catagory:");
    fflush(stdin);
    gets(history.catagory);
    printf("Enter food name:");
    fflush(stdin);
    gets(history.name);
    printf("Enter the feeding date:");
    fflush(stdin);
    gets(history.date);
    printf("Enter feeding time:");
    fflush(stdin);
    gets(history.time);
    printf("Enter the food quantity(kg):");
    fflush(stdin);
    scanf("%f",&history.quantity);

    save_feed();

    add_record: printf("\n\t\t\t 1.Do You Want To Add Another new Feeding history?\n\t\t\t 2.Return to Feeding history Menu");
    printf("\n\t\t\tEnter your choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        create_feed();
    }else if (choice==2){
       feed_menu();
    }else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto add_record;
    }

return 0;
}

//Save feed info in a file
void save_feed(){

    file_to_operate = fopen("feedinginformation.txt", "a");
    fwrite(&history, sizeof(struct feed), 1, file_to_operate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(file_to_operate);
}

//View all feed detail
void view_feed()
{
    system("cls");
    file_to_operate = fopen("feedinginformation.txt", "r");
    printf("\n---All Feeding History---\n\n");
    printf(" Project ID \tFeed ID \tFood catagory \tFood name \tFeeding date \tFeeding time \tFood quantity(kg)");
    while (fread(&history, sizeof(struct feed), 1, file_to_operate))
    {
        printf("\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%f\n",history.p_id,history.id,history.catagory,history.name,history.date,history.time,history.quantity);
    }
    fclose(file_to_operate);

    add_record2: printf("\n\t\t\t 1.Feeding history Menu\n\t\t\t 2.Main Menu\n\t\t\t 3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
       feed_menu();
    }else if (choice==2){
      menu();
    }else if(choice==3){
        exit(0);
    }
    else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto add_record2;
    }
}

// Update a feed info from the file
void update_feed(){
    system("cls");
    printf("\nUpdate Feeding Information \n");

    printf("Please enter project id you want to modify: ");
    char p_id[20];
    fflush(stdin);
    gets(p_id);
    file_to_operate = fopen("feedinginformation.txt", "r+");
    int found = 0;
    while (fread(&history, sizeof(struct feed), 1, file_to_operate))
    {
        if (strcmp(history.id,p_id)==0)
        {
            found = 1;
            printf("\nProvide all necessary information about the Feeding\n\n");
            printf("Enter Project ID:");
            fflush(stdin);
            gets(history.p_id);
            printf("Enter Feeding ID:");
            fflush(stdin);
            gets(history.id);
            printf("Enter the food catagory:");
            fflush(stdin);
            gets(history.catagory);
            printf("Enter food name:");
            fflush(stdin);
            gets(history.name);
            printf("Enter the feeding date:");
            fflush(stdin);
            gets(history.date);
            printf("Enter feeding time:");
            fflush(stdin);
            gets(history.time);
            printf("Enter the food quantity(kg):");
            fflush(stdin);
            scanf("%f",&history.quantity);
                fseek(file_to_operate, -sizeof(history), SEEK_CUR);
                fwrite(&history, sizeof(struct feed), 1, file_to_operate);
                break;
        }
    }
    fclose(file_to_operate);
    if (found == 1)
    {
        printf("\Feeding information updated\n");
    }
    else
    {
        printf("\nProject with the given ID  not found in file\n");
    }

    update: printf("\n\t\t\t1.Do You Want To Modify Another Feeding info?\n\t\t\t2.Manage Feeding Menu\n\t\t\t3.Main Menu");
    printf("\n\t\t\tEnter Your Choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        update_feed();
    }else if (choice==2){
       feed_menu();
    }else if(choice==3){
        menu();
    }else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto update;
    }

}

//Delete a project info from the file
void delete_feed(){

    system("cls");
    printf("\n\tDelete Feeding Information \n");

    FILE  *remove_file;
    char p_id[20];
    printf("\nEnter The project id :");
    fflush(stdin);
    gets(p_id);

    file_to_operate = fopen("feedinginformation.txt", "r+");

    remove_file = fopen("temp.txt", "a+");
    if (file_to_operate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&history, sizeof(struct feed), 1, file_to_operate))
    {
        if (strcmp(history.id,p_id)!=0)
        {
            fwrite(&history, sizeof(struct feed), 1, remove_file);
        }
    }

    fclose(file_to_operate);
    fclose(remove_file);

    remove("feedinginformation.txt");
    rename("temp.txt", "feedinginformation.txt");

         printf("\Feeding Info  Successfully Deleted\n");



    deleterecord: printf("\n\t\t\t1.Do You Want To delete Another Feeding info?\n\t\t\t2.Manage Feeding Menu\n\t\t\t3.Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        delete_feed();
    }else if (choice==2){
       feed_menu();
    }else if(choice==3){
        menu();
    }else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto deleterecord;
    }

}

//Functions for manage salary option
//Sub menu for manage salary
void salary_menu(){
    system("cls");
    int choice;
    printf("\n\n\n---------Mazumdar's Agro & Frisharies Admin Panel---------\n");
    printf("1. Create New employee Salary profile\n");
    printf("2. View all Employee's salary and details\n");
    printf("3. Update existing profile\n");
    printf("4. Delete a profile\n");
    printf("5. Return to Main Menu\n");
    lbl5: printf("Choose the Option(1/2/3/4/5):");

    fflush(stdin);
    scanf("%d", &choice);
     switch (choice)
    {
    case 1:
        create_salary();
        break;
    case 2:
        view_salary();
        break;
    case 3:
        update_salary();
        break;
    case 4:
        delete_salary();
        break;
    case 5:
        printf("\nBack Successfully\n");
        menu();
        break;
    default:
        printf("\nInvalid Input!\nPlease try again!!\n");
        goto lbl5;
    }
}

//Create a new salary record
void create_salary(){

    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n");

    printf("\nProvide all necessary information about the employee\n\n");

    printf("Enter Project ID:");
    fflush(stdin);
    gets(salary.p_id);
    printf("Enter Salary ID:");
    fflush(stdin);
    gets(salary.id);
    printf("Enter the employee's name:");
    fflush(stdin);
    gets(salary.name);
    printf("Enter the employee's address:");
    fflush(stdin);
    gets(salary.address);
    printf("Enter the employee's phone number:");
    fflush(stdin);
    gets(salary.phone);
    printf("Enter the employee's E-mail address:");
    fflush(stdin);
    gets(salary.email);
    printf("Enter the employee's salary:");
    fflush(stdin);
    scanf("%f",&salary.salary);

    save_salary();

    add_record: printf("\n\t\t\t 1.Do You Want To Add Another new Employee Profile?\n\t\t\t 2.Return to Manage employee salary Menu");
    printf("\n\t\t\tEnter your choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        create_salary();
    }else if (choice==2){
       salary_menu();
    }else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto add_record;
    }

return 0;
}

//Save salary info in a file
void save_salary(){

    file_to_operate = fopen("salaryinformation.txt", "a");
    fwrite(&salary, sizeof(struct employee), 1, file_to_operate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(file_to_operate);
}

//View all salary detail
void view_salary()
{
    system("cls");
    file_to_operate = fopen("salaryinformation.txt", "r");
    printf("\n---All Employee salary detail---\n\n");
    printf(" Project ID \tEmployee ID \tEmployee name \tEmployee address \tEmployee phone \tEmployee E-mail \tEmployee salary");
    while (fread(&salary, sizeof(struct employee), 1, file_to_operate))
    {
        printf("\n\n%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t\t%s\t\t\t%.2f\n",salary.p_id,salary.id,salary.name,salary.address,salary.phone,salary.email,salary.salary);
    }
    fclose(file_to_operate);

    add_record2: printf("\n\t\t\t 1.Manage employee salary menu\n\t\t\t 2.Main Menu\n\t\t\t 3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
       salary_menu();
    }else if (choice==2){
      menu();
    }else if(choice==3){
        exit(0);
    }
    else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto add_record2;
    }
}

// Update a employee's salary info from the file
void update_salary(){
    system("cls");
    printf("\nUpdate Employee's salary Information \n");

    printf("Please enter project id you want to modify: ");
    char p_id[20];
    fflush(stdin);
    gets(p_id);
    file_to_operate = fopen("salaryinformation.txt", "r+");
    int found = 0;
    while (fread(&salary, sizeof(struct employee), 1, file_to_operate))
    {
        if (strcmp(salary.id,p_id)==0)
        {
            found = 1;
            printf("\nProvide all necessary information about the Employee\n\n");
            printf("Enter Project ID:");
            fflush(stdin);
            gets(salary.p_id);
            printf("Enter Salary ID:");
            fflush(stdin);
            gets(salary.id);
            printf("Enter the employee's name:");
            fflush(stdin);
            gets(salary.name);
            printf("Enter the employee's address:");
            fflush(stdin);
            gets(salary.address);
            printf("Enter the employee's phone number:");
            fflush(stdin);
            gets(salary.phone);
            printf("Enter the employee's E-mail address:");
            fflush(stdin);
            gets(salary.email);
            printf("Enter the employee's salary:");
            fflush(stdin);
            scanf("%f",&salary.salary);
                fseek(file_to_operate, -sizeof(salary), SEEK_CUR);
                fwrite(&salary, sizeof(struct employee), 1, file_to_operate);
                break;
        }
    }
    fclose(file_to_operate);
    if (found == 1)
    {
        printf("\Salary information updated\n");
    }
    else
    {
        printf("\nProject with the given ID  not found in file\n");
    }

    update: printf("\n\t\t\t1.Do You Want To Modify Another Salary info?\n\t\t\t2.Manage Salary Menu\n\t\t\t3.Main Menu");
    printf("\n\t\t\tEnter Your Choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        update_salary();
    }else if (choice==2){
       salary_menu();
    }else if(choice==3){
        menu();
    }else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto update;
    }

}

//Delete a employee's salary info from the file
void delete_salary(){

    system("cls");
    printf("\n\tDelete Salary Information \n");

    FILE  *remove_file;
    char p_id[20];
    printf("\nEnter The project id :");
    fflush(stdin);
    gets(p_id);

    file_to_operate = fopen("salaryinformation.txt", "r+");

    remove_file = fopen("temp.txt", "a+");
    if (file_to_operate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&salary, sizeof(struct employee), 1, file_to_operate))
    {
        if (strcmp(salary.id,p_id)!=0)
        {
            fwrite(&salary, sizeof(struct employee), 1, remove_file);
        }
    }

    fclose(file_to_operate);
    fclose(remove_file);

    remove("salaryinformation.txt");
    rename("temp.txt", "salaryinformation.txt");

         printf("\Salary Info  Successfully Deleted\n");



    deleterecord: printf("\n\t\t\t1.Do You Want To delete Another Salary info?\n\t\t\t2.Manage Salary Menu\n\t\t\t3.Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        delete_salary();
    }else if (choice==2){
       salary_menu();
    }else if(choice==3){
        menu();
    }else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto deleterecord;
    }

}

//Functions for manage selling
//Sub menu of manage sell
void sell_menu(){
    system("cls");
    int choice;
    printf("\n\n\n---------Mazumdar's Agro & Frisharies Admin Panel---------\n");
    printf("1. Create New Selling Record\n");
    printf("2. View all Selling Records\n");
    printf("3. Update existing selling record\n");
    printf("4. Delete a selling record\n");
    printf("5. Return to Main Menu\n");
    lbl5: printf("Choose the Option(1/2/3/4/5):");

    fflush(stdin);
    scanf("%d", &choice);
     switch (choice)
    {
    case 1:
        create_sell();
        break;
    case 2:
        view_sell();
        break;
    case 3:
        update_sell();
        break;
    case 4:
        delete_sell();
        break;
    case 5:
        printf("\nBack Successfully\n");
        menu();
        break;
    default:
        printf("\nInvalid Input!\nPlease try again!!\n");
        goto lbl5;
    }
}

//Create a new selling record
void create_sell(){

    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n");

    printf("\nProvide all necessary information about the Sell\n\n");

    printf("Enter Project ID:");
    fflush(stdin);
    gets(record.p_id);
    printf("Enter Selling ID:");
    fflush(stdin);
    gets(record.id);
    printf("Enter the Selling product's name:");
    fflush(stdin);
    gets(record.sell_name);
    printf("Enter the date of sell:");
    fflush(stdin);
    gets(record.date);
    printf("Enter the buyer's name:");
    fflush(stdin);
    gets(record.buyer);
    printf("Enter the quantity of the product(kg):");
    fflush(stdin);
    scanf("%f",&record.quantity);
    printf("Enter the price per unit(kg):");
    fflush(stdin);
    scanf("%f",&record.unit_price);
    printf("Enter the total selling price:");
    fflush(stdin);
    scanf("%f",&record.total_amount);

    save_sell();

    add_record: printf("\n\t\t\t 1.Do You Want To Add Another new Selling Record?\n\t\t\t 2.Return to Manage Selling Information Menu");
    printf("\n\t\t\tEnter your choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        create_sell();
    }else if (choice==2){
       sell_menu();
    }else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto add_record;
    }

return 0;
}

//Save selling info in a file
void save_sell(){

    file_to_operate = fopen("sellinformation.txt", "a");
    fwrite(&record, sizeof(struct sell), 1, file_to_operate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(file_to_operate);
}

//View all selling details
void view_sell()
{
    system("cls");
    file_to_operate = fopen("sellinformation.txt", "r");
    printf("\n---All Selling Records---\n\n");
    printf(" Project ID \tSelling ID \tProduct's name \tSelling date \tBuyer's name \tProduct's quantity(kg) \tUnit price(kg) Total amount");
    while (fread(&record, sizeof(struct sell), 1, file_to_operate))
    {
        printf("\n\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%.4f\t\t\t%.2f\t\t%.2f\n",record.p_id,record.id,record.sell_name,record.date,record.buyer,record.quantity,record.unit_price,record.total_amount);
    }
    fclose(file_to_operate);

    add_record2: printf("\n\t\t\t 1.Manage selling information menu\n\t\t\t 2.Main Menu\n\t\t\t 3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
       sell_menu();
    }else if (choice==2){
      menu();
    }else if(choice==3){
        exit(0);
    }
    else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto add_record2;
    }
}

// Update a selling info from the file
void update_sell(){
    system("cls");
    printf("\nUpdate Selling Information \n");

    printf("Please enter project id you want to modify: ");
    char p_id[20];
    fflush(stdin);
    gets(p_id);
    file_to_operate = fopen("sellinformation.txt", "r+");
    int found = 0;
    while (fread(&record, sizeof(struct sell), 1, file_to_operate))
    {
        if (strcmp(record.id,p_id)==0)
        {
            found = 1;
            printf("\nProvide all necessary information about the Sell\n\n");
            printf("Enter Project ID:");
            fflush(stdin);
            gets(record.p_id);
            printf("Enter Selling ID:");
            fflush(stdin);
            gets(record.id);
            printf("Enter the Selling product's name:");
            fflush(stdin);
            gets(record.sell_name);
            printf("Enter the date of sell:");
            fflush(stdin);
            gets(record.date);
            printf("Enter the buyer's name:");
            fflush(stdin);
            gets(record.buyer);
            printf("Enter the quantity of the product(kg):");
            fflush(stdin);
            scanf("%f",&record.quantity);
            printf("Enter the price per unit(kg):");
            fflush(stdin);
            scanf("%f",&record.unit_price);
            printf("Enter the total selling price:");
            fflush(stdin);
            scanf("%f",&record.total_amount);
            fseek(file_to_operate, -sizeof(record), SEEK_CUR);
            fwrite(&record, sizeof(struct sell), 1, file_to_operate);
            break;
        }
    }
    fclose(file_to_operate);
    if (found == 1)
    {
        printf("\Selling information updated\n");
    }
    else
    {
        printf("\nProject with the given ID  not found in file\n");
    }

    update: printf("\n\t\t\t1.Do You Want To Modify Another Selling info?\n\t\t\t2.Manage Selling record Menu\n\t\t\t3.Main Menu");
    printf("\n\t\t\tEnter Your Choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        update_sell();
    }else if (choice==2){
       sell_menu();
    }else if(choice==3){
        menu();
    }else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto update;
    }

}

//Delete a selling info from the file
void delete_sell(){

    system("cls");
    printf("\n\tDelete Selling Information \n");

    FILE  *remove_file;
    char p_id[20];
    printf("\nEnter The project id :");
    fflush(stdin);
    gets(p_id);

    file_to_operate = fopen("sellinformation.txt", "r+");

    remove_file = fopen("temp.txt", "a+");
    if (file_to_operate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&record, sizeof(struct sell), 1, file_to_operate))
    {
        if (strcmp(record.id,p_id)!=0)
        {
            fwrite(&record, sizeof(struct sell), 1, remove_file);
        }
    }

    fclose(file_to_operate);
    fclose(remove_file);

    remove("sellinformation.txt");
    rename("temp.txt", "sellinformation.txt");

         printf("\Selling Info  Successfully Deleted\n");



    deleterecord: printf("\n\t\t\t1.Do You Want To delete Another Selling info?\n\t\t\t2.Manage Selling  Menu\n\t\t\t3.Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        delete_sell();
    }else if (choice==2){
       sell_menu();
    }else if(choice==3){
        menu();
    }else{
      printf("\n\t\t\tInvalid Input! Please enter a valid choice");
      goto deleterecord;
    }
}

//Report generation
void report_generate(){
    system("cls");

    char pro_id[20];
    float total_expense=0, total_sell=0,total_feed=0;
    printf("\n\n\t------------Project Report------------\n");
    id:printf("\n\nPlease enter the project id to Generate the Report: ");
    fflush(stdin);
    gets(pro_id);

    file_to_operate = fopen("expenseinformation.txt", "r");
    while (fread(&detail, sizeof(struct expense), 1, file_to_operate))
    {
        if (strcmp(detail.p_id,pro_id)==0)
        {
           total_expense += detail.amount;
        }else{
            printf("There is no project with this ID!!");
            goto id;}
    }
    fclose(file_to_operate);

    file_to_operate = fopen("sellinformation.txt", "r");
    while (fread(&record, sizeof(struct sell), 1, file_to_operate))
    {
        if (strcmp(record.p_id,pro_id)==0)
        {
           total_sell += record.total_amount;
        }else{
            printf("There is no project with this ID!!");
            goto id;}
    }
    fclose(file_to_operate);

    file_to_operate = fopen("feedinginformation.txt", "r");
    while (fread(&history, sizeof(struct feed), 1, file_to_operate))
    {
        if (strcmp(history.p_id,pro_id)==0)
        {
           total_feed += history.quantity;
        }else{
            printf("There is no project with this ID!!");
            goto id;}
    }
    fclose(file_to_operate);

    printf("\n\tProject Id : %s\n", pro_id);
    printf("\n\tTotal Feed Amount of the Project: %.2f KG\n", total_feed);
    printf("\n\tTotal Sell of the project: %.2f(BDT)\n", total_sell);
    printf("\n\tTotal Expense of the Project: %.2f(BDT)\n", total_expense);
    if(total_sell>total_expense){
        printf("\n\tProfit : %.2f (BDT)\n",total_sell-total_expense);
    }else{
        printf("\n\tLoss : %.2f (BDT)\n",total_expense-total_sell);
    }

    sub: printf("\n\t\t\t1. Do You Want To Generate Report For Another Project?\n\t\t\t2. Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");

    int choice;
    scanf("%d",&choice);
    if(choice==1){
        report_generate();
    }else if (choice==2){
        menu();
    }else if(choice==3){
        system("cls");
        printf("\n\n\t\t----- Thank You Very Much -----\n\n");
        exit(0);
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto sub;
    }
}
