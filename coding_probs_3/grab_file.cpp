#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class PhoneDirectory {
    string filename;

public:
    PhoneDirectory(const string &file) : filename(file) {}

    bool getPhoneNumber(const string &targetName, string &phone) {
        ifstream file(filename, ios::binary);

        if (!file)
            return false;

        file.seekg(0, ios::end);
        long long low = 0;
        long long high = file.tellg();

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            file.clear();
            file.seekg(mid);

            // Skip partial line
            if (mid != 0) {
                string dummy;
                getline(file, dummy);
            }

            long long currentPos = file.tellg();

            string line;

            if (!getline(file, line))
                break;

            size_t comma = line.find(',');

            if (comma == string::npos)
                return false;

            string name = line.substr(0, comma);
            string number = line.substr(comma + 1);

            if (name == targetName) {
                phone = number;
                return true;
            }

            if (name < targetName) {
                low = file.tellg();
            } else {
                high = currentPos - 1;
            }
        }

        return false;
    }
};

int main() {

    PhoneDirectory directory("phonebook.txt");

    string phone;

    if (directory.getPhoneNumber("Charlie", phone))
        cout << phone << endl;
    else
        cout << "Not Found\n";
}