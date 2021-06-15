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
//To find whether the given linked list is empty
bool isEmpty(node* head,string msg)
{
    if (head == NULL)
    {
        cout << "First create your linked list and try to " << msg << endl;
        return true;
    }
    else
        return false;
}
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
    if (isEmpty(*ref,"delete the node of specified position"))
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
//Delete first node of the linked list
void deleteFirstNode(node* &head)
{
    if (isEmpty(head,"delete first node"))
        return;
    node* temp = head;
    head = (head)->next;
    free(temp);
    return;
}
void deleteAll(node* &head)
{
    if(isEmpty(head,"delete all nodes"))
        return;
    node* prev = head;
    while (head)
    {
        head = head->next;
        free(prev);
        prev = head;
    }
    cout << "deleted all nodes";
}
//Delete all occurance of a number from the linked list.
node* deleteAllBasedOnData(node *head,int num)
{
    if (isEmpty(head, "delete all occurance of the element"))
        return NULL;
    node *curr = head;
    while (head->data == num)
    {
        if (head->next)
        {
            head = head->next;
        }
        else
        {
            cout << "Deleted given element from the linked list";
            return NULL;
        }
    }
    while (curr->next)
    {
        if (curr->next->data == num)
        {
            curr->next = curr->next->next;
        }
        else
            curr = curr->next;
    }
    cout << "Deleted All occurance of the given data!!";
    return head;
}
//Find the Duplicate element in the linked list and remove duplicate occurance from the linked list.
void removeDuplicate(node* ref)
{
    node *temp1, *temp2, * duplicate;
    temp1 = ref;
    int flag = 0;
    while (temp1 && temp1->next)
    {
        temp2 = temp1;
        while (temp2->next)
        {
            if (temp1->data == temp2->next->data)
            {
                duplicate = temp2->next;
                temp2->next = temp2->next->next;
                free(duplicate);
                flag++;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
    cout << "Number of duplicate elements :" << flag << " ,are removed from the linked list" << endl;
    cout << "Linked list now contains only identical element!!" << endl;
}
//Update the element in the specific postion
void updateList(node **ref, int pos, int element)
{
    if (pos < 0)
    {
        cout << "Position is invalid!! Position must be positive" << endl;
        return;
    }
    if (isEmpty(*ref,"update the linked list"))
        return;
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
    
    if (isEmpty(head,"sort the elements in it"))
        return;
    node* curr, * currNext;
    curr = head;
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
    if (isEmpty(head,"search the element from the list"))
        return;
    while (head != NULL)
    {
        if (head->data == element)
        {
            cout << "Element: "<<element<<" found at " << pos;
            return;
        }
        pos++;
        head=head->next;
    }
    cout << "Element is not available in the list. Try new element" << endl;
}
//Get middle element of the linked list using Two pointer technique.
void getMiddleEle(node* head)
{
    if (isEmpty(head,"get middle element from the linked list"))
        return;
    node* first = head;
    node* sec = head;
    int pos = 1;
    while (sec && sec->next)
    {
        first = first->next;
        sec = sec->next->next;
        pos++;
    }
    cout << "Middle element of the given linked list is :" << first->data<<" , presented at the position :"<<pos<<endl;
}
//Reverse the linked list
void reverseList(node** head)
{
    if (isEmpty(*head,"reverst the list"))
        return;
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
/*Finding Loop using two pointer algorithm*/
void detectLoop(node* head)
{
    node *ptr1 = head, *ptr2 = head;
    while (ptr1 && ptr2 && ptr2->next)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
        if (ptr1 == ptr2)
        {
            cout << "Loop identified"<<endl;
            return;
        }
    }
    cout << "Loop not found!!"<<endl;
}
/* Print the Linked list*/
void traverse(node* node)
{
    if (isEmpty(node,"traverse or print the list"))
        return;
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
    cout << "Press 6 to delete the first element from the linnked list" << endl;
    cout << "Press 7 to delete all elements" << endl;
    cout << "Press 8 to delete all occurance of the number from the linked list" << endl;
    cout << "Press 9 to delete the duplicate elements from the linked list" << endl;
    cout << "Press 10 to update the element of the specific position in linked list"<<endl;
    cout << "Press 11 to sort the linked list" << endl;
    cout << "Press 12 to find the element in the list" << endl;
    cout << "Press 13 to find the middle element from the linked list" << endl;
    cout << "Press 14 to Reverse the linked list" << endl;
    cout << "Press 15 to detect if there is loop in the linked list" << endl;
    cout << "Press 16 to print the list" << endl;
    cout << "Press 17 to Quit!!" << endl;
    cout << "==============================================" << endl;
    cin >> opt;
    cout << endl;
    return opt;
}
int main()
{
    cout<<"Singly Linked list Demo:" << endl;
    cout<<"=====================" << endl;
    int choice = option();
     node* head = NULL; // Initialis=zing with empty list
     int element; //Element to be added or deleted
     int position; // Position at which the insertion or deletion to be made
     while (choice != 17)
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
            //Remove first element from the linked list
            deleteFirstNode(head);
            break;
        }
        case 7:
        {
            //Delete all elements from linked list
            deleteAll(head);
            break;
        }
        case 8:
        {
            //Delete specific number from the linked list
            cout << "Enter the element that need to be searched and deleted ";
            cin >> element;
            head= deleteAllBasedOnData(head,element);
            break;
        }
        case 9:
        {
            //To remove duplicate occurance of the number from the linked list
            removeDuplicate(head);
            break;
        }
        case 10:
        {
            //Update the element at the specific position
            cout << "Enter the Position of the element to be updated: ";
            cin >> position;
            cout << "\nEnter the element that to be updated at the position " << position<<" :";
            cin >> element;
            updateList(&head, position, element);
            break;
        }
        case 11:
        {
            //To sort the available linked list
            sortList(head);
            break;
        }
        case 12:
        {
            //Search the element position in the linked list
            cout << "Enter the element that need to be searched in the list: ";
            cin >> element;
            search(head,element);
            break;
        }
        case 13:
        {
            //Get the middle element of the linked list using Two pointer technique
            getMiddleEle(head);
            break;
        }
        case 14:
        {
            //Reverse the linked list
            reverseList(&head);
            break;
        }
        case 15:
        {
            //Created loop to test while writing the code- head->next->next = head;
            detectLoop(head);
            break;
        }
        case 16:
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
    cout << "Quitinng!!! catch you later";
}
