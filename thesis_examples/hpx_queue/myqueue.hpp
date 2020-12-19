
#include <hpx/hpx.hpp>
#include <queue>

class MyQueue: public hpx::components::locking_hook< hpx::components::component_base<MyQueue> >
{
public:
    void Push(int id);
    int Pop();
    size_t Size();

    HPX_DEFINE_COMPONENT_ACTION(MyQueue, Push, Push_action_MyQueue);
    HPX_DEFINE_COMPONENT_ACTION(MyQueue, Pop, Pop_action_MyQueue);
    HPX_DEFINE_COMPONENT_ACTION(MyQueue, Size, Size_action_MyQueue);
    
private:
    std::queue<int> myqueue;
};

typedef MyQueue::Push_action_MyQueue Push_action_MyQueue;
typedef MyQueue::Pop_action_MyQueue Pop_action_MyQueue;
typedef MyQueue::Size_action_MyQueue Size_action_MyQueue;
HPX_REGISTER_ACTION_DECLARATION(Push_action_MyQueue);
HPX_REGISTER_ACTION_DECLARATION(Pop_action_MyQueue);
HPX_REGISTER_ACTION_DECLARATION(Size_action_MyQueue);
