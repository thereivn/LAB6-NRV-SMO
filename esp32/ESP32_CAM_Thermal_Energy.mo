model ESP32_CAM_Thermal_Energy
  "Complete thermal and energy model of ESP32-CAM"

  // Parameters
  parameter Real T_initial = 25 "Initial temperature (°C)";
  parameter Real T_ambient = 25 "Ambient temperature (°C)";
  parameter Real C_chip = 5 "Chip heat capacity (J/K)";
  parameter Real R_chip_case = 15 "Chip to case thermal resistance (K/W)";
  parameter Real R_case_heatsink = 8 "Case to heatsink thermal resistance (K/W)";
  parameter Real R_heatsink_air = 25 "Heatsink to air thermal resistance (K/W)";
  parameter Real P_active = 0.8 "Power dissipation in active mode (W)";
  parameter Real P_sleep = 0.1 "Power dissipation in sleep mode (W)";

  // Energy Model Parameters
  parameter Real I_video = 0.280 "Current in video mode (A)";
  parameter Real I_processing = 0.200 "Current in processing mode (A)";
  parameter Real I_sleep = 0.010 "Current in sleep mode (A)";
  parameter Real V_battery = 3.7 "Battery voltage (V)";
  parameter Real Q_initial = 9.0 "Initial battery charge (Ah)";
  parameter Real t_video = 30 "Video recording time (s)";
  parameter Real t_processing = 10 "Processing time (s)";
  parameter Real t_sleep = 60 "Sleep time (s)";

  // Variables
  Real T_chip(start = T_initial + 273.15) "Chip temperature (K)";
  Real T_case "Case temperature (K)";
  Real T_heatsink "Heatsink temperature (K)";
  Integer mode(start = 1) "1=Video, 2=Processing, 3=Sleep";
  Real SoC "State of Charge (%)";
  Real T_celsius "Chip temperature in °C";
  Real power_consumption "Instantaneous power consumption (W)";
  Real battery_charge "Battery charge remaining (Ah)";
  Real i_load "Load current (A)";
  Real p_dissipation "Power dissipation (W)";
  Real t_next_switch(start = 0) "Time of next mode switch";

  // Constants
  constant Integer VIDEO = 1;
  constant Integer PROCESSING = 2;
  constant Integer SLEEP = 3;

equation 
  // Mode switching logic - simplified without when
  mode = if time < t_video then VIDEO else 
         if time < t_video + t_processing then PROCESSING else 
         if time < t_video + t_processing + t_sleep then SLEEP else 
         VIDEO; // This simple model will repeat the cycle

  // Current based on mode
  i_load = if mode == VIDEO then I_video else 
           if mode == PROCESSING then I_processing else I_sleep;
  
  // Power dissipation based on mode
  p_dissipation = if mode == VIDEO then P_active else 
                  if mode == PROCESSING then P_active else P_sleep;

  // Thermal equations - RC network
  C_chip * der(T_chip) = p_dissipation - (T_chip - T_case) / R_chip_case;
  (T_chip - T_case) / R_chip_case = (T_case - T_heatsink) / R_case_heatsink;
  (T_case - T_heatsink) / R_case_heatsink = (T_heatsink - (T_ambient + 273.15)) / R_heatsink_air;

  // Battery charge calculation
  battery_charge = Q_initial - i_load * time / 3600;
  SoC = max(0, battery_charge / Q_initial * 100);

  // Temperature in Celsius
  T_celsius = T_chip - 273.15;

  // Power consumption
  power_consumption = i_load * V_battery;

  // Time of next switch (for monitoring only)
  t_next_switch = if mode == VIDEO then t_video - mod(time, t_video + t_processing + t_sleep) else
                  if mode == PROCESSING then t_processing - mod(time - t_video, t_video + t_processing + t_sleep) else
                  t_sleep - mod(time - t_video - t_processing, t_video + t_processing + t_sleep);

end ESP32_CAM_Thermal_Energy;