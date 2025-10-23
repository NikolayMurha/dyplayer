#ifdef ARDUINO
#include <Arduino.h>
#include "DYPlayer.h"

// Detect optional serial implementations. Allow project to disable them via macros.
#ifdef __has_include
#if __has_include("SoftwareSerial.h") && !defined(DYPLAYER_DISABLE_SOFTWARE_SERIAL)
#define HAS_SOFTWARE_SERIAL
#endif
#if __has_include("AltSoftSerial.h") && !defined(DYPLAYER_DISABLE_ALTSOFTSERIAL)
#define HAS_ALTSOFTSERIAL
#endif
#endif

#ifdef __has_include
#if __has_include("HardwareSerial.h")
#define HAS_HARDWARE_SERIAL
#endif
#endif

// Include optional serial types
#ifdef HAS_SOFTWARE_SERIAL
#include "SoftwareSerial.h"
#endif
#ifdef HAS_ALTSOFTSERIAL
#include "AltSoftSerial.h"
#endif

namespace DY
{
  class Player : public DYPlayer
  {
  public:
    Stream *port;
    bool isSoftSerial;
    bool isAltSoftSerial;
    Player();
#ifdef HAS_HARDWARE_SERIAL
    Player(HardwareSerial *port);
#endif

#ifdef HAS_SOFTWARE_SERIAL
    Player(SoftwareSerial *port);
#endif
#ifdef HAS_ALTSOFTSERIAL
    Player(AltSoftSerial *port);
#endif
    void begin();
    void serialWrite(uint8_t *buffer, uint8_t len);
    bool serialRead(uint8_t *buffer, uint8_t len);
  };
}
#endif
