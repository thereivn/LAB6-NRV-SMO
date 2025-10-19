/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "/output/ESP32_CAM_Results_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation _output_ESP32_CAM_Results_performSimulation
#define prefixedName_updateContinuousSystem _output_ESP32_CAM_Results_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation _output_ESP32_CAM_Results_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int _output_ESP32_CAM_Results_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int _output_ESP32_CAM_Results_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int _output_ESP32_CAM_Results_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int _output_ESP32_CAM_Results_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int _output_ESP32_CAM_Results_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int _output_ESP32_CAM_Results_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int _output_ESP32_CAM_Results_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int _output_ESP32_CAM_Results_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int _output_ESP32_CAM_Results_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int _output_ESP32_CAM_Results_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 16
type: SIMPLE_ASSIGN
T_celsius = -273.15 + T_chip
*/
void _output_ESP32_CAM_Results_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  (data->localData[0]->realVars[4] /* T_celsius variable */) = -273.15 + (data->localData[0]->realVars[0] /* T_chip STATE(1) */);
  TRACE_POP
}
/*
equation index: 21
type: LINEAR

<var>T_heatsink</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void _output_ESP32_CAM_Results_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  /* Linear equation system */
  int retValue;
  double aux_x[1] = { (data->localData[1]->realVars[5] /* T_heatsink variable */) };
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 21 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  
  retValue = solve_linear_system(data, threadData, 1, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,21};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 21 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[5] /* T_heatsink variable */) = aux_x[0];

  TRACE_POP
}
/*
equation index: 22
type: SIMPLE_ASSIGN
mode = if time < t_video then 1 else if time < t_video + t_processing then 2 else if time < t_video + t_processing + t_sleep then 3 else 1
*/
void _output_ESP32_CAM_Results_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_boolean tmp9;
  modelica_integer tmp10;
  modelica_boolean tmp11;
  modelica_integer tmp12;
  tmp1 = 1.0;
  tmp2 = fabs((data->simulationInfo->realParameter[15] /* t_video PARAM */));
  relationhysteresis(data, &tmp0, data->localData[0]->timeValue, (data->simulationInfo->realParameter[15] /* t_video PARAM */), tmp1, tmp2, 0, Less, LessZC);
  tmp11 = (modelica_boolean)tmp0;
  if(tmp11)
  {
    tmp12 = ((modelica_integer) 1);
  }
  else
  {
    tmp4 = 1.0;
    tmp5 = fabs((data->simulationInfo->realParameter[15] /* t_video PARAM */)) + fabs((data->simulationInfo->realParameter[13] /* t_processing PARAM */));
    relationhysteresis(data, &tmp3, data->localData[0]->timeValue, (data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */), tmp4, tmp5, 1, Less, LessZC);
    tmp9 = (modelica_boolean)tmp3;
    if(tmp9)
    {
      tmp10 = ((modelica_integer) 2);
    }
    else
    {
      tmp7 = 1.0;
      tmp8 = fabs((data->simulationInfo->realParameter[15] /* t_video PARAM */)) + fabs((data->simulationInfo->realParameter[13] /* t_processing PARAM */)) + fabs((data->simulationInfo->realParameter[14] /* t_sleep PARAM */));
      relationhysteresis(data, &tmp6, data->localData[0]->timeValue, (data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */) + (data->simulationInfo->realParameter[14] /* t_sleep PARAM */), tmp7, tmp8, 2, Less, LessZC);
      tmp10 = (tmp6?((modelica_integer) 3):((modelica_integer) 1));
    }
    tmp12 = tmp10;
  }
  (data->localData[0]->integerVars[0] /* mode DISCRETE */) = tmp12;
  TRACE_POP
}
/*
equation index: 23
type: SIMPLE_ASSIGN
i_load = if mode == 1 then I_video else if mode == 2 then I_processing else I_sleep
*/
void _output_ESP32_CAM_Results_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  (data->localData[0]->realVars[7] /* i_load variable */) = (((data->localData[0]->integerVars[0] /* mode DISCRETE */) == ((modelica_integer) 1))?(data->simulationInfo->realParameter[3] /* I_video PARAM */):(((data->localData[0]->integerVars[0] /* mode DISCRETE */) == ((modelica_integer) 2))?(data->simulationInfo->realParameter[1] /* I_processing PARAM */):(data->simulationInfo->realParameter[2] /* I_sleep PARAM */)));
  TRACE_POP
}
/*
equation index: 24
type: SIMPLE_ASSIGN
battery_charge = Q_initial + 0.0002777777777777778 * (-i_load) * time
*/
void _output_ESP32_CAM_Results_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->localData[0]->realVars[6] /* battery_charge variable */) = (data->simulationInfo->realParameter[6] /* Q_initial PARAM */) + (0.0002777777777777778) * (((-(data->localData[0]->realVars[7] /* i_load variable */))) * (data->localData[0]->timeValue));
  TRACE_POP
}
/*
equation index: 25
type: SIMPLE_ASSIGN
SoC = max(0.0, battery_charge / Q_initial * 100.0)
*/
void _output_ESP32_CAM_Results_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  (data->localData[0]->realVars[2] /* SoC variable */) = fmax(0.0,(DIVISION_SIM((data->localData[0]->realVars[6] /* battery_charge variable */),(data->simulationInfo->realParameter[6] /* Q_initial PARAM */),"Q_initial",equationIndexes)) * (100.0));
  TRACE_POP
}
/*
equation index: 26
type: SIMPLE_ASSIGN
power_consumption = i_load * V_battery
*/
void _output_ESP32_CAM_Results_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->localData[0]->realVars[9] /* power_consumption variable */) = ((data->localData[0]->realVars[7] /* i_load variable */)) * ((data->simulationInfo->realParameter[12] /* V_battery PARAM */));
  TRACE_POP
}
/*
equation index: 27
type: SIMPLE_ASSIGN
p_dissipation = if mode == 1 then P_active else if mode == 2 then P_active else P_sleep
*/
void _output_ESP32_CAM_Results_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  (data->localData[0]->realVars[8] /* p_dissipation variable */) = (((data->localData[0]->integerVars[0] /* mode DISCRETE */) == ((modelica_integer) 1))?(data->simulationInfo->realParameter[4] /* P_active PARAM */):(((data->localData[0]->integerVars[0] /* mode DISCRETE */) == ((modelica_integer) 2))?(data->simulationInfo->realParameter[4] /* P_active PARAM */):(data->simulationInfo->realParameter[5] /* P_sleep PARAM */)));
  TRACE_POP
}
/*
equation index: 28
type: SIMPLE_ASSIGN
$DER.T_chip = (p_dissipation + (T_case - T_chip) / R_chip_case) / C_chip
*/
void _output_ESP32_CAM_Results_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  (data->localData[0]->realVars[1] /* der(T_chip) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[8] /* p_dissipation variable */) + DIVISION_SIM((data->localData[0]->realVars[3] /* T_case variable */) - (data->localData[0]->realVars[0] /* T_chip STATE(1) */),(data->simulationInfo->realParameter[8] /* R_chip_case PARAM */),"R_chip_case",equationIndexes),(data->simulationInfo->realParameter[0] /* C_chip PARAM */),"C_chip",equationIndexes);
  TRACE_POP
}
/*
equation index: 29
type: SIMPLE_ASSIGN
t_next_switch = if mode == 1 then t_video - mod(time, t_video + t_processing + t_sleep, 0) else if mode == 2 then t_processing - mod(time - t_video, t_video + t_processing + t_sleep, 3) else t_sleep - mod(time - t_video - t_processing, t_video + t_processing + t_sleep, 6)
*/
void _output_ESP32_CAM_Results_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  (data->localData[0]->realVars[10] /* t_next_switch variable */) = (((data->localData[0]->integerVars[0] /* mode DISCRETE */) == ((modelica_integer) 1))?(data->simulationInfo->realParameter[15] /* t_video PARAM */) - _event_mod_real(data->localData[0]->timeValue, (data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */) + (data->simulationInfo->realParameter[14] /* t_sleep PARAM */), ((modelica_integer) 0), data, threadData):(((data->localData[0]->integerVars[0] /* mode DISCRETE */) == ((modelica_integer) 2))?(data->simulationInfo->realParameter[13] /* t_processing PARAM */) - _event_mod_real(data->localData[0]->timeValue - (data->simulationInfo->realParameter[15] /* t_video PARAM */), (data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */) + (data->simulationInfo->realParameter[14] /* t_sleep PARAM */), ((modelica_integer) 3), data, threadData):(data->simulationInfo->realParameter[14] /* t_sleep PARAM */) - _event_mod_real(data->localData[0]->timeValue - (data->simulationInfo->realParameter[15] /* t_video PARAM */) - (data->simulationInfo->realParameter[13] /* t_processing PARAM */), (data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */) + (data->simulationInfo->realParameter[14] /* t_sleep PARAM */), ((modelica_integer) 6), data, threadData)));
  TRACE_POP
}

