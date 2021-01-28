#include "myqueue.hpp"
#include <hpx/hpx.hpp>


template <typename T>
class MyQueue_Client: hpx::components::client_base<MyQueue_Client<T>, MyQueue<T>>
{
public:
	friend class hpx::serialization::access;
    typedef hpx::components::client_base<MyQueue_Client<T>, MyQueue<T>> base_type;

	MyQueue_Client() : base_type(hpx::local_new<MyQueue<T>>())
	{}
	MyQueue_Client(hpx::id_type locality) : base_type(hpx::new_<MyQueue<T>>(locality))
	{}

	template <typename ... Args>
	hpx::future<void> Push(Args ... args)
	{
		typedef typename MyQueue<T>::template Push_action_MyQueue<Args...> action_type;
		return hpx::async<action_type>(this->get_id(), args...);
	}

	hpx::future<T> Pop() {
		typedef typename MyQueue<T>::Pop_action_MyQueue action_type;
		return hpx::async<action_type>(this->get_id());
	}
	
	hpx::future<size_t> Size() {
		typedef typename MyQueue<T>::Size_action_MyQueue action_type;
		return hpx::async<action_type>(this->get_id());
	}

	hpx::future<hpx::id_type> Migrate(hpx::id_type dest) {
		return hpx::components::migrate<MyQueue<T>>(this->get_id(), dest);
	}

	template <typename Archive>
	void serialize(Archive& ar, unsigned) {   
	}
};

