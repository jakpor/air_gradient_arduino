#ifndef _OPEN_METRICS_H_
#define _OPEN_METRICS_H_

#include "src/AgConfigure.h"
#include "src/AgValue.h"
#include "src/AgWiFiConnector.h"
#include "src/AirGradient.h"
#include "src/AgApiClient.h"

class OpenMetrics {
private:
  AirGradient *ag;
  Measurements &measure;
  Configuration &config;
  WifiConnector &wifiConnector;
  AgApiClient &apiClient;

public:
  OpenMetrics(Measurements &measure, Configuration &conig,
              WifiConnector &wifiConnector, AgApiClient& apiClient);
  ~OpenMetrics();
  void setAirGradient(AirGradient *ag);
  const char *getApiContentType(void);
  const char* getApi(void);
  String getPayload(void);
};

#endif /** _OPEN_METRICS_H_ */
