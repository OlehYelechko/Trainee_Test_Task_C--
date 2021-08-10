#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>


int main(int argc, char ** argv){

    int temp;
    int period_of_counting = 1000;
    if(argc > 1){
        std::stringstream ss(argv[1]);
        if(ss >> temp){
            if(temp > 0 && temp  < 1001){
                period_of_counting = temp;
                std::cout << "Period value is " << temp << std::endl;
            }else{
                std::cout << "Period value passed wrong value" << std::endl;
                std::cout << "Period value has default value"<< std::endl;
            }
        }else{
            std::cout << "Error on reading terminal argument"<< std::endl;
            std::cout << "Period value has default value"<< std::endl;
        }    
    }
    

    std::ofstream WriteCounterFile;
    std::ifstream ReadCounterFile;
    int counter;
     ReadCounterFile.open("counter.txt");
     try{
        if(ReadCounterFile.is_open()){    
            ReadCounterFile >> counter;
            ReadCounterFile.close();
        }else{
            throw 1;
        }
     }catch(int){
        std::cerr << "Error occured when opening file!" << std::endl;
        exit(3);
     }

     while(true){
            WriteCounterFile.open("counter.txt");
            counter++;
            WriteCounterFile << counter;
        
            std::cout << counter << std::endl;
            WriteCounterFile.close();
            std::this_thread::sleep_for(std::chrono::milliseconds(period_of_counting));
        }
    return 0;
}