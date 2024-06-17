#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <queue>
#include "Request.h"

class RequestQueue {
public:
    void addRequest(const Request& request);
    Request getRequest();
    bool isEmpty() const;
    int size() const; // New method to get the size of the queue

private:
    std::queue<Request> queue;
};

#endif // REQUESTQUEUE_H
