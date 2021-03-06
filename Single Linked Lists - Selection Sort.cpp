
#include "pch.h"
#include <iostream>

using namespace std;

// Node Declaration 

struct node
{
	int val;
	struct node *next;
}*head;


// Class Declaration
 
class sl_list
{
public:
	node* create(int);
	void insert();
	void sort();
	void display();
	sl_list()
	{
		head = NULL;
	}
};

//Contains Menu to choose whether to insert, sort or display

int main()
{
	int choice, nodes, element, position, i;
	sl_list sl;
	head = NULL;
	while (1)
	{
		cout << "!-------------------------------!\n";
		cout << "Lets Sort Single linked lists \n";
		cout << "But Before that, we need to create a linked list \n";
		cout << "Make sure you enter 15 random numbers to be stored in the linked list by choosing the options \n \n";
		cout << "1.Insert Node \n";
		cout << "2.Sort Link List \n";
		cout << "3.Display the Single Linked List \n";
		cout << "4.Exit the terminal \n " << endl;
		cout << "Enter your choice : \n \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Inserting new node \n";
			sl.insert();
			break;
		case 2:
			cout << "The Linked List will be sorted now. \n";
			sl.sort();
			break;
		case 3:
			cout << "The single linked list is as shown: \n";
			sl.display();
			break;
		case 4:
			cout << "Exiting the program.......\n";
			exit(1);
			break;
		default:
			cout << "Wrong Choice !!! Please choose the numbers from above. \n";
		}
	}
}

//Creating Node

node *sl_list::create(int value)
{
	struct node *tmp;
	tmp = new(struct node);
	if (tmp == NULL)
	{
		cout << "Memory not allocated \n";
		return 0;
	}
	else
	{
		tmp->val = value;
		tmp->next = NULL;
		return tmp;
	}
}


// Inserting element

void sl_list::insert()
{
	int value;
	cout << "Enter the value to be inserted: ";
	cin >> value;
	struct node *tmp, *p;
	tmp = create(value);
	if (head == NULL)
	{
		head = tmp;
		head->next = NULL;
	}
	else
	{
		p = head;
		head = tmp;
		head->next = p;
	}
	cout << value << " is Inserted \n";
}


// To Display the values in linked list

void sl_list::display()
{
	struct node *tmp;
	if (head == NULL)
	{
		cout << "The List is Empty\n";
		return;
	}
	tmp = head;
	cout << "Elements of list are: \n";
	while (tmp != NULL)
	{
		cout << tmp->val << "\t";
		tmp = tmp->next;
	}
	cout << "End of Values \n";
}

// Sorting the elements in ascending order


void sl_list::sort()
{
	struct node *ptr, *trv;
	int value;
	if (head == NULL)
	{
		cout << "The List is empty\n";
		return;
	}
	ptr = head;
	while (ptr != NULL)
	{
		for (trv = ptr->next; trv != NULL; trv = trv->next)
		{
			if (ptr->val > trv->val)
			{
				value = ptr->val;
				ptr->val = trv->val;
				trv->val = value;
			}
		}
		ptr = ptr->next;
	}
}
/*
int sl_list::sort()
{
	struct node *ptr, *trv, *min, *tmp, *startptr, *prevmin, *sttemp, *mintemp, *mintrav;
	int count = 0;
	if (head == NULL)
	{
		cout << "The List is empty\n";
		return 0;
	}


	ptr = head;
	trv = head;
	prevmin = head;
	mintemp = NULL;
	sttemp = NULL;
	

	for (ptr = head; ptr != NULL; ptr = ptr->next)
	{
		//head = ptr;
		min = ptr;
		startptr = ptr;
		trv = ptr;
		prevmin = ptr;
		while (trv->next != NULL)
		{
			if (min->val > trv->next->val)
			{
				min = trv->next;
				if (prevmin->val == min->val)
				{
					prevmin = prevmin->next;
				}
				else 
				{
					prevmin = trv;
				}
				
			}
			trv = trv->next;
		}
		cout << min->val << " min val\n";
//		cout << prevmin->next->val << " prevmin next val = min val\n";
		cout << prevmin->val << " prevmin val\n";
//		/*
		if (min->val != ptr->val)
		{
			if (ptr == head)
			{
				tmp = min->next;
				min->next = ptr->next;
				ptr->next = tmp;
				head = min;
				head->next = min->next;
				prevmin->next = ptr;
				
			}
			else
			{
				tmp = min->next;
				min->next = ptr->next;
				ptr->next = tmp;
				prevmin->next = ptr;
				ptr = min;
			}
			
				
			cout << min->val << " min\n";
			cout << min->next << " min next val\n";
			cout << head->val << " head\n";
			cout << head->next << " head\n";
			cout << startptr->val << "start pointer \n";

		}
//		
	}
	return 0;
}/*

			
			mintemp = min;
			cout << mintemp->val << " mintemp\n";
			cout << mintemp->next << " mintemp next address\n\n";

			sttemp = startptr;
			cout << sttemp->val << " sttemp\n";
			cout << sttemp->next << " sttemp next address\n\n";

			cout << startptr->next << " startptr next address value before putting mintemp in there\n";
			startptr = mintemp;
			cout << startptr->next << " startptr next address value after putting mintemp in there\n\n";

			cout << min->val << " min value before populating with sttemp\n";
			min = sttemp;
			cout << min->val << " min value after sttemp is moved to min\n\n";

			cout << prevmin->next << " prevmin next address value before min goes in it\n";
			cout << prevmin->next->val << " prevmin next value before min goes in it\n";
			prevmin->next = min;
			cout << prevmin->next << " prevmin next address value after min goes in it\n";
			cout << prevmin->next->val << " prevmin next value after min goes in it\n\n";
			prevmin->next->next = mintemp->next;
			
			cout << prevmin->next->next << " prevmin next next address value after mintemp next goes in it\n";
			cout << prevmin->next->next->val << " prevmin next next value after mintemp next goes in it\n";
			cout << startptr->next << " startptr next address value before startptr goes in it\n\n";
			cout << startptr->next->val << " startptr next value before startptr goes in it\n";
			
			cout << ptr->next << " ptr next address value after startptr goes in it\n";
			cout << ptr->next->val << " ptr next value after startptr goes in it\n";
			cout << startptr->next << " startptr next address value after startptr goes in it\n";
			cout << startptr->next->val << " startptr next value after startptr goes in it\n";

			cout << sttemp->next << " ptr next address value before startptr goes in it\n";
			cout << sttemp->next->val << " ptr next value before startptr goes in it\n";
			cout << startptr->next << " startptr next address value before startptr goes in it\n";
			cout << startptr->next->val << " startptr next value before startptr goes in it\n";
			startptr = head;
			startptr->next = ptr->next;y
			min->next = mintemp->next;
			

			cout << min->next << " min next address value before startptr goes in it\n";
			cout << min->val << " min next value before startptr goes in it\n";
			cout << startptr->next << " startptr next address value final\n";
			cout << startptr->val << " startptr next value final\n";

			mintrav = head;
			cout << mintrav->val << " head value\n";

			while (ptr->next != NULL)
			{
				if (ptr->val == 2)
				{
					count = 1;
				}
				if (mintrav->val > ptr->next->val)
				{
					mintrav = head;
				}
				ptr = ptr->next;
			}
			cout << count << " count value \n";
		}

	return;
}
*/