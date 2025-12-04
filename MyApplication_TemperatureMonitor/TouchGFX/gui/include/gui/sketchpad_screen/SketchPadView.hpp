#ifndef SKETCHPADVIEW_HPP
#define SKETCHPADVIEW_HPP

#include <gui_generated/sketchPad_screen/SketchPadViewBase.hpp>
#include <gui/sketchpad_screen/SketchPadPresenter.hpp>

class SketchPadView : public SketchPadViewBase
{
public:
    SketchPadView();
    virtual ~SketchPadView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    SketchContainer& getSketch()
      {
          return sketchContainer1;   //获取绘制窗口名字
      }

protected:

};

#endif // SKETCHPADVIEW_HPP
