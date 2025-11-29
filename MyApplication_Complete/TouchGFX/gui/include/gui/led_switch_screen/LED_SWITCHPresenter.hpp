#ifndef LED_SWITCHPRESENTER_HPP
#define LED_SWITCHPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LED_SWITCHView;

class LED_SWITCHPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LED_SWITCHPresenter(LED_SWITCHView& v);

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

    virtual ~LED_SWITCHPresenter() {}

private:
    LED_SWITCHPresenter();

    LED_SWITCHView& view;
};

#endif // LED_SWITCHPRESENTER_HPP
