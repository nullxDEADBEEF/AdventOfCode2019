#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream inputFile;
    inputFile.open( "data.txt" );
    std::vector<int> dataEntries;
    std::string fileLine;
    int currentIndex = 0;
    
    while( std::getline( inputFile, fileLine, ',' ) ) {
        dataEntries.push_back( std::stoi( fileLine ) );
    }
    
    for ( ; currentIndex < dataEntries.size(); ) {
        if ( dataEntries[currentIndex] == 1 ) {
            // add
            int position1 = dataEntries[currentIndex + 1];
            int position1Value = dataEntries[position1];
            int position2 = dataEntries[currentIndex + 2];
            int position2Value = dataEntries[position2];
            int sum = position1Value + position2Value;
            int outputPosition = dataEntries[currentIndex + 3];
            dataEntries[outputPosition] = sum;
            currentIndex += 4;
            
        } else if ( dataEntries[currentIndex] == 2 ) {
            // multiply
            int position1 = dataEntries[currentIndex + 1];
            int position1Value = dataEntries[position1];
            int position2 = dataEntries[currentIndex + 2];
            int position2Value = dataEntries[position2];
            int sum = position1Value * position2Value;
            int outputPosition = dataEntries[currentIndex + 3];
            dataEntries[outputPosition] = sum;
            currentIndex += 4;
            
        } else if ( dataEntries[currentIndex] == 99 ) {
            // stop program
            std::cout << dataEntries[0] << std::endl;
            return 0;
        }
    }
    
    inputFile.close();
    
    return 0;
}