#include <stdio.h> //For Taking Input And Output Of Data
#include <string.h> //For Manupulating Strings
#include <stdlib.h> //For Dynamic Memory Allocation And Clear Screen
#include <ctype.h> //For Manupulating Characters
#include<Windows.h>
#include<time.h>
typedef long long unsigned int llu;

struct User //Structure For Storing User Details
{
    char *User_Name;
    char  *Mobile_Number;
    char *Email;
    char *Address;
}*Current_User; //Declared Here So It Can Be Accessed Globally

struct Selected_Car_Details //Structure For Storing Selected Car Details
{
    int Brand_Code;  //For Storing Brand Code
    int Model_Code; //For Storing Model Code
    int Colour_Code; //For Storing Colour Code
    int Mod_Type; //For Storing Current Mod Code
    int Mod_Sub_Type[6];  //Array For Storing Sub-Modification Code
}Selected;

struct Car_Brands //Structure For Storing Car Brand Details
{
    int Brand_Code;
    char Model[25];
    int Car_Model_Starts_At;
    int Car_Model_Ends_At;
};

struct Car_Brands Brands[7] = {
                                1, "Kia",0,3,
                                2, "Hyundai",3,8,
                                3, "Honda",8,11,
                                4, "Mahindra",11,16,
                                5, "Maruti Suzuki",16,21,
                                6, "Mercedez",21,25,
                                7, "Toyota",25,28
                                };

struct Car_Model // Structure For Storing Car Model Details
{
    int Car_Code;
    char Model[25];
    int Car_Cost;
};

struct Car_Model Models[29] = {
                                1,"Kia Sonet             ",1379000,
                                2,"Kia Seltos            ",1865000,
                                3,"Kia Carnival          ", 3549000,
                                4,"Hyundai Santro        ",489000,
                                5,"Hyundai i10           ",539000,
                                6,"Hyundai i20           ",703000,
                                7,"Hyundai Verna         ",   940000,
                                8,"Hyundai Creta         ",1044000,
                                9,"Honda City            ",950000,
                                10,"Honda Amaze          ",665000,
                                11,"Honda Jazz           ",811000,
                                12,"Mahindra Thar        ",1353000,
                                13,"Mahindra XUV 300     ", 841000,
                                14,"Mahindra XUV 500     ", 931000,
                                15,"Mahindra XUV 700     ", 1318000,
                                16,"Mahindra Scropio     ", 1199000,
                                17,"Maruti Suzuki Swift  ",591000,
                                18,"Maruti Suzuki Baleno ", 642000,
                                19,"Maruti Suzuki Ertiga ", 835000,
                                20,"Maruti Suzuki Brezza ", 799000,
                                21,"Maruti Suzuki S-Cross", 950000,
                                22,"Mercedez S-Class     ", 16000000,
                                23,"Mercedez C-Class     ", 5500000,
                                24,"Mercedez AMG         ", 17200000,
                                25,"Mercedez Benz        ",4490000,
                                26,"Toyota Camry         ", 4435000,
                                27,"Toyota Innova        ",1786000,
                                28,"Toyota Fortuner      ",3239000,
                                29,"Toyota Land Cruiser  ",902000,
                                };

struct Car_Colour //Structure For Storing Car Colour Details
{
    int Colour_Code;
    char Colour_Name[20];
};

struct Car_Colour Colours[7] = {
                                1, "Black",
                                2, "White",
                                3, "Red",
                                4, "Blue",
                                5, "Dark Green",
                                6, "Grey",
                                7, "Yellow"};

struct Modification_Types // Structure For Storing Modification Details
{
    int Mod_Type_Code;
    char Mod_Type[25];
    int Mod_Starts_At;
    int Mod_Ends_At;
};

struct Modification_Types Mod_Types[6] = {
                                            1, "Wheels                  ",0,4,
                                            2, "Vents                   ",4,5,
                                            3, "Lights                  ",5,9,
                                            4, "Spoiler                 ",9,11,
                                            5, "Side_Skirts(Exhaust)    ",11,13,
                                            6, "Car_Stereo(Sound System)",13,14}; //Space Given To Deign Bill
                                            