OMC_DISABLE_OPT
int _output_ESP32_CAM_Results_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  _output_ESP32_CAM_Results_functionLocalKnownVars(data, threadData);
  _output_ESP32_CAM_Results_eqFunction_16(data, threadData);

  _output_ESP32_CAM_Results_eqFunction_21(data, threadData);

  _output_ESP32_CAM_Results_eqFunction_22(data, threadData);

  _output_ESP32_CAM_Results_eqFunction_23(data, threadData);

  _output_ESP32_CAM_Results_eqFunction_24(data, threadData);

  _output_ESP32_CAM_Results_eqFunction_25(data, threadData);

  _output_ESP32_CAM_Results_eqFunction_26(data, threadData);

  _output_ESP32_CAM_Results_eqFunction_27(data, threadData);

  _output_ESP32_CAM_Results_eqFunction_28(data, threadData);

  _output_ESP32_CAM_Results_eqFunction_29(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int _output_ESP32_CAM_Results_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void _output_ESP32_CAM_Results_eqFunction_21(DATA* data, threadData_t *threadData);
extern void _output_ESP32_CAM_Results_eqFunction_22(DATA* data, threadData_t *threadData);
extern void _output_ESP32_CAM_Results_eqFunction_27(DATA* data, threadData_t *threadData);
extern void _output_ESP32_CAM_Results_eqFunction_28(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  {
    _output_ESP32_CAM_Results_eqFunction_21(data, threadData);
    threadData->lastEquationSolved = 21;
  }
  {
    _output_ESP32_CAM_Results_eqFunction_22(data, threadData);
    threadData->lastEquationSolved = 22;
  }
  {
    _output_ESP32_CAM_Results_eqFunction_27(data, threadData);
    threadData->lastEquationSolved = 27;
  }
  {
    _output_ESP32_CAM_Results_eqFunction_28(data, threadData);
    threadData->lastEquationSolved = 28;
  }
}

int _output_ESP32_CAM_Results_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  _output_ESP32_CAM_Results_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "/output/ESP32_CAM_Results_12jac.h"
#include "/output/ESP32_CAM_Results_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks _output_ESP32_CAM_Results_callback = {
   (int (*)(DATA *, threadData_t *, void *)) _output_ESP32_CAM_Results_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) _output_ESP32_CAM_Results_performQSSSimulation,    /* performQSSSimulation */
   _output_ESP32_CAM_Results_updateContinuousSystem,    /* updateContinuousSystem */
   _output_ESP32_CAM_Results_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   _output_ESP32_CAM_Results_initialLinearSystem,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   _output_ESP32_CAM_Results_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   _output_ESP32_CAM_Results_initializeDAEmodeData,
   _output_ESP32_CAM_Results_functionODE,
   _output_ESP32_CAM_Results_functionAlgebraics,
   _output_ESP32_CAM_Results_functionDAE,
   _output_ESP32_CAM_Results_functionLocalKnownVars,
   _output_ESP32_CAM_Results_input_function,
   _output_ESP32_CAM_Results_input_function_init,
   _output_ESP32_CAM_Results_input_function_updateStartValues,
   _output_ESP32_CAM_Results_data_function,
   _output_ESP32_CAM_Results_output_function,
   _output_ESP32_CAM_Results_setc_function,
   _output_ESP32_CAM_Results_setb_function,
   _output_ESP32_CAM_Results_function_storeDelayed,
   _output_ESP32_CAM_Results_function_storeSpatialDistribution,
   _output_ESP32_CAM_Results_function_initSpatialDistribution,
   _output_ESP32_CAM_Results_updateBoundVariableAttributes,
   _output_ESP32_CAM_Results_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   _output_ESP32_CAM_Results_functionRemovedInitialEquations,
   _output_ESP32_CAM_Results_updateBoundParameters,
   _output_ESP32_CAM_Results_checkForAsserts,
   _output_ESP32_CAM_Results_function_ZeroCrossingsEquations,
   _output_ESP32_CAM_Results_function_ZeroCrossings,
   _output_ESP32_CAM_Results_function_updateRelations,
   _output_ESP32_CAM_Results_zeroCrossingDescription,
   _output_ESP32_CAM_Results_relationDescription,
   _output_ESP32_CAM_Results_function_initSample,
   _output_ESP32_CAM_Results_INDEX_JAC_A,
   _output_ESP32_CAM_Results_INDEX_JAC_B,
   _output_ESP32_CAM_Results_INDEX_JAC_C,
   _output_ESP32_CAM_Results_INDEX_JAC_D,
   _output_ESP32_CAM_Results_INDEX_JAC_F,
   _output_ESP32_CAM_Results_INDEX_JAC_H,
   _output_ESP32_CAM_Results_initialAnalyticJacobianA,
   _output_ESP32_CAM_Results_initialAnalyticJacobianB,
   _output_ESP32_CAM_Results_initialAnalyticJacobianC,
   _output_ESP32_CAM_Results_initialAnalyticJacobianD,
   _output_ESP32_CAM_Results_initialAnalyticJacobianF,
   _output_ESP32_CAM_Results_initialAnalyticJacobianH,
   _output_ESP32_CAM_Results_functionJacA_column,
   _output_ESP32_CAM_Results_functionJacB_column,
   _output_ESP32_CAM_Results_functionJacC_column,
   _output_ESP32_CAM_Results_functionJacD_column,
   _output_ESP32_CAM_Results_functionJacF_column,
   _output_ESP32_CAM_Results_functionJacH_column,
   _output_ESP32_CAM_Results_linear_model_frame,
   _output_ESP32_CAM_Results_linear_model_datarecovery_frame,
   _output_ESP32_CAM_Results_mayer,
   _output_ESP32_CAM_Results_lagrange,
   _output_ESP32_CAM_Results_pickUpBoundsForInputsInOptimization,
   _output_ESP32_CAM_Results_setInputData,
   _output_ESP32_CAM_Results_getTimeGrid,
   _output_ESP32_CAM_Results_symbolicInlineSystem,
   _output_ESP32_CAM_Results_function_initSynchronous,
   _output_ESP32_CAM_Results_function_updateSynchronous,
   _output_ESP32_CAM_Results_function_equationsSynchronous,
   _output_ESP32_CAM_Results_inputNames,
   _output_ESP32_CAM_Results_dataReconciliationInputNames,
   _output_ESP32_CAM_Results_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "ESP32_CAM_Thermal_Energy"
