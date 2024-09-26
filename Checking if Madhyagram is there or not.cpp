#include <stdio.h>

// Function to check if "Madhyagram" is on the route
int isMadhyagramOnRoute(const char* route[], int numStations) {
    for (int i = 0; i < numStations; ++i) {
        if (strcmp(route[i], "Madhyagram") == 0) {
            return 1; 
        }
    }
    return 0;
}

int main() {
    const char* stations[] = {
        "Sealdah", "Station1", "Station2", "Madhyagram", "Station3", "Barasat"
    };
    int numStations = sizeof(stations) / sizeof(stations[0]);

    if (isMadhyagramOnRoute(stations, numStations)) {
        printf("Madhyagram is on the route!\n");
    } else {
        printf("Madhyagram is NOT on the route.\n");
    }

    return 0;
}

