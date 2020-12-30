#include "processor.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
    float totalCpuTime1 = LinuxParser::ActiveJiffies();
    float idleCpuTime1 = LinuxParser::IdleJiffies();
    
    sleep(1);

    float totalCpuTime2 = LinuxParser::ActiveJiffies();
    float idleCpuTime2 = LinuxParser::IdleJiffies();


return ((totalCpuTime2-totalCpuTime1) - (idleCpuTime2-idleCpuTime1)) / (totalCpuTime2-totalCpuTime1);

}