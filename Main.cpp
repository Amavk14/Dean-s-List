#include <iostream>
#include "Course.h"
#include "Student.h"
int main() {
 // Create some sample students
 Student student1("Henry Nguyen", 3.5, new double[4]{85, 90, 78, 92});
 Student student2("Brenda Stern", 2.0, new double[4]{70, 65, 60, 55});
 Student student3("Lynda Robison", 3.2, new double[4]{88, 76, 84, 91});
 Student student4("Sonya King", 3.9, new double[4]{92, 95, 90, 89});
 // Create the course and add students
 Course course;
 course.AddStudent(student1);
 course.AddStudent(student2);
 course.AddStudent(student3);
 course.AddStudent(student4);
 // Print the course roster before dropping
 std::cout << "Course Roster Before Dropping:" << std::endl;
 course.PrintRoster();
 // Drop a student (example: Brenda Stern)
 course.DropStudent("Stern");

 // Print the course roster after dropping
 std::cout << "\nCourse Roster After Dropping:" << std::endl;
 course.PrintRoster();
 // Print the Dean's List
 std::cout << "\nDean's List:" << std::endl;
 std::vector<Student> deansList = course.GetDeansList();
 for (const auto& student : deansList) {
 
std::cout << student.GetName() << " - GPA: " << student.GetGPA() << std::endl;
 }
 return 0;
}
