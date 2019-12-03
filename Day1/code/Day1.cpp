#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

int main() {
    // read input
    std::ifstream dataFile;
    dataFile.open( "../data.txt" );
    std::vector<int> dataEntries;
    std::string fileLine;
    int sumOfFuel = 0;
    int fuelForPart1 = 0;
    int fuelRequirements = 0;
    int sum = 0;
    
    // read in data
    while ( std::getline( dataFile, fileLine ) ) {
        dataEntries.push_back( std::stoi( fileLine ) );
    }
    
    // part 1
    for ( auto i : dataEntries ) {
        fuelForPart1 += std::floor( i / 3 ) - 2;
    }
    
    // part 2
    for ( auto i : dataEntries ) {
        // do calculation for each entry
        // and add total fuel sum
        sumOfFuel = std::floor( i / 3 ) - 2;
        sum += sumOfFuel;
        
        int fuelForMass = sumOfFuel;
        
        while ( fuelForMass > 0 ) {
            fuelRequirements = std::floor( fuelForMass / 3 ) - 2;
            if ( fuelRequirements <= 0 ) {
                break;
            }
            fuelForMass = std::floor( fuelForMass / 3 ) - 2;
            
            int additionalFuel = fuelRequirements;
            sum += additionalFuel;
        }
    }
    
    std::cout << fuelForPart1 << std::endl;
    std::cout << sum << std::endl;
    
    dataFile.close();
    
    return 0;
}