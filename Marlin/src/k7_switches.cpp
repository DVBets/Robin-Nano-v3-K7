/**
 * Easythreed K7 three-position switch handling
 */
#include "inc/MarlinConfig.h"

#if BOTH(CUSTOM_K7_SWITCHES, K7_SWITCH_LOGIC)

void handle_feed_mode() {
  // TODO: implement feed mode behavior
}

void handle_normal_mode() {
  // TODO: implement normal mode behavior
}

void handle_retract_mode() {
  // TODO: implement retract mode behavior
}

void handle_switch_idle() {
  // TODO: implement idle handling when no switch position is detected
}

void k7_switches_init() {
  SET_INPUT_PULLUP(FEED_SWITCH_PIN);
  SET_INPUT_PULLUP(NORMAL_SWITCH_PIN);
  SET_INPUT_PULLUP(RETRACT_SWITCH_PIN);
  SET_INPUT_PULLUP(RESERVE_SWITCH_PIN);
}

void k7_switches_task() {
  if (!READ(FEED_SWITCH_PIN))        handle_feed_mode();
  else if (!READ(NORMAL_SWITCH_PIN)) handle_normal_mode();
  else if (!READ(RETRACT_SWITCH_PIN)) handle_retract_mode();
  else                                handle_switch_idle();
}

#endif