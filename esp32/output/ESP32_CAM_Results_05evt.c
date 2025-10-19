/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "/output/ESP32_CAM_Results_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void _output_ESP32_CAM_Results_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *_output_ESP32_CAM_Results_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"time < t_video",
  "time < t_video + t_processing",
  "time < t_video + t_processing + t_sleep",
  "mod(time, t_video + t_processing + t_sleep, 0)",
  "mod(time - t_video, t_video + t_processing + t_sleep, 3)",
  "mod(time - t_video - t_processing, t_video + t_processing + t_sleep, 6)"};
  static const int occurEqs0[] = {1,22};
  static const int occurEqs1[] = {1,22};
  static const int occurEqs2[] = {1,22};
  static const int occurEqs3[] = {1,29};
  static const int occurEqs4[] = {1,29};
  static const int occurEqs5[] = {1,29};
  static const int *occurEqs[] = {occurEqs0,occurEqs1,occurEqs2,occurEqs3,occurEqs4,occurEqs5};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */

int _output_ESP32_CAM_Results_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  
  TRACE_POP
  return 0;
}

int _output_ESP32_CAM_Results_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  tmp1 = 1.0;
  tmp2 = fabs((data->simulationInfo->realParameter[15] /* t_video PARAM */));
  tmp0 = LessZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[15] /* t_video PARAM */), tmp1, tmp2, data->simulationInfo->storedRelations[0]);
  gout[0] = (tmp0) ? 1 : -1;

  tmp4 = 1.0;
  tmp5 = fabs((data->simulationInfo->realParameter[15] /* t_video PARAM */)) + fabs((data->simulationInfo->realParameter[13] /* t_processing PARAM */));
  tmp3 = LessZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */), tmp4, tmp5, data->simulationInfo->storedRelations[1]);
  gout[1] = (tmp3) ? 1 : -1;

  tmp7 = 1.0;
  tmp8 = fabs((data->simulationInfo->realParameter[15] /* t_video PARAM */)) + fabs((data->simulationInfo->realParameter[13] /* t_processing PARAM */)) + fabs((data->simulationInfo->realParameter[14] /* t_sleep PARAM */));
  tmp6 = LessZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */) + (data->simulationInfo->realParameter[14] /* t_sleep PARAM */), tmp7, tmp8, data->simulationInfo->storedRelations[2]);
  gout[2] = (tmp6) ? 1 : -1;

  tmp9 = floor((data->localData[0]->timeValue) / ((data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */) + (data->simulationInfo->realParameter[14] /* t_sleep PARAM */)));
  tmp10 = floor((data->simulationInfo->mathEventsValuePre[((modelica_integer) 0)]) / (data->simulationInfo->mathEventsValuePre[((modelica_integer) 0)+1]));
  gout[3] = tmp9 != tmp10 ? 1 : -1;

  tmp11 = floor((data->localData[0]->timeValue - (data->simulationInfo->realParameter[15] /* t_video PARAM */)) / ((data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */) + (data->simulationInfo->realParameter[14] /* t_sleep PARAM */)));
  tmp12 = floor((data->simulationInfo->mathEventsValuePre[((modelica_integer) 3)]) / (data->simulationInfo->mathEventsValuePre[((modelica_integer) 3)+1]));
  gout[4] = tmp11 != tmp12 ? 1 : -1;

  tmp13 = floor((data->localData[0]->timeValue - (data->simulationInfo->realParameter[15] /* t_video PARAM */) - (data->simulationInfo->realParameter[13] /* t_processing PARAM */)) / ((data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */) + (data->simulationInfo->realParameter[14] /* t_sleep PARAM */)));
  tmp14 = floor((data->simulationInfo->mathEventsValuePre[((modelica_integer) 6)]) / (data->simulationInfo->mathEventsValuePre[((modelica_integer) 6)+1]));
  gout[5] = tmp13 != tmp14 ? 1 : -1;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *_output_ESP32_CAM_Results_relationDescription(int i)
{
  const char *res[] = {"time < t_video",
  "time < t_video + t_processing",
  "time < t_video + t_processing + t_sleep"};
  return res[i];
}

int _output_ESP32_CAM_Results_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_boolean tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_boolean tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  
  if(evalforZeroCross) {
    tmp16 = 1.0;
    tmp17 = fabs((data->simulationInfo->realParameter[15] /* t_video PARAM */));
    tmp15 = LessZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[15] /* t_video PARAM */), tmp16, tmp17, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp15;

    tmp19 = 1.0;
    tmp20 = fabs((data->simulationInfo->realParameter[15] /* t_video PARAM */)) + fabs((data->simulationInfo->realParameter[13] /* t_processing PARAM */));
    tmp18 = LessZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */), tmp19, tmp20, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[1] = tmp18;

    tmp22 = 1.0;
    tmp23 = fabs((data->simulationInfo->realParameter[15] /* t_video PARAM */)) + fabs((data->simulationInfo->realParameter[13] /* t_processing PARAM */)) + fabs((data->simulationInfo->realParameter[14] /* t_sleep PARAM */));
    tmp21 = LessZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */) + (data->simulationInfo->realParameter[14] /* t_sleep PARAM */), tmp22, tmp23, data->simulationInfo->storedRelations[2]);
    data->simulationInfo->relations[2] = tmp21;
  } else {
    data->simulationInfo->relations[0] = (data->localData[0]->timeValue < (data->simulationInfo->realParameter[15] /* t_video PARAM */));

    data->simulationInfo->relations[1] = (data->localData[0]->timeValue < (data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */));

    data->simulationInfo->relations[2] = (data->localData[0]->timeValue < (data->simulationInfo->realParameter[15] /* t_video PARAM */) + (data->simulationInfo->realParameter[13] /* t_processing PARAM */) + (data->simulationInfo->realParameter[14] /* t_sleep PARAM */));
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

