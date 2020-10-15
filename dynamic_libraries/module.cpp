
#include <hpx/hpx.hpp>


struct Object: public hpx::components::component_base<Object> 
{
    Object(int base_data = 0) :
        _base_data(base_data) {
        std::cout << "Object()" << std::endl;
    }
private:
    int _base_data;
};

typedef hpx::components::component<Object> Pod_type;
HPX_REGISTER_COMPONENT(Pod_type, Object);

extern "C"
{
    void hello_t();
}

void hello_t () {

    auto id_gid = hpx::new_<Object>(hpx::find_here(), 99).get();
    
}