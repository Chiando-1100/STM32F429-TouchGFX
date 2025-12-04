#include <gui/tempscreen_screen/TempScreenView.hpp>
#include <gui/tempscreen_screen/TempScreenPresenter.hpp>

TempScreenPresenter::TempScreenPresenter(TempScreenView& v)
    : view(v)
{

}

void TempScreenPresenter::activate()
{
	model->setTemperatureSampling(true);
}

void TempScreenPresenter::deactivate()
{
	model->setTemperatureSampling(false);
}
void TempScreenPresenter::onNewTemperature(int16_t temp10)
{
    view.updateTemperature(temp10);
}
