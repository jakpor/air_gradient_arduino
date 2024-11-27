#ifndef _LOCAL_SERVER_H_
#define _LOCAL_SERVER_H_

#include "src/AgConfigure.h"
#include "src/AgValue.h"
#include "src/AirGradient.h"
#include "src/AgWiFiConnector.h"
#include "OpenMetrics.h"
#include <Arduino.h>
#include <ESP8266WebServer.h>

class LocalServer : public PrintLog {
private:
  AirGradient *ag;
  OpenMetrics &openMetrics;
  Measurements &measure;
  Configuration &config;
  WifiConnector &wifiConnector;
  ESP8266WebServer server;
  AgFirmwareMode fwMode;

public:
  LocalServer(Stream &log, OpenMetrics &openMetrics, Measurements &measure,
              Configuration &config, WifiConnector& wifiConnector);
  ~LocalServer();

  bool begin(void);
  void setAirGraident(AirGradient *ag);
  String getHostname(void);
  void setFwMode(AgFirmwareMode fwMode);
  void _handle(void);
  void _GET_config(void);
  void _PUT_config(void);
  void _GET_metrics(void);
  void _GET_measure(void);
};

#endif /** _LOCAL_SERVER_H_ */
