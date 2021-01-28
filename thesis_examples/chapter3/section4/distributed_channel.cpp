#include <hpx/hpx_main.hpp>
#include <hpx/hpx.hpp>


HPX_REGISTER_CHANNEL(double);

void troca_de_dados(hpx::lcos::channel<double> canal) {
    for (double d : canal)
        std::cout << d << std::endl;
}
HPX_PLAIN_ACTION(troca_de_dados, troca_de_dados_action);

int main() {
    // cria o canal na localidade atual
    hpx::lcos::channel<double> canal(hpx::find_here());

    // envia o canal para a ação, que potencialmente irá executar remotamente
    hpx::apply(troca_de_dados_action(), hpx::find_here(), canal);
    
    // envia os dados para o recetor
    std::vector<double> v = { 1.2, 3.4, 5.0 };
    for (double d : v)
        canal.set(d);
        
    // explicitamente encerra o canal de comunicação (implícito quando sai fora do escopo)
    canal.close();
}