// TODO 1.the declarations for the multi-threading support in the Standard C++ Library in new headers.
#include <thread>
#include <iostream>

using namespace std;

// TODO 2.the code for writing the message for writting the message has been moved to a separate function.
void hello() 
{
	cout<<"hello concurrent"<<endl;
}

int main_helloConcurrent() 
{
	// TODO 3.the std::thread object t has the new function hello()
	std::thread t(hello);
	//TODO 4.the function join() start the thread
	t.join();

	cout<<"hello main"<<endl;
	system("pause");

	return 1;
}