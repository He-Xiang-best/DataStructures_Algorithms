#include <iostream>    
#include <cstdlib>    
using namespace std;     
#include "lnkList.h"  
#include "seqList.h"
#include "doubleLinkList.h"  //Ë«Á´±í 

template<class T>   
void testList(List<T>* p) 
{
	if(p->empty())cout<<"empty list\n";
	cout << "test insert:\n";
	int n, i;
	T val;     
	cout<<"input number of nodes;£º\n";       
	cin >> n;   
	cout<<"input each node's insertion position and value:\n";
	while (n > 0) 
	{   
        cin >> i;   
        cin >> val;  
		try                 
		{
			p->insert(i, val); 
		}                      
		catch (outOfRange)
		{
			cerr << "error,catch outOfRange\n";
		}           
        n--;   
	}   
	p->traverse();    
	cout << "test inverse:\n";
	p->inverse();
	p->traverse();  

	cout << "test search:\n";
	cout<<"input the value:\n";
	cin >> val;	 
	cout<<"the position of "<<val<<" is:"<<p->search(val)<<endl;

	cout << "test delete:\n";
	cout<<"input the position:\n";
	cin >> i;   
	try
	{
		p->remove(i);
	}
	catch (outOfRange)
	{
		cerr<<"error,catch outOfRange\n";
	}
	p->traverse();   
  
	cout<<"test visit:\n";
	cout<<"input the position[0...n-1]:\n"; 
	cin >> i; 
	try
	{
		cout<<"position:"<<i<<"£º"<<p->visit(i)<<endl;
	}
	catch(outOfRange)
	{
		cerr<<"error,catch outOfRange\n";
	} 
}

template<class T> 
void testLinkCreate(linkList<T> *lk)
{       
	cout <<"test headCreate:\n";
	lk->
	headCreate();
	lk->traverse();

	lk->outPut();

	cout <<"test tailCreate:\n";
	lk->tailCreate();
	lk->traverse();
}

int main()   
{   
	//linkList<int> *lk;  
	seqList<int> *lk;
	//lk = new linkList<int>(); 
    lk = new seqList<int>();
	testList(lk); 

	system("pause");
	return 0;
}   

