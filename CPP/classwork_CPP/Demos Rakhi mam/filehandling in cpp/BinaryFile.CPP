#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
void main()
{
	fstream f,t;
	char name[30],add[20],phone[11],tn[30];
	int ch=0,flag=0;
	while(ch!=6)
	{
		cout<<"1. Add a Record"<<"\n";
		cout<<"2. List all Records"<<"\n";
		cout<<"3. Search a Record"<<"\n";
		cout<<"4. Modify a Record"<<"\n";
		cout<<"5. Delete a Record"<<"\n";
		cout<<"6. Exit"<<"\n";
		cout<<"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:f.open("stud.dbf",ios::app);
			           if(!f.good())
			           {
				cout<<"file can't be opened";
				return;
			           }
			           cout<<"Enter Name:";
			           cin>>name;
			           cout<<"Enter Address:";
			           cin>>add;
			           cout<<"Enter Phone:";
			           cin>>phone;
			           f<<name<<"\t"<<add<<"\t"<<phone<<endl;
			           cout<<"Record Added";
			           f.close();
			           break;
			case 2:f.open("stud.dbf",ios::in);
				   if(!f.good())
				   {
						cout<<"file can't be opened";
						getch();
						return;
				   }
				   cout<<"Name"<<"\t"<<"Address"<<"\t"<<"Phone"<<"\n";
				   f>>name>>add>>phone;
				   while(!f.eof())
				   {
					cout<<name<<"\t"<<add<<"\t"<<phone<<"\n";
					f>>name>>add>>phone;
				   }
				   f.close();
				   break;
			case 3:f.open("stud.dbf",ios::in);
				   if(!f.good())
				   {
						cout<<"file can't be opened";
						getch();
						return;
				   }
				   cout<<"Enter Name to Search:";
				   cin>>tn;
				   f>>name>>add>>phone;
				   while(f)
				   {
						if(strcmp(name,tn)==0)
							break;
						f>>name>>add>>phone;
				   }
				   if(!f)
						cout<<"Name not found";
				   else
					cout<<name<<"\t"<<add<<"\t"<<phone<<"\n";
				   f.close();
				   break;
			case 4:f.open("stud.dbf",ios::in);
				   if(!f.good())
				   {
						cout<<"file can't be opened";
						getch();
						return;
				   }
				   t.open("temp.dbf",ios::out);
				   if(!t.good())
				   {
						cout<<"Operation Unsuccesful";
						f.close();
						getch();
						return;
				   }
				   cout<<"Enter Name to Modify:";
				   cin>>tn;
				   flag=0;
				   f>>name>>add>>phone;
				   while(f)
				   {
					if(strcmp(name,tn)==0)
					{
					cout<<"Enter New Details:"<<endl;
					cout<<"Enter Name:";
					cin>>name;
					cout<<"Enter Address:";
					cin>>add;
					cout<<"Enter Phone:";
					cin>>phone;
					flag=1;
					}
					t<<name<<"\t"<<add<<"\t"<<phone<<endl;
					f>>name>>add>>phone;
				   }
				   f.close();
				   t.close();
				   if(flag==0)
				   {
						cout<<"Name not found";
						remove("temp.dbf");
				   }
				   else
				   {
						cout<<"record Modified";
						remove("stud.dbf");
						rename("temp.dbf","stud.dbf");
				   }
				   break;
			case 5:f.open("stud.dbf",ios::in);
				   if(!f.good())
				   {
						cout<<"file can't be opened";
						getch();
						return;
				   }
				   t.open("temp.dbf",ios::out);
				   if(!t.good())
				   {
						cout<<"Operation Unsuccesful";
						f.close();
						getch();
						return;
				   }
				   cout<<"Enter Name to Delete:";
				   cin>>tn;
				   flag=0;
				   f>>name>>add>>phone;
				   while(f)
				   {
					if(strcmp(name,tn)==0)
						flag=1;
					else
						t<<name<<"\t"<<add<<"\t"<<phone<<endl;
					f>>name>>add>>phone;
				   }
				   f.close();
				   t.close();
				   if(flag==0)
				   {
						cout<<"Name not found";
						remove("temp.dbf");
				   }
				   else
				   {
						cout<<"record Deleted";
						remove("stud.dbf");
						rename("temp.dbf","stud.dbf");
				   }
				   break;
			}
			getch();
	}
}

