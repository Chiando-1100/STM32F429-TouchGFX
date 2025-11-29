#ifndef TEMPERATURESCREENVIEW_HPP
#define TEMPERATURESCREENVIEW_HPP

#include <gui_generated/temperaturescreen_screen/TemperatureScreenViewBase.hpp>
#include <gui/temperaturescreen_screen/TemperatureScreenPresenter.hpp>

class TemperatureScreenView : public TemperatureScreenViewBase
{
public:
    TemperatureScreenView();
    virtual ~TemperatureScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void updateTemperature(int16_t temp10);   // 新增
    void resetGraph();
    void disableGraph();
protected:
    uint16_t xIndex;   // 当前采样点索引
};

#endif // TEMPERATURESCREENVIEW_HPP
