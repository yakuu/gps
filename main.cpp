#include <iostream>
#include <conio.h> // for _getch() function

struct GPSLocation {
    double latitude;
    double longitude;
};

void changeLocation(GPSLocation& location, char direction, double distance) {
    switch (direction) {
        case 'w':
            location.latitude += distance;
            break;
        case 'a':
            location.longitude -= distance;
            break;
        case 's':
            location.latitude -= distance;
            break;
        case 'd':
            location.longitude += distance;
            break;
        default:
            std::cout << "Invalid direction. Please use W, A, S, or D." << std::endl;
            break;
    }
}

int main() {
    GPSLocation currentLocation;
    currentLocation.latitude = 0.0;
    currentLocation.longitude = 0.0;

    double distance = 0.001; // Distance to move in each step (adjust as needed)

    char key;
    while (true) {
        std::cout << "Current Location: (" << currentLocation.latitude << ", "
                  << currentLocation.longitude << ")" << std::endl;
        std::cout << "Enter W, A, S, or D to change the location (Q to quit): ";
        key = _getch();

        if (key == 'q' || key == 'Q')
            break;

        changeLocation(currentLocation, key, distance);
        system("cls"); // Clear console screen (Windows specific, change for other platforms)
    }

    return 0;
}
