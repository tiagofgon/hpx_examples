
#include <hpx/hpx.hpp>
#include <hpx/hpx_main.hpp>


// component base named Resource
struct Resource : hpx::components::abstract_base_migration_support< hpx::components::abstract_component_base<Resource> >
{
public:
    Resource() = default;
    virtual ~Resource() = default;

    Resource(int idp) : 
        _idp{idp} 
    {
        std::cout << "Resource()" << std::endl;
    }

    Resource(Resource&& rhs)
      : _idp(std::move(rhs._idp))
    {}

    Resource& operator=(Resource&& rhs)
    {
        _idp = std::move(rhs._idp);
        return *this;
    }

    template <typename Archive>
    void serialize(Archive& ar, unsigned)
    {
        ar & _idp;
    }

private:
    int _idp;

};

HPX_DEFINE_GET_COMPONENT_TYPE(Resource);




// Concrete component named Domain derived from Resource
// struct Domain: public hpx::components::locking_hook< hpx::components::abstract_migration_support< hpx::components::component_base<Domain>, Resource > > ????? ERROR
// struct Domain: public hpx::components::abstract_migration_support< hpx::components::locking_hook<hpx::components::component_base<Domain>>, Resource >   ????? ERROR
struct Domain: public hpx::components::abstract_migration_support< hpx::components::component_base<Domain>, Resource >
{

using base_type = hpx::components::abstract_migration_support< hpx::components::component_base<Domain>, Resource >;

typedef hpx::components::component_base<Domain>::wrapping_type wrapping_type;
typedef Domain type_holder;
typedef Resource base_type_holder;

public:
    Domain() = delete;
    ~Domain() = default;;

    Domain(int idp) :
        base_type(idp),
        _idp2(idp)
    {
        std::cout << "Domain()" << std::endl;
    }

    Domain(Domain&& rhs) :
        base_type(std::move(rhs)),
        _idp2(std::move(rhs._idp2))
    {}

    Domain& operator=(Domain&& rhs)
    {
        this->Resource::operator=(std::move(static_cast<Resource&>(rhs)));
        _idp2 = std::move(rhs._idp2);
        return *this;
    }

    template <typename Archive>
    void serialize(Archive& ar, unsigned version)
    {
        ar & _idp2;
    }

private:
    int _idp2;
};


typedef hpx::components::component<Domain> Domain_type;
HPX_REGISTER_DERIVED_COMPONENT_FACTORY(Domain_type, Domain, "Resource");




int main() {

    hpx::local_new<Domain>(5);


    return 0;
}
