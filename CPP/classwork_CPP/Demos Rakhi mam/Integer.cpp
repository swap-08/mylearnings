#include<iostream>
using namespace std;
class Integer
{
	private: int n;
	public: Integer()
			   {
				   n=0;
			   }
			   Integer(int x)
			   {
				   n=x;
			   }
			   Integer(Integer &t)
			   {
				   n=t.n;
			   }
			   ~Integer()
			   {
				   cout<<"In Destructor"<<endl;
			   }
			   void showInteger()
			   {
				   cout<<n<<endl;
			   }
};
void main()
{
	Integer a;
	Integer b(10);
	Integer c(b);
	a.showInteger();
	b.showInteger();
	c.showInteger();
}
