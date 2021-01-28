#include "myqueue_client.hpp"
#include <hpx/hpx.hpp>
#include <hpx/hpx_main.hpp>
#include <hpx/iostream.hpp>


int main(int argc, char* argv[]) {
    hpx::id_type locality = hpx::find_here();
    MyQueue_Client myqueue(locality);
    auto f1 = myqueue.Push(1);
    auto f2 = myqueue.Push(2, 3, 4, 5);

    auto f3 = hpx::dataflow([&myqueue](auto f1, auto f2){
        auto element = myqueue.Pop();
        std::cout << element.get() << std::endl; // irá imprimir 1 ou 2, depende se f1 foi computado primeiro que f2 ou não
    }, f1, f2);

    f3.then([&myqueue](auto f3){ 
        auto size = myqueue.Size();
        std::cout << size.get() << std::endl; // irá imprimir 4
    }).get();
}