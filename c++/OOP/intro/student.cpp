#include <cassert>
#include <stdexcept>
#include <string>
#include <iostream>

class Student{
    public:
    Student(std::string name, int grade, float gpa);
    void setName(std::string name){name_ = name;};
    bool setGrade(int grade);
    bool setGPA(float gpa);
    std::string Name()const {return this->name_;}
    int Grade()const {return this->grade_;}
    float GPA()const {return this->gpa_;}
    void Validate();

    private:
    std::string name_;
    int grade_;
    float gpa_;

};
bool Student::setGrade(int grade){
    
    if(!(grade>0 && grade <= 12)) throw std:: invalid_argument("invalid grade");
    this->grade_ = grade;
    return true;
    
}

bool Student::setGPA(float gpa){

    
    if(!(gpa>=0.0 && gpa <= 4.0)) throw std::invalid_argument("invalid gpa");
    this->gpa_ = gpa;
    return true;
    
}
Student::Student(std::string name, int grade, float gpa){
    
    this->name_ = name;
    this->gpa_ = gpa;
    this->grade_ = grade;
    Validate();
    
}
void Student::Validate(){
    if(!(gpa_>=0.0 && gpa_ <= 4.0)) throw std::invalid_argument("invalid gpa");
    if(!(grade_>0 && grade_ <= 12)) throw std:: invalid_argument("invalid grade");

}

int main(){

    Student student("fake name",4,3.2f);

    assert(student.Name() == "fake name");
    assert(student.Grade() == 4);
    assert(student.GPA() == 3.2f);


    bool myexception{false};
    try {
        student.setGrade(17);
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<"\n";
       myexception = true;
    }
    std::cout<<student.Grade();
    assert(myexception);

}