
#include <hpx/hpx.hpp>
#include <hpx/hpx_main.hpp>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
    {
        std::cout << "Antes da barreira: " << std::endl;
        hpx::lcos::barrier barrier("barreira", 2);
        barrier.wait();
    }

    std::cout << "program " << std::endl;
    std::cout << "Localidade: " << hpx::get_locality_id() << std::endl;

    {
        //auto res = system("/home/tfg/Documentos/hpx_examples/hello_world/program");
    }

    return 0;
}
