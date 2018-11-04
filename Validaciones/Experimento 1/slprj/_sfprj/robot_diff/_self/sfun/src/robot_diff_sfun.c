/* Include files */

#include "robot_diff_sfun.h"
#include "c1_robot_diff.h"
#include "c2_robot_diff.h"
#include "c3_robot_diff.h"
#include "c4_robot_diff.h"
#include "c5_robot_diff.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _robot_diffMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void robot_diff_initializer(void)
{
}

void robot_diff_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_robot_diff_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_robot_diff_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_robot_diff_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_robot_diff_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_robot_diff_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_robot_diff_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_robot_diff_process_testpoint_info_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char machineName[128];
  if (nrhs < 3 || !mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;

  /* Possible call to get testpoint info. */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_testpoint_info"))
    return 0;
  mxGetString(prhs[1], machineName, sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (!strcmp(machineName, "robot_diff")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_robot_diff_get_testpoint_info(void);
        plhs[0] = sf_c1_robot_diff_get_testpoint_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_robot_diff_get_testpoint_info(void);
        plhs[0] = sf_c2_robot_diff_get_testpoint_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_robot_diff_get_testpoint_info(void);
        plhs[0] = sf_c3_robot_diff_get_testpoint_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_robot_diff_get_testpoint_info(void);
        plhs[0] = sf_c4_robot_diff_get_testpoint_info();
        break;
      }

     case 5:
      {
        extern mxArray *sf_c5_robot_diff_get_testpoint_info(void);
        plhs[0] = sf_c5_robot_diff_get_testpoint_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }

    return 1;
  }

  return 0;

#else

  return 0;

#endif

}

unsigned int sf_robot_diff_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(789114442U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4270091864U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3727722867U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1053995724U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3841797737U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3902678383U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4156873681U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(572614491U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_robot_diff_get_check_sum(mxArray *plhs[]);
          sf_c1_robot_diff_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_robot_diff_get_check_sum(mxArray *plhs[]);
          sf_c2_robot_diff_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_robot_diff_get_check_sum(mxArray *plhs[]);
          sf_c3_robot_diff_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_robot_diff_get_check_sum(mxArray *plhs[]);
          sf_c4_robot_diff_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_robot_diff_get_check_sum(mxArray *plhs[]);
          sf_c5_robot_diff_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(784597580U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(508478511U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1608615269U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1082679159U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3682006369U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2273481331U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3571290561U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3191584659U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_robot_diff_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "tBMzxDUxqGjPCDnNi9jroH") == 0) {
          extern mxArray *sf_c1_robot_diff_get_autoinheritance_info(void);
          plhs[0] = sf_c1_robot_diff_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "BczmfQ4ObeNZQv9ccBZmUD") == 0) {
          extern mxArray *sf_c2_robot_diff_get_autoinheritance_info(void);
          plhs[0] = sf_c2_robot_diff_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "IdAvotD264VM0gEYv6N5zC") == 0) {
          extern mxArray *sf_c3_robot_diff_get_autoinheritance_info(void);
          plhs[0] = sf_c3_robot_diff_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "qBQoOhwWf4NOtDz02aUgIF") == 0) {
          extern mxArray *sf_c4_robot_diff_get_autoinheritance_info(void);
          plhs[0] = sf_c4_robot_diff_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "7SpAC7gcZLItYMekvUZ5AF") == 0) {
          extern mxArray *sf_c5_robot_diff_get_autoinheritance_info(void);
          plhs[0] = sf_c5_robot_diff_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_robot_diff_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_robot_diff_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_robot_diff_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_robot_diff_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_robot_diff_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_robot_diff_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_robot_diff_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_robot_diff_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_robot_diff_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_robot_diff_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_robot_diff_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void robot_diff_debug_initialize(void)
{
  _robot_diffMachineNumber_ = sf_debug_initialize_machine("robot_diff","sfun",0,
    5,0,0,0);
  sf_debug_set_machine_event_thresholds(_robot_diffMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_robot_diffMachineNumber_,0);
}

void robot_diff_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_robot_diff_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("robot_diff",
      "robot_diff");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_robot_diff_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
