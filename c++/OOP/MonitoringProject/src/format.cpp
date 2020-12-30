#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds[[maybe_unused]]) { 
    
    long l_hour = seconds/3600;
    long l_minute = seconds%3600/60;
    long l_second = seconds%3600%60;
    string s_hour = (l_hour < 10 ? "0" : "") + std::to_string(l_hour);
    string s_minute = (l_minute < 10 ? "0" : "") +  std::to_string(l_minute);
    string s_second = (l_second < 10 ? "0" : "") +  std::to_string(l_second);

    return s_hour + ":" + s_minute + ":" + s_second;       

}