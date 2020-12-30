#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, kernel,version;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >>version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() { 

  bool neededDataAcquired = false;
  string line;
  string key,value,kb;
  float MemTotal,MemFree,MemAvailable,Buffers,Cached;
  std::ifstream filestream((kProcDirectory + kMeminfoFilename));

  if(filestream.is_open()){
    while (std::getline(filestream, line)){
      
      //std::replace(line.begin(), line.end(), ':', '_');
      std::istringstream linestream(line);
      while(linestream>>key>>value>>kb){
          if(key == "MemTotal:") MemTotal = std::stof(value);
          if(key == "MemFree:") MemFree = std::stof(value);
          if(key == "MemAvailable:") MemAvailable = std::stof(value);
          if(key == "Buffers:") Buffers = std::stof(value);
          if(key == "Cached:") Cached = std::stof(value);
          if(key == "SwapCached:"){
            neededDataAcquired = true;
            break;
          }
      }
      if(neededDataAcquired) break;
    }

  //bool debugFlag = true;
  }
  float usedMem = MemTotal- MemFree;
  usedMem -= Buffers + Cached;

  return usedMem / MemTotal;   
  }

// TODO: Read and return the system uptime
long LinuxParser::UpTime() { 
  
  string line;
  string second1,second2;
  long totalSecond,idleSecond;
  std::ifstream filestream((kProcDirectory + kUptimeFilename));
  if(filestream.is_open()){
    std::getline(filestream,line);
    std::istringstream linestream(line);;
    while(linestream>>second1>>second2){
      totalSecond = std::stol(second1);
      idleSecond = std::stol(second2);
    }
  }else throw std::runtime_error("Couldn't read system uptime!!");
  
  
  return totalSecond; }

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() { return LinuxParser::ActiveJiffies() + LinuxParser::IdleJiffies(); }

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid[[maybe_unused]]) { 
  
    long sytemUptime = LinuxParser::UpTime();

    std::string line,token;
    long utime,stime,cutime,cstime,starttime ,totaltime;
    std::ifstream filestream((LinuxParser::kProcDirectory + std::to_string(pid) + LinuxParser::kStatFilename));
    if(filestream.is_open()){
        std::getline(filestream,line);
        std::istringstream linestream(line);
        int count = 1;
        while(linestream>>token){

            if(count == 14) utime = std::stol(token);
            if(count == 15) stime = std::stol(token);
            if(count == 16) cutime = std::stol(token);
            if(count == 17) cstime = std::stol(token);
            //if(count == 22) starttime = std::stol(token);

            count++;
        }
        totaltime = utime + stime;
        totaltime += cutime + cstime;
    }
  return totaltime;
}

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() {
  std::vector<std::string> cpuValuesStr = LinuxParser::CpuUtilization();
  std::vector<long> cpuValues;
  cpuValues.clear();
  if(!cpuValuesStr.empty()){
    for(auto value : cpuValuesStr){
      cpuValues.emplace_back(std::stol(value));
    }
    return cpuValues[LinuxParser::kUser_]    + cpuValues[LinuxParser::kNice_] +
           cpuValues[LinuxParser::kSystem_]  + cpuValues[LinuxParser::kIdle_] +
           cpuValues[LinuxParser::kIOwait_]  + cpuValues[LinuxParser::kIRQ_]  +
           cpuValues[LinuxParser::kSoftIRQ_] + cpuValues[LinuxParser::kSteal_];
  }
}

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() {

  std::vector<std::string> cpuValuesStr = LinuxParser::CpuUtilization();
  std::vector<long> cpuValues;
  cpuValues.clear();
  if(!cpuValuesStr.empty()){
    for(auto value : cpuValuesStr){
      cpuValues.emplace_back(std::stol(value));
    }
    return cpuValues[LinuxParser::kIdle_] + cpuValues[LinuxParser::kIOwait_];
  }
}

// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() {

  vector<string> cpuValues;
  string line;
  string key,value;
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if(filestream.is_open()){
    std::getline(filestream,line);
    std::istringstream linestream(line);
    linestream>>key;
    while(linestream>>value){
      cpuValues.emplace_back(value);
    }
  }
    
  return cpuValues;
}

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() {
  
  string line;
  string key,value;
  int TotalProcesses;
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if(filestream.is_open()){
    while(getline(filestream,line)){
      std::istringstream linestream(line);
      while(linestream>>key){
        if(key == "processes"){
          linestream>>value;
          TotalProcesses = std::stoi(value);
          break;
        }
      }
      
    }


  }else throw std::runtime_error("Couldn't read system stat directory!!");
  
  
   return TotalProcesses; 
}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() {
  string line;
  string key,value;
  int runningProcesses;
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if(filestream.is_open()){
    while(getline(filestream,line)){
      std::istringstream linestream(line);
      while(linestream>>key){
        if(key == "procs_running"){
          linestream>>value;
          runningProcesses = std::stoi(value);
          break;
        }
      } 
    }
  }else throw std::runtime_error("Couldn't read system stat directory!!");
  
  
  
  return runningProcesses; 
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid[[maybe_unused]]) {
  
  std::string line;
  std::string command;
  std::ifstream filestream(kProcDirectory + std::to_string(pid) + kCmdlineFilename);
  if(filestream.is_open()){
    std::getline(filestream,line);
    std::istringstream inputstream(line);
    inputstream>>command;
  }
  return command;
}

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid[[maybe_unused]]) { 

  std::string line,key,usedMemory;
  bool neededDataAcquired{false};
  std::ifstream filestream(kProcDirectory + std::to_string(pid) + kStatusFilename);
  if(filestream.is_open()){
    while(std::getline(filestream,line)){
      std::istringstream linestream(line);
      while(linestream>>key){
        if(key == "VmSize:"){
          linestream>>usedMemory;
          return std::to_string(std::stoi(usedMemory) / 1024);
          // neededDataAcquired = true;
          // break;
        } 
      }
      //cleaif(neededDataAcquired)break;
    }
  }
 
  return string();
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid[[maybe_unused]]) {

  std::string key,value,line;
  std::ifstream filestream(kProcDirectory + std::to_string(pid) + kStatusFilename);
  if(filestream.is_open()){
    while(std::getline(filestream,line)){
      std::istringstream linestream(line);
      while(linestream>>key){
        if(key == "UID:" || key == "Uid:") {
          linestream>>value;}
      }

    }
  }else{ throw std::runtime_error("Process User Id couldn't read!!");}

  
  return value;
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid[[maybe_unused]]) { 
  
  std::string userID = LinuxParser::Uid(pid);
  std::string userName,userIDparsed,x;
  std::string key,value,line;
  std::ifstream filestream(kPasswordPath);
  bool neededDataAcquired = false;
  if(filestream.is_open()){
    while(std::getline(filestream,line)){
      std::istringstream linestream(line);
      while(linestream>>key){
        std::replace(key.begin(), key.end(), ':', ' ');
        std::istringstream keystream(key);
        keystream>>userName>>x>>userIDparsed;
        if(userID == userIDparsed){
          neededDataAcquired = true;
          break;
        }
      }
      if(neededDataAcquired) break;
    }
  }else throw std::runtime_error("User name directory cannot opened!!");

  return userName; }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid[[maybe_unused]]) { 
  
  string line;
  string stringToken;
  long upTime;
  std::ifstream filestream((kProcDirectory + std::to_string(pid) + kStatFilename));
  if(filestream.is_open()){
    std::getline(filestream,line);
    std::istringstream linestream(line);;
    int count = 0;
    while(linestream>>stringToken){
      if(count == 20){
        linestream>>stringToken;
        upTime = std::stol(stringToken);
        break;
      }
      count++;
    }
  }else throw std::runtime_error("Couldn't read process uptime!!");
  
  return upTime / sysconf(_SC_CLK_TCK);
 }