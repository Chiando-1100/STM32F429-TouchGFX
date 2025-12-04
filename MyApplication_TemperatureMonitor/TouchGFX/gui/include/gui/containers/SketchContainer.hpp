#ifndef SKETCHCONTAINER_HPP
#define SKETCHCONTAINER_HPP

#include <gui_generated/containers/SketchContainerBase.hpp>
#include <touchgfx/widgets/canvas/Line.hpp> //通过画线来逼近绘制曲线的效果
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>

struct LineNode //直线节点，用于保存每一条线的位置数据，用于滤波和平滑算法
{
    touchgfx::Line line;
    touchgfx::PainterRGB565 painter;

    int16_t sx, sy;   // 我们自己保存的起点
    int16_t ex, ey;   // 我们自己保存的终点
};

class SketchContainer : public SketchContainerBase
{
public:
    SketchContainer();
    virtual ~SketchContainer() {}

    virtual void initialize();

    enum { MAX_LINES = 600 };   // 可改 400~700，600 不会爆 RAM

       virtual void handleClickEvent(const touchgfx::ClickEvent& event) override;
       virtual void handleDragEvent(const touchgfx::DragEvent& event) override;

       void clear();
       void setColor(touchgfx::colortype c);

protected:
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
