
int main() {

  // To use a variable you need to declare it first. A variabel is defined like
  // this: [datatype] [variableName] = [data];

  // Examples:

  // The datatype is an int, so it stores a positive whole number.
  int number1 = 10;
  // This will just become 5.
  int number2 = -5;
  // This will just become 3.
  int number3 = 3.14159;

  // A double can store a positive and negative decimal number, with up to 15
  // decimal places. The rest gets cut off.
  double double1 = 3.14159;
  // This will be -8.23749.
  double double2 = -8.23749;

  // A float is like a double, but can only store 7-8 decimal numbers.

  // A boolean is either true or false. Unlike in python, you don't have to type
  // it with a capital T or F.
  bool bool1 = true;
  bool bool2 = false;

  // A char stores a prespecified number if characters. These characters are
  // stored in an array. A string is essentially an array of characters, but it
  // can be sized much easier.
  char char1[100] = "This is a piece of text. The unused chars are marked as "
                    "none, but thay can be used later.";
  // When no lenght is specified, it will be a single character.
  char char2 = 'D';

  // We can declare it variable but not assign a value to it like this. This is
  // especially handy for user inputs!
  int notYetGivenAValue;

  // We CANNOT define strings yet, since we need to include the <string> library
  // to do so. What are libraries you may ask? Good question, look at the next
  // document to find out!

  // Before we go on, you need to look at functions. Functions also have
  // datatypes. The datatype of a function depends on the datatype it returns.
  // If it returns an integer, use int. If it returns a boolean, use bool.
  // If the function doesn't return anything, use void.

  return 0;
}