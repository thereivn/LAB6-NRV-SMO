/* External objects file */
#include "/output/ESP32_CAM_Results_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

void _output_ESP32_CAM_Results_callExternalObjectDestructors(DATA *data, threadData_t *threadData)
{
  if(data->simulationInfo->extObjs)
  {
    free(data->simulationInfo->extObjs);
    data->simulationInfo->extObjs = 0;
  }
}
#if defined(__cplusplus)
}
#endif

