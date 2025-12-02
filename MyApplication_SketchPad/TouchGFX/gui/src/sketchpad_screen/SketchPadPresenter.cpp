#include <gui/sketchpad_screen/SketchpadView.hpp>
#include <gui/sketchpad_screen/SketchpadPresenter.hpp>
#include <touchgfx/Color.hpp>

SketchPadPresenter::SketchpadPresenter(SketchpadView& v)
    : view(v)
{

}

void SketchPadPresenter::activate()
{

}

void SketchPadPresenter::deactivate()
{

}

void SketchPadPresenter::clearSketch()
{
    view.getSketch().clear();
}

void SketchPadPresenter::setSketchColor(touchgfx::colortype c)
{
    view.getSketch().setColor(c);
}

void SketchPadPresenter::updateRedValue(int value){
	r = value;
};
void SketchPadPresenter::updateGreenValue(int value){
	g = value;
};
void SketchPadPresenter::updateBlueValue(int value){
	b = value;
};

touchgfx::colortype SketchPadPresenter::getColorValue(){
	touchgfx::colortype c = touchgfx::Color::getColorFromRGB(r,g,b);
	return c;
}

touchgfx::colortype SketchPadPresenter::confirmColorValue()
{
	touchgfx::colortype c = touchgfx::Color::getColorFromRGB(r,g,b);
	setSketchColor(c);
	return c;
}
