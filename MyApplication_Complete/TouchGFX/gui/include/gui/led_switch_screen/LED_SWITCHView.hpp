#ifndef LED_SWITCHVIEW_HPP
#define LED_SWITCHVIEW_HPP

#include <gui_generated/led_switch_screen/LED_SWITCHViewBase.hpp>
#include <gui/led_switch_screen/LED_SWITCHPresenter.hpp>

class LED_SWITCHView : public LED_SWITCHViewBase
{
public:
    LED_SWITCHView();
    virtual ~LED_SWITCHView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:

};

#endif // LED_SWITCHVIEW_HPP
