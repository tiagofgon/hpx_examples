#include <hpx/hpx_main.hpp>
#include <hpx/hpx.hpp>


class MyClass { 
    private: 
        int length; 
        int width;

    public:
        template <typename Archive>
        void serialize(Archive& ar, unsigned) {   
            ar & length;
            ar & width;
        }
 
        int getLength(){ return length; }
        int getWidth(){ return width; }
        void setLength(int length){ this->length = length; }
        void setWidth(int width){ this->width = width; }
};

int main() {
    std::unique_ptr<MyClass> p1 = std::make_unique<MyClass>(); // criação de um objeto do tipo MyClass
    p1->setLength(90);
    p1->setWidth(40);

    // serializar
    std::vector<char> buffer;
    hpx::serialization::output_archive oarchive(buffer);
    oarchive << p1;
    
    // desserializar
    std::unique_ptr<MyClass> p2;
    hpx::serialization::input_archive iarchive(buffer);
    iarchive >> p2;
    
    std::cout << p2->getLength() << std::endl;
    std::cout << p2->getWidth() << std::endl;

    return 0;
}