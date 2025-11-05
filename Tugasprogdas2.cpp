#include <bits/stdc++.h>
using namespace std;

struct studentType {
  string studentFName, studentLName;
  int testScore;
  char grade;
};

void getData(studentType list[], int size) {
  for (int i = 0; i < size; i++) {
    cout << "Enter first name, last name, and test score for student " << i + 1
         << ": ";
    cin >> list[i].studentFName >> list[i].studentLName >> list[i].testScore;
  }
}

void assignGrade(studentType list[], int size) {
  for (int i = 0; i < size; i++) {
    int score = list[i].testScore;
    if (score >= 90)
      list[i].grade = 'A';
    else if (score >= 80)
      list[i].grade = 'B';
    else if (score >= 70)
      list[i].grade = 'C';
    else if (score >= 60)
      list[i].grade = 'D';
    else
      list[i].grade = 'F';
  }
}

int highestScore(const studentType list[], int size) {
  int highest = list[0].testScore;
  for (int i = 1; i < size; i++) {
    if (list[i].testScore > highest)
      highest = list[i].testScore;
  }
  return highest;
}

void printHighest(const studentType list[], int size, int highest) {
  cout << "\nStudents with the highest score (" << highest << "):\n";
  for (int i = 0; i < size; i++) {
    if (list[i].testScore == highest)
      cout << list[i].studentLName << ", " << list[i].studentFName << endl;
  }
}

void printAll(const studentType list[], int size) {
  cout << left << setw(20) << "Name" << setw(10) << "Score" << setw(10)
       << "Grade";

  for (int i = 0; i < size; i++) {
    cout << left << setw(20)
         << (list[i].studentLName + ", " + list[i].studentFName) << setw(10)
         << list[i].testScore << setw(10) << list[i].grade << endl;
  }
}

int main() {
  studentType student[20];
  getData(student, 20);
  assignGrade(student, 20);
  int topScore = highestScore(student, 20);

  cout << "\nStudent Scores";
  printAll(student, 20);
  printHighest(student, 20, topScore);
}
