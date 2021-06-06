// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Singly linked list Practise

#include <iostream>
#include <stack>
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
/*Delete last node of the linked list*/
void deleteLastNdoe(node** head)
{
    while (*head && (*head)->next)
        head = &(*head)->next;
    free(*head);   /**/
    *head = NULL;  
}
//Update the element in the specific postion
void updateList(node **ref, int pos, int element)
{
    if (pos < 0)
    {
        cout << "Position is invalid!! Position must be positive" << endl;
        return;
    }
    if (*ref == NULL)
    {
        cout << "No elements available build your linked list first" << endl;
        return;
    }
    node* temp = *ref;
    int i;
    for (i = 0; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        cout << "Position not availalble!! Try another position for updating" << endl;
        cout << "Maximum Number of position available : " << i;
        return;
    }
    temp->data=element;
}
//Sort the given linked list
void sortList(node* head)
{
    node* curr, * currNext;
    curr = head;
    if (curr == NULL)
    {
        cout << "No Elements to sort. Build your own linked list and try sorting";
        return;
    }
    while(curr)
    {
        currNext = head;
        while (currNext->next)
        {
            if (currNext->data >= currNext->next->data)
            {
                swap(currNext->next->data, currNext->data);
            }
            currNext = currNext->next;
        }
        curr = curr->next;
    }

}
//To Search specific element or to find the element's position in the list
void search(node* head,int element)
{
    int pos=1;
    if (head == NULL)
    {
        cout << "No elements presented in the list. First build your linked list and try searching the element in it!!" << endl;
        return;
    }
    while (head != NULL)
    {
        if (head->data == element)
        {
            cout << "Element- "<<element<<" found at " << pos;
            return;
        }
        pos++;
        head=head->next;
    }
    cout << "Element is not available in the list. Try new element" << endl;
}
//Reverse the linked list
void reverseList(node** head)
{
    if (*head == NULL)
    {
        cout << "Prepare the linked first to reverse it" << endl;
        return;
    }
    stack<node*> s; //Creating temp stack memory and storing it to list after reversing
    node* temp = *head;
    while (temp->next)
    {
        s.push(temp);
        temp = temp->next;
    }
    *head = temp;
    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}
/* Print the Linked list*/
void traverse(node* node)
{
    if (node == NULL)
    {
        cout << "No elements to print. Build your new list" << endl;
        return;
    }
    while (node != NULL)
    {
        cout << " " << node->data<<" -> ";
        node = node->next;
    }
}
/*Option that need to be selected for 
1) append
2) insert at the beginning 
3) insert the element at the specific position
4) delete the element from specific position
5) delete the element from end
6) Update the element in the specific position
7) Sort the element in the linked list
8) Search the element from the linked list
9) Reverse the linked list
10) Traverse or Display the linked list*/
int option()
{
    int opt;
    cout << "\n==============================================" << endl;
    cout << "Enter your choice of operation:" << endl;
    cout << "Press 1 to insert specific element at the End" << endl;
    cout << "Press 2 to insert the element at the beginning" << endl;
    cout << "Press 3 to insert the element at the specific position after which to be added" << endl;
    cout << "Press 4 to delete the element from the linked list from specific position" << endl;
    cout << "Press 5 to delete the last element from the linked list" << endl;
    cout << "Press 6 to update the element of the specific position in linked list"<<endl;
    cout << "Press 7 to sort the linked list" << endl;
    cout << "Press 8 to find the element in the list" << endl;
    cout << "Press 9 to Reverse the linked list" << endl;
    cout << "Press 10 to print the list" << endl;
    cout << "Press 11 to Quit!!" << endl;
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
     while (choice != 11)
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
            cin>>position;
            cout<< "\nInput the number to be added at the position "<<position<<" : ";
            cin>>element;
            insertPos(head,position-1,element);
            break;
        }
        case 4:
        {
            //Delete a element
            cout<<"Enter the Position of the element that need to be deleted";
            cin>>position;
            deleteNode(&head, position-1);
            break;
        }
        case 5:
        {
            //Remove last element from the linked list.
            deleteLastNdoe(&head);
            break;
        }
        case 6:
        {
            //Update the element at the specific position
            cout << "Enter the Position of the element to be updated: ";
            cin >> position;
            cout << "\nEnter the element that to be updated at the position " << position<<" :";
            cin >> element;
            updateList(&head, position, element);
            break;
        }
        case 7:
        {
            //To sort the available linked list
            sortList(head);
            break;
        }
        case 8:
        {
            //Search the element position in the linked list
            cout << "Enter the element that need to be searched in the list: ";
            cin >> element;
            search(head,element);
            break;
        }
        case 9:
        {
            //Reverse the linked list
            reverseList(&head);
            break;
        }
        case 10:
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
