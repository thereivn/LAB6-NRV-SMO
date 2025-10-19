/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "/output/ESP32_CAM_Results_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 30
type: SIMPLE_ASSIGN
$START.T_chip = T_initial + 273.15
*/
static void _output_ESP32_CAM_Results_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  (data->modelData->realVarsData[0] /* T_chip STATE(1) */).attribute .start = (data->simulationInfo->realParameter[11] /* T_initial PARAM */) + 273.15;
    (data->localData[0]->realVars[0] /* T_chip STATE(1) */) = (data->modelData->realVarsData[0] /* T_chip STATE(1) */).attribute .start;
    infoStreamPrint(LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[0].info /* T_chip */.name, (modelica_real) (data->localData[0]->realVars[0] /* T_chip STATE(1) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int _output_ESP32_CAM_Results_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  infoStreamPrint(LOG_INIT, 1, "updating min-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* max ******************************************************** */
  infoStreamPrint(LOG_INIT, 1, "updating max-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* nominal **************************************************** */
  infoStreamPrint(LOG_INIT, 1, "updating nominal-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(LOG_INIT, 1, "updating primary start-values");
  _output_ESP32_CAM_Results_eqFunction_30(data, threadData);
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  TRACE_POP
  return 0;
}

OMC_DISABLE_OPT
int _output_ESP32_CAM_Results_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

