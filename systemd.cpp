/*сделай демон для SystemD без ЛЛМ, который будет:
создавать файл, 
записывать в него время и дату,
а при отсутствии файла, создаст его снова
*/
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <thread>
#include <iomanip>
#include <csignal>
#include <atomic>

std::atomic<bool> keep_running(true);   

void signal_handler(int signum) {
    keep_running = false;
}

int main(){
   
    std::signal(SIGTERM, signal_handler); // завершеие от системы
    std::signal(SIGINT, signal_handler); // завершение от ctrl c в терм


    std::ofstream file("/home/tony/Downloads/time.txt", std::ios::app);

    
    while(keep_running == true){
    auto now = std::chrono::system_clock::now();
    std::time_t nowtime = std::chrono::system_clock::to_time_t(now);
    file << std::put_time(std::localtime(&nowtime), "%y-%m-%d %H:%M:%S") << std::endl;
    file.flush();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    return 0;
}