/* Include files */

#include "blascompat32.h"
#include "robot_diff_sfun.h"
#include "c5_robot_diff.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "robot_diff_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[7] = { "camino", "nargin", "nargout",
  "K_last", "X_target", "Y_target", "K_new" };

/* Function Declarations */
static void initialize_c5_robot_diff(SFc5_robot_diffInstanceStruct
  *chartInstance);
static void initialize_params_c5_robot_diff(SFc5_robot_diffInstanceStruct
  *chartInstance);
static void enable_c5_robot_diff(SFc5_robot_diffInstanceStruct *chartInstance);
static void disable_c5_robot_diff(SFc5_robot_diffInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_robot_diff(SFc5_robot_diffInstanceStruct
  *chartInstance);
static void ext_mode_exec_c5_robot_diff(SFc5_robot_diffInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_robot_diff(SFc5_robot_diffInstanceStruct *
  chartInstance);
static void set_sim_state_c5_robot_diff(SFc5_robot_diffInstanceStruct
  *chartInstance, const mxArray *c5_st);
static void finalize_c5_robot_diff(SFc5_robot_diffInstanceStruct *chartInstance);
static void sf_c5_robot_diff(SFc5_robot_diffInstanceStruct *chartInstance);
static void initSimStructsc5_robot_diff(SFc5_robot_diffInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_robot_diffInstanceStruct *chartInstance,
  const mxArray *c5_K_new, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_robot_diffInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_c_emlrt_marshallIn(SFc5_robot_diffInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_d_emlrt_marshallIn(SFc5_robot_diffInstanceStruct
  *chartInstance, const mxArray *c5_is_active_c5_robot_diff, const char_T
  *c5_identifier);
static uint8_T c5_e_emlrt_marshallIn(SFc5_robot_diffInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_robot_diffInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_robot_diff(SFc5_robot_diffInstanceStruct
  *chartInstance)
{
  int32_T *c5_sfEvent;
  uint8_T *c5_is_active_c5_robot_diff;
  c5_is_active_c5_robot_diff = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c5_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c5_is_active_c5_robot_diff = 0U;
}

static void initialize_params_c5_robot_diff(SFc5_robot_diffInstanceStruct
  *chartInstance)
{
}

static void enable_c5_robot_diff(SFc5_robot_diffInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_robot_diff(SFc5_robot_diffInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_robot_diff(SFc5_robot_diffInstanceStruct
  *chartInstance)
{
}

static void ext_mode_exec_c5_robot_diff(SFc5_robot_diffInstanceStruct
  *chartInstance)
{
  c5_update_debugger_state_c5_robot_diff(chartInstance);
}

static const mxArray *get_sim_state_c5_robot_diff(SFc5_robot_diffInstanceStruct *
  chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_b_hoistedGlobal;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_c_hoistedGlobal;
  real_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  uint8_T c5_d_hoistedGlobal;
  uint8_T c5_d_u;
  const mxArray *c5_e_y = NULL;
  real_T *c5_K_new;
  real_T *c5_X_target;
  real_T *c5_Y_target;
  uint8_T *c5_is_active_c5_robot_diff;
  c5_K_new = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_Y_target = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_X_target = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_is_active_c5_robot_diff = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(4), FALSE);
  c5_hoistedGlobal = *c5_K_new;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *c5_X_target;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_c_hoistedGlobal = *c5_Y_target;
  c5_c_u = c5_c_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 2, c5_d_y);
  c5_d_hoistedGlobal = *c5_is_active_c5_robot_diff;
  c5_d_u = c5_d_hoistedGlobal;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 3, c5_e_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_robot_diff(SFc5_robot_diffInstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  boolean_T *c5_doneDoubleBufferReInit;
  real_T *c5_K_new;
  real_T *c5_X_target;
  real_T *c5_Y_target;
  uint8_T *c5_is_active_c5_robot_diff;
  c5_K_new = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_Y_target = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_X_target = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_is_active_c5_robot_diff = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c5_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  *c5_K_new = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    0)), "K_new");
  *c5_X_target = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 1)), "X_target");
  *c5_Y_target = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 2)), "Y_target");
  *c5_is_active_c5_robot_diff = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 3)), "is_active_c5_robot_diff");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_robot_diff(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_robot_diff(SFc5_robot_diffInstanceStruct *chartInstance)
{
}

static void sf_c5_robot_diff(SFc5_robot_diffInstanceStruct *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_K_last;
  uint32_T c5_debug_family_var_map[7];
  real_T c5_camino[2];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 3.0;
  real_T c5_X_target;
  real_T c5_Y_target;
  real_T c5_K_new;
  int32_T c5_i0;
  int32_T *c5_sfEvent;
  real_T *c5_b_K_last;
  real_T *c5_b_X_target;
  real_T *c5_b_Y_target;
  real_T *c5_b_K_new;
  c5_b_K_new = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_b_Y_target = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_b_X_target = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_K_last = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, *c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_b_K_last, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_b_X_target, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_b_Y_target, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_b_K_new, 3U);
  *c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, *c5_sfEvent);
  c5_hoistedGlobal = *c5_b_K_last;
  c5_K_last = c5_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c5_camino, 0U, c5_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 2U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_K_last, 3U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_X_target, 4U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Y_target, 5U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_K_new, 6U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c5_sfEvent, 4);
  for (c5_i0 = 0; c5_i0 < 2; c5_i0++) {
    c5_camino[c5_i0] = 3832.64 + -832.63999999999987 * (real_T)c5_i0;
  }

  _SFD_EML_CALL(0U, *c5_sfEvent, 7);
  c5_K_new = c5_K_last + 1.0;
  _SFD_EML_CALL(0U, *c5_sfEvent, 9);
  if (CV_EML_IF(0, 1, 0, c5_K_new >= 1.0)) {
    _SFD_EML_CALL(0U, *c5_sfEvent, 10);
    c5_K_new = 1.0;
  }

  _SFD_EML_CALL(0U, *c5_sfEvent, 13);
  c5_X_target = c5_camino[_SFD_EML_ARRAY_BOUNDS_CHECK("camino", (int32_T)
    _SFD_INTEGER_CHECK("K_new", c5_K_new), 1, 1, 1, 0) - 1];
  _SFD_EML_CALL(0U, *c5_sfEvent, 14);
  c5_Y_target = c5_camino[_SFD_EML_ARRAY_BOUNDS_CHECK("camino", (int32_T)
    _SFD_INTEGER_CHECK("K_new", c5_K_new), 1, 1, 1, 0)];
  _SFD_EML_CALL(0U, *c5_sfEvent, -14);
  sf_debug_symbol_scope_pop();
  *c5_b_X_target = c5_X_target;
  *c5_b_Y_target = c5_Y_target;
  *c5_b_K_new = c5_K_new;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *c5_sfEvent);
  sf_debug_check_for_state_inconsistency(_robot_diffMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc5_robot_diff(SFc5_robot_diffInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc5_robot_diffInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_robot_diffInstanceStruct *chartInstance,
  const mxArray *c5_K_new, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_K_new), &c5_thisId);
  sf_mex_destroy(&c5_K_new);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_robot_diffInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_K_new;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc5_robot_diffInstanceStruct *)chartInstanceVoid;
  c5_K_new = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_K_new), &c5_thisId);
  sf_mex_destroy(&c5_K_new);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i1;
  real_T c5_b_inData[2];
  int32_T c5_i2;
  real_T c5_u[2];
  const mxArray *c5_y = NULL;
  SFc5_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc5_robot_diffInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    c5_b_inData[c5_i1] = (*(real_T (*)[2])c5_inData)[c5_i1];
  }

  for (c5_i2 = 0; c5_i2 < 2; c5_i2++) {
    c5_u[c5_i2] = c5_b_inData[c5_i2];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 1, 2), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

