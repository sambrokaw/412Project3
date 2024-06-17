#include "WebServer.h"

WebServer::WebServer() : remainingTime(0) {}

bool WebServer::isBusy() const {
    return remainingTime > 0;
}

void WebServer::processRequest(const Request& request) {
    remainingTime = request.getTime();
}

void WebServer::update(int time) {
    if (remainingTime > 0) {
        remainingTime -= time;
    }
}
