#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node * root;

int ln;

void create_node()
{
    struct node * temp; 
    temp = (struct node *) malloc(sizeof(struct node));
    printf("Enter Data \n");
    scanf("%d", &temp->data);
    temp->next= NULL;
    if (root==NULL)
    {
        root = temp;
    }
    else
    {
        struct node * ptr = root;
        while (ptr->next != NULL)
        {
            ptr= ptr->next;
        }
        ptr->next = temp;
    }
}


void display_node()
{
    struct node * temp = root;
    if (temp == NULL)
    {
        printf("Empty List \n\n");
    }
    else
    {
        while(temp != NULL)
            {
               printf("%d -->",temp->data);
               temp = temp->next;
            }
            printf("End of list\n\n");
    }
}

void delete()
{
    struct node * temp;
    int loc;
    printf("Enter the location want to delete\n");
    scanf("%d",&loc);
    if (loc>ln)
    {
        printf("Invalid location\n\n");
        exit(1);
    }
    else if (loc==1)
    {
        temp = root;
        root = temp->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        struct node * ptr = root, *q;
        int i = 1;
        while(i<loc-1)
        {
            ptr = ptr->next;
            i++;
        }
        q = ptr->next;
        ptr->next = q->next;
        q->next = NULL;
        free(q);
    }
    
    display_node();
}


void add_node()
{
    struct node * temp, *p;
    int loc, i=1;
    printf("Enter location to add node\n");
    scanf("%d", &loc);
    if(loc>ln)
    {
        printf("Invalid location\n");
        exit(1);
    }
    else
    {
        p = root;
        while(i<loc)
        {
            p=p->next;
            i++;  
        }
        temp= (struct node *)malloc(sizeof(struct node));
        printf("Enter new node data\n");
        scanf("%d",&temp->data);
        temp->next=NULL;
        temp->next= p->next;
        p->next= temp;

    }
    display_node();
}

void reverse_node()
{
    struct node * p, *q;
    p=q=root;
    int i=0,j=ln-1, k, temp;
    while (i<j)
    {
        k=0;
        while(k<j)
        {
            q=q->next;
            k++;

        }
        temp = p->data;
        p->data = q->data;
        q->data = temp;
        i++; 
        j--;
        p=p->next;
        q=root;
    }

}


void main()
{   
    int ch;
    printf("enter length: \n");
    scanf("%d", &ln);
    for (int i=0;i<ln;i++)
    {
        create_node();
    }

    display_node();

    printf("Select Operation\n1:Delete from position\n2:Add to position\n3:Reverse list\n\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            delete();
            
            break;
        case 2:
            add_node();
            break;
        case 3:
            reverse_node();
            display_node();
            break;
        default:
            printf("Invalid Selection\n\n");
    }
}
