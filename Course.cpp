#include "Course.h"
#include <iostream>
#include <algorithm> // For std::remove_if
// Default constructor
Course::Course() {}
// Destructor (optional cleanup if needed)

Course::~Course() {}
// Add a student to the course roster
void Course::AddStudent(const Student& student) {
 roster.push_back(student);
}
// Print the course roster
void Course::PrintRoster() const {
 for (const auto& student : roster) {
 
std::cout << student.GetName() << " - GPA: " << student.GetGPA() << std::endl;
 }
}
// Get students who made the Dean's List (GPA >= 3.5)
std::vector<Student> Course::GetDeansList() const {
 std::vector<Student> deansList;
 for (const auto& student : roster) {
 
if (student.GetGPA() >= 3.5) {
 
deansList.push_back(student);
 
}
 }
 return deansList;
}
// Drop a student by last name

void Course::DropStudent(const std::string& lastName) {
 // Use std::remove_if to find the student with the matching last name
 auto it = std::remove_if(roster.begin(), roster.end(),
 
[&lastName](const Student& student) {
 
return student.GetName().substr(student.GetName().find_last_of(" ") + 1) == 
lastName;
 
});
 // If a student with the last name was found, erase it from the vector
 if (it != roster.end()) {
 
roster.erase(it, roster.end());
 
std::cout << "Student " << lastName << " has been dropped from the course." << 
std::endl;
 } else {
 
std::cout << "Student " << lastName << " not found in the course roster." << std::endl;
 }
}
