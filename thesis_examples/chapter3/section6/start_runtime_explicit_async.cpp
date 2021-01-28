#include <hpx/hpx_start.hpp>


int hpx_main(int argc, char * argv[]) {
    // Any HPX application logic goes here...
    return hpx::finalize();
}

int main(int argc, char * argv[]) {
    // Initialize HPX, run hpx_main.
    hpx::start(argc, argv);
    std::cout << "Hello from the main thread!" << std::endl;
    
    // Wait for hpx::finalize being called.
    return hpx::stop();
}