#ifndef STREET_H
#define STREET_H
#include "city.h"
#include "city_list.h"

using namespace std;

class Street {
public:
  // Constructor
  // stream - reference to input stream of a file containing street data
  // cities - reference to city list containing the relevant cities
  Street(istream &stream, CityList &cities);

  // Used for path calculation. Returns the city with the corresponding
  // visited step value
  City *getCityByStep(int currentStep) const;

  // Checks if this street has the given city as a starting or ending point
  bool connectedToCity(const City &city) const;

  // Returns the city on the other end of the street (from the given city)
  City *getConnectedCity(const City &city) const;

  // Returns the length of the street
  const unsigned int getLength() const;

  // Simple display of the street
  void printSelf() const;

  // Destructor
  // ~Street(); // nothing to destructure

private:
  unsigned int fromCityId;
  unsigned int toCityId;
  unsigned int length;
  City *fromCity;
  City *toCity;
};

#endif