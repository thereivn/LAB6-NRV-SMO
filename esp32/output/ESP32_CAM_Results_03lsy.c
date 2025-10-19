/* Linear Systems */
#include "/output/ESP32_CAM_Results_model.h"
#include "/output/ESP32_CAM_Results_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* linear systems */

/*
equation index: 17
type: SIMPLE_ASSIGN
T_case = ((-T_chip) - R_chip_case * T_heatsink / R_case_heatsink) / (-1.0 - R_chip_case / R_case_heatsink)
*/
void _output_ESP32_CAM_Results_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[3] /* T_case variable */) = DIVISION_SIM((-(data->localData[0]->realVars[0] /* T_chip STATE(1) */)) - (((data->simulationInfo->realParameter[8] /* R_chip_case PARAM */)) * (DIVISION_SIM((data->localData[0]->realVars[5] /* T_heatsink variable */),(data->simulationInfo->realParameter[7] /* R_case_heatsink PARAM */),"R_case_heatsink",equationIndexes))),-1.0 - (DIVISION_SIM((data->simulationInfo->realParameter[8] /* R_chip_case PARAM */),(data->simulationInfo->realParameter[7] /* R_case_heatsink PARAM */),"R_case_heatsink",equationIndexes)),"-1.0 - R_chip_case / R_case_heatsink",equationIndexes);
  TRACE_POP
}

void residualFunc21(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,21};
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (data->localData[0]->realVars[5] /* T_heatsink variable */) = xloc[0];
  /* local constraints */
  _output_ESP32_CAM_Results_eqFunction_17(data, threadData);
  res[0] = (-273.15 + (data->localData[0]->realVars[5] /* T_heatsink variable */) - (data->simulationInfo->realParameter[10] /* T_ambient PARAM */)) * ((data->simulationInfo->realParameter[7] /* R_case_heatsink PARAM */)) + ((data->localData[0]->realVars[5] /* T_heatsink variable */) - (data->localData[0]->realVars[3] /* T_case variable */)) * ((data->simulationInfo->realParameter[9] /* R_heatsink_air PARAM */));
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData21(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  const int indices[1] = {5/* T_heatsink */};
  for (int i = 0; i < 1; ++i) {
    linearSystemData->nominal[i] = data->modelData->realVarsData[indices[i]].attribute.nominal;
    linearSystemData->min[i]     = data->modelData->realVarsData[indices[i]].attribute.min;
    linearSystemData->max[i]     = data->modelData->realVarsData[indices[i]].attribute.max;
  }
}


/*
equation index: 10
type: SIMPLE_ASSIGN
T_case = ((-T_chip) - R_chip_case * T_heatsink / R_case_heatsink) / (-1.0 - R_chip_case / R_case_heatsink)
*/
void _output_ESP32_CAM_Results_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[3] /* T_case variable */) = DIVISION_SIM((-(data->localData[0]->realVars[0] /* T_chip STATE(1) */)) - (((data->simulationInfo->realParameter[8] /* R_chip_case PARAM */)) * (DIVISION_SIM((data->localData[0]->realVars[5] /* T_heatsink variable */),(data->simulationInfo->realParameter[7] /* R_case_heatsink PARAM */),"R_case_heatsink",equationIndexes))),-1.0 - (DIVISION_SIM((data->simulationInfo->realParameter[8] /* R_chip_case PARAM */),(data->simulationInfo->realParameter[7] /* R_case_heatsink PARAM */),"R_case_heatsink",equationIndexes)),"-1.0 - R_chip_case / R_case_heatsink",equationIndexes);
  TRACE_POP
}

void residualFunc14(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,14};
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (data->localData[0]->realVars[5] /* T_heatsink variable */) = xloc[0];
  /* local constraints */
  _output_ESP32_CAM_Results_eqFunction_10(data, threadData);
  res[0] = (-273.15 + (data->localData[0]->realVars[5] /* T_heatsink variable */) - (data->simulationInfo->realParameter[10] /* T_ambient PARAM */)) * ((data->simulationInfo->realParameter[7] /* R_case_heatsink PARAM */)) + ((data->localData[0]->realVars[5] /* T_heatsink variable */) - (data->localData[0]->realVars[3] /* T_case variable */)) * ((data->simulationInfo->realParameter[9] /* R_heatsink_air PARAM */));
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData14(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  const int indices[1] = {5/* T_heatsink */};
  for (int i = 0; i < 1; ++i) {
    linearSystemData->nominal[i] = data->modelData->realVarsData[indices[i]].attribute.nominal;
    linearSystemData->min[i]     = data->modelData->realVarsData[indices[i]].attribute.min;
    linearSystemData->max[i]     = data->modelData->realVarsData[indices[i]].attribute.max;
  }
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize linear systems */
void _output_ESP32_CAM_Results_initialLinearSystem(int nLinearSystems, LINEAR_SYSTEM_DATA* linearSystemData)
{
  /* linear systems */
  assertStreamPrint(NULL, nLinearSystems > 1, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[1].equationIndex = 21;
  linearSystemData[1].size = 1;
  linearSystemData[1].nnz = 0;
  linearSystemData[1].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[1].residualFunc = residualFunc21;
  linearSystemData[1].strictTearingFunctionCall = NULL;
  linearSystemData[1].analyticalJacobianColumn = _output_ESP32_CAM_Results_functionJacLSJac1_column;
  linearSystemData[1].initialAnalyticalJacobian = _output_ESP32_CAM_Results_initialAnalyticJacobianLSJac1;
  linearSystemData[1].jacobianIndex = 1 /*jacInx*/;
  linearSystemData[1].setA = NULL;  //setLinearMatrixA21;
  linearSystemData[1].setb = NULL;  //setLinearVectorb21;
  linearSystemData[1].initializeStaticLSData = initializeStaticLSData21;
  
  assertStreamPrint(NULL, nLinearSystems > 0, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[0].equationIndex = 14;
  linearSystemData[0].size = 1;
  linearSystemData[0].nnz = 0;
  linearSystemData[0].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[0].residualFunc = residualFunc14;
  linearSystemData[0].strictTearingFunctionCall = NULL;
  linearSystemData[0].analyticalJacobianColumn = _output_ESP32_CAM_Results_functionJacLSJac0_column;
  linearSystemData[0].initialAnalyticalJacobian = _output_ESP32_CAM_Results_initialAnalyticJacobianLSJac0;
  linearSystemData[0].jacobianIndex = 0 /*jacInx*/;
  linearSystemData[0].setA = NULL;  //setLinearMatrixA14;
  linearSystemData[0].setb = NULL;  //setLinearVectorb14;
  linearSystemData[0].initializeStaticLSData = initializeStaticLSData14;
}

#if defined(__cplusplus)
}
#endif

