/* Algebraic */
#include "/output/ESP32_CAM_Results_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void _output_ESP32_CAM_Results_eqFunction_16(DATA* data, threadData_t *threadData);
extern void _output_ESP32_CAM_Results_eqFunction_23(DATA* data, threadData_t *threadData);
extern void _output_ESP32_CAM_Results_eqFunction_24(DATA* data, threadData_t *threadData);
extern void _output_ESP32_CAM_Results_eqFunction_25(DATA* data, threadData_t *threadData);
extern void _output_ESP32_CAM_Results_eqFunction_26(DATA* data, threadData_t *threadData);
extern void _output_ESP32_CAM_Results_eqFunction_29(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  {
    _output_ESP32_CAM_Results_eqFunction_16(data, threadData);
    threadData->lastEquationSolved = 16;
  }
  {
    _output_ESP32_CAM_Results_eqFunction_23(data, threadData);
    threadData->lastEquationSolved = 23;
  }
  {
    _output_ESP32_CAM_Results_eqFunction_24(data, threadData);
    threadData->lastEquationSolved = 24;
  }
  {
    _output_ESP32_CAM_Results_eqFunction_25(data, threadData);
    threadData->lastEquationSolved = 25;
  }
  {
    _output_ESP32_CAM_Results_eqFunction_26(data, threadData);
    threadData->lastEquationSolved = 26;
  }
  {
    _output_ESP32_CAM_Results_eqFunction_29(data, threadData);
    threadData->lastEquationSolved = 29;
  }
}
/* for continuous time variables */
int _output_ESP32_CAM_Results_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  _output_ESP32_CAM_Results_function_savePreSynchronous(data, threadData);
  
  functionAlg_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ALGEBRAICS);
#endif

  TRACE_POP
  return 0;
}

#ifdef __cplusplus
}
#endif
