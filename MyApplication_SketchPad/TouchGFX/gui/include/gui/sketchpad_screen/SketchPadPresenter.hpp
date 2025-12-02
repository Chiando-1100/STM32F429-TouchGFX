#ifndef SKETCHPADPRESENTER_HPP
#define SKETCHPADPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SketchPadView;

class SketchPadPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SketchPadPresenter(SketchPadView& v);

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

    virtual ~SketchPadPresenter() {}

    void clearSketch();
    void setSketchColor(touchgfx::colortype c);
    void updateRedValue(int value);
    void updateGreenValue(int value);
    void updateBlueValue(int value);
    touchgfx::colortype getColorValue();
    touchgfx::colortype confirmColorValue();

private:
    SketchPadView& view;
    SketchPadPresenter();
    int r,g,b;
};

#endif // SKETCHPADPRESENTER_HPP
