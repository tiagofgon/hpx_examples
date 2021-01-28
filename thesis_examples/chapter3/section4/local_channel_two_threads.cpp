#include <hpx/hpx_main.hpp>
#include <hpx/hpx.hpp>

void troca_de_dados(hpx::lcos::local::receive_channel<int> canal,
                    hpx::lcos::local::send_channel<> done)
{
    hpx::future<int> received_data = canal.get(); // recebe o valor
    std::cout << received_data.get() << std::endl; // imprime 42
    done.set(); // envia o sinal de retorno
}

int main() {
    hpx::lcos::local::channel<int> canal; // canal para transmissão de um valor
    hpx::lcos::local::channel<> done;     // canal para transmissão de um acknowledgement
    hpx::apply(&troca_de_dados, canal, done); // execução de forma assincrona da função
        
    canal.set(42); // envia um valor do tipo int
    done.get(); // espera pelo sinal de retorno
}