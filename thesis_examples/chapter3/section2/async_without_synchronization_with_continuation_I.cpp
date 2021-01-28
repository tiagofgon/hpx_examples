#include <hpx/hpx_main.hpp>
#include <hpx/hpx.hpp>


// primeira ação
double add_one(double i) {
    return i+1;
}
HPX_PLAIN_ACTION(add_one, add_one_action);

// segunda ação
double add_two(double i) {
    return i+2;
}
HPX_PLAIN_ACTION(add_two, add_two_action);


int main(){
    add_one_action act1;
    add_two_action act2;
    
    hpx::future<double> f = hpx::async_continue(act1, hpx::make_continuation(act2), hpx::find_here(), 2.8);
    std::cout << f.get() << "\n"; // Irá imprimir: 5.8: ((2.8 + 1) + 2)
    return 0;
}