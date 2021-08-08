#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

int main(){
    std::ofstream WriteCounterFile;
    std::ifstream ReadCounterFile;
    int counter;
    while(true){
        ReadCounterFile.open("counter.txt");
        if(ReadCounterFile.is_open()){
            ReadCounterFile >> counter;
        }else{
            std::cout << "Error occured with opening of file\n";
        }
        ReadCounterFile.close();
        WriteCounterFile.open("counter.txt");
        counter++;
        WriteCounterFile << counter;
        
        std::cout << counter << std::endl;
        WriteCounterFile.close();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
  
}