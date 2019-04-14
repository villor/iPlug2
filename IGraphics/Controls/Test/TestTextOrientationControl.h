/*
 ==============================================================================

 This file is part of the iPlug 2 library. Copyright (C) the iPlug 2 developers.

 See LICENSE.txt for  more info.

 ==============================================================================
*/

#pragma once

/**
 * @file
 * @copydoc TestTextOrientationControl
 */

#include "IControl.h"

/** Control to test drawing text with orientation
 *   @ingroup TestControls */
class TestTextOrientationControl : public IKnobControlBase
{
  static const int size = 14;
    
public:
    TestTextOrientationControl(IRECT bounds)
  : IKnobControlBase(bounds), mCount(-1)
  {
    SetTooltip("TestTextOrientationControl");
    mDblAsSingleClick = true;
    Next();
    mValue = 0.5;
  }

  void Draw(IGraphics& g) override
  {
    IRECT drawRECT = mRECT;
    const char* str = "Some Text To Rotate";
    mText.mOrientation = mValue * 360.0 - 180.0;
    
    g.MeasureText(mText, str, drawRECT);
    g.FillRect(COLOR_WHITE, mRECT);
    g.FillRect(COLOR_MID_GRAY, drawRECT);
    g.DrawText(mText, str, mRECT);
  }

  void OnMouseDown(float x, float y, const IMouseMod& mod) override
  {
    mDrag = false;
  }
    
  void OnMouseUp(float x, float y, const IMouseMod& mod) override
  {
    if (!mDrag)
    {
      Next();
      SetDirty(false);
    }
  }
    
  void OnMouseDrag(float x, float y, float dX, float dY, const IMouseMod& mod) override
  {
    mDrag = true;
    IKnobControlBase::OnMouseDrag(x, y, dX, dY, mod);
  }

  void Next()
  {
    if (++mCount > 8)
      mCount = 0;
      
    IColor c = DEFAULT_TEXT_FGCOLOR;
    const char* font = "Roboto-Regular";
    if (mCount == 0)
      mText = IText(size, c, font, IText::kAlignNear, IText::kVAlignTop);
    else if (mCount == 1)
      mText = IText(size, c, font, IText::kAlignCenter, IText::kVAlignTop);
    else if (mCount == 2)
      mText = IText(size, c, font, IText::kAlignFar, IText::kVAlignTop);
    else if (mCount == 3)
      mText = IText(size, c, font, IText::kAlignNear, IText::kVAlignMiddle);
    else if (mCount == 4)
      mText = IText(size, c, font, IText::kAlignCenter, IText::kVAlignMiddle);
    else if (mCount == 5)
      mText = IText(size, c, font, IText::kAlignFar, IText::kVAlignMiddle);
    else if (mCount == 6)
      mText = IText(size, c, font, IText::kAlignNear, IText::kVAlignBottom);
    else if (mCount == 7)
      mText = IText(size, c, font, IText::kAlignCenter, IText::kVAlignBottom);
    else
      mText = IText(size, c, font, IText::kAlignFar, IText::kVAlignBottom);
  }

private:
  bool mDrag = false;
  int mCount;
};