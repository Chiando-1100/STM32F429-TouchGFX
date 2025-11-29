#ifndef SELECTSCREENVIEW_HPP
#define SELECTSCREENVIEW_HPP

#include <gui_generated/selectscreen_screen/SelectScreenViewBase.hpp>
#include <gui/selectscreen_screen/SelectScreenPresenter.hpp>

class SelectScreenView : public SelectScreenViewBase
{
public:
    SelectScreenView();
    virtual ~SelectScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SELECTSCREENVIEW_HPP
