#pragma once

#include "IPlugPlatform.h"

static const int DEFAULT_FPS = 25;

// If not dirty for this many timer ticks, we call OnGUIIDle.
// Only looked at if USE_IDLE_CALLS is defined.
static const int IDLE_TICKS = 20;

#define DEFAULT_ANIMATION_DURATION 100

#ifndef CONTROL_BOUNDS_COLOR
#define CONTROL_BOUNDS_COLOR COLOR_GREEN
#endif

#define PARAM_EDIT_W 40
#define PARAM_EDIT_H 16

#define MAX_URL_LEN 256
#define MAX_NET_ERR_MSG_LEN 1024

#define MAX_IMG_SCALE 3

static const int DEFAULT_TEXT_ENTRY_LEN = 7;
static const double DEFAULT_GEARING = 4.0;

//what is this stuff
#define MAX_INET_ERR_CODE 32
#define TOOLWIN_BORDER_W 6
#define TOOLWIN_BORDER_H 23
#define MAX_CLASSNAME_LEN 128
//

static const float GRAYED_ALPHA = 0.25f;

#ifdef OS_WIN
  const char* const DEFAULT_FONT = "Verdana";
  const int DEFAULT_TEXT_SIZE = 12;
#elif defined OS_MAC
  const char* const DEFAULT_FONT = "Monaco";
  const int DEFAULT_TEXT_SIZE = 10;
  #ifndef DEFAULT_PATH
  static const char* DEFAULT_PATH = "~/Desktop";
  #endif
#elif defined OS_IOS
  const char* const DEFAULT_FONT = "Monaco";
  const int DEFAULT_TEXT_SIZE = 10;
#elif defined OS_LINUX
  const char* const DEFAULT_FONT = "DejaVu Sans";
  const int DEFAULT_TEXT_SIZE = 10;
#elif defined OS_WEB
  const char* const DEFAULT_FONT = "DejaVu Sans";
  const int DEFAULT_TEXT_SIZE = 10;
#endif

const int FONT_LEN = 32;

/** @enum EType Blend type
 * \todo This could use some documentation
 */
enum EBlendType
{
  kBlendNone,     // Copy over whatever is already there, but look at src alpha.
  kBlendClobber,  // Copy completely over whatever is already there.
  kBlendAdd,
  kBlendColorDodge,
  // etc
};

enum EFileAction
{
  kFileOpen,
  kFileSave  
};

enum EDirection
{
  kVertical = 0,
  kHorizontal = 1
};

enum EVColor
{
  kBG = 0,    // background color: All vector controls should fill their BG with this color, which is transparent by default
  kFG,        // foreground
  kOFF = kFG, // off states will use the same color as kFG to fill
  kPR,        // pressed
  kON = kPR,  // on states will use the same color as kPR to fill
  kFR,        // frame: the color of the stroke/borders
  kHL,        // highlight: mouse over or focus
  kSH,        // shadow
  kX1,        // extra1
  kX2,        // extra2
  kX3,        // extra3
  kNumDefaultVColors
};

enum EFillRule
{
  kFillWinding,
  kFillEvenOdd
};

enum ELineCap
{
  kCapButt,
  kCapRound,
  kCapSquare
};

enum ELineJoin
{
  kJoinMiter,
  kJoinRound,
  kJoinBevel
};

enum EPatternType
{
  kSolidPattern,
  kLinearPattern,
  kRadialPattern
};

enum EPatternExtend
{
  kExtendNone,
  kExtendPad,
  kExtendReflect,
  kExtendRepeat
};