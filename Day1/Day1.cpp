#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

int main() {
    // read input
    std::ifstream dataFile;
    dataFile.open( "data.txt" );
    std::vector<int> dataEntries;
    std::string fileLine;
    int sumOfFuel = 0;
    
    while ( std::getline( dataFile, fileLine ) ) {
        dataEntries.push_back( std::stoi( fileLine ) );
    }
    
    for ( auto i : dataEntries ) {
        // do calculation for each entry
        // and add to total fuel sum
        sumOfFuel += std::floor( i / 3 ) - 2;
    }
    
    dataFile.close();
    
    std::cout << sumOfFuel << std::endl;
    
    return 0;
}