struct Modifications_Sub_Types // Structure For Storing Modification Details
{
    int Mod_Code;
    char Mod_Name[25];
    int Mod_Cost;
};

struct Modifications_Sub_Types Car_Modification[14]={
    1,"Atomic Wheels     ",2000,
    2,"Off Road Wheels   ",4000,
    3,"Twist Wheels      ",3000,
    4,"Mega Wheels       ",2500,
    5,"Roof Scoop Vent   ",4000,
    6,"Tail Light        ",3000,
    7,"Polo Light        ",5000,
    8,"Fog Light         ",8000,
    9,"White LED Light   ",12000,
    10,"Win Spoiler      ",12000,
    11,"Alpha Spoiler    ",10000,
    12,"Medium Exhaust   ",6000,
    13,"Twin Exhaust     ",8000,
    14,"Boost Bass       ",15000,
};

struct Final_Bill //Structure For Storing Bill Details
{
    llu Car_Cost;
    llu Mod_Cost;
    int GST;
    llu Total_Price;
    llu Final_Price;
};

struct Final_Bill Bill = {0,0,28,0,0};

int RangeCheck(int i,int low,int high) //Function To Check Range Of i
{
    if((i>=low && i<=high))
        return 1;
    else
        return 0;
}

void Get_User_Details(); //Function To Get User Details
void Display_Car_Brands(); //Function T0 Display All Car Brands
void Display_Brand_Models(); //Function To Display Cars Of Selected Brands
void Display_Car_Colours(); //Function To Display Available Car Colours
void Display_Modification_Types(); //Function To Display Modifications That Can Be Applied
void Display_Modification_Sub_Types(); //Function To Display Sub-Modifications Of Selected Modifications
void Display_Bill(); //Function To Display Final Bill

int main()
{
    system("@cls||clear");
    srand(time(0));
    int sml = 1;
    char buy_or_not;
    printf("\t%cWELCOME TO OUR SHOP %c\n", sml, sml);
    printf("   Do You Want To But A Car?(Y/N): ");
    scanf("%c", &buy_or_not);
    if (toupper(buy_or_not) == 'Y')
    {
        Get_User_Details();
        Display_Car_Brands();
        Bill.Car_Cost += Models[Selected.Model_Code-1].Car_Cost;
        Display_Bill();
    }
    else
    {
        printf("Thanks For Visiting..");
        return 0;
    }
    free(Current_User);
    return 0;
}

void Get_User_Details()
{
    system("@cls||clear"); //For Clearing Screen

    Current_User = (struct User*)malloc(sizeof(struct User));

    Current_User->User_Name = (char *)malloc(40*(sizeof(char)));
    Current_User->Mobile_Number = (char *)malloc(10*(sizeof(char)));
    Current_User->Email = (char *)malloc(80*(sizeof(char)));
    Current_User->Address = (char *)malloc(40*(sizeof(char)));
    char c;
    
    printf("\nDear Customer Please Enter Your Details\n");
    printf("Enter Your Name: ");
    getchar();
    scanf("%[^\n]%*c",Current_User->User_Name);
    printf("Enter Your Mobile Number: ");
    scanf("%[^\n]%*c",Current_User->Mobile_Number);
    printf("Enter Your Email: ");
    scanf("%s",Current_User->Email);
    getchar();
    printf("Enter Your Address: ");
    scanf("%[^\n]%*c",Current_User->Address);

    system("@cls||clear");
}

void Display_Car_Brands()
{
    printf("These Are All The Available Car Brands:\n");
    for(int i=0;i<sizeof(Brands)/sizeof(struct Car_Brands);i++)
        printf("0%d - %s\n",Brands[i].Brand_Code,Brands[i].Model);
    printf("\nWhich Car Brand You Want To Select: ");
    scanf("%d",&Selected.Brand_Code); //Getting Brand Code

    system("@cls||clear");

    if(!RangeCheck(Selected.Brand_Code,1,7))
    {
        system("@cls||clear");
        printf("\nInvalid Choice,Please Select A Valid Code\n\n");
        Display_Car_Brands();
    }
    else
        Display_Brand_Models();
}

