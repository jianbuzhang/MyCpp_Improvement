#include <thread>
#include <iostream>

using namespace std;

class background_task
{
public:
	background_task();
	~background_task();
public:
	void operator()() const
	{
		cout<<"do something"<<endl;
		cout<<"do something else"<<endl;
	}

private:

};

background_task::background_task()
{
}

background_task::~background_task()
{
}

background_task f;
thread my_thread(f);

/*********************************/
struct func
{
	int& i;
	func(int& i_) :i(i_) {}

	void operator()()
	{
		for (unsigned j = 0; i < 100000; ++j)
		{

		}
	}

};