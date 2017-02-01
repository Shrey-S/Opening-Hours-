//
//  main.cpp
//  CS1160 HW
//
//  Created by Shrey Sethi on 1/30/17.
//  Copyright © 2017 Shrey Sethi. All rights reserved.
//
//  Program to check is a certain place is open right now or not.
//

#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int place, open;
    cout << "The Locations are- \n"
        << "1. Gym\n"
        << "2. Library\n"
        << "Enter Serial Number of the Location: ";           // Displays and inputs Serial Numbers (S. no.)
    cin >> place;                                             // of Place
   
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int day = ltm->tm_wday, hour = ltm->tm_hour; // Stores value of day and hour
    cout << "Time: " << hour << ":00\n\n";       // Displays hour of the day
    
    switch (place) {                             // Checks for S. no. of location
        case 1:
            if (hour >= 6 && hour < 24)          // Checks if location is open
                open = 1;
            else
                open = 0;
            break;
        case 2:                                      // Check for second location
            if ((hour >= 7) && (hour < 20))
                open = 1;
            else
                open = 0;
            break;
        default:
            open = -1;                               // Stores '-1' if S. No. is invalid
    }
    switch (open) {                                  // Displays 1 of 3 Outputs based on
        case 1:                                      // value of 'open'
            cout << "It is: OPEN.\n\n";
            break;
        case 0:
            cout << "It is: CLOSED\n\n";
            break;
        case -1:
            cout << "Invalid Serial Number!\n\n";
            break;
    }
}
