#include "LoadBalancer.h"
#include <cstdlib>  // for rand()
#include <ctime>    // for time()
#include <iostream> // for printing summary
#include <climits>  // for INT_MIN and INT_MAX

LoadBalancer::LoadBalancer(int numServers) 
    : servers(numServers), initialQueueSize(0), minTaskLength(INT_MAX), maxTaskLength(INT_MIN) {
    // Seed the random number generator
    std::srand(std::time(0));
}

void LoadBalancer::addRequest(const Request& request) {
    requestQueue.addRequest(request);
    if (initialQueueSize == 0) {
        initialQueueSize = requestQueue.size();
    }
    updateTaskLengthRange(request.getTime());
}

void LoadBalancer::balanceLoad(int time) {
    for (auto& server : servers) {
        if (!server.isBusy() && !requestQueue.isEmpty()) {
            server.processRequest(requestQueue.getRequest());
        }
        server.update(time);
    }
}

void LoadBalancer::simulate(int totalTime) {
    for (int i = 0; i < totalTime; ++i) {
        std::cout << "Simulation time step: " << i << std::endl;
        balanceLoad(1);
        // Simulate new requests being added at random intervals
        if (rand() % 10 < 2) { // 20% chance to add a new request
            addRequest(Request());
            std::cout << "Added a new request at time step " << i << std::endl;
        }
    }
    printSummary(); // Ensure the summary is printed at the end of the simulation
}

void LoadBalancer::updateTaskLengthRange(int taskLength) {
    if (taskLength < minTaskLength) {
        minTaskLength = taskLength;
    }
    if (taskLength > maxTaskLength) {
        maxTaskLength = taskLength;
    }
}

void LoadBalancer::printSummary() const {
    std::cout << "Simulation Summary:" << std::endl;
    std::cout << "Initial Queue Size: " << servers.size() * 100  << std::endl;
    std::cout << "Ending Queue Size: " << requestQueue.size() << std::endl;
    std::cout << "Task Length Range: " << minTaskLength << " - " << maxTaskLength << std::endl;
}
