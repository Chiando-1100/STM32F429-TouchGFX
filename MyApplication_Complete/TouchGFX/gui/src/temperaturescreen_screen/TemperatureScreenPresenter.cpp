#include <gui/temperaturescreen_screen/TemperatureScreenView.hpp>
#include <gui/temperaturescreen_screen/TemperatureScreenPresenter.hpp>
#include "temp_sensor.h"

TemperatureScreenPresenter::TemperatureScreenPresenter(TemperatureScreenView& v)
    : view(v)
{

}

void TemperatureScreenPresenter::activate()
{
	active = true;
	model->setTemperatureSampling(true);
}

void TemperatureScreenPresenter::deactivate()
{
	active = false;
	model->setTemperatureSampling(false);
	view.disableGraph();
}
void TemperatureScreenPresenter::onNewTemperature(int16_t temp10)
{
	if (!active) return;
    view.updateTemperature(temp10);
}

