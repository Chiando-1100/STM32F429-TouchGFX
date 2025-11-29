#ifndef BTNCONTAINER_HPP
#define BTNCONTAINER_HPP

#include <gui_generated/containers/BtnContainerBase.hpp>

class BtnContainer : public BtnContainerBase
{
public:
    BtnContainer();
    virtual ~BtnContainer() {}

    virtual void initialize();
protected:
};

#endif // BTNCONTAINER_HPP
