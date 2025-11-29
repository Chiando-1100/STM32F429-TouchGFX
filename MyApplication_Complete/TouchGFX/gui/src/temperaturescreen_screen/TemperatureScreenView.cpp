#include <gui/temperaturescreen_screen/TemperatureScreenView.hpp>
#include "temp_sensor.h"
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <cstdint>

TemperatureScreenView::TemperatureScreenView()
	: xIndex(0)
{

}

void TemperatureScreenView::setupScreen()
{
    TemperatureScreenViewBase::setupScreen();
    xIndex = 0;
    tempGraph.clear();

}

void TemperatureScreenView::tearDownScreen()
{
    TemperatureScreenViewBase::tearDownScreen();
    // 停止图表继续刷新
	tempGraph.setVisible(false);
	tempGraph.invalidate();          // ← 清除所有未绘制区域
	remove(tempGraph);
}

void TemperatureScreenView::updateTemperature(int16_t temp10)
{
    // 1. 更新数字显示（tempText）
    float t = temp10 / (10.0f);
    Unicode::snprintfFloat(tempTextBuffer, TEMPTEXT_SIZE, "%.1f", t);
    tempText.invalidate();

    // 2. 更新折线图
    tempGraph.addDataPoint(t);

    // 如果用了“滚动模式”，TouchGFX 会自动把旧点左移；否则你可以控制缓存大小
    tempGraph.invalidate();
}

void TemperatureScreenView::resetGraph()
{
    for (int i = 0; i < 50; i++)
        tempGraph.addDataPoint(0);
    tempGraph.invalidate();
}

void TemperatureScreenView::disableGraph()
{
    tempGraph.setVisible(false);       // 停止绘制
    tempGraph.invalidate();            // 强制刷新一次，把区域清掉

}



