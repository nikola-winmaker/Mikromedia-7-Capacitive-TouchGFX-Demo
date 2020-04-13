/**
******************************************************************************
* File Name : TouchGFXConfiguration.cpp
******************************************************************************
* @attention
*
* <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
* All rights reserved.</center></h2>
*
* This software component is licensed by ST under Ultimate Liberty license
* SLA0044, the "License"; You may not use this file except in compliance with
* the License. You may obtain a copy of the License at:
* www.st.com/SLA0044
*
******************************************************************************
*/
#include <texts/TypedTextDatabase.hpp>
#include <fonts/ApplicationFontProvider.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <BitmapDatabase.hpp>
#include <platform/driver/lcd/LCD16bpp.hpp>
#include <STM32TouchController.hpp>
#include <touchgfx/hal/OSWrappers.hpp>
#include <touchgfx/hal/NoDMA.hpp>
#include <TouchGFXHAL.hpp>
#include <stm32f7xx_hal.h>


extern "C" void touchgfx_init();
extern "C" void touchgfx_taskEntry();

extern uint32_t vsync_sem;
static STM32TouchController tc;
static NoDMA dma;
static LCD16bpp display;
static ApplicationFontProvider fontProvider;
static Texts texts;
static TouchGFXHAL hal(dma, display, tc, 800, 480);

//ManyBlockAllocator<32000,8,2> frameBufferAllocator;
ManyBlockAllocator<96000,4,2> frameBufferAllocator;

void touchgfx_init()
{

  Bitmap::registerBitmapDatabase(BitmapDatabase::getInstance(), BitmapDatabase::getInstanceSize());
  TypedText::registerTexts(&texts);
  Texts::setLanguage(0);

  FontManager::setFontProvider(&fontProvider);

  FrontendHeap& heap = FrontendHeap::getInstance();
  (void)heap; // we need to obtain the reference above to initialize the frontend heap.

  hal.initialize();
  tc.init();

  hal.registerEventListener(*(Application::getInstance()));
  hal.setFrameBufferAllocator(&frameBufferAllocator);
  hal.setFrameRefreshStrategy(HAL::REFRESH_STRATEGY_PARTIAL_FRAMEBUFFER);

  hal.setTouchSampleRate(1);
  hal.setFingerSize(1);

  hal.enableLCDControllerInterrupt();
  hal.enableInterrupts();
}

void touchgfx_taskEntry()
{
  OSWrappers::waitForVSync();	// when  VSYNC occurs, signals TouchGFX to start a rendering
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/