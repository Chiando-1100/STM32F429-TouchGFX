#ifndef SELECTSCREENPRESENTER_HPP
#define SELECTSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SelectScreenView;

class SelectScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SelectScreenPresenter(SelectScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~SelectScreenPresenter() {}

private:
    SelectScreenPresenter();

    SelectScreenView& view;
};

#endif // SELECTSCREENPRESENTER_HPP
