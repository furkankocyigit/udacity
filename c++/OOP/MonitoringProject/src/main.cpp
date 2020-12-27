#include "ncurses_display.h"
#include "system.h"
#include "linux_parser.h"

constexpr bool simulationFlag = false;
void debugFunction(){

  std::string sKernel = LinuxParser::Kernel();
  bool flag = false;
  
}

int main() {
  if(!simulationFlag){
    System system;
    NCursesDisplay::Display(system);
  }else{
    debugFunction();
  }
  
}