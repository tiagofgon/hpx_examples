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


int main(int argc, char* argv[]) {

    hpx::id_type locality = hpx::find_here();
    MyQueue_Client<Object> myqueue(locality, 42);
    Object objA; Object objB; Object objC;
    
    myqueue.Push(objA).get();
    myqueue.Push(objB).get();
    myqueue.Push(objC).get();

    myqueue.Pop().get();
    
    auto size = myqueue.Size();
    std::cout << size.get() << std::endl; // irá imprimir 2

    auto id = myqueue.GetID();
    std::cout << id.get() << std::endl; // irá imprimir 42

    return 0;
}