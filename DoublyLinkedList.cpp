#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node* prev;
};
//To find whether the given linked list is empty
bool isEmpty(node* head, string msg)
{
	if (head == NULL)
	{
		cout << "First create your linked list and try to " << msg << endl;
		return true;
	}
	else
		return false;
}
//Insert the node at beggining
void insertFront(node** head, int ele)
{
	node* new_node = new node();//Created new node
	new_node->data = ele; //Added data to it
	new_node->next = *head;//Made new nodes next pointer to head
	new_node->prev = NULL;//As it is first node make its prev node as null
	if (*head!=NULL)
		(*head)->prev = new_node;//fixing head prev as new_node
	*head = new_node;
}
//Insert at End or append the element
void insertEnd(node** head, int ele)
{
	node* new_node = new node();
	node* last = *head;
	new_node->data = ele;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return;
	}
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	return;

}
//Insert at the specific poition of  the doubly linked list
void insertAtposition(node* head, int position, int element)
{
	if (isEmpty(head, "insert at specific position"))
		return;
	if (position < 0)
	{
		cout << "Invalid position!!";
		return;
    }
	node* temp, *q;
	int i;
	q = head;
	for (i = 1; i < position&&q->next; i++)
		q = q->next;
	if (i<position-1)
	{
		cout << "Position not available in the linked list" << endl;
		return;
	}

	temp = new node();
	temp->data = element;
	if (q->next == NULL)
	{
		q->next = temp;
		temp->next = NULL;
		temp->prev = q;
	}
	else
	{
		temp->next = q->next;
		temp->next->prev = temp;
		q->next = temp;
		temp->prev = q;
	}
	cout << "Element is inserted in the position" << endl;
}
void deletePosition(node** head, int pos)
{
	if(isEmpty(*head,"delete the data"))
		return;
	if (pos < 1)
	{
		cout << "Enter the valid position to delete it!!";
		return;
	}
	node* curr = *head;
	int i;
	for (i = 1; curr != NULL && i < pos; i++)
	{
		curr = curr->next;
	}
	if (curr == NULL)
	{
		cout<<"Position not avaialble try different position"<<endl;
		cout << "Total number of elements in the linked list : " << i << endl;
		return;
	}
	if (*head == curr)
		*head = curr->next;
	if (curr->next)
		curr->next->prev = curr->prev;
	if (curr->prev)
		curr->prev->next = curr->next;
	free(curr);
	cout << "Deleted node from the inputed position: " << pos;
}
//Delete all occurance of the specific number from the doubly linked list
void deleteAllOcc(node** head, int ele)
{
	if (isEmpty(*head, "delete all elements from list"))
		return;
	node* curr = *head;
	node* next;
	while (curr)
	{
		if (curr->data == ele)
		{
			next = curr->next;

		}
	}
}
//Delete all elements from the doubly linked list
void deleteAllElements(node* &head)
{
	if (isEmpty(head, "delete all nodes"))
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
void UpdateData(node* head, int oldEle , int newEle)
{
	int pos = 1;
	bool flag = true;
	if (isEmpty(head, "update the element"))
		return;
	node* curr;
	curr = head;
	while (curr!=NULL)
	{
		pos++;
		if (curr->data == oldEle)
		{
			curr->data = newEle;
			cout << "Found " << oldEle << "at the position " << pos << " and replaced with new element " << newEle<<endl;
			flag = false;
		}
		if (curr->next != NULL)
			curr = curr->next;
		else
			break;
	}
	if (flag)
		cout << "The element " << oldEle << " not found in the list.Try to update different element"<<endl;
	
}
//to remove duplicate element from the doubly linked list
void removeDuplicate(node *head)
{
	if (isEmpty(head,"remove the duplicate element"))
		return;
	node *curr,*temp,*dup;
	curr = head;
	while (curr!=NULL && curr->next!=NULL)
	{
		temp = curr;
		while (temp->next)
		{
			if (curr->data == temp->next->data)
			{
				dup = temp->next;
				temp->next = temp->next->next;
				free(dup);
			}
			else
				temp = temp->next;
		}
		curr = curr->next;
	}
	cout << "Removed duplicate elements!!" << endl;
}
//To Find the middle element and delete it from the list
node* delMiddleEle(node* head)
{
	if (isEmpty(head, "delete middle element"))
		return NULL;
	if (head->next==NULL)
	{
		free (head);
		cout << "Deleted Middle element";
		return NULL;
	}
	node* ptr1 = head;
	node* ptr2 = head;
	node* prev = NULL;
	while (ptr2 && ptr2->next)
	{
		ptr2 = ptr2->next->next;
		prev = ptr1;
		ptr1 = ptr1->next;
	}
	prev->next = ptr1->next;
	free(ptr1);
	cout << "Deleted middle element" << endl;
	return head;
}
//To search the element from the list
void searchElement(node* head,int element)
{
	int pos = 1;
	if (isEmpty(head, "search the element from the list"))
		return;
	while (head != NULL)
	{
		if (head->data == element)
		{
			cout << "Element: " << element << " found at " << pos;
			return;
		}
		pos++;
		head = head->next;
	}
	cout << "Element is not available in the list. Try new element" << endl;
}
//To sort the doubly linked list
void sortList(node* head)
{
	if (isEmpty(head, "sort the list"))
		return;
	node* curr, * currNext;
	curr = head;
	while (curr)
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
//Traverse the Doubly linked list
void traverse(node* head)
{
	if (isEmpty(head, "traverse or print the list"))
		return;
	while (head != NULL)
	{
		cout << " " << head->data << " -> ";
		head = head->next;
	}
	cout << "NULL" << endl;
}
int option()
{
	int opt;
	cout << "\n==============================================" << endl;
	cout << "Enter your choice of operation:" << endl;
	cout << "Press 1 to insert a element at Beginning of the list" << endl;
	cout << "Press 2 to insert a element at end of the list" << endl;
	cout << "Press 3 to insert a element at specific position" << endl;
	cout << "Press 4 to delete a element at specific position" << endl;
	cout << "Press 5 to delete all occurance of the element" << endl;
	cout << "Press 6 to delete the element at the speciffic position" << endl;
	cout << "Press 7 to delete all elements in the doubly linked list" << endl;
	cout << "Press 8 to remove the duplicate element from the list" << endl;
	cout << "Press 9 to delete the middle element" << endl;
	cout << "Press 10 to update the element inputed from the list" << endl;	
	cout << "Press 11 to search" << endl;
	cout << "Press 12 to sort" << endl;
	cout << "Press 13 to traverse" << endl;
	cout << "Press 14 to Quit" << endl;
	cout << "==============================================" << endl;
	cin >> opt;
	cout << endl;
	return opt;
}
int main()
{
	node* head = NULL;//Initializing the list
	cout << "Doubly linked list Demo!!" << endl;
	int choice = option();
	int element, position;
	while (choice != 14)
	{
		switch (choice)
		{
		case 1:
		{
			cout<<"Enter the Element to be inserted at first ";
			cin>>element;
			insertFront(&head,element);
			break;
		}
		case 2:
		{
			cout<<"Enter the Element to be appended to the linked list";
			cin>>element;
			insertEnd(&head, element);
			break;
		}
		case 3:
		{
			cout<<"Enter the Position where the element to inserted in linked list ";
			cin>>position;
			cout<<"\nEnter the element that need to be inserted at the position " << position<<" :";
			cin>>element;
			insertAtposition(head, position, element);
			break;
		}
		case 4:
		{
			cout<<"Enter the Position of element to delete : ";
			cin>>position;
			deletePosition(&head, position);
			break;
		}
		case 5:
		{
			cout<<"Enter the element for which all occurance of it need to be deleted from the list ";
			cin >> element;
			deleteAllOcc(&head, element);
			break;
		}
		case 6:
		{
			cout << "Enter the position of the element that need to be deleted from the list ";
			cin >> position;
			break;
		}
		case 7:
		{
			deleteAllElements(head);
			break;
		}
		case 8:
		{
			removeDuplicate(head);
			break;
		}
		case 9:
		{
			head=delMiddleEle(head);
			break;
		}
		case 10:
		{
			int newEle;
			cout<<"Enter the Data that need to be update ";
			cin >> element;
			cout << "\nEnter the number to be updated instead of  " << element << " :";
			cin >> newEle;
			UpdateData(head, element, newEle);
			break;
		}
		
		case 11:
		{
			cout << "Enter the Element to be searched from the list ";
			cin >> element;
			searchElement(head, element);
			break;
		}
		case 12:
		{
			sortList(head);
			break;
		}
		case 13:
		{
			traverse(head);
			break;
		}
		default:
		{
			cout << "Select proper choice!!If you need to exit press 14";
			break;
		}
		}
		choice = option();
		
	}
	cout << "Quiting the program!! catch you later.";

}

