//cl /EHsc /I D:\Project\boost_1_53_0\boost_1_53_0\ multiple_inheritance.cpp
#include <iostream>

class A{
	public:
	  void foo()
	  {
		  std::cout<< "Class A\n";
	  }
	  char a;
};

class B: public A{
	public:
	   void foo1()
	  {
		  std::cout<< "Class B\n";
	  }
	  int b;
};

#define TYPE int
class C: public B
//class C
{
	public:
	C(TYPE  _a)
	{
		c = _a ;
	}
	char c;
	//TYPE a;


};


// Client code
int main()
{
	C c(0x60);
	char * x = reinterpret_cast<char *>(&c);
	//c.foo();
	std::cout << "Class C size = "<< sizeof(C)  ;
	printf("\nC.a = %lx\n", *(&c));
	printf("\nAddress of C = %lx\n\n", &c);
	for(int index =0; index < sizeof(C); index++)
	   { printf("%x ", *x); x++;}
	return 0;
}

