#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int STRING_CHAR_SIZE = 100;

class Newstring {
    private:
        char data[STRING_CHAR_SIZE];
        int size;
    public:
        Newstring(const char chars[]) {
            int countedChars = 0;
            int charLimit = strlen(chars) > STRING_CHAR_SIZE ? STRING_CHAR_SIZE : strlen(chars);

            for (int i = 0; i < charLimit; i++) {
                countedChars++;
                data[i] = chars[i];
            }

            size = countedChars;
        };

        Newstring(int integer) {
            string parsedData = to_string(integer);

            int countedChars = 0;
            int charLimit = parsedData.length() > STRING_CHAR_SIZE ? STRING_CHAR_SIZE : parsedData.length();

            for (int i = 0; i < charLimit; i++) {
                countedChars++;
                data[i] = parsedData[i];
            }

            size = countedChars;
        };

        const char& operator[](const int &i) {
            return data[i];
        };

        void operator=(const char chars[]) {
            int countedChars = 0;
            int charLimit = strlen(chars) > STRING_CHAR_SIZE ? STRING_CHAR_SIZE : strlen(chars);

            for (int i = 0; i < charLimit; i++) {
                countedChars++;
                data[i] = chars[i];
            }

            size = countedChars;
        }

        Newstring operator=(const Newstring& string) {
            for (int i = 0; i < string.size; i++) data[i] = string.data[i];

            size = string.size;

            return *this;
        }

        bool operator==(const Newstring& string) {
            bool equals = true;

            for (int i = 0; i < string.size; i++) {
                if (data[i] != string.data[i]) {
                    equals = false;

                    break;
                }
            }

            return equals;
        }

        bool operator==(const char chars[]) {
            bool equals = true;

            for (int i = 0; i < strlen(chars); i++) {
                if (data[i] != chars[i]) {
                    equals = false;

                    break;
                }
            }

            return equals;
        }

        int length() {
            return size;
        };
};

ostream& operator<<(ostream &os, Newstring* string) {
    for (int i = 0; i < string->length(); i++) cout << (*string)[i];

    return os;
}

int main() {
    Newstring str1 = 69;
    Newstring str2 = "Test";
    Newstring str3 = str2 = str1;

    cout
        << (str3 == str2) << endl
        << (str3 == "69") << endl
        << str3.length() << endl
        << str3[1] << endl
        << &str3 << endl;

    return 0;
}