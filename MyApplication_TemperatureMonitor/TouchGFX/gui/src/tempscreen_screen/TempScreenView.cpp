#include <gui/tempscreen_screen/TempScreenView.hpp>
#include <cstdint>

TempScreenView::TempScreenView()
{

}

void TempScreenView::setupScreen()
{
	TempScreenViewBase::setupScreen();
}

void TempScreenView::tearDownScreen()
{
    TempScreenViewBase::tearDownScreen();

}

void TempScreenView::updateTemperature(int16_t temp10)
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


