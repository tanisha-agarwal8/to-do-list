#include<bits/stdc++.h>

using namespace std;

void display();
void seeTODO();
void deleteTODO();
void createTODO();
void updateIndex();

class todo
{
	public:
	int count;
	string task;
	todo *next;
};
todo* head=NULL;

int main()
{
	int choice;
	display();
	while(1)
	{
		system("cls");
		cout<<"1. Display your ToDo list\n";
		cout<<"2. Create new ToDo\n";
		cout<<"3. Delete your ToDo\n";
		cout<<"4. Exit\n";
		cout<<"\n\nEnter your choice\t:\t";
		cin>>choice;
		switch (choice) 
		{
		case 1:
			seeTODO();
			break;
		case 2:
			createTODO();
			break;
		case 3:
			deleteTODO();
			break;
		case 4:
			exit(1);
			break;
		default:
			cout<<"\nInvalid Choice!!!\n";
			system("pause");
		}
	}
	return 0;
}

void display()
{
	cout<<"Welcome to Your To-do List......\n";
	system("pause");
}

void seeTODO()
{
	system("cls");
	todo* temp=head;
	cout<<"\n\n\n";
	if(head==NULL)
		cout<<"Empty To-do list....!\n";
	while(temp!=NULL)
	{
		cout<<temp->count<<"."<<temp->task<<endl;
		fflush(stdin);
		temp=temp->next;
	}
	cout<<"\n\n";
	system("pause");
}

void createTODO()
{	
	char c;
	todo *temp,*newTask;
	system("cls");
	while(1)
	{
		printf("\nWant to add new ToDo ??\nPress 'y' for Yes and 'n'for No \n\t\t");
		fflush(stdin);
		cin>>c;
		if (c == 'n')
			break;
		else
		{
			if(head==NULL)
			{
				newTask=new todo();
				head=newTask;
				cout<<"\nEnter the task.....\n";
				fflush(stdin);
				cin>>newTask->task;
				newTask->count=1;
				head->next=NULL;
			}
			else
			{
				temp=new todo();
				cout<<"\nEnter the task....\n";
				fflush(stdin);
				cin>>temp->task;
				temp->next=NULL;
				newTask->next=temp;
				newTask=newTask->next;
			}
			updateIndex();	
		}
	}
	
}

void deleteTODO()
{
	system("cls");
	int n;
	todo *temp,*del;
	if(head==NULL)
		cout<<"Empty To-do List....!\n";
	else
	{
		del=head;
		temp=head->next;
		cout<<"Enter the Index you want to delete:";
		cin>>n;
		while(1)
		{
			if(del->count==n)
			{
				head=head->next;
				delete(del);
				updateIndex();
				break;
			}
			else if(temp->count==n)
			{
				del->next=temp->next;
				delete(temp);
				updateIndex();
				break;
			}
			else
			{
				del=temp;
				temp=temp->next;
			}
		}		
	}
	system("pause");
}

void updateIndex()
{
	int i=1;
	todo* temp=head;
	while(temp!=NULL)
	{
		temp->count=i;
		i++;
		temp=temp->next;
	}
}
