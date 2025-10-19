#if defined(__cplusplus)
  extern "C" {
#endif
  int _output_ESP32_CAM_Results_mayer(DATA* data, modelica_real** res, short*);
  int _output_ESP32_CAM_Results_lagrange(DATA* data, modelica_real** res, short *, short *);
  int _output_ESP32_CAM_Results_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int _output_ESP32_CAM_Results_setInputData(DATA *data, const modelica_boolean file);
  int _output_ESP32_CAM_Results_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif