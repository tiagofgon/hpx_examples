#include "myqueue.hpp"

void MyQueue::Push(int id) {
    myqueue.push(id);
}

int MyQueue::Pop() {
    myqueue.pop();
    return myqueue.front();
}

size_t MyQueue::Size() {
    return myqueue.size();
}

typedef hpx::components::component<MyQueue> MyQueue_type;
HPX_REGISTER_COMPONENT(MyQueue_type, MyQueue);

typedef MyQueue::Push_action_MyQueue Push_action_MyQueue;
typedef MyQueue::Pop_action_MyQueue Pop_action_MyQueue;
typedef MyQueue::Size_action_MyQueue Size_action_MyQueue;
HPX_REGISTER_ACTION(Push_action_MyQueue);
HPX_REGISTER_ACTION(Pop_action_MyQueue);
HPX_REGISTER_ACTION(Size_action_MyQueue);
