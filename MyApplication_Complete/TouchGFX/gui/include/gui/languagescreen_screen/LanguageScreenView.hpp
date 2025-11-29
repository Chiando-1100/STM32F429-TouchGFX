#ifndef LANGUAGESCREENVIEW_HPP
#define LANGUAGESCREENVIEW_HPP

#include <gui_generated/languagescreen_screen/LanguageScreenViewBase.hpp>
#include <gui/languagescreen_screen/LanguageScreenPresenter.hpp>

class LanguageScreenView : public LanguageScreenViewBase
{
public:
    LanguageScreenView();
    virtual ~LanguageScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LANGUAGESCREENVIEW_HPP
