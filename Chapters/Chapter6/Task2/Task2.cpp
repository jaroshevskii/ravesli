#include <iostream>

struct Students {
  std::string name;
  int grade;
};

size_t getNumberOfStudents() {
  std::cout << "Enter number of students\n"
            << "> ";
  size_t numberOfStudents;
  std::cin >> numberOfStudents;
  std::cout << '\n';
  return numberOfStudents;
}

int getGrade() {
  int grade;

  while (true) {
    std::cout << "> Grade = ";
    std::cin >> grade;

    if (grade >= 0 && grade <= 100)
      return grade;

    std::cout << "\n"
              << "Error: Grade is not correct.\n";
  }
}

void setStudents(Students *students, const size_t &numberOfStudents) {
  std::cout << "Enter data about " << numberOfStudents << " students.\n";

  for (size_t i = 0; i < numberOfStudents; ++i) {
    std::cout << "Student #" << i + 1 << ":\n"
              << "  > Name = ";
    std::cin >> students[i].name;

    std::cout << "  ";
    students[i].grade = getGrade();
    std::cout << '\n';
  }
  std::cout << '\n';
}

void sortStudents(Students *students, const size_t &numberOfStudents) {
  for (int iteration = 0; iteration < numberOfStudents - 1; ++iteration) {
    for (size_t index = 0; index < numberOfStudents - 1 - iteration; ++index) {

      if (students[index].grade < students[index + 1].grade)
        std::swap(students[index].grade, students[index + 1].grade);
    }
  }
}

void printStudents(const Students *students, const size_t &numberOfStudents) {
  std::cout << "Students:\n";
  for (size_t i = 0; i < numberOfStudents; ++i) {
    std::cout << "  Student #" << i + 1 << ":\n"
              << "    Name: " << students[i].name << "\n"
              << "    Grede: " << students[i].grade << "\n"
              << '\n';
  }
}

int main() {
  const size_t numberOfStudents = getNumberOfStudents();
  auto students = new Students[numberOfStudents];
  setStudents(students, numberOfStudents);

  sortStudents(students, numberOfStudents);
  printStudents(students, numberOfStudents);

  delete[] students;
  return 0;
}