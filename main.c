#include<stdio.h>
#include<conio.h>
#include<stdlib.h> 
#include<string.h>
#include<time.h>
int today_customer=0;
int total_income=0;
int item_id;
int cust_id=0;
void add_item();
int flag=0;
struct Item
{
	char name[50]; 
	int item_id;
	float rating;
	float price; 
	struct Item *next;
	struct Item *prev;
} ;
struct Item *head;
struct Item *last;

//int customer_id=1;
struct order{
	int customer_id;
	int items[20][3];
	int amount;
	struct order *next;
	struct order *prev;
};
struct  order *head1;
struct order *last1; 

struct Item *get_new_item( int id,char i[],float p,float rating )
{
	struct Item* temp=(struct Item*)malloc(sizeof(struct Item)); 
	
	 temp->item_id=id;
	strcpy(temp->name,i);
	temp->rating=rating;//get by function
	temp->price=p;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
} 

void insert(int id,char n[],float p,float rating)
{
	struct Item *get_new_item( int id,char i[],float p,float rating);
	struct Item *New;
	struct Item *dummy;
	New=get_new_item(id,n,p,rating);
	
	if(head==NULL)
	{
		head=New;
	
		
	} 
	else
	{
		
		dummy=head;
		while(dummy->next!=NULL) 
		 dummy=dummy->next;
		 dummy->next=New;
		 New->prev=dummy;
	
	} 
	
	
} 
struct order *get_new_order()
{ 
   struct order *temp=(struct order*)malloc(sizeof(struct order));
   temp->next=NULL;
   temp->prev=NULL;
   return temp;
} 
void display()
{  
     
    system("cls");
    struct Item *headd;
	printf("                       DIYA'S CAFE                          \n\n");
	printf("                          MENU                               \n\n\n");
	printf("ID         Item Name            Price         RATING\n");
	if(flag==0)
	{
	
	insert(1,"DABELI",15,4.4);
	insert(2,"BURGER",20,4.5);
	insert(3,"PIZZA",150,4.6);
	insert(4,"PANI-PURI",20,3.4);
	insert(5,"CHINESE",90,4.4);
	insert(6,"PASTTA",70,4.9); 
	flag++;
}
	
	struct Item *tempp=head;
	if(head==NULL)
	{
		printf("empty");
	} 
	while(tempp!=NULL)
	{
		printf("%d         %s         %f         %f\n",tempp->item_id,tempp->name,tempp->price,tempp->rating);
		tempp=tempp->next;
	} 
	printf("--------------------------------------------------------------");
	

	
} 

void order(){ 
   int a[10] [2];
   int n,j=0,i=0;
   time_t t;
   time(&t);
  printf("\n Taking your order:\n");
   do{ 
   	   printf("\nplease enter the food id of item and its quantity:");
   	   for(i=0;i<2;i++) 
   	       {
   	       	     scanf("\n %d",&a[j][i]);
			}
			j++;
			printf("\n you want to add more item:(press 1)\n");
			scanf("%d",&n);
   } while(n==1);
   int total_amount;
   char name[25];
   printf("enter your name:\n");
   scanf("%s",&name);
   int k; 
   system("cls");
   printf("\n__________________________________________________________________________________\n");
   printf("\n                                       BILL                                      \n");
   printf("\n Name:-%s",name);
   printf("\n Date:-%s",ctime(&t));
  // printf("\n _______________________________________________________________________\n");
	printf("\nId        Item_name        qty        price\n");
   
   for( k=0;k<j;k++) 
   {  

   	  struct Item *temp=head; 
	   if(head==NULL)
     	{
		printf("empty");
	    } 
	  
   	    while((temp->item_id)!=a[k][0])
   	    {  
   	  	   temp=temp->next;
		 } 
		 printf("\n_______________________________________________________________________\n");
		 
		 printf("\n%d        %s        %d        %f",temp->item_id,temp->name,a[k][1],(a[k][1]*(temp->price)));   
         total_amount= total_amount+(a[k][1]*(temp->price));
 } 
 printf("\n________________________________________________________________");
 printf("\n total payble amount is:-%d\n",total_amount); 
 printf("\n Have a great meal :)");
 
struct order *get_new_order();
struct order *temp2;
cust_id++;
temp2=get_new_order();
temp2->amount=total_amount;
temp2->customer_id=cust_id;
int p,s;
for(p=0;p<j;p++) 
{
	for(s=0;s<2;s++)
	{ 
	   temp2->items[p][s]=a[p][s];
	}
} 
if(head1==NULL)
{
	head1=temp2;
	last1=temp2;
}
else
{
	last1->next=temp2;
	temp2->prev=last1;
	last1=temp2;
} 
 today_customer++;
 total_income= total_income+total_amount;
 
} 
 void display_order_history()
 {
 	 printf("\n order history\n");
 	 printf("SR_NO      AMOUNT\n");
 	 struct order *temp;
 	 temp=head1;
 	 if(head1==NULL)
 	 {
 	 	printf("empty");
	  } 
	  
	  while(temp!=NULL)
	  {
	  	   printf("%d     %d\n",temp->customer_id,temp->amount);
	  	   temp=temp->next;
	  }
 }
