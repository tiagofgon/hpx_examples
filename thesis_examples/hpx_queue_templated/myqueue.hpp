
#include <hpx/hpx.hpp>
#include <queue>


template <typename T>
class MyQueue: public hpx::components::locking_hook< hpx::components::component_base<MyQueue<T>> >
{


public:
    void Push(T object) {
        myqueue.push(object);
    }
    T Pop() {
        myqueue.pop();
        return myqueue.front();
    }
    size_t Size() {
        return myqueue.size();
    }

    HPX_DEFINE_COMPONENT_ACTION(MyQueue, Push, Push_action_MyQueue);
    HPX_DEFINE_COMPONENT_ACTION(MyQueue, Pop, Pop_action_MyQueue);
    HPX_DEFINE_COMPONENT_ACTION(MyQueue, Size, Size_action_MyQueue);
    
private:
    std::queue<T> myqueue;
};


#define REGISTER_MYQUEUE_DECLARATION(type)                  \
    HPX_REGISTER_ACTION_DECLARATION(                        \
        MyQueue<type>::Push_action_MyQueue,                 \
        HPX_PP_CAT(__MyQueue_Push_action_MyQueue_, type));  \
    HPX_REGISTER_ACTION_DECLARATION(                        \
        MyQueue<type>::Pop_action_MyQueue,                  \
        HPX_PP_CAT(__MyQueue_Pop_action_MyQueue_, type));   \
    HPX_REGISTER_ACTION_DECLARATION(                        \
        MyQueue<type>::Size_action_MyQueue,                 \
        HPX_PP_CAT(__MyQueue_Size_action_MyQueue_, type));  \

#define REGISTER_MYQUEUE(type)                              \
    HPX_REGISTER_ACTION(                                    \
        MyQueue<type>::Push_action_MyQueue,                 \
        HPX_PP_CAT(__MyQueue_Push_action_MyQueue_, type));  \
    HPX_REGISTER_ACTION(                                    \
        MyQueue<type>::Pop_action_MyQueue,                  \
        HPX_PP_CAT(__MyQueue_Pop_action_MyQueue_, type));   \
    HPX_REGISTER_ACTION(                                    \
        MyQueue<type>::Size_action_MyQueue,                 \
        HPX_PP_CAT(__MyQueue_Size_action_MyQueue_, type));  \
    typedef ::hpx::components::component< MyQueue<type> > HPX_PP_CAT(__MyQueue_, type); \
    HPX_REGISTER_COMPONENT(HPX_PP_CAT(__MyQueue_, type))                                                                