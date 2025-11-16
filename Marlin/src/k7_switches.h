#pragma once

#include "inc/MarlinConfigPre.h"

#if BOTH(CUSTOM_K7_SWITCHES, K7_SWITCH_LOGIC)
  void k7_switches_init();
  void k7_switches_task();

  void handle_feed_mode();
  void handle_normal_mode();
  void handle_retract_mode();
  void handle_switch_idle();
#else
  inline void k7_switches_init() {}
  inline void k7_switches_task() {}
#endif