#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"

class WebServer {
public:
    WebServer();
    bool isBusy() const;
    void processRequest(const Request& request);
    void update(int time);

private:
    int remainingTime;
};

#endif // WEBSERVER_H
