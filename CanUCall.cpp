#include <iostream>
#include <string>
#include <list>
using namespace std;

int finder(list<string> searched, string thing);

int main() {
    string answer, answer2, answer3;
    list <string> possibleAnswersN = {"no", "No", "nah", "Nah"};
    list <string> possibleAnswersP = {"yes", "Yes", "yeah", "Yeah"};
    
    cout << "Can you call tonight? ";
    getline(cin, answer);
    cout << endl;
    
    
    bool yield = finder(possibleAnswersN, answer);
    bool yield4 =finder(possibleAnswersP, answer);
    
    if(yield == true){
        cout << "Oh, okay, that's fine. But, why not, if I may ask? ";
        getline(cin, answer2);
        cout << endl << "Well, this is just a program I wrote, and I have nor the time nor the knowledge to integrate an AI that can analyze your situation and answer, so I'm just gonna ask you: Is your excuse reasonable? ";
        getline(cin, answer3);
            
        cout << endl << endl;
            
        if(size(answer3) >= 2){
        
            bool yield2 = finder(possibleAnswersN, answer3);
            bool yield3 = finder(possibleAnswersP, answer3);
            
            if(yield2){
                cout << "That means you can call! YIPPIE!!!";
            }
            else if(yield3){
                cout << "fudge";
            }
            else{
                cout << "Yeah I don't understand that so I'm just gonna count that as yes.";
            }
        }
    }
    else if(yield4){
        cout << "YIPPIE!!!";
    }
    else{
        cout << "Yeah I don't understand that so I'm just gonna count that as a yes.";
    }

    return 0;
}

int finder(list<string> searched, string thing) {
    bool result = false;

    for(string sana : searched) {
        if(sana == thing){
            result = true;
        }
    };

    return result;
}