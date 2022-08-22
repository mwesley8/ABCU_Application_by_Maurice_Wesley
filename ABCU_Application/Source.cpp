#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

struct Courses {
    string number;
    string title;
    vector <string> prerequisites;

    Courses() {}
};

int main() {
    ifstream myFileStream ("Classes.txt");
    string line;
    char delim{ ',' };
    regex lim{ "," };

    while (getline(myFileStream, line)) {
        Courses course;
        string temp;
        stringstream ss(line);
        string word = "";

        getline(cin, course.number, delim);
        getline(cin, course.title, delim);
        getline(cin, temp, '\n');

        if (temp == "") {
            course.prerequisites.push_back("None");
        }
        else {
            for (int i = 0; i < temp.size(); ++i) {
                cout << temp[i] << endl;
                word = word += temp[i];
                if ((temp[i] == ',') || (temp[i] == '\0')) {
                    course.prerequisites.push_back(word);
                    cout << word << endl;
                    word = "";
                }
            }
        }
        for (int i = 0; i < course.prerequisites.size(); ++i) {
            if (i < course.prerequisites.size() - 1) {
                //cout << course.prerequisites.at(i) << ", ";
            }
            else {
                //cout << course.prerequisites.at(i) << endl;
            }
        }
        //cout << endl;
    }

}