#ifndef IOTC_COMMON_PLATFORM_H
#define IOTC_COMMON_PLATFORM_H

#ifdef ARDUINO_SAMD_FEATHER_M0
#include <Adafruit_WINC1500.h>
#include <Adafruit_WINC1500SSLClient.h>
#define ARDUINO_WIFI_SSL_CLIENT Adafruit_WINC1500SSLClient

#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#define ARDUINO_WIFI_SSL_CLIENT WiFiClientSecure

#elif defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000)
#include <WiFi101.h>
#include <WifiSSLClient.h>
#define ARDUINO_WIFI_SSL_CLIENT WiFiSSLClient

#elif defined(ARDUINO_SAMD_MKR1010)
defined(ARDUINO_SAMD_MKR1000)
#include <WiFi101.h>
#include <WifiSSLClient.h>
#define ARDUINO_WIFI_SSL_CLIENT WiFiSSLClient

#elif defined(ARDUINO)
#include <WiFi101.h>
#include <WifiSSLClient.h>
#endif

#ifdef ARDUINO_WIFI_SSL_CLIENT
#define USE_LIGHT_CLIENT 1
#endif // ARDUINO_WIFI_SSL_CLIENT

#if defined(__MBED__)
#include <mbed.h>
#include "MQTTmbed.h"
#include "MQTTClient.h"
#include <mbedtls/md.h>
#include <mbedtls/sha256.h>
#include <mbedtls/base64.h>
#include "../mbed_os/mbed_tls_client.h"
#define WAITMS wait_ms
#define SERIAL_PRINT printf

#elif defined (ARDUINO)
#include <arduino.h>
#include <avr/pgmspace.h>
#include "WiFiUdp.h"
#include "base64.h"
#include "sha256.h"
#include "../arduino/PubSubClient.h"
#define WAITMS delay
#define SERIAL_PRINT Serial.print
#else
#error "NOT SUPPORTED"
#endif // defined(__MBED__)

#ifndef PROGMEM
#define PROGMEM
#endif

#endif // IOTC_COMMON_PLATFORM_H