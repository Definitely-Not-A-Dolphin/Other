// To do anything besides declaring variables and functions, we need to include
// libraries. Libraries contain functions, by including them you can actually
// make use of those function.

// Iostream, short for input-output-stream allows for the most basic stuff, like
// outputting and inputting stuff.
#include <iostream>

int main() {

  // The first thing that iostream lets us do, is outputting stuff.
  // The print() equivalent of C++ is cout. When we call it, make sure to type
  // 'std::' before it, so that the compiler knows that it is not a variable
  // name.
  std::cout << "Hello World!";

  // << is the insertion operator, it 'inserts' "Hello World!" into the cout (or
  // something this is kinda weird, just remember it).

  std::cout << " This will be printed on the same line.";
  std::cout << std::endl
            << "This will be on a new line, because we ended the line with "
               "endl(ine). '\n' can also be used, since it is kinda the "
               "universal symbol for an enter.";

  // Noticde you we can keep writing on a new line without errors! Because we
  // haven't used a semicolon, the compiler will interpret it all as one big
  // line instead! This is very useful for readability.

  std::cout << std::endl
            << "And now for my next trick, I will need you to pick a number! ";
  int pickANumber;
  std::cin >> pickANumber;
  std::cout << std::endl
            << "Was your number " << pickANumber << "?" << std::endl;

  // cin is the C++ equivalent of input.
  // The extraction operator >> puts the input from the user in the variable. (I
  // know that it sounds like the two names should be swapped).

  // Okay that was it for now bye!

  return 0;
}