#include<fstream.h>
#include<conio.h>
#include<string.h>
class textfilehandle
{
  private: char fn[13];
		   textfilehandle(){} //User cannot create an Object without File Name

  public:  textfilehandle (char *tfh)
		   {
			  strcpy(fn,tfh);
		   }
		   void addtext(char *n);
		   void displayfile();
		   void addfilecontents(char *tn);
};


void textfilehandle::addtext(char *n)
 {
	  ofstream o;
	  o.open(fn,ios::app);
	  if(o.good())
	  {
		   for(int i=0;n[i]!='\0';i++)	//enter character untill null character is found
			   o.put(n[i]);
		   o.close();
	  }
	  else
		   cout<<"operation failed";
 }

void textfilehandle::displayfile()
{
  ifstream ifs(fn);
   if(!ifs.good())
  {
	  cout<<"Operation Failed";
	  getch();
	  return;
  }
  char ch;
  ch=ifs.get();
  while(!ifs.eof())
  {
	cout<<ch;
	ch=ifs.get();
  }
  ifs.close();
}
void textfilehandle::addfilecontents(char *tn)
{
  fstream f;
  ifstream ifs(tn);
  if(!ifs.good())
  {
	  cout<<"Operation Failed";
	  getch();
	  return;
  }
  f.open(fn,ios::app);
  if(!f.good())
  {
	  ifs.close();
	  cout<<"Operation Failed";
	  getch();
	  return;
  }
  char ch;
  ifs.get(ch);
  while(!ifs.eof())
  {
	f.put(ch);
	ifs.get(ch);
  }
  ifs.close();
  f.close();
}
void main()
{
  clrscr();
  textfilehandle tfh("a.txt");
  char n[100];
  cout<<"enter contents to add in a.txt\n";
  cin.getline(n,100);
  tfh.addtext(n);
  cout<<"\n\nContents of a.txt...\n\n";
  tfh.displayfile();
  getch();
  tfh.addfilecontents("b.txt");
  cout<<"\n\nContents of a.txt after adding contents of b.txt...\n\n";
  tfh.displayfile();
  getch();
}