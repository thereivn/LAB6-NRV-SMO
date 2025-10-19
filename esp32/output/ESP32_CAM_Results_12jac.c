/* Jacobians 8 */
#include "/output/ESP32_CAM_Results_model.h"
#include "/output/ESP32_CAM_Results_12jac.h"
#include "simulation/jacobian_util.h"
#include "util/omc_file.h"
/* constant equations */
/* dynamic equations */

/*
equation index: 12
type: SIMPLE_ASSIGN
T_case.$pDERLSJac0.dummyVarLSJac0 = T_heatsink.SeedLSJac0 * R_chip_case / (R_chip_case + R_case_heatsink)
*/
void _output_ESP32_CAM_Results_eqFunction_12(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,12};
  jacobian->tmpVars[0] /* T_case.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_TMP_VAR */ = DIVISION((jacobian->seedVars[0] /* T_heatsink.SeedLSJac0 SEED_VAR */) * ((data->simulationInfo->realParameter[8] /* R_chip_case PARAM */)),(data->simulationInfo->realParameter[8] /* R_chip_case PARAM */) + (data->simulationInfo->realParameter[7] /* R_case_heatsink PARAM */),"R_chip_case + R_case_heatsink");
  TRACE_POP
}

/*
equation index: 13
type: SIMPLE_ASSIGN
$res_LSJac0_1.$pDERLSJac0.dummyVarLSJac0 = T_heatsink.SeedLSJac0 * R_case_heatsink + (T_heatsink.SeedLSJac0 - T_case.$pDERLSJac0.dummyVarLSJac0) * R_heatsink_air
*/
void _output_ESP32_CAM_Results_eqFunction_13(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,13};
  jacobian->resultVars[0] /* $res_LSJac0_1.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_VAR */ = (jacobian->seedVars[0] /* T_heatsink.SeedLSJac0 SEED_VAR */) * ((data->simulationInfo->realParameter[7] /* R_case_heatsink PARAM */)) + (jacobian->seedVars[0] /* T_heatsink.SeedLSJac0 SEED_VAR */ - jacobian->tmpVars[0] /* T_case.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[9] /* R_heatsink_air PARAM */));
  TRACE_POP
}

OMC_DISABLE_OPT
int _output_ESP32_CAM_Results_functionJacLSJac0_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = _output_ESP32_CAM_Results_INDEX_JAC_LSJac0;
  
  TRACE_POP
  return 0;
}

int _output_ESP32_CAM_Results_functionJacLSJac0_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = _output_ESP32_CAM_Results_INDEX_JAC_LSJac0;
  _output_ESP32_CAM_Results_eqFunction_12(data, threadData, jacobian, parentJacobian);
  _output_ESP32_CAM_Results_eqFunction_13(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 19
type: SIMPLE_ASSIGN
T_case.$pDERLSJac1.dummyVarLSJac1 = T_heatsink.SeedLSJac1 * R_chip_case / (R_chip_case + R_case_heatsink)
*/
void _output_ESP32_CAM_Results_eqFunction_19(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,19};
  jacobian->tmpVars[0] /* T_case.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_TMP_VAR */ = DIVISION((jacobian->seedVars[0] /* T_heatsink.SeedLSJac1 SEED_VAR */) * ((data->simulationInfo->realParameter[8] /* R_chip_case PARAM */)),(data->simulationInfo->realParameter[8] /* R_chip_case PARAM */) + (data->simulationInfo->realParameter[7] /* R_case_heatsink PARAM */),"R_chip_case + R_case_heatsink");
  TRACE_POP
}

/*
equation index: 20
type: SIMPLE_ASSIGN
$res_LSJac1_1.$pDERLSJac1.dummyVarLSJac1 = T_heatsink.SeedLSJac1 * R_case_heatsink + (T_heatsink.SeedLSJac1 - T_case.$pDERLSJac1.dummyVarLSJac1) * R_heatsink_air
*/
void _output_ESP32_CAM_Results_eqFunction_20(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,20};
  jacobian->resultVars[0] /* $res_LSJac1_1.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_VAR */ = (jacobian->seedVars[0] /* T_heatsink.SeedLSJac1 SEED_VAR */) * ((data->simulationInfo->realParameter[7] /* R_case_heatsink PARAM */)) + (jacobian->seedVars[0] /* T_heatsink.SeedLSJac1 SEED_VAR */ - jacobian->tmpVars[0] /* T_case.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_TMP_VAR */) * ((data->simulationInfo->realParameter[9] /* R_heatsink_air PARAM */));
  TRACE_POP
}

OMC_DISABLE_OPT
int _output_ESP32_CAM_Results_functionJacLSJac1_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = _output_ESP32_CAM_Results_INDEX_JAC_LSJac1;
  
  TRACE_POP
  return 0;
}

int _output_ESP32_CAM_Results_functionJacLSJac1_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = _output_ESP32_CAM_Results_INDEX_JAC_LSJac1;
  _output_ESP32_CAM_Results_eqFunction_19(data, threadData, jacobian, parentJacobian);
  _output_ESP32_CAM_Results_eqFunction_20(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
int _output_ESP32_CAM_Results_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int _output_ESP32_CAM_Results_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int _output_ESP32_CAM_Results_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int _output_ESP32_CAM_Results_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int _output_ESP32_CAM_Results_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

OMC_DISABLE_OPT
int _output_ESP32_CAM_Results_functionJacA_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = _output_ESP32_CAM_Results_INDEX_JAC_A;
  
  TRACE_POP
  return 0;
}

int _output_ESP32_CAM_Results_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = _output_ESP32_CAM_Results_INDEX_JAC_A;
  TRACE_POP
  return 0;
}

OMC_DISABLE_OPT
int _output_ESP32_CAM_Results_initialAnalyticJacobianLSJac0(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "/output/ESP32_CAM_Results_JacLSJac0.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 2, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int _output_ESP32_CAM_Results_initialAnalyticJacobianLSJac1(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "/output/ESP32_CAM_Results_JacLSJac1.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 2, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
int _output_ESP32_CAM_Results_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int _output_ESP32_CAM_Results_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int _output_ESP32_CAM_Results_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int _output_ESP32_CAM_Results_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int _output_ESP32_CAM_Results_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
OMC_DISABLE_OPT
int _output_ESP32_CAM_Results_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "/output/ESP32_CAM_Results_JacA.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 0, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_ONLY_SPARSITY;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %zu", 1+1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}



