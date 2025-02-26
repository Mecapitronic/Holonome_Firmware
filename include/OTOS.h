#ifndef OTOS_H
#define OTOS_H

#include <Arduino.h>
#include "pins.h"
#include "ESP32_Helper.h"
using namespace Printer;

#include <SparkFun_Qwiic_OTOS_Arduino_Library.h>
#include <Wire.h>


class OpticalTrackingOdometrySensor
{
public:
    void Initialisation();
    void Update();
    void HandleCommand(Command cmd);
    void PrintCommandHelp();
    
    void SetPose(float x, float y, float h);
    void Teleplot();

    PoseF position;
    PoseF velocity;
    PoseF acceleration;

private:
    sfe_otos_pose2d_t myPosition;
    sfe_otos_pose2d_t myVelocity;
    sfe_otos_pose2d_t myAcceleration;
    bool isConnected = false;
    QwiicOTOS myOtos;
};

#endif
