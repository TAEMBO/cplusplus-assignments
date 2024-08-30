#include "Encyclopedia.h"
#include <iostream>

void Encyclopedia::SetEdition(string ed) {
   edition = ed;
}

void Encyclopedia::SetNumPages(int num) {
   numPages = num;
}

string Encyclopedia::GetEdition() {
   return edition;
}

int Encyclopedia::GetNumPages() {
   return numPages;
}

void Encyclopedia::PrintInfo() {
   Book::PrintInfo();
   cout << "   Edition: " << edition << endl;
   cout << "   Number of Pages: " << numPages << endl;
}