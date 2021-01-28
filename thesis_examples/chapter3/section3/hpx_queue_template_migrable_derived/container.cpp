#include "container.hpp"

Container::Container() = default;
Container::~Container() = default;

Container::Container(int id) : _id{id}
{}

int Container::GetID() const {
    return _id;
}

int Container::GetID_nonvirt() const {
    return GetID();
}


typedef Container Container;
HPX_DEFINE_GET_COMPONENT_TYPE(Container);


typedef Container::GetID_action_Container GetID_action_Container;

HPX_REGISTER_ACTION(GetID_action_Container);