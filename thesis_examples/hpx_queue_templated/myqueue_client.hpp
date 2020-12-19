#include "myqueue.hpp"
#include <hpx/hpx.hpp>


template <typename T>
class MyQueue_Client: hpx::components::client_base<MyQueue_Client<T>, MyQueue<T>>
{
public:
    typedef hpx::components::client_base<MyQueue_Client<T>, MyQueue<T>> base_type;

	MyQueue_Client() : base_type(hpx::local_new<MyQueue<T>>())
	{}
	MyQueue_Client(hpx::id_type locality) : base_type(hpx::new_<MyQueue<T>>(locality))
	{}

	hpx::future<void> Push(T object) {
		typedef typename MyQueue<T>::Push_action_MyQueue action_type;
		return hpx::async<action_type>(this->get_id(), object);
	}

	hpx::future<T> Pop() {
		typedef typename MyQueue<T>::Pop_action_MyQueue action_type;
		return hpx::async<action_type>(this->get_id());
	}
	
	hpx::future<size_t> Size() {
		typedef typename MyQueue<T>::Size_action_MyQueue action_type;
		return hpx::async<action_type>(this->get_id());
	}
};

