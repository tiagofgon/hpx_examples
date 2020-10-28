#include <unistd.h>
#include <sys/wait.h>
#include <iostream>


int main() {

std::cout << "P2 " << std::endl;
auto res = system("/home/tfg/Documentos/hpx_examples/add_dynamic_localities/build/program --hpx:hpx=localhost:1338 --hpx:agas=localhost:1337 --hpx:run-hpx-main --hpx:expect-connecting-localities --hpx:worker");

    return 0;
}