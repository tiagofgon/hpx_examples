#include "myqueue.hpp"
#include <hpx/hpx.hpp>

class MyQueue_Client: hpx::components::client_base<MyQueue_Client, MyQueue>
{
public:
    typedef hpx::components::client_base<MyQueue_Client, MyQueue> base_type;
	MyQueue_Client() : base_type(hpx::local_new<MyQueue>())
	{}
	MyQueue_Client(hpx::id_type locality) : base_type(hpx::new_<MyQueue>(locality))
	{}

	hpx::future<void> Push(int id) {
		typedef MyQueue::Push_action_MyQueue action_type;
		return hpx::async<action_type>(this->get_id(), id);
	}

	hpx::future<int> Pop() {
		typedef MyQueue::Pop_action_MyQueue action_type;
		return hpx::async<action_type>(this->get_id());
	}
	
	hpx::future<size_t> Size() {
		typedef MyQueue::Size_action_MyQueue action_type;
		return hpx::async<action_type>(this->get_id());
	}
};

