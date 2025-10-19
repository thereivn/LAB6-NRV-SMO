/* Linearization */
#include "/output/ESP32_CAM_Results_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *_output_ESP32_CAM_Results_linear_model_frame()
{
  return "model linearized_model \"_output_ESP32_CAM_Results\"\n"
  "  parameter Integer n = 1 \"number of states\";\n"
  "  parameter Integer m = 0 \"number of inputs\";\n"
  "  parameter Integer p = 0 \"number of outputs\";\n"
  "  parameter Real x0[n] = %s;\n"
  "  parameter Real u0[m] = %s;\n"
  "\n"
  "  parameter Real A[n, n] =\n\t[%s];\n\n"
  "  parameter Real B[n, m] = zeros(n, m);%s\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] = zeros(p, m);%s\n\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[m];\n"
  "  output Real y[p];\n"
  "\n"
  "  Real 'x_T_chip' = x[1];\n"
  "equation\n"
  "  der(x) = A * x + B * u;\n"
  "  y = C * x + D * u;\n"
  "end linearized_model;\n";
}
const char *_output_ESP32_CAM_Results_linear_model_datarecovery_frame()
{
  return "model linearized_model \"_output_ESP32_CAM_Results\"\n"
  "  parameter Integer n = 1 \"number of states\";\n"
  "  parameter Integer m = 0 \"number of inputs\";\n"
  "  parameter Integer p = 0 \"number of outputs\";\n"
  "  parameter Integer nz = 9 \"data recovery variables\";\n"
  "  parameter Real x0[1] = %s;\n"
  "  parameter Real u0[0] = %s;\n"
  "  parameter Real z0[9] = %s;\n"
  "\n"
  "  parameter Real A[n, n] =\n\t[%s];\n\n"
  "  parameter Real B[n, m] = zeros(n, m);%s\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] = zeros(p, m);%s\n\n"
  "  parameter Real Cz[nz, n] =\n\t[%s];\n\n"
  "  parameter Real Dz[nz, m] = zeros(nz, m);%s\n\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[m];\n"
  "  output Real y[p];\n"
  "  output Real z[nz];\n"
  "\n"
  "  Real 'x_T_chip' = x[1];\n"
  "  Real 'z_SoC' = z[1];\n"
  "  Real 'z_T_case' = z[2];\n"
  "  Real 'z_T_celsius' = z[3];\n"
  "  Real 'z_T_heatsink' = z[4];\n"
  "  Real 'z_battery_charge' = z[5];\n"
  "  Real 'z_i_load' = z[6];\n"
  "  Real 'z_p_dissipation' = z[7];\n"
  "  Real 'z_power_consumption' = z[8];\n"
  "  Real 'z_t_next_switch' = z[9];\n"
  "equation\n"
  "  der(x) = A * x + B * u;\n"
  "  y = C * x + D * u;\n"
  "  z = Cz * x + Dz * u;\n"
  "end linearized_model;\n";
}
#if defined(__cplusplus)
}
#endif

