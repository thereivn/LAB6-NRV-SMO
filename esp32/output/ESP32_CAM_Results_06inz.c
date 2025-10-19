/* Initialization */
#include "/output/ESP32_CAM_Results_model.h"
#include "/output/ESP32_CAM_Results_11mix.h"
#include "/output/ESP32_CAM_Results_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void _output_ESP32_CAM_Results_functionInitialEquations_0(DATA *data, threadData_t *threadData);
extern void _output_ESP32_CAM_Results_eqFunction_22(DATA *data, threadData_t *threadData);

extern void _output_ESP32_CAM_Results_eqFunction_23(DATA *data, threadData_t *threadData);

extern void _output_ESP32_CAM_Results_eqFunction_27(DATA *data, threadData_t *threadData);

extern void _output_ESP32_CAM_Results_eqFunction_24(DATA *data, threadData_t *threadData);

extern void _output_ESP32_CAM_Results_eqFunction_25(DATA *data, threadData_t *threadData);

extern void _output_ESP32_CAM_Results_eqFunction_26(DATA *data, threadData_t *threadData);


/*
equation index: 7
type: SIMPLE_ASSIGN
t_next_switch = if mode == 1 then t_video - mod(time, t_video + t_processing + t_sleep) else if mode == 2 then t_processing - mod(time - t_video, t_video + t_processing + t_sleep) else t_sleep - mod(time - t_video - t_processing, t_video + t_processing + t_sleep)
*/
void _output_ESP32_CAM_Results_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_boolean tmp5;
  modelica_real tmp6;
  tmp5 = (modelica_boolean)((data->localData[0]->integerVars[0] /* mode DISCRETE */) == ((modelica_integer) 1));
  if(tmp5)
  {
    tmp0 = (data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */) + (data->simulationInfo->realParameter[14] /* t_sleep PARAM */);
    if (tmp0 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(time, t_video + t_processing + t_sleep)");}
    tmp6 = (data->simulationInfo->realParameter[15] /* t_video PARAM */) - modelica_real_mod(data->localData[0]->timeValue, tmp0);
  }
  else
  {
    tmp3 = (modelica_boolean)((data->localData[0]->integerVars[0] /* mode DISCRETE */) == ((modelica_integer) 2));
    if(tmp3)
    {
      tmp1 = (data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */) + (data->simulationInfo->realParameter[14] /* t_sleep PARAM */);
      if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(time - t_video, t_video + t_processing + t_sleep)");}
      tmp4 = (data->simulationInfo->realParameter[13] /* t_processing PARAM */) - modelica_real_mod(data->localData[0]->timeValue - (data->simulationInfo->realParameter[15] /* t_video PARAM */), tmp1);
    }
    else
    {
      tmp2 = (data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */) + (data->simulationInfo->realParameter[14] /* t_sleep PARAM */);
      if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(time - t_video - t_processing, t_video + t_processing + t_sleep)");}
      tmp4 = (data->simulationInfo->realParameter[14] /* t_sleep PARAM */) - modelica_real_mod(data->localData[0]->timeValue - (data->simulationInfo->realParameter[15] /* t_video PARAM */) - (data->simulationInfo->realParameter[13] /* t_processing PARAM */), tmp2);
    }
    tmp6 = tmp4;
  }
  (data->localData[0]->realVars[10] /* t_next_switch variable */) = tmp6;
  TRACE_POP
}

/*
equation index: 8
type: SIMPLE_ASSIGN
T_chip = $START.T_chip
*/
void _output_ESP32_CAM_Results_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  (data->localData[0]->realVars[0] /* T_chip STATE(1) */) = (data->modelData->realVarsData[0] /* T_chip STATE(1) */).attribute .start;
  TRACE_POP
}
extern void _output_ESP32_CAM_Results_eqFunction_16(DATA *data, threadData_t *threadData);


/*
equation index: 14
type: LINEAR

<var>T_heatsink</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void _output_ESP32_CAM_Results_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  /* Linear equation system */
  int retValue;
  double aux_x[1] = { (data->localData[1]->realVars[5] /* T_heatsink variable */) };
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 14 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  
  retValue = solve_linear_system(data, threadData, 0, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,14};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 14 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[5] /* T_heatsink variable */) = aux_x[0];

  TRACE_POP
}
extern void _output_ESP32_CAM_Results_eqFunction_28(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void _output_ESP32_CAM_Results_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  _output_ESP32_CAM_Results_eqFunction_22(data, threadData);
  _output_ESP32_CAM_Results_eqFunction_23(data, threadData);
  _output_ESP32_CAM_Results_eqFunction_27(data, threadData);
  _output_ESP32_CAM_Results_eqFunction_24(data, threadData);
  _output_ESP32_CAM_Results_eqFunction_25(data, threadData);
  _output_ESP32_CAM_Results_eqFunction_26(data, threadData);
  _output_ESP32_CAM_Results_eqFunction_7(data, threadData);
  _output_ESP32_CAM_Results_eqFunction_8(data, threadData);
  _output_ESP32_CAM_Results_eqFunction_16(data, threadData);
  _output_ESP32_CAM_Results_eqFunction_14(data, threadData);
  _output_ESP32_CAM_Results_eqFunction_28(data, threadData);
  TRACE_POP
}

int _output_ESP32_CAM_Results_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  _output_ESP32_CAM_Results_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No _output_ESP32_CAM_Results_functionInitialEquations_lambda0 function */

int _output_ESP32_CAM_Results_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

