
#include <hpx/hpx.hpp>
#include <hpx/hpx_main.hpp>

int main()
{

    std::cout << "Olá mundo!, a partir da localidade: " << hpx::get_locality_id() << std::endl;

    return 0;
}
