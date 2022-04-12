//
//
///*
//2.1 基本线程管理
//*/
//
//
//
//#include <thread>
//
//void do_something(int& i) 
//{
//	++i;
//}
//
//struct func
//{
//	/*
//	int a	声明一个int类型，名称叫a
//	int* a	声明一个int指针类型，名称叫a
//	int& a	声明一个int引用类型，名称叫a
//	*/
//	int& i;
//	func(int& i_) :i(i_) {}
//
//	void operator()()
//	{
//		for (unsigned j = 0; j < 1000000; ++j)
//		{
//			do_something(i);
//		}
//	}
//};
//
//void oops() 
//{
//	int some_local_state = 0;
//	func my_func(some_local_state);
//	std::thread my_thread(my_func);
//	my_thread.detach();	//detach()
//}
//
//int main_2_1() 
//{
//	oops();
//	system("pause");
//
//	return 1;
//}
