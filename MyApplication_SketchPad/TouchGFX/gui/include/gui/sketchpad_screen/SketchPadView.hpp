#ifndef SKETCHPADVIEW_HPP
#define SKETCHPADVIEW_HPP

#include <gui_generated/sketchpad_screen/SketchpadViewBase.hpp>
#include <gui/sketchpad_screen/SketchpadPresenter.hpp>

class SketchpadView : public SketchpadViewBase
{
public:
    SketchpadView();
    virtual ~SketchpadView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    SketchContainer& getSketch()
      {
          return sketchContainer1;   //获取绘制窗口名字
      }

protected:

};

#endif // SKETCHPADVIEW_HPP
