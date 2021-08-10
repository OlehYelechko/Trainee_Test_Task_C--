#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char** argv){
    int status;
    int PID = fork();
    if(PID == 0){
        std::cout << "Child first init PID: " << getpid() << std::endl;
        execv("./Child", argv);
    }else if (PID > 0){
        std::cout << "PID of parent process" << getpid() << std::endl;
        while(true){
            if (!waitpid(-1, &status, 0)){
                std::cout << "UNKNOWN" << std::endl;
            }else if (waitpid(-1, &status, 0) == -1){
                std::cout << "Error" << std::endl;
                int PIDofRestart = fork();
                if(PIDofRestart == -1){
                    std::cerr << "Error when restarting fork!" << std::endl;
                    return 2;
                }
                if(!PIDofRestart){
                    std::cout << "Child restart PID: " << getpid() << std::endl;
                    execv("./Child", argv);
                }else{
                    std::cout <<"Parent PID: " << getpid() << std::endl;
                }
            }else{
                std::cout  <<"SUCCESS" << std::endl;
            }
            sleep(1);
        }
    }else{
        std::cerr << "Fork was unsuccessful!" <<std::endl;
    }
    return 0;
}
