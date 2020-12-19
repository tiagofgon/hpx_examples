#include "myqueue_client.hpp"
#include <hpx/hpx.hpp>
#include <hpx/hpx_main.hpp>
#include <hpx/iostream.hpp>

// int main(int argc, char* argv[]) {

//     hpx::id_type locality = hpx::find_here();
//     std::unique_ptr<MyQueue_Client> myqueue = std::make_unique<MyQueue_Client>(locality);
//     auto f1 = myqueue->Push(1);
//     auto f2 = myqueue->Push(2);

//     auto final = hpx::dataflow([&myqueue](auto f1, auto f2){
//         auto size = myqueue->Size();
//         std::cout << size.get() << std::endl;
//     }, f1, f2);

//     final.get();

// }

int main(int argc, char* argv[]) {
    
    hpx::id_type locality = hpx::find_here();
    MyQueue_Client myqueue(locality);
    auto f1 = myqueue.Push(1);
    auto f2 = myqueue.Push(2);

    auto final = hpx::dataflow([&myqueue](auto f1, auto f2){
        auto size = myqueue.Size();
        std::cout << size.get() << std::endl;
    }, f1, f2);

    final.get();

}