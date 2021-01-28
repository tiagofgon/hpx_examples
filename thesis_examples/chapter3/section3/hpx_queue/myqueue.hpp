
#include <hpx/hpx.hpp>
#include <queue>

class MyQueue: public hpx::components::locking_hook< hpx::components::component_base<MyQueue> >
{
public:
    template <typename ... Args>
    void Push(Args&& ... args) {
        (myqueue.push_back(std::forward<Args>(args)), ...);
    }
    int Pop();
    size_t Size();

    HPX_DEFINE_COMPONENT_ACTION(MyQueue, Pop, Pop_action_MyQueue);
    HPX_DEFINE_COMPONENT_ACTION(MyQueue, Size, Size_action_MyQueue);

    template <typename ... Args>
    struct Push_action_MyQueue
    : hpx::actions::make_action<
        decltype(&MyQueue::Push<Args...>),
        &MyQueue::Push<Args...>
    >::type {};

private:
    std::vector<int> myqueue;
};

typedef MyQueue::Pop_action_MyQueue Pop_action_MyQueue;
typedef MyQueue::Size_action_MyQueue Size_action_MyQueue;
HPX_REGISTER_ACTION_DECLARATION(Pop_action_MyQueue);
HPX_REGISTER_ACTION_DECLARATION(Size_action_MyQueue);