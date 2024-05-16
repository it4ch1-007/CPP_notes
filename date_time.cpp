#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

/***
 * Creates a std::tm structure from raw date.
 *
 * \param year (must be 1900 or greater)
 * \param month months since January – [1, 12]
 * \param day day of the month – [1, 31]
 * \param minutes minutes after the hour – [0, 59]
 * \param seconds seconds after the minute – [0, 61](until C++11) / [0, 60] (since C++11)
 */

std::tm CreateTmStruct(int year, int month, int day, int hour, int minutes, int seconds) {
	struct tm tm_ret = { 0 };

	tm_ret.tm_sec = seconds;
	tm_ret.tm_min = minutes;
	tm_ret.tm_year = year-1900;
	tm_ret.tm_mon = month-1;
	tm_ret.tm_mday = day;
	tm_ret.tm_hour = hour;
	return tm_ret;
}
int get_days_in_year(int year) {
	using namespace std::chrono;
	using namespace std;
	typedef duration<int, ratio_multiply<hours::period, ratio<24>>::type> days;

	//We make a struct that will store the info of the starting time or a year at the starting of the function
	std::tm tm_start = CreateTmStruct(year, 1, 1, 0, 0, 0);
	auto tms = system_clock::from_time_t(std::mktime(&tm_start));

	//This will store the info of the next year as it is given the parameter year+1
	std::tm tm_end = CreateTmStruct(year + 1, 1, 1, 0, 0, 0);
	auto tme = system_clock::from_time_t(std::mktime(&tm_end));

	auto diff_in_days = std::chrono::duration_cast<days>(tme - tms);
	//This specifies how to count the duration between the consecutive years whether it is days or in seconds.

	//.count method is used to get the duration between two time structs in any form we want using duration_cast.
	return diff_in_days.count();
}
int main() {

	for (int year = 2000; year <= 2025; ++year)
	{
		//std::cout << "There are " << get_days_in_year(year) << " days in " << year << std::endl;
	}

	//Calculating the time elapsed between two instances of the program code running.

	auto start1 = std::chrono::system_clock::now(); //This will get the time from the system clock at that point of time
	long long j = 0;
	while (j < pow(10, 5)) {
		j++;
	}
	
	auto end1 = std::chrono::system_clock::now();//This is the end timing for the for loop
	auto start2 = std::chrono::system_clock::now();//Starting of the while loop
	
	for (long long i = 0; i < pow(10, 5); i++) {
		;
	}
	
	auto end2 = std::chrono::system_clock::now();//End of time for while loop
	
	std::chrono::duration<double> elapsed1 = (end1 - start1);
	std::chrono::duration<double> elapsed2 = (end2 - start2);
	std::cout << "For loop took " << elapsed1.count() << std::endl;
	std::cout << "While loop took " << elapsed2.count() << std::endl;
}