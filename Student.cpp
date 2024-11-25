#include <iostream>
#include <iomanip>
#include "Student.h"
using namespace std;

// Default constructor
Student::Student() {
 name = "Louie";
 gpa = 1.0;
 scores = new double[4](); // Allocate memory for scores and initialize to 0
}
// Parameterized constructor
Student::Student(string inputName, double inputGpa, double* inputScores) {
 name = inputName;
 gpa = inputGpa;
 scores = new double[4];
 for (int i = 0; i < 4; ++i) {
 
scores[i] = inputScores[i]; // Copy values from input array
 }
}
// Copy constructor
Student::Student(const Student& other) {
 name = other.name;
 gpa = other.gpa;
 copyScoresFrom(other); // Copy the scores array properly
}
// Copy assignment operator
Student& Student::operator=(const Student& other) {

 if (this != &other) { // Avoid self-assignment
 
name = other.name;
 
gpa = other.gpa;
 
// Clean up existing resources
 
delete[] scores;
 
// Copy the scores array
 
copyScoresFrom(other);
 }
 return *this;
}
// Helper function to copy the scores array
void Student::copyScoresFrom(const Student& other) {
 scores = new double[4]; // Allocate new memory for scores
 for (int i = 0; i < 4; ++i) {
 
scores[i] = other.scores[i]; // Copy values from other object
 }
}
// Destructor
Student::~Student() {
 delete[] scores; // Deallocate memory for scores array
}

// Set the student's name
void Student::SetName(string inputName) {
 name = inputName;
}
// Get the student's name
string Student::GetName() const {
 return name;
}
// Set the GPA
void Student::SetGPA(double inputGpa) {
 gpa = inputGpa;
}
// Get the GPA
double Student::GetGPA() const {
 return gpa;
}
// Set a specific score at an index
void Student::SetScoreAt(int idx, double score) {
 if (idx >= 0 && idx < 4) {
 
scores[idx] = score;
 }
}

// Get the score at a specific index
double Student::GetScoresAt(int idx) const {
 if (idx >= 0 && idx < 4) {
 
return scores[idx];
 }
 return 0.0; // Return 0.0 if index is out of bounds
}
// Calculate and update GPA based on score averages
void Student::UpdateGPA() {
 double sum = 0.0;
 for (int i = 0; i < 4; ++i) {
 
sum += scores[i];
 }
 double avg = sum / 4;
 // Determine GPA based on average
 if (avg >= 90.0) {
 
gpa = 4.0;
 } else if (avg >= 80.0) {
 
gpa = 3.0;
 } else if (avg >= 70.0) {
 
gpa = 2.0;
 } else if (avg >= 60.0) {
 
gpa = 1.0;
 } else {

 
gpa = 0.0;
 }
}
// Print student's information
void Student::PrintInfo() const {
 cout << name << " (" << fixed << setprecision(2) << gpa << ")" << endl;
 cout << "Scores: [";
 for (int i = 0; i < 4; ++i) {
 
cout << fixed << setprecision(2) << scores[i];
 
if (i < 3) cout << ", ";
 }
 cout << "]" << endl;
}
