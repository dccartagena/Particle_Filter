#ifndef __c5_robot_diff_h__
#define __c5_robot_diff_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  ChartInfoStruct chartInfo;
} SFc5_robot_diffInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_robot_diff_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_robot_diff_get_check_sum(mxArray *plhs[]);
extern void c5_robot_diff_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
