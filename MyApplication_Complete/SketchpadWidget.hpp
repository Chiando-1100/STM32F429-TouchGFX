/*
 * SketchpadWidget.hpp
 *
 *  Created on: Nov 17, 2025
 *      Author: chiando
 */

#ifndef __SKETCHPADWIDGET_HPP
#define __SKETCHPADWIDGET_HPP

#include <touchgfx/widgets/canvas/CanvasWidget.hpp>
#include <touchgfx/widgets/canvas/Canvas.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/events/ClickEvent.hpp>
#include <touchgfx/events/DragEvent.hpp>
#include <touchgfx/hal/HAL.hpp>

class Sketchpad : public touchgfx::CanvasWidget
{
public:
    Sketchpad();

    virtual void setPosition(int16_t x, int16_t y, int16_t width, int16_t height) override;
    virtual void handleClickEvent(const touchgfx::ClickEvent& evt) override;
    virtual void handleDragEvent(const touchgfx::DragEvent& evt) override;
    virtual bool draw(const touchgfx::Rect& invalidatedArea) const override;

    void clear();
    void setPenColor(touchgfx::colortype color);
    void setPenWidth(uint8_t width);

private:
    bool isDrawing;
    int16_t lastX, lastY;
    int16_t currentX, currentY;
    touchgfx::colortype penColor;
    uint8_t penWidth;
    touchgfx::Rect sketchArea;
};

#endif


