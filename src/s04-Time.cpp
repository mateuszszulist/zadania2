#include "Time.h"

int main()
{
	Time t(22, 59, 59);
	t.to_string();
	t.next_hour();
	t.to_string();
	t.next_minute();
	t.to_string();
	t.next_second();
	t.to_string();
	std::cout << t.to_string(t.time_of_day()) << std::endl;
	Time t1(5, 24, 34);
	Time t2(5, 15, 34);
	std::cout << (t1==t2) << std::endl;
	std::cout << (t1!=t2) << std::endl;
	std::cout << (t1<t2) << std::endl;
	std::cout << (t1>t2) << std::endl;
	{
		Time t1(21, 14, 34);
		Time t2(23, 07, 29);
		Time t3=t1-t2;
		Time t4=t1+t2;
		t3.to_string();
		t4.to_string();
	}
	Time t3(4, 5, 23);
	Time t4 = t3.time_to_midnight();
	t4.to_string();
	std::cout << t3.count_seconds() << std::endl;
	std::cout << t3.count_minutes() << std::endl;
	return 0;
}
