#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;


Process::Process(int pid) : pid_(pid){
    cpu_ = LinuxParser::ActiveJiffies(this->pid_);
    //ram_ = std::stoi(LinuxParser::Ram(this->pid_));
}
// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
    long sytemUptime = LinuxParser::UpTime();

    long seconds = sytemUptime - (LinuxParser::ActiveJiffies(this->pid_) / sysconf(_SC_CLK_TCK));

    return ((float)LinuxParser::ActiveJiffies(this->pid_) / sysconf(_SC_CLK_TCK)) / seconds;
}

// TODO: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(this->pid_); }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(this->pid_); }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(this->pid_); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(this->pid_); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a[[maybe_unused]]) const { 
    return this->cpu_ > a.cpu_; }