const mxArray *sf_c5_robot_diff_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c5_nameCaptureInfo;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc5_robot_diffInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_c_emlrt_marshallIn(SFc5_robot_diffInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i3;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i3, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i3;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc5_robot_diffInstanceStruct *)chartInstanceVoid;
  c5_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_sfEvent), &c5_thisId);
  sf_mex_destroy(&c5_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_d_emlrt_marshallIn(SFc5_robot_diffInstanceStruct
  *chartInstance, const mxArray *c5_is_active_c5_robot_diff, const char_T
  *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_is_active_c5_robot_diff), &c5_thisId);
  sf_mex_destroy(&c5_is_active_c5_robot_diff);
  return c5_y;
}

static uint8_T c5_e_emlrt_marshallIn(SFc5_robot_diffInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_robot_diffInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c5_robot_diff_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(161165461U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(665915100U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1346109592U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3853934973U);
}

mxArray *sf_c5_robot_diff_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("7SpAC7gcZLItYMekvUZ5AF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c5_robot_diff(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[6],T\"K_new\",},{M[1],M[5],T\"X_target\",},{M[1],M[7],T\"Y_target\",},{M[8],M[0],T\"is_active_c5_robot_diff\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_robot_diff_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_robot_diffInstanceStruct *chartInstance;
    chartInstance = (SFc5_robot_diffInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_robot_diffMachineNumber_,
           5,
           1,
           1,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_robot_diffMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_robot_diffMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_robot_diffMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"K_last");
          _SFD_SET_DATA_PROPS(1,2,0,1,"X_target");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Y_target");
          _SFD_SET_DATA_PROPS(3,2,0,1,"K_new");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,48877);
        _SFD_CV_INIT_EML_IF(0,1,0,48758,48785,-1,48818);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);

        {
          real_T *c5_K_last;
          real_T *c5_X_target;
          real_T *c5_Y_target;
          real_T *c5_K_new;
          c5_K_new = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c5_Y_target = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c5_X_target = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c5_K_last = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_K_last);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_X_target);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_Y_target);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_K_new);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_robot_diffMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_robot_diff_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S, infoStruct,
      5, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c5_robot_diff(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc5_robot_diffInstanceStruct*) chartInstanceVar
    )->S);
  chart_debug_initialization(((SFc5_robot_diffInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c5_robot_diff((SFc5_robot_diffInstanceStruct*)
    chartInstanceVar);
  initialize_c5_robot_diff((SFc5_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_robot_diff(void *chartInstanceVar)
{
  enable_c5_robot_diff((SFc5_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_robot_diff(void *chartInstanceVar)
{
  disable_c5_robot_diff((SFc5_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_robot_diff(void *chartInstanceVar)
{
  sf_c5_robot_diff((SFc5_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c5_robot_diff(void *chartInstanceVar)
{
  ext_mode_exec_c5_robot_diff((SFc5_robot_diffInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_robot_diff(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_robot_diff
    ((SFc5_robot_diffInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_robot_diff();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c5_robot_diff(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_robot_diff();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_robot_diff((SFc5_robot_diffInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_robot_diff(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_robot_diff(S);
}

static void sf_opaque_set_sim_state_c5_robot_diff(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c5_robot_diff(S, st);
}

static void sf_opaque_terminate_c5_robot_diff(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_robot_diffInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_robot_diff((SFc5_robot_diffInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_robot_diff_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_robot_diff((SFc5_robot_diffInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_robot_diff(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_robot_diff((SFc5_robot_diffInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c5_robot_diff_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c5_robot_diff\",T\"is_active_c5_robot_diff\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x4'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"int32\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 4, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 3851270630U, 3363230343U, 1651207761U,
    946165807U };

  return checksum;
}

static void mdlSetWorkWidths_c5_robot_diff(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_robot_diff_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,5,1);
      sf_mark_chart_reusable_outputs(S,infoStruct,5,3);
    }

    sf_set_rtw_dwork_info(S,infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1966977689U));
  ssSetChecksum1(S,(981143504U));
  ssSetChecksum2(S,(3570466394U));
  ssSetChecksum3(S,(1337289193U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_robot_diff(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_robot_diff(SimStruct *S)
{
  SFc5_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc5_robot_diffInstanceStruct *)malloc(sizeof
    (SFc5_robot_diffInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_robot_diffInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_robot_diff;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_robot_diff;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_robot_diff;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_robot_diff;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_robot_diff;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_robot_diff;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_robot_diff;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_robot_diff;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_robot_diff;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_robot_diff;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_robot_diff;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c5_robot_diff;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c5_robot_diff_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_robot_diff(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_robot_diff(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_robot_diff(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_robot_diff_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
