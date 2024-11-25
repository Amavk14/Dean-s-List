#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;
class Student {
public:

 Student(); // Default constructor
 Student(string inName, double inGpa, double* inScores); // Parameterized constructor
 ~Student(); // Destructor
 Student(const Student& other); // Copy constructor
 Student& operator=(const Student& other); // Copy assignment operator
 void SetName(string inName);
 string GetName() const;
 void SetGPA(double inGpa);
 double GetGPA() const;
 void SetScoreAt(int index, double score);
 double GetScoresAt(int index) const;
 void UpdateGPA();
 void PrintInfo() const;
private:
 string name;
 double gpa;
 double* scores; // Pointer to dynamically allocated array of scores
 void copyScoresFrom(const Student& other); // Helper function to copy the scores array
};
#endif // STUDENT_H
