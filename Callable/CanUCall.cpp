#include <iostream>
#include <list>
#include <string>
using namespace std;

bool finder(list<string> searched, string thing);

int main() {
  list<string> noList = {"no", "No", "nah", "Nah", "nei", "Nei", "nee", "Nee"};
  list<string> yesList = {"Yes", "yes", "Yeah", "yeah",
                          "Yea", "yea", "Ye",   "ye"};

  cout << "Can you call tonight? ";
  string callable;
  getline(cin, callable);
  cout << endl;

  if (finder(noList, callable)) {
    cout << "Oh, okay, that's fine. But, why not, if I may ask? ";
    string reason;
    getline(cin, reason);

    cout
        << endl
        << "Well, this is just a program I wrote, and I have nor the time nor "
           "the knowledge to integrate an AI that can analyze your situation "
           "and answer, so I'm just gonna ask you: Is your excuse reasonable? ";
    string reasonable;
    getline(cin, reasonable);

    cout << endl << endl;

    if (finder(noList, reasonable)) {
      cout << "That means you can call! Yippie!";
    } else if (finder(yesList, reasonable)) {
      cout << "Fuck";
    } else {
      cout << "Yeah I don't understand that so I'll just count that as a yes.";
    }
  } else if (finder(yesList, callable)) {
    cout << "Yippie!";
  } else {
    cout << "Yeah I don't understand that so I'm just gonna count that as a "
            "yes.";
  }

  return 0;
}

bool finder(list<string> searched, string thing) {
  bool result = false;

  for (string comparer : searched) {
    if (comparer == thing) {
      result = true;
    }
  };

  return result;
}