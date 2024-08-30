#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

struct Movie {
    string title;
    string showtime;
    string rating;
};

int main() {
    ifstream file;
    string fileName;

    getline(cin, fileName);

    file.open(fileName);

    if (!file.is_open()) {
        cout << "Faile to open file" << endl;

        return 1;
    }

    vector<Movie> movies;
    string record;
    string section;

    getline(file, record);

    while (!file.eof()) {
        stringstream stringStream(record);
        Movie newMovie;
        int propIndex = 0;
        bool movieExists = false;
        int movieExistsIndex;

        while (stringStream.good()) {
            getline(stringStream, section, ',');

            if (propIndex == 0) {
                newMovie.showtime = section;
            } else if (propIndex == 1) {
                newMovie.title = section;
            } else {
                newMovie.rating = section;
            }

            propIndex++;
        }

        for (int i = 0; i < static_cast<int>(movies.size()); i++) {
            if (movies.at(i).title == newMovie.title) {
                movieExists = true;
                movieExistsIndex = i;
            }
        }

        if (movieExists) {
            movies.at(movieExistsIndex).showtime = movies.at(movieExistsIndex).showtime + " " + newMovie.showtime;
        } else {
            movies.push_back(newMovie);
        }

        getline(file, record);
    }

    file.close();

    for (int i = 0; i < static_cast<int>(movies.size()); i++) {
        Movie currentMovie = movies.at(i);

        cout
            << left << setw(44)
            << (static_cast<int>(currentMovie.title.size()) > 44 ? currentMovie.title.substr(0, 44) : currentMovie.title)
            << " | "
            << right << setw(5) << currentMovie.rating
            << " | "
            << currentMovie.showtime << endl;
    }
    
    return 0;
}