#define _OMC_LIT_RESOURCE_0_dir_data "/app"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,24,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,4,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void _output_ESP32_CAM_Results_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &_output_ESP32_CAM_Results_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "ESP32_CAM_Thermal_Energy";
  data->modelData->modelFilePrefix = "/output/ESP32_CAM_Results";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/app";
  data->modelData->modelGUID = "{c50cce22-5df3-46fe-8cd2-03a41cee0e3e}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "/output/ESP32_CAM_Results_init.c"
    ;
  static const char contents_info[] =
    #include "/output/ESP32_CAM_Results_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "/output/ESP32_CAM_Results_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "/output/ESP32_CAM_Results_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "/output/ESP32_CAM_Results_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 1;
  data->modelData->nVariablesReal = 11;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 1;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 16;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 0;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 6;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 3;
  data->modelData->nMathEvents = 9;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 31;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 2;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 8;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  data->modelData->nDelayExpressions = 0;
  data->modelData->nBaseClocks = 0;
  data->modelData->nSpatialDistributions = 0;
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
  data->modelData->nSetcVars = 0;
  data->modelData->ndataReconVars = 0;
  data->modelData->nSetbVars = 0;
  data->modelData->nRelatedBoundaryConditions = 0;
  data->modelData->linearizationDumpLanguage = OMC_LINEARIZE_DUMP_LANGUAGE_MODELICA;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}


