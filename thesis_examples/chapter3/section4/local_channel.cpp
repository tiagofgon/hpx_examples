#include <hpx/hpx_main.hpp>
#include <hpx/hpx.hpp>

int main() {
    hpx::lcos::local::channel<int> canal; // cria um canal do tipo int
    canal.set(42); // coloca no canal o valor 42
    hpx::future<int> msg_received = canal.get(); // recebe do canal o valor 42 dentro de um future
    std::cout << msg_received.get() << std::endl; // irá imprimir '42'
}