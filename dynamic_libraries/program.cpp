
#include <hpx/hpx.hpp>
#include <hpx/hpx_main.hpp>

int main()
{

    std::string const& library = "libmodule.so";
    void *handle = dlopen(library.c_str(), RTLD_NOW);

    std::string const& function = "hello_t";
    typedef void (*func_type)(void);
    func_type func = (func_type)dlsym(handle, function.c_str());

    func();

    return 0;
}
