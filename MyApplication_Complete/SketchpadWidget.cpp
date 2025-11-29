/*
 * SketchpadWidget.cpp
 *
 *  Created on: Nov 17, 2025
 *      Author: chiando
 */


#include "SketchpadWidget.hpp"

Sketchpad::Sketchpad()
    : CanvasWidget(), isDrawing(false), lastX(0), lastY(0), currentX(0), currentY(0),
      penColor(touchgfx::Color::getColorFromRGB(0, 0, 0)), penWidth(2)
{
    setPosition(0, 0, touchgfx::HAL::DISPLAY_WIDTH, touchgfx::HAL::DISPLAY_HEIGHT);
}

void Sketchpad::setPosition(int16_t x, int16_t y, int16_t width, int16_t height)
{
    CanvasWidget::setPosition(x, y, width, height);
    sketchArea = touchgfx::Rect(x, y, width, height);
}

void Sketchpad::handleClickEvent(const touchgfx::ClickEvent& evt)
{
    if (evt.getType() == touchgfx::ClickEvent::PRESSED)
    {
        isDrawing = true;
        lastX = evt.getX();
        lastY = evt.getY();
        currentX = lastX;
        currentY = lastY;
        invalidate();
    }
    else if (evt.getType() == touchgfx::ClickEvent::RELEASED)
    {
        isDrawing = false;
    }
}

void Sketchpad::handleDragEvent(const touchgfx::DragEvent& evt)
{
    if (isDrawing)
    {
        currentX = evt.getX();
        currentY = evt.getY();

        const int16_t minX = touchgfx::min(lastX, currentX) - penWidth;
        const int16_t minY = touchgfx::min(lastY, currentY) - penWidth;
        const int16_t maxX = touchgfx::max(lastX, currentX) + penWidth;
        const int16_t maxY = touchgfx::max(lastY, currentY) + penWidth;
        touchgfx::Rect invalidRect(minX, minY, maxX - minX, maxY - minY);

        invalidateRect(invalidRect & sketchArea);
        lastX = currentX;
        lastY = currentY;
    }
}

bool Sketchpad::draw(const touchgfx::Rect& invalidatedArea) const
{
    if (!isDrawing)
        return true;

    // 此处Canvas的命名空间和路径已适配你的版本
    touchgfx::Canvas canvas(this, invalidatedArea);
    canvas.setColor(penColor);
    canvas.setLineWidth(penWidth);
    canvas.setStrokeLineCap(touchgfx::Canvas::ROUND_CAP);
    canvas.setStrokeLineJoin(touchgfx::Canvas::ROUND_JOIN);

    canvas.moveTo(lastX, lastY);
    canvas.lineTo(currentX, currentY);
    canvas.stroke();

    return true;
}

void Sketchpad::clear()
{
    invalidate();
}

void Sketchpad::setPenColor(touchgfx::colortype color)
{
    penColor = color;
}

void Sketchpad::setPenWidth(uint8_t width)
{
    penWidth = width;
}

