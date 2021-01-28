#include <hpx/hpx_main.hpp>
#include <hpx/hpx.hpp>

// Definição da função print_double no espaço global
void print_double(double d) {
    std::cout << d << std::endl;
}
// Macro no espaço global com o nome da função e o nome do tipo da ação a criar
HPX_PLAIN_ACTION(print_double, print_double_action);

int main() {
    print_double_action action;
    hpx::future<void> f = hpx::async(action, hpx::find_here(), 2.8);
    //
    // ... outro código pode ser executado aqui
    //
    f.get();
    return 0;
}