void Display_Brand_Models()
{
    for(int i=Brands[Selected.Brand_Code-1].Car_Model_Starts_At;i<Brands[Selected.Brand_Code-1].Car_Model_Ends_At;i++)
            printf("%d - %s - Rs.%d\n",Models[i].Car_Code,Models[i].Model,Models[i].Car_Cost);

    printf("\nWhich Car Model You Want To Select: ");
    scanf("%d",&Selected.Model_Code); //Getting Model Code

    system("@cls||clear");

    if(!RangeCheck(Selected.Model_Code,Brands[Selected.Brand_Code-1].Car_Model_Starts_At+1,Brands[Selected.Brand_Code-1].Car_Model_Ends_At))
    {
        system("@cls||clear");
        printf("\nInvalid Choice,Please Select A Valid Code\n\n");
        Display_Brand_Models();
    }
    else
        Display_Car_Colours();
}

void Display_Car_Colours()
{
    printf("\nThese Are All The Available Car Colours:\n");

    for(int i=0;i<sizeof(Colours)/sizeof(struct Car_Colour);i++)
        printf("0%d - %s\n",Colours[i].Colour_Code,Colours[i].Colour_Name);
    
    printf("\nWhich Car Colour Would You Like To Opt For: ");
    scanf("%d",&Selected.Colour_Code); //Getting Colour Code

    if(!RangeCheck(Selected.Colour_Code,1,7))
    {
        system("@cls||clear");
        printf("\nInvalid Choice,Please Select A Valid Code\n\n");
        Display_Car_Colours();
    }
    else
    {
        char Start_Adding_Mods;
        printf("\nDo You Want To Modifications(Y/N): ");
        scanf(" %c",&Start_Adding_Mods);
        if(toupper(Start_Adding_Mods) == 'Y')
        {
            system("@cls||clear");
            Display_Modification_Types();
        }
    }
}

void Display_Modification_Types()
{

    printf("\nThese Are All The Available Car Modifications Types:\n");
    for(int i=0;i<sizeof(Mod_Types)/sizeof(struct Modification_Types);i++)
        printf("0%d - %s\n",Mod_Types[i].Mod_Type_Code,Mod_Types[i].Mod_Type);
    
    printf("\nWhich Car Modification Do You Want To Opt For : ");
    scanf("%d",&Selected.Mod_Type); //Getting Current Mod Type

    if(!RangeCheck(Selected.Mod_Type,1,6))
    {
        system("@cls||clear");
        printf("\nInvalid Choice,Please Select A Valid Code\n\n");
        Display_Modification_Types();
    }
    else
    {
        system("@cls||clear");
        Display_Modification_Sub_Types();
    }
}

void Display_Modification_Sub_Types()
{
    for(int i=Mod_Types[Selected.Mod_Type-1].Mod_Starts_At;i<Mod_Types[Selected.Mod_Type-1].Mod_Ends_At;i++)
        printf("%d - %s - Rs.%d\n",Car_Modification[i].Mod_Code,Car_Modification[i].Mod_Name,Car_Modification[i].Mod_Cost);
    
    printf("Which Type Of Modification Do You Want?: ");
    scanf("%d",&Selected.Mod_Sub_Type[Selected.Mod_Type-1]); //Storing Selected Sub Modifications In The Selected Array

    if(!RangeCheck(Selected.Mod_Sub_Type[Selected.Mod_Type-1],Mod_Types[Selected.Mod_Type-1].Mod_Starts_At,Mod_Types[Selected.Mod_Type-1].Mod_Ends_At))
    {
        system("@cls||clear");
        printf("\nInvalid Choice,Please Select A Valid Code\n\n");
        Display_Modification_Sub_Types();
    }
    else
    {
        char add_mode = 'N';
        printf("\nDo You Want To Add More Modifications(Y/N): ");
        scanf(" %c",&add_mode);
        if(toupper(add_mode) == 'Y')
        {
            Display_Modification_Types();
        }
    }
}