int login()
{
	 char username[20];
	 char userpwd[11];
	 int i;
	 system("cls");
	 printf("\n enter your username:");
	 scanf("%s",username);
	 printf("\n Enter your password:");
	 for(i=0;i<10;i++)
	 {
	 	 userpwd[i]=getch();
	 	 printf("*");
	 } 
	 userpwd[i]='\0'; 
	 if((strcmp(username,"admin")==0 )&&(strcmp(userpwd,"diya116200")==0)) 
	 {
	 	printf("\n logged in susscessfully\n");
	 	return 1;
	 } 
	 else
	 {
	  
	  printf("\n incorrect username or passeword");
	  return 0; 
}
 }
	  
void display_options() 
{ 
   int choice,ans;
	do{
		printf("It is admin pannel:\n");
		printf("\n 1)show customer data \n 2)total income \n 3)show  total number of customer visited \n  4)add dish \n5)exit");
          scanf("%d",&choice);        

		 switch(choice) 
	     {
	     	case 1: display_order_history();
	     		break;
	     	case 2:printf("\n today's total income:%d/n", total_income);
	     	     break;
	     	case 3:printf("\n total customer visited:%d",today_customer);
	     	     break;
	     	case 4:add_item();
	     	 break;
	     	case 5:
			   exit(0);
			   break;      
	     	       
		 }
		 printf("\n Do you want to do some action:");
		scanf("%d",&ans);	
	} 
	while(ans==1);
} 
void add_item()
{   
    char  s[20];
    float price,rating;
    int id,ans;
    do{
	
    printf("\n enter id of  this dish");
    scanf("%d",&id);
	printf("\n enter name of dish:");
	scanf("%s",&s);
	printf("\n enter price of dish:");
	scanf("%f",&price);
	printf("\n enter rating of the dish out of 5:");
	scanf("%f",&rating); 
	insert(id,s,price,rating);
	printf("\n want to enter more dishes");
	scanf("%d",&ans);
}
while(ans==1);
	
}

int main()
{ 
   int ans,anss;
   int choice;


	do{  
	    system("cls");
	     printf("_______________________________________________________________________________________________________________________\n");
	     printf("                                                      DIYA'S CAFE                                                 \n");
	     printf("________________________________________________________________________________________________________________________\n");
	     printf("\nHello,welcome to diya's cafe.....when you put your stress outside :) :) :)\n");
	     printf("\n choose who you are:\n");
	     printf(" 1)customer\n 2)admin \n 3)exit\n");
		scanf("%d",&choice);
	     switch(choice) 
	     {
	     	case 1: display();
	     	         printf("\n\nwant to order something?");
	     	         scanf("%d",&ans);
	     	         if(ans==1) 
	     	          order();
	     	          else 
	     	             break;
	     		break;
	     		
	     	case 2:  
			        do{
					if(login())
	     	        {
					 system("cls");
					  display_options();
					  break;
	     	        
					} 
	     	        else{
					 
	     	         printf("\nwant to login again");
	     	         scanf("%d",&anss); 
					  }
	     	        
	     	       } while(anss==1);
					 
	     	 break;
	     	case 3:
			   exit(0);
			   break;      
	     	       
		 }
		printf("\n main pannel(home)press 1:");
		scanf("%d",&ans);
	} 
	while(ans==1); 
    }
