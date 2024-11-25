
#ifndef COURSE_H
#define COURSE_H
#include <vector>

#include "Student.h"
class Course {
public:
 Course(); // Default constructor
 ~Course(); // Destructor to handle cleanup
 void AddStudent(const Student& student); // Add a student to the course
 void PrintRoster() const; // Print the course roster
 std::vector<Student> GetDeansList() const; // Get students with GPA >= 3.5
 void DropStudent(const std::string& lastName); // Drop a student by last name
private:
 std::vector<Student> roster; // Vector of students enrolled in the course
};
#endif // COURSE_H
