#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "temp_sensor.h"


Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	if (!enableTemperatureSampling){
		return;     // ← 关键：不在温度界面时不采样
	}
		tickCount++;
	//if (tickCount >= 6)
	//{
	    tickCount = 0;

	    float t = TS_GetTemperature();      // 调用 C 函数
	    int16_t t10 = (int16_t)(t * 10);    // 放大 10 倍传给 GUI（避免用 float）

	    if (modelListener != 0)
	    {
	        modelListener->onNewTemperature(t10);
	    }
	//}
}
