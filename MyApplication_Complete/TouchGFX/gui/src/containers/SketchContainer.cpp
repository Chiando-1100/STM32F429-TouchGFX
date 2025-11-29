#include <gui/containers/SketchContainer.hpp>
#include <touchgfx/Color.hpp>

struct SmoothState
{
    int16_t x1 = 0;    // 上一帧
    int16_t x2 = 0;    // 上上帧
    int16_t y1 = 0;
    int16_t y2 = 0;

    void reset(int16_t x, int16_t y)
    {
        x1 = x2 = x;
        y1 = y2 = y;
    }
};

SketchContainer::SketchContainer()
    : lineCount(0),
      touchActive(false),
      fingerDown(false),
      lastX(0),
      lastY(0)
{
    setTouchable(true);
    currentColor=(touchgfx::Color::getColorFromRGB(0,0,0));
}

void SketchContainer::initialize()
{
    SketchContainerBase::initialize();

    box1.setPosition(CANVAS_X, CANVAS_Y, CANVAS_W, CANVAS_H);
    box1.setColor(touchgfx::Color::getColorFromRGB(255,255,255));

    for (int i = 0; i < MAX_LINES; i++)
        {
            LineNode& node = lines[i];

            node.sx = 0;
            node.sy = 0;
            node.ex = 0;
            node.ey = 0;

            node.line.setPosition(CANVAS_X, CANVAS_Y, CANVAS_W, CANVAS_H);
            node.painter.setColor(currentColor);
            node.line.setLineWidth(2);
            node.line.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
            node.line.setVisible(false);

            node.line.setPainter(node.painter);

            // Line 本身不能设置 position，因此只加入
            add(node.line);
        }
}

bool SketchContainer::insideCanvas(int16_t x, int16_t y) const
{
    return (x >= CANVAS_X && x < CANVAS_X + CANVAS_W &&
            y >= CANVAS_Y && y < CANVAS_Y + CANVAS_H);
}

static inline bool isJump(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int d2 = dx*dx + dy*dy;

    return (d2 > 30 && d2 < 120);   // 12~20px 视为跳点
}

static inline int smooth(int oldValue, int newValue)
{
    return (oldValue + newValue*3) / 4; // 75% 新点
}

inline int16_t smooth2(int16_t x2, int16_t x1, int16_t n)
{
    // 二阶滤波：1/4 old2 + 2/4 old1 + 1/4 new
    return (x2 + x1*2 + n) >> 2;
}

// 返回 true = 会覆盖旧线，禁止绘制
bool SketchContainer::willOverlap(int x0, int y0, int x1, int y1)
{
    const int minDist2 = 9;  // <3px 认为覆盖

    for (int i = 0; i < lineCount; i++)
    {
        const LineNode& LN = lines[i];

        int dx = LN.sx - x1;
        int dy = LN.sy - y1;
        if (dx*dx + dy*dy < minDist2) return true;

        dx = LN.ex - x1;
        dy = LN.ey - y1;
        if (dx*dx + dy*dy < minDist2) return true;
    }
    return false;
}


void SketchContainer::handleClickEvent(const touchgfx::ClickEvent& e)
{
    if (e.getType() == touchgfx::ClickEvent::PRESSED)
    {
        fingerDown = true;
        lastX = e.getX();
        lastY = e.getY();

        if (!insideCanvas(lastX, lastY))
            fingerDown = false;
    }
    else if (e.getType() == touchgfx::ClickEvent::RELEASED)
    {
        fingerDown = false;
        touchActive = false;
    }

    SketchContainerBase::handleClickEvent(e);
}

void SketchContainer::handleDragEvent(const touchgfx::DragEvent& e)
{
    if (!fingerDown) return;

    int rx = e.getNewX();
    int ry = e.getNewY();

    if (!insideCanvas(rx, ry))
    {
        fingerDown = false;
        return;
    }

    int x = (lastX * 1 + rx * 3) >> 2;  // 简单平滑
    int y = (lastY * 1 + ry * 3) >> 2;

    if (abs(x - lastX) < 2 && abs(y - lastY) < 2)
        return;

    if (willOverlap(lastX, lastY, x, y))
        return;

    if (lineCount >= MAX_LINES)
        return;

    LineNode& node = lines[lineCount];

    node.sx = lastX;
    node.sy = lastY;
    node.ex = x;
    node.ey = y;

    node.painter.setColor(currentColor);
    node.line.setPainter(node.painter);

    node.line.setLineWidth(2);
    node.line.setVisible(true);

    node.line.setStart(node.sx - CANVAS_X, node.sy - CANVAS_Y);
    node.line.setEnd(node.ex - CANVAS_X,   node.ey - CANVAS_Y);

    node.line.invalidate();

    lastX = x;
    lastY = y;
    lineCount++;
}


void SketchContainer::clear()
{
    for (int i = 0; i < lineCount; i++)
    {
        lines[i].line.setVisible(false);
        lines[i].line.invalidate();
    }
    lineCount = 0;
}


void SketchContainer::setColor(touchgfx::colortype c)
{
	currentColor = c;
}
