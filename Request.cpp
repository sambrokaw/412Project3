#include "Request.h"
#include <sstream>
#include <random>

// Helper function to generate a random integer within a range
int getRandomInt(int min, int max) {
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}

// Constructor
Request::Request() 
    : ipIn(generateRandomIp()), 
      ipOut(generateRandomIp()), 
      time(getRandomInt(1, 10)) {}

// Generate a random IP address
std::string Request::generateRandomIp() const {
    std::ostringstream ip;
    ip << getRandomInt(0, 255) << "."
       << getRandomInt(0, 255) << "."
       << getRandomInt(0, 255) << "."
       << getRandomInt(0, 255);
    return ip.str();
}

std::string Request::getIpIn() const { return ipIn; }
std::string Request::getIpOut() const { return ipOut; }
int Request::getTime() const { return time; }
