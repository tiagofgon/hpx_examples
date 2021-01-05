
#include <hpx/hpx.hpp>
#include <hpx/hpx_main.hpp>


struct MyComponent: public hpx::components::component_base<MyComponent> 
{
public:
    template <typename ... Args>
    void Run(Args&& ... args) {
        (std::cout << ... << args); 
        std::cout << std::endl;
    }

    template <typename ... Args>
    struct Run_action_MyComponent
    : hpx::actions::make_action<
        decltype(&MyComponent::Run<Args...>),
        &MyComponent::Run<Args...>
    >::type
    {};
};

HPX_REGISTER_COMPONENT_MODULE();
typedef hpx::components::component<MyComponent> MyComponent_type;
HPX_REGISTER_COMPONENT(MyComponent_type, MyComponent);

int main()
{
    auto gid = hpx::local_new<MyComponent>().get();

    {// don't work
        std::string string = "hello";
        typedef MyComponent::Run_action_MyComponent<std::string> action_type;
        hpx::apply<action_type>(gid, string);
    }

    {// work
        std::string const& string = "hello";
        typedef MyComponent::Run_action_MyComponent<std::string const&> action_type;
        hpx::apply<action_type>(gid, string);
    }
    return 0;
}
