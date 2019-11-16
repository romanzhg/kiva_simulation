#ifndef KIVA_SIMULATION_SRC_LOGGER_H_
#define KIVA_SIMULATION_SRC_LOGGER_H_

#include <iostream>
#include <string>

namespace ks {

inline void log(const std::string &s) {
  std::cout << s << std::endl;
}

inline void LogFatal(const std::string &s) {
  log(s);
  exit(0);
}

}
#endif