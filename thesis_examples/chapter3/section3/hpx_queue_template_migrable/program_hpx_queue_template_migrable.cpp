#include "myqueue_client.hpp"
#include <hpx/hpx.hpp>
#include <hpx/hpx_main.hpp>
#include <hpx/iostream.hpp>



class Object {
public:
    Object() = default;
    void setA(int a) {
        this->a = a;
    }
    void setB(double b) {
        this->b = b;
    }
    void setC(std::string c) {
        this->c = c;
    }

    int getA(){
        return a;
    }
    double getB() {
        return b;
    }
    std::string getC(){
        return c;
    }
    //friend class hpx::serialization::access;
    template <typename Archive>
    void serialize(Archive& ar, unsigned) {   
        ar& a;
        ar& b;
        ar& c;
    }

private:
    int a = 1;
    double b = 1.1;
    std::string c = "1.2";
};

REGISTER_MYQUEUE(Object);
REGISTER_MYQUEUE(int);


int main(int argc, char* argv[]) {
    
    if(hpx::get_locality_id() != 0) {
        hpx::lcos::barrier barrier("barreira444", 2);
        barrier.wait();
        return 0;
    }


    hpx::id_type locality = hpx::find_here();
    MyQueue_Client<Object> myqueue(locality);
    Object objA; Object objB; Object objC;
    
    myqueue.Push(objA).get();
    myqueue.Push(objB).get();
    myqueue.Push(objC).get();

    // std::vector<hpx::id_type> remote_localities = hpx::find_remote_localities();
    // hpx::id_type dest = remote_localities[0];
    // myqueue.Migrate(dest).get();

    myqueue.Pop().get();
    
    auto size = myqueue.Size();
    std::cout << size.get() << std::endl; // irá imprimir 1


    // hpx::lcos::barrier barrier("barreira444", 2);
    // barrier.wait();
    return 0;
}
