#ifndef WELCOME_H
#define WELCOME_H

/// Welcome.
class Welcome {
private:
  char *data = nullptr;

public:
  Welcome();
  ~Welcome();

  /// Prints a welcome messange.
  void print() const;
};

#endif // WELCOME_H