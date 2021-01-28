#include <hpx/hpx_main.hpp>
#include <hpx/hpx.hpp>


namespace app
{
    // Definição da função print_double dentro do espaço app
    void print_double(double d) {
        std::cout << d << std::endl;
    }
    HPX_DEFINE_PLAIN_ACTION(print_double, print_double_action);
}
// Macro no espaço global com o nome do tipo da ação e um nome único para fins internos ao HPX
HPX_REGISTER_ACTION(app::print_double_action, app_print_double_action);

int main() {
    app::print_double_action action;
    action(hpx::find_here(), 2.8); // Execução da ação, na localidade presente, de forma síncrona
    return 0;
}