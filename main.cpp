#include <iostream>
#include "LoadBalancer.h"

int main() {
    int numServers, simulationTime;

    std::cout << "Enter the number of servers: ";
    std::cin >> numServers;

    std::cout << "Enter the length of the simulation in clock cycles: ";
    std::cin >> simulationTime;

    LoadBalancer lb(numServers);

    std::cout << "Initializing the request queue" << std::endl;
    for (int i = 0; i < numServers * 100; i++) {
        lb.addRequest(Request());
    }

    std::cout << "Starting simulation" << std::endl;
    lb.simulate(simulationTime);
    std::cout << "Simulation completed." << std::endl;

    return 0;
}