#if defined(__MINGW32__) || defined(_MSC_VER)

#if !defined(_UNICODE)
#define _UNICODE
#endif
#if !defined(UNICODE)
#define UNICODE
#endif

#include <windows.h>
char** omc_fixWindowsArgv(int argc, wchar_t **wargv)
{
  char** newargv;
  /* Support for non-ASCII characters
  * Read the unicode command line arguments and translate it to char*
  */
  newargv = (char**)malloc(argc*sizeof(char*));
  for (int i = 0; i < argc; i++) {
    newargv[i] = omc_wchar_to_multibyte_str(wargv[i]);
  }
  return newargv;
}

#define OMC_MAIN wmain
#define OMC_CHAR wchar_t
#define OMC_EXPORT __declspec(dllexport) extern

#else
#define omc_fixWindowsArgv(N, A) (A)
#define OMC_MAIN main
#define OMC_CHAR char
#define OMC_EXPORT extern
#endif

#if defined(threadData)
#undef threadData
#endif
/* call the simulation runtime main from our main! */
#if defined(OMC_DLL_MAIN_DEFINE)
OMC_EXPORT int omcDllMain(int argc, OMC_CHAR **argv)
#else
int OMC_MAIN(int argc, OMC_CHAR** argv)
#endif
{
  char** newargv = omc_fixWindowsArgv(argc, argv);
  /*
    Set the error functions to be used for simulation.
    The default value for them is 'functions' version. Change it here to 'simulation' versions
  */
  omc_assert = omc_assert_simulation;
  omc_assert_withEquationIndexes = omc_assert_simulation_withEquationIndexes;

  omc_assert_warning_withEquationIndexes = omc_assert_warning_simulation_withEquationIndexes;
  omc_assert_warning = omc_assert_warning_simulation;
  omc_terminate = omc_terminate_simulation;
  omc_throw = omc_throw_simulation;

  int res;
  DATA data;
  MODEL_DATA modelData;
  SIMULATION_INFO simInfo;
  data.modelData = &modelData;
  data.simulationInfo = &simInfo;
  measure_time_flag = 0;
  compiledInDAEMode = 0;
  compiledWithSymSolver = 0;
  MMC_INIT(0);
  omc_alloc_interface.init();
  {
    MMC_TRY_TOP()
  
    MMC_TRY_STACK()
  
    _output_ESP32_CAM_Results_setupDataStruc(&data, threadData);
    res = _main_initRuntimeAndSimulation(argc, newargv, &data, threadData);
    if(res == 0) {
      res = _main_SimulationRuntime(argc, newargv, &data, threadData);
    }
    
    MMC_ELSE()
    rml_execution_failed();
    fprintf(stderr, "Stack overflow detected and was not caught.\nSend us a bug report at https://trac.openmodelica.org/OpenModelica/newticket\n    Include the following trace:\n");
    printStacktraceMessages();
    fflush(NULL);
    return 1;
    MMC_CATCH_STACK()
    
    MMC_CATCH_TOP(return rml_execution_failed());
  }

  fflush(NULL);
#if !defined(OMC_DLL_MAIN_DEFINE) /* do not exit, return in DLL mode */
  EXIT(res);
#endif
  return res;
}

#ifdef __cplusplus
}
#endif


