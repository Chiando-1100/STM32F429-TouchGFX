#ifndef LANGUAGESCREENPRESENTER_HPP
#define LANGUAGESCREENPRESENTER_HPP


#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>
#include <texts/TextKeysAndLanguages.hpp>
using namespace touchgfx;

class LanguageScreenView;

class LanguageScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LanguageScreenPresenter(LanguageScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~LanguageScreenPresenter() {}

private:
    LanguageScreenPresenter();

    LanguageScreenView& view;
};

#endif // LANGUAGESCREENPRESENTER_HPP
