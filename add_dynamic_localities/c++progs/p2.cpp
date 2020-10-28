#include <unistd.h>
#include <sys/wait.h>
#include <iostream>


int main() {

std::cout << "P2 " << std::endl;
auto res = system("/home/tfg/Documentos/hpx_examples/add_dynamic_localities/hello_world/build/program --hpx:hpx=localhost:1338 --hpx:agas=localhost:1337 --hpx:run-hpx-main --hpx:expect-connecting-localities --hpx:worker");



//     int pid = fork();
//     if (pid == 0)
//     {
//         execl("/home/tfg/Documentos/hpx_examples/add_dynamic_localities/build/program", "/home/tfg/Documentos/hpx_examples/add_dynamic_localities/build/program", "--hpx:hpx=localhost:1337", "--hpx:expect-connecting-localities", "--hpx:console", "--hpx:localities 2", nullptr);
//         //execl("/home/tfg/Documentos/hpx_examples/add_dynamic_localities/hello_world/build/program", "/home/tfg/Documentos/hpx_examples/add_dynamic_localities/hello_world/build/program", nullptr);

//     }
// else if (pid > 0)
// {
//     int status;
//     waitpid(pid, &status, 0);

//     printf("I'm the parent\n");
//     return 1;
//     // The parent process, do whatever is needed
//     // The parent process can even exit while the child process is running, since it's independent
// }
// else
// {
//     // Error forking, still in parent process (there are no child process at this point)
//     std::cout << "Fork error:" <<  '\n';
// }


    return 0;
}