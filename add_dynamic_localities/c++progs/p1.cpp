#include <unistd.h>
#include <sys/wait.h>
#include <iostream>


int main() {

std::cout << "P1 " << std::endl;
auto res = system("/home/tfg/Documentos/hpx_examples/add_dynamic_localities/build/program --hpx:hpx=localhost:1337 --hpx:expect-connecting-localities --hpx:console");

    return 0;
}