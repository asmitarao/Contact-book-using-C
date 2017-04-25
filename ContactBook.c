#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Tree
{
	char fname[15];
	char lname[15];
	char num[12];
	char mail[23];
	char address[70];
	struct node *left; 
	struct node *right;
};
typedef struct Tree NODE;
NODE *root,*new,*hold;
void create(char fna[],char lna[],char nu[],char ma[],char ad[])
{
//NODE *new;
	new=(NODE *)malloc(sizeof(NODE));
	strcpy(new->fname,fna);
	strcpy(new->lname,lna);
	strcpy(new->num,nu);
	strcpy(new->mail,ma);
	strcpy(new->address,ad);
	new->left=NULL;
	new->right=NULL;
/*return(new);*/
}

int i;
int search_index=0; 
int display_index = 0;

void bstins(char fna[],char lna[],char nu[],char ma[],char ad[])
{
	NODE *temp = root;
	int flag=1;
	create(fna, lna, nu, ma, ad);
	if(root==NULL)
		root=new;
	else
	{
		
		while(flag)
		{
			//char a[15];
			//strcpy(new->fname,a);
			//char b[15];
			//strcpy(temp->fname,b);
			//int r=strcmp(a,b);
			if(strcmp(new->fname,temp->fname)<0)
			{
				if(temp->left==NULL)
				{
					temp->left=new;
					flag=0;
				}
				else
					temp=temp->left;
			}
			else if(strcmp(new->fname,temp->fname)>0)
			{
				if(temp->right==NULL)
				{
					temp->right=new;
					flag=0;
				}
				else
					temp=temp->right;
			}
			else if(strcmp(new->fname,temp->fname)==0)
			{
				//char c[15];
				//strcpy(new->lname,c);
				//char d[15];
				//strcpy(temp->lname,d);
				//int s=strcmp(c,d);
				if(strcmp(new->lname,temp->lname)<0)
				{
					if(temp->left==NULL)
					{
						temp->left=new;
						flag=0;
					}
					else
						temp=temp->left;
				}
				else if(strcmp(new->lname,temp->lname)>0 || strcmp(new->lname,temp->lname)==0)
				{
					if(temp->right==NULL)
					{
						temp->right=new;
						flag=0;
					}
					else
						temp=temp->right;
				}
			}
		}
		
	}	
}

void display(NODE *root)
{
    if (root != NULL) {
    display_index = 1;
        display(root->left);
       /* FILE *ptr = fopen( "display.txt", "w" );
        fprintf(ptr,display());
        fclose(ptr);*/
        printf("The first name of the contact is %s\n",root->fname);
		printf("the last name of the contact is %s\n",root->lname);
		printf("Number : \t%s\n",root->num);
		printf("Email : \t%s\n",root->mail);
		printf("Address :\t%s\n\n",root->address);
        //did not print residential address
        display(root->right);
    }  
}

void delete(char dfna[],char dlna[])
{ 
	NODE *temp,*parent,*q,*insucc;
	parent=NULL;
	q=NULL;
	if(root==NULL)
		printf("The contact book is empty\n");
	else
    {
		temp=root; 
	    while(temp!=NULL && strcmp(dfna,temp->fname)!=0)
    	{ 
	       parent=temp; 
      	   if(strcmp(dfna,temp->fname)<0)
          	  temp=temp->left;
			else if(strcmp(dfna,temp->fname)>0)
	          temp=temp->right;
     	}
     	
	while(temp!=NULL && strcmp(dlna,temp->lname)!=0)
    	{ 
      	    if(strcmp(dlna,temp->lname)<0)
          	  temp=temp->left;
			else if(strcmp(dlna,temp->lname)>0)
	          temp=temp->right;
     	}
    if(temp==NULL)
       printf("The given name not found");

    else if(temp->left==NULL)
        q=temp->right;
    else if(temp->right==NULL)
        q=temp->left;
    else 
     { insucc=temp->right;
       while(insucc->left!=NULL)
         insucc=insucc->left;
       insucc->left=temp->left;
       q=temp->right;
     }
     if(parent==NULL)
         root=q;    
     else if(temp == parent->left)
         parent->left=q;
     else
         parent->right=q;
	if(temp!=NULL)
	{	
		printf("the contact name to be deleted has been found in contact list\n the contact details are :\n\n");		
		printf("The first name of the contact is %s\n",temp->fname);
		printf("the last name of the contact is %s\n",temp->lname);
		printf("Number : \t%s\n",temp->num);
		printf("Email : \t%s\n",temp->mail);
		printf("Address :\t%s\n\n",temp->address);
		free(temp);
	}
}

}

void search(NODE *root , char s_fname[])
{
	NODE *temp;
	temp=root;
	if(root != NULL)
	{
		search(root->left, s_fname);
		if(strstr(root->fname,s_fname))
		{
			printf("The first name of the contact is %s\n",root->fname);
			printf("the last name of the contact is %s\n",root->lname);
			printf("Number : \t%s\n",root->num);
			printf("Email : \t%s\n",root->mail);
			printf("Address :\t%s\n\n",root->address);
			search_index=1;	
    	}
		search(root->right, s_fname);
	}
		
}

int main(void)
{ 
	system("clear");
	root=NULL;
	int ch=0;
	char first_name[15]={0};
	char last_name[15]={0};
	char contact[12]={0};
	char email[35]={0};
	char adre[80]={0};
	char s_fname[10]={0};
	char del_first[15]={0};
    char del_last[15]={0};
	
	while(1)
	{
		printf(" \n 1.Insert a new contact \n 2.Delete a contact  \n 3.Search a contact \n 4.Display all contacts \n 5.Exit the application \n\n");
		printf("Enter the choice to select\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter First name\n");
				scanf("%s",first_name);
				printf("Enter last name without spaces\n");
				scanf("%s",last_name);
				printf("Enter number\n");
				scanf("%s",contact);
				printf("Enter Email\n");
				scanf("%s",email);
				printf("Enter address without spaces (give commas to separate the fields)\n");
				scanf("%s",adre);
				bstins(first_name,last_name,contact,email,adre);
				break;
			case 2:
				printf("Enter the first name of the contact to be deleted\n");
                scanf("%s",del_first);
			    printf("Enter the last name of the contact to be deleted\n");
				scanf("%s",del_last);
                delete(del_first,del_last);
				break;
			case 3:
				search_index = 0;
				printf("Enter the first name of the contact(s) you want to search for ...\n");
				scanf("%s",s_fname);
				printf("searching contact ....\n\n");
				search(root , s_fname);
				if(search_index == 0)
					printf("No contacts found !! \n\n");
				break;
			case 4:
				display_index = 0;
		 		display(root);
		 		if(display_index == 0)
					printf("Contact list is empty !! \n\n");
				break;
			case 5:
				exit(0);
				break;
			default: printf("Invalid Option , Exiting the Program\n");
				exit(1);
		}
	
	}
	return 0;
}
