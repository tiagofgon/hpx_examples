
#include <hpx/hpx.hpp>


class Container: public hpx::components::abstract_base_migration_support< hpx::components::abstract_component_base<Container> >
{

public:
    typedef hpx::components::abstract_base_migration_support< hpx::components::abstract_component_base<Container> > base_type;

    Container(); // needed by hpx for serialization
    virtual ~Container();
    Container(int _id);

    // Components which should be migrated using hpx::migrate<> need to
    // be Serializable and CopyConstructable. Components can be
    // MoveConstructable in which case the serialized data is moved into the
    // component's constructor.
    Container(Container const& rhs)
      : base_type(rhs), _id(rhs._id)
    {}

    Container(Container && rhs)
      : base_type(std::move(rhs)), _id(rhs._id)
    {}

    Container& operator=(Container const & rhs)
    {
        _id = rhs._id;
        return *this;
    }
    Container& operator=(Container && rhs)
    {
        _id = rhs._id;
        return *this;
    }

    virtual int GetID() const;
    int GetID_nonvirt() const;

    HPX_DEFINE_COMPONENT_ACTION(Container, GetID_nonvirt, GetID_action_Container);
    
    template <typename Archive>
    void serialize(Archive& ar, unsigned version)
    {
        ar & _id;
    }

private:
    int _id;
};

typedef Container::GetID_action_Container GetID_action_Container;
HPX_REGISTER_ACTION_DECLARATION(GetID_action_Container);