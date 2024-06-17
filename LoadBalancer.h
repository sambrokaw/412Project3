#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "Request.h"
#include "WebServer.h"
#include "RequestQueue.h"
#include <vector>

class LoadBalancer {
public:
    LoadBalancer(int numServers);
    void addRequest(const Request& request); // Updated declaration

    void balanceLoad(int time);
    void simulate(int totalTime);
    void printSummary() const;

private:
    std::vector<WebServer> servers;
    RequestQueue requestQueue;
    int initialQueueSize;
    int minTaskLength;
    int maxTaskLength;

    void updateTaskLengthRange(int taskLength);
};

#endif // LOADBALANCER_H
