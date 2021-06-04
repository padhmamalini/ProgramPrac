// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Singly linked list Practise

#include <iostream>
using namespace std;
/* Struct Node - Represent a single node*/
class node
{
public:
    int data;//Linked list Data
     node *next; // Pointer - address to access
};
/*Insert the element at the end
  Parameters: 
  head --> A reference to the head address that have been passed from main
  data --> A element that need to be appended 
  */
void insert_end(node** head, int data)
{
    node* new_node = new node();
    node *last = *head;
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        return ;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}
/*insert the element at the begining
Parameter:
head - Head address
data - data to be inserted*/
void insert_front(node** head, int data)
{
    node* new_node = new node();
    new_node->data = data; 
    new_node->next = *head; //Making head node as next node
    *head = new_node; //Making new node as head node
}
/* Insert element at the specific position*/
void insertPos(node *head,int pos, int data)
{
    if (pos < 0)
    {
        cout << "Position is invalid!! Position must be positive" << endl;
        return;
    }
    node* snode = head;
    int i;
    //Traversing the linked list and finding the positions address
    for (i = 0; snode && snode->next && i < pos; snode = snode->next, ++i) {}
    if (i != pos)//position not available in the list or position beyond the size
    {
        cout << "Position Not available in the list!!! Try another position" << endl;
        cout << "Total number of elements available in the list: " << i+1 << endl;
        return;
    }
    node* new_node = new node;
    new_node->data = data;
    new_node->next = snode ? snode->next : NULL;
    if (snode)
        snode->next = new_node;
}

/*delete the element of the given position */
void deleteNode(node **ref, int pos)
{
    if (*ref == NULL)
        return;
    node* temp = *ref;
    if (pos == 0)
    {
        *ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
        return;
    node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
/* Print the Linked list*/
void traverse(node* node)
{
    while (node != NULL)
    {
        cout << " " << node->data<<" -> ";
        node = node->next;
    }
}
/*Option that need to be selected for 
i)   append
ii)  insert at the beginning 
iii) insert the element at the specific position
iv)  delete the element at the end
v)   delete the element from specific position
vi)  Traverse or Display the linked list*/
int option()
{
    int opt;
    cout << "\n==============================================" << endl;
    cout << "Enter your choice of operation:" << endl;
    cout << "Press 1 to insert specific element at the End" << endl;
    cout << "Press 2 to insert the element at the beginning" << endl;
    cout << "Press 3 to insert the element at the specific position after which to be added" << endl;
    cout << "Press 4 to delete the element fro the linked list" << endl;
    cout << "Press 5 to Print the list in reverse order" << endl;
    cout << "Press 6 to print the list" << endl;
    cout << "Press 7 to Quit!!" << endl;
    cout << "==============================================" << endl;
    cin >> opt;
    cout << endl;
    return opt;
}
int main()
{
    cout<<"Linked list Demo:" << endl;
    cout<<"=====================" << endl;
    int choice = option();
     node* head = NULL; // Initialis=zing with empty list
     int element; //Element to be added or deleted
     int position; // Position at which the insertion or deletion to be made
     while (choice != 7)
    {
        
        switch (choice)
        {
        case 1:
        {
            //Append the element to the list
            cout << "Input the number to be appended: ";
            cin >> element;
            insert_end(&head, element);
            break;
        }
        case 2:
        {
            //Insert at the begining
            cout << "Input the number to be added at beginning: ";
            cin >> element;
            insert_front(&head, element);
            break;
        }
        case 3:
        {
            //Insert the element at the speccific position
            cout << "Enter the Position after which the element need to be inserted:";
            cin >> position;
            cout << "\nInput the number to be added at the position "<<position<<" : ";
            cin >> element;
            insertPos(head,position-1,element);
            break;
        }
        case 4:
        {
            //Delete a element
            cout << "Enter the Position of the element that need to be deleted";
            cin >> position;
            deleteNode(&head, position-1);
            break;
        }
        /*case 5:
        {
            revTraverse(head);
        }*/
        case 6:
        {
            // Print the element
            traverse(head);
            break;
        }
        default:
        {
            cout<<"Enter the valid choice!!If you need to exit input 7";
            break;
        }
        }
        choice = option();
    }
    


}
