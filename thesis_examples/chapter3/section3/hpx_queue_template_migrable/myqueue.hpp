
#include <hpx/hpx.hpp>
#include <queue>


template <typename T>
class MyQueue: public hpx::components::migration_support< hpx::components::component_base<MyQueue<T>> >
{

public:
    friend class hpx::serialization::access;

    typedef hpx::components::migration_support< hpx::components::component_base<MyQueue<T>> > base_type;
    // Components which should be migrated using hpx::migrate<> need to
    // be Serializable and CopyConstructable. Components can be
    // MoveConstructable in which case the serialized data is moved into the
    // component's constructor.
    MyQueue(MyQueue const& rhs)
      : base_type(rhs), myqueue(rhs.myqueue)
    {}

    MyQueue(MyQueue && rhs)
      : base_type(std::move(rhs)), myqueue(rhs.myqueue)
    {}

    MyQueue& operator=(MyQueue const & rhs)
    {
        myqueue = rhs.myqueue;
        return *this;
    }
    MyQueue& operator=(MyQueue && rhs)
    {
        myqueue = rhs.myqueue;
        return *this;
    }

    MyQueue() = default;

    template <typename ... Args>
    void Push(Args ... args) {
        (myqueue.push_back(args), ...);
    }
    T Pop() {
        T element = myqueue.front();
        myqueue.erase(myqueue.begin());
        return element;
    }
    size_t Size() {
        return myqueue.size();
    }

    HPX_DEFINE_COMPONENT_ACTION(MyQueue, Pop, Pop_action_MyQueue);
    HPX_DEFINE_COMPONENT_ACTION(MyQueue, Size, Size_action_MyQueue);

    template <typename ... Args>
    struct Push_action_MyQueue
    : hpx::actions::make_action<
        decltype(&MyQueue::Push<Args...>),
        &MyQueue::Push<Args...>
    >::type {};

    template <typename Archive>
    void serialize(Archive& ar, unsigned version)
    {
        ar & myqueue;
    }

private:
    std::vector<T> myqueue;

};


#define REGISTER_MYQUEUE_DECLARATION(type)                  \
    HPX_REGISTER_ACTION_DECLARATION(                        \
        MyQueue<type>::Pop_action_MyQueue,                  \
        HPX_PP_CAT(__MyQueue_Pop_action_MyQueue_, type));   \
    HPX_REGISTER_ACTION_DECLARATION(                        \
        MyQueue<type>::Size_action_MyQueue,                 \
        HPX_PP_CAT(__MyQueue_Size_action_MyQueue_, type));  \

#define REGISTER_MYQUEUE(type)                              \
    HPX_REGISTER_ACTION(                                    \
        MyQueue<type>::Pop_action_MyQueue,                  \
        HPX_PP_CAT(__MyQueue_Pop_action_MyQueue_, type));   \
    HPX_REGISTER_ACTION(                                    \
        MyQueue<type>::Size_action_MyQueue,                 \
        HPX_PP_CAT(__MyQueue_Size_action_MyQueue_, type));  \
    typedef ::hpx::components::component< MyQueue<type> > HPX_PP_CAT(__MyQueue_, type); \
    HPX_REGISTER_COMPONENT(HPX_PP_CAT(__MyQueue_, type))                                                                
