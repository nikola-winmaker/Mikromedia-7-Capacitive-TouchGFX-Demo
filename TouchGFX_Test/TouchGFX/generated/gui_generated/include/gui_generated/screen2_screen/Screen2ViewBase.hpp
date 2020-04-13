/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN2VIEWBASE_HPP
#define SCREEN2VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/containers/SwipeContainer.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/containers/progress_indicators/CircleProgress.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565Bitmap.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/widgets/AnimatedImage.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>
#include <touchgfx/widgets/RadioButtonGroup.hpp>
#include <touchgfx/mixins/Draggable.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <touchgfx/mixins/MoveAnimator.hpp>

class Screen2ViewBase : public touchgfx::View<Screen2Presenter>
{
public:
    Screen2ViewBase();
    virtual ~Screen2ViewBase() {}
    virtual void setupScreen();
    virtual void handleTickEvent();
    virtual void afterTransition();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box box1;
    touchgfx::Draggable< touchgfx::MoveAnimator< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > > > > flexButton1;
    touchgfx::SwipeContainer swipeContainer2;
    touchgfx::Container swipeContainer2Page1;
    touchgfx::Button button3;
    touchgfx::Container swipeContainer2Page2;
    touchgfx::CircleProgress circleProgress1;
    touchgfx::PainterRGB565Bitmap circleProgress1Painter;
    touchgfx::Container swipeContainer2Page3;
    touchgfx::RadioButton radioButton1;
    touchgfx::Box box2;
    touchgfx::AnimatedImage animatedImage1;
    touchgfx::ButtonWithLabel buttonWithLabel1;
    touchgfx::ButtonWithIcon buttonWithIcon2;
    touchgfx::RadioButtonGroup<1> radioButtonGroup1;

private:

    /*
     * Delay Variable Declarations
     */
    static const uint16_t INTERACTION3_DURATION = 0;
    uint16_t interaction3Counter;

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen2ViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<Screen2ViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 12000;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // SCREEN2VIEWBASE_HPP