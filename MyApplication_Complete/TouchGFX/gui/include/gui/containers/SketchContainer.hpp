#ifndef SKETCHCONTAINER_HPP
#define SKETCHCONTAINER_HPP

#include <gui_generated/containers/SketchContainerBase.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>

struct LineNode
{
    touchgfx::Line line;
    touchgfx::PainterRGB565 painter;

    int16_t sx, sy;   // 我们自己保存的起点
    int16_t ex, ey;   // 我们自己保存的终点
};


class SketchContainer : public SketchContainerBase
{
public:
    enum { MAX_LINES = 600 };   // 可改 400~700，600 不会爆 RAM

    SketchContainer();
    virtual ~SketchContainer() {}

    virtual void initialize() override;

    virtual void handleClickEvent(const touchgfx::ClickEvent& event) override;
    virtual void handleDragEvent(const touchgfx::DragEvent& event) override;

    void clear();
    void setColor(touchgfx::colortype c);

private:
    LineNode lines[MAX_LINES];

    int      lineCount;
    bool     touchActive;
    bool     fingerDown;
    int16_t  lastX;
    int16_t  lastY;
    touchgfx::colortype currentColor;

    enum { CANVAS_X = 0 };
    enum { CANVAS_Y = 0 };
    enum { CANVAS_W = 240 };
    enum { CANVAS_H = 260 };
    bool willOverlap(int x0, int y0, int x1, int y1);
    bool insideCanvas(int16_t x, int16_t y) const;
};

#endif // SKETCHCONTAINER_HPP