void Display_Bill()
{
    system("@cls||clear");
    SYSTEMTIME stime;
    GetSystemTime(&stime);
    int sml =1;
    for (int i = 0; i <= 120; i++) 
        printf("-");

    printf("\n\t\t\t\t\t\t     INFINITY CAR SHOP\n");

    for (int i = 0; i <= 120; i++)
        printf("-");
    printf("\n\n");
    printf("DATE: %d/%d/%d\t\t\t\t\t\t\t\t\t\tTIME: %s\n\n", stime.wDay, stime.wMonth, stime.wYear, __TIME__);
    printf("SHOP DETAILS :         \t\t\t\t\t\t            CUSTOMER DETAILS :\n\n");
    printf("INFINITY CAR SHOP         \t\t\t\t\t            CUSTOMER_NAME: %s\n", Current_User->User_Name);
    printf("E-420 PANDIT DEENDAYAL   \t\t\t\t\t            MOBILE NO    : %s\n", Current_User->Mobile_Number);
    printf("ENERGY UNIVERSITY,       \t\t\t\t\t            E-MAIL       : %s\n", Current_User->Email);
    printf("PDPU-ROAD, GANDHINAGAR.  \t\t\t\t\t            ADDRESS      : %s\n", Current_User->Address);
    printf("MOBILE N0 : 9832333736            \n");
    printf("          : 9832303837            \n");
    printf("E-MAIL    : infinitycar_2022@gmail.com\n\n");
    for (int i = 0; i <= 120; i++)
        printf(":");
    printf("\n\nCAR PURCHASED: \t\t\t\t SERIAL NUMBER: \t\t\t\t PRICE:\n\n");
    printf("%s",Models[Selected.Model_Code-1].Model);
    printf("\t\t\t GJ-18-%c%c-%d",'A'+rand()%26,'A'+rand()%26,rand()%9999);
    printf("\t\t\t\t         Rs.%d\n",Models[Selected.Model_Code-1].Car_Cost);
    printf("(%s)\n\n",Colours[Selected.Colour_Code-1].Colour_Name);

    for (int i = 0; i <= 120; i++)
    {
        printf("-");
    }
    printf("\n\n\t\t\t\t\t\t   MODIFICATIONS\n\n");
    for(int i=0;i<6;i++)
    {
        if(Selected.Mod_Sub_Type[i]!=0)
        {
            printf("%s\t\t\t\t\t\t\t\t\t Rs.%d\n",Car_Modification[Selected.Mod_Sub_Type[i]-1].Mod_Name,Car_Modification[Selected.Mod_Sub_Type[i]-1].Mod_Cost);
            Bill.Mod_Cost += Car_Modification[Selected.Mod_Sub_Type[i]-1].Mod_Cost;
        }
        else    
            printf("Default %s \t\t\t\t\t\t\t Rs.0\n",Mod_Types[i].Mod_Type);
    }
    Bill.Total_Price +=  Bill.Car_Cost; //Adding Car Cost To Total Price
    Bill.Total_Price +=  Bill.Mod_Cost; //Adding Mod Cost To Total Price
    Bill.Final_Price = Bill.Total_Price*(100+Bill.GST)/100; //Formula To Calculate Final Bill
    for (int i = 0; i <= 120; i++)
        printf("-");
    printf("\n\t\t\t\t\t\t\t\t MODIFICATION PRICE   : Rs.%llu\n",Bill.Mod_Cost);
    printf("\n\t\t\t\t\t\t\t\t TOTAL PRICE          : Rs.%llu\n",Bill.Total_Price);
    printf("\n\t\t\t\t\t\t\t\t +28%% GST             : Rs.%llu\n\n",Bill.Total_Price*28/100);
    for (int i = 0; i <= 120; i++)
        printf("-");
    //printf("\n\t\t\t\t\t\t\t\t FINAL PRICE          : Rs.%llu\n",Bill.Final_Price);
    printf("\nTOTAL PRICE (28%% GST)\t\t\t\t\t\t\t              : Rs.%llu\n", Bill.Final_Price);
    for (int i = 0; i <= 120; i++)
        printf("-");
    printf("\n\t\t\t\t\t %c %c %c THANK YOU! VISIT AGAIN !! %c %c %c\n", sml, sml, sml, sml, sml, sml);
    for (int i = 0; i <= 120; i++)
        printf("-");
}