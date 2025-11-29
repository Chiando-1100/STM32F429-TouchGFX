#include <gui/sketchpad_screen/SketchpadView.hpp>
#include <gui/sketchpad_screen/SketchpadPresenter.hpp>
#include <touchgfx/Color.hpp>

SketchpadPresenter::SketchpadPresenter(SketchpadView& v)
    : view(v)
{

}

void SketchpadPresenter::activate()
{

}

void SketchpadPresenter::deactivate()
{

}

void SketchpadPresenter::clearSketch()
{
    view.getSketch().clear();
}

void SketchpadPresenter::setSketchColor(touchgfx::colortype c)
{
    view.getSketch().setColor(c);
}

void SketchpadPresenter::updateRedValue(int value){
	r = value;
};
void SketchpadPresenter::updateGreenValue(int value){
	g = value;
};
void SketchpadPresenter::updateBlueValue(int value){
	b = value;
};

touchgfx::colortype SketchpadPresenter::getColorValue(){
	touchgfx::colortype c = touchgfx::Color::getColorFromRGB(r,g,b);
	return c;
}

touchgfx::colortype SketchpadPresenter::confirmColorValue()
{
	touchgfx::colortype c = touchgfx::Color::getColorFromRGB(r,g,b);
	setSketchColor(c);
	return c;
}
