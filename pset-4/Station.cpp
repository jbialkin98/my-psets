/* 
 * Josh Bialkin
 * Station.cpp
 * CPSC 223, PSET 4
 * 3/30/23
 * Implementation of the Station class
 */

#include "Station.h"

// Constructor
Station::Station(){
	name = "NoName";
    access = false;
}

// Parameterized Constructor
Station::Station(string input_name, bool input_access){
    name = input_name;
    access = input_access;
}

// Function: isEqual
// Input: station
// Returns: bool
// Does: returns true if the inputted station has the same name and access
//       as the station we are comparing it to, false otherwise
bool Station::isEqual(Station s){
    if (name == s.getName() && access == s.getAccess()) {
        return true;
    }
    return false;
}

// Function: print
// Input: ostream object
// Returns: void
// Does: prints the name of the station, followed by a space, and then 
//       either "A" or "U" depending on if the station is accessible
void Station::print(ostream &outfile){
    string appropriateLetter;
    if (access == true) {
        appropriateLetter = "A";
    } else if (access == false) {
        appropriateLetter = "U";
    }
    outfile << name << " " << appropriateLetter;
}


