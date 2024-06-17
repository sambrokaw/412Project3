#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <random>

class Request {
public:
    Request();
    std::string getIpIn() const;
    std::string getIpOut() const;
    int getTime() const;

private:
    std::string generateRandomIp() const;
    std::string ipIn;
    std::string ipOut;
    int time;
};

#endif // REQUEST_H
