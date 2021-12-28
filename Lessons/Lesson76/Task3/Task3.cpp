#include <iostream>

int main() {
  const int scores[]{73, 85, 84, 44, 78};
  const int numberOfStudents = sizeof(scores) / sizeof(scores[0]);

  size_t maxIndex = 0;

  for (int student = 0; student < numberOfStudents; ++student) {
    if (scores[student] > scores[maxIndex])
      maxIndex = student;
  }

  std::cout << "The best score: " << scores[maxIndex] << "\n"
            << "Index of the best score: " << maxIndex << "\n";
  return 0;
}