// 2.3 Transferring ownership of a thread
//2.3 转移线程的所有权

#include <thread>
#include <iostream>

using namespace std;

void do_something(int& i) 
{
	++i;
	cout << i << endl;
}

void do_something_in_current_thread() 
{
	cout<<"do_something_in_current_thread"<<endl;
}

// 清单2.1 函数已经结束，线程依旧访问局部变量  ****************************
struct func
{
	int& i;
	func(int& i_) : i(i_) {}
	void operator() ()
	{
		for (unsigned j = 0; j<1000000; ++j)
		{
			do_something(i); // 1. 潜在访问隐患：悬空引用
		}
	}
};
void oops()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	std::thread my_thread(my_func);
	my_thread.detach(); // 2. 不等待线程结束
}

//清单2.2 等待线程完成  **************************************
struct func; // 定义在清单2.1中
void f()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	std::thread t(my_func);
	try
	{
		do_something_in_current_thread();
	}
	catch(...)
	{
		t.join(); // 1
		throw;
	} t
		.join(); // 2
}


// 清单2.3 使用RAII等待线程完成  ***************************************
class thread_guard
{
	std::thread& t;
public:
	explicit thread_guard(std::thread& t_) :
		t(t_)
	{}

	~thread_guard()
	{
		if (t.joinable()) // 1
		{
			t.join(); // 2
		}
	} 
	thread_guard(thread_guard const&) = delete; // 3
	thread_guard& operator=(thread_guard const&) = delete;
};
struct func; // 定义在清单2.1中
void f()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	std::thread t(my_func);
	thread_guard g(t);
	do_something_in_current_thread();
} // 4

// 清单2.4 使用分离线程去处理其他文档	**********************
//void edit_document(std::string const& filename)
//{
//	open_document_and_display_gui(filename);
//	while (!done_editing())
//	{
//		user_command cmd = get_user_input();
//		if (cmd.type==open_new_document)
//		{
//			std::string const new_name = get_filename_from_user();
//			std::thread t(edit_document, new_name);		//1
//			t.detach();		//2
//		}
//		else
//		{
//			process_user_input(cmd);
//		}
//	}
//}

// 清单2.5 函数返回std::thread对象	**************************
std::thread f1() 
{
	void some_function();
	return std::thread(some_function);
}


std::thread g1() 
{
	void some_other_function(int);
	std::thread t(some_other_function);
	return t;
}


// 清单2.6 scoped_thread的用法	**************************
class scoped_thread
{
public:
	explicit scoped_thread(std::thread t_) :t(std::move(t_))	// 1
	{
		if (!t.joinable())		// 2
		{
			throw std::logic_error("no thread");
		}
	}
	~scoped_thread()
	{
		t.join();	// 3
	}
	std::thread t;
	scoped_thread(scoped_thread const&) = delete;
	scoped_thread& operator=(scoped_thread const&) = delete;


private:

};

struct func;	// 定义在清单2.1中

void f2_6() 
{
	int some_local_state;
}

int main() 
{
	return 1;
}