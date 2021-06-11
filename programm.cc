#include "city.h"
#include "city_list.h"
#include "street_list.h"
#include <fstream>
#include <iostream>

using namespace std;

// Passt.  Rade
int main(int argc, char *argv[]) {

  // check correct usage
  if (argc < 6) {
    cout << "Usage:" << endl;
    cout << "programm <citiesFile> <areasFile> <streetsFile> fromCityName "
            "toCityName"
         << endl;
  }

  // read cities
  char *cityFileName = argv[1];
  ifstream s(cityFileName);

  CityList cities(s, argv[4], argv[5]);
  s.close();

  // read streets
  s.open(argv[3]); // argv[3] = path to streets file
  StreetList streets(s, cities);
  s.close();

  // calculate path
  vector<City *> path = streets.getPath();

  // print the path if it exists
  if (path.size() > 0) {
    cout << "The path is as follows: " << endl;
    for (City *c : path) {
      cout << c->getName();
      if (c != path.back()) {
        cout << " -> ";
      }
    }

    cout << endl;

  } else {
    cout << "There is no path between " << argv[4];
    cout << " and " << argv[5];
    cout << ", according to the given data." << endl;
  }

  return 0;
}
