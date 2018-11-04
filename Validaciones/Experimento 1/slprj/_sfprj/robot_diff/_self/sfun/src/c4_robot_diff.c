/* Include files */

#include "blascompat32.h"
#include "robot_diff_sfun.h"
#include "c4_robot_diff.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "robot_diff_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[5] = { "pol", "nargin", "nargout",
  "volt", "ro" };

/* Function Declarations */
static void initialize_c4_robot_diff(SFc4_robot_diffInstanceStruct
  *chartInstance);
static void initialize_params_c4_robot_diff(SFc4_robot_diffInstanceStruct
  *chartInstance);
static void enable_c4_robot_diff(SFc4_robot_diffInstanceStruct *chartInstance);
static void disable_c4_robot_diff(SFc4_robot_diffInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_robot_diff(SFc4_robot_diffInstanceStruct
  *chartInstance);
static void ext_mode_exec_c4_robot_diff(SFc4_robot_diffInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_robot_diff(SFc4_robot_diffInstanceStruct *
  chartInstance);
static void set_sim_state_c4_robot_diff(SFc4_robot_diffInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_robot_diff(SFc4_robot_diffInstanceStruct *chartInstance);
static void sf_c4_robot_diff(SFc4_robot_diffInstanceStruct *chartInstance);
static void initSimStructsc4_robot_diff(SFc4_robot_diffInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_robot_diffInstanceStruct *chartInstance,
  const mxArray *c4_ro, const char_T *c4_identifier, real_T c4_y[5]);
static void c4_b_emlrt_marshallIn(SFc4_robot_diffInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[5]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_robot_diffInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_d_emlrt_marshallIn(SFc4_robot_diffInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_e_emlrt_marshallIn(SFc4_robot_diffInstanceStruct
  *chartInstance, const mxArray *c4_is_active_c4_robot_diff, const char_T
  *c4_identifier);
static uint8_T c4_f_emlrt_marshallIn(SFc4_robot_diffInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_robot_diffInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_robot_diff(SFc4_robot_diffInstanceStruct
  *chartInstance)
{
  int32_T *c4_sfEvent;
  uint8_T *c4_is_active_c4_robot_diff;
  c4_is_active_c4_robot_diff = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c4_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c4_is_active_c4_robot_diff = 0U;
}

static void initialize_params_c4_robot_diff(SFc4_robot_diffInstanceStruct
  *chartInstance)
{
}

static void enable_c4_robot_diff(SFc4_robot_diffInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_robot_diff(SFc4_robot_diffInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_robot_diff(SFc4_robot_diffInstanceStruct
  *chartInstance)
{
}

static void ext_mode_exec_c4_robot_diff(SFc4_robot_diffInstanceStruct
  *chartInstance)
{
  c4_update_debugger_state_c4_robot_diff(chartInstance);
}

static const mxArray *get_sim_state_c4_robot_diff(SFc4_robot_diffInstanceStruct *
  chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_u[5];
  const mxArray *c4_b_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  uint8_T *c4_is_active_c4_robot_diff;
  real_T (*c4_ro)[5];
  c4_ro = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_is_active_c4_robot_diff = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2), FALSE);
  for (c4_i0 = 0; c4_i0 < 5; c4_i0++) {
    c4_u[c4_i0] = (*c4_ro)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_hoistedGlobal = *c4_is_active_c4_robot_diff;
  c4_b_u = c4_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_robot_diff(SFc4_robot_diffInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[5];
  int32_T c4_i1;
  boolean_T *c4_doneDoubleBufferReInit;
  uint8_T *c4_is_active_c4_robot_diff;
  real_T (*c4_ro)[5];
  c4_ro = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_is_active_c4_robot_diff = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c4_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "ro",
                      c4_dv0);
  for (c4_i1 = 0; c4_i1 < 5; c4_i1++) {
    (*c4_ro)[c4_i1] = c4_dv0[c4_i1];
  }

  *c4_is_active_c4_robot_diff = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 1)), "is_active_c4_robot_diff");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_robot_diff(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_robot_diff(SFc4_robot_diffInstanceStruct *chartInstance)
{
}

static void sf_c4_robot_diff(SFc4_robot_diffInstanceStruct *chartInstance)
{
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  real_T c4_volt[5];
  uint32_T c4_debug_family_var_map[5];
  real_T c4_pol[5];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real_T c4_ro[5];
  int32_T c4_i5;
  static real_T c4_p[5] = { 135.931074586891, -1131.18106050753,
    3464.28806284511, -4823.87750852904, 2935.52549616993 };

  int32_T c4_i6;
  real_T c4_x[5];
  int32_T c4_i7;
  int32_T c4_k;
  real_T c4_b_k;
  static real_T c4_dv1[5] = { 135.931074586891, -1131.18106050753,
    3464.28806284511, -4823.87750852904, 2935.52549616993 };

  real_T c4_d0;
  int32_T c4_i8;
  int32_T c4_i9;
  boolean_T c4_b_x[5];
  int32_T c4_c_k;
  int32_T c4_i;
  int32_T c4_b_i;
  int32_T c4_a;
  const mxArray *c4_y = NULL;
  int32_T c4_tmp_sizes;
  int32_T c4_loop_ub;
  int32_T c4_i10;
  int32_T c4_tmp_data[5];
  int32_T c4_b_tmp_sizes;
  int32_T c4_j;
  int32_T c4_c_i;
  int32_T c4_d_i;
  int32_T c4_b_tmp_data[5];
  int32_T c4_b_a;
  int32_T c4_b_loop_ub;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T *c4_sfEvent;
  real_T (*c4_b_ro)[5];
  real_T (*c4_b_volt)[5];
  c4_b_ro = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_volt = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
  c4_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, *c4_sfEvent);
  for (c4_i2 = 0; c4_i2 < 5; c4_i2++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_volt)[c4_i2], 0U);
  }

  for (c4_i3 = 0; c4_i3 < 5; c4_i3++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_ro)[c4_i3], 1U);
  }

  *c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, *c4_sfEvent);
  for (c4_i4 = 0; c4_i4 < 5; c4_i4++) {
    c4_volt[c4_i4] = (*c4_b_volt)[c4_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c4_pol, 0U, c4_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c4_volt, 3U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c4_ro, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c4_sfEvent, 3);
  for (c4_i5 = 0; c4_i5 < 5; c4_i5++) {
    c4_pol[c4_i5] = c4_p[c4_i5];
  }

  _SFD_EML_CALL(0U, *c4_sfEvent, 4);
  for (c4_i6 = 0; c4_i6 < 5; c4_i6++) {
    c4_x[c4_i6] = c4_volt[c4_i6];
  }

  for (c4_i7 = 0; c4_i7 < 5; c4_i7++) {
    c4_ro[c4_i7] = 135.931074586891;
  }

  for (c4_k = 0; c4_k < 4; c4_k++) {
    c4_b_k = 2.0 + (real_T)c4_k;
    c4_d0 = c4_dv1[(int32_T)c4_b_k - 1];
    for (c4_i8 = 0; c4_i8 < 5; c4_i8++) {
      c4_ro[c4_i8] = c4_x[c4_i8] * c4_ro[c4_i8] + c4_d0;
    }
  }

  _SFD_EML_CALL(0U, *c4_sfEvent, 6);
  for (c4_i9 = 0; c4_i9 < 5; c4_i9++) {
    c4_b_x[c4_i9] = (c4_ro[c4_i9] > 1500.0);
  }

  c4_c_k = 0;
  for (c4_i = 1; c4_i < 6; c4_i++) {
    c4_b_i = c4_i - 1;
    if (c4_b_x[c4_b_i]) {
      c4_a = c4_c_k + 1;
      c4_c_k = c4_a;
    }
  }

  if (c4_c_k <= 5) {
  } else {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", "Assertion failed.", 15, 0U, 0U, 0U,
      2, 1, strlen("Assertion failed.")), FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, c4_y);
  }

  c4_tmp_sizes = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c4_c_k);
  c4_loop_ub = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c4_c_k) - 1;
  for (c4_i10 = 0; c4_i10 <= c4_loop_ub; c4_i10++) {
    c4_tmp_data[c4_i10] = 0;
  }

  c4_b_tmp_sizes = c4_tmp_sizes;
  c4_j = 1;
  for (c4_c_i = 1; c4_c_i < 6; c4_c_i++) {
    c4_d_i = c4_c_i;
    if (c4_b_x[c4_d_i - 1]) {
      c4_b_tmp_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c4_j, 1, c4_b_tmp_sizes, 1,
        0) - 1] = c4_d_i;
      c4_b_a = c4_j + 1;
      c4_j = c4_b_a;
    }
  }

  c4_b_loop_ub = c4_b_tmp_sizes - 1;
  for (c4_i11 = 0; c4_i11 <= c4_b_loop_ub; c4_i11++) {
    c4_ro[c4_b_tmp_data[c4_i11] - 1] = 1500.0;
  }

  _SFD_EML_CALL(0U, *c4_sfEvent, -6);
  sf_debug_symbol_scope_pop();
  for (c4_i12 = 0; c4_i12 < 5; c4_i12++) {
    (*c4_b_ro)[c4_i12] = c4_ro[c4_i12];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *c4_sfEvent);
  sf_debug_check_for_state_inconsistency(_robot_diffMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc4_robot_diff(SFc4_robot_diffInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i13;
  real_T c4_b_inData[5];
  int32_T c4_i14;
  real_T c4_u[5];
  const mxArray *c4_y = NULL;
  SFc4_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc4_robot_diffInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i13 = 0; c4_i13 < 5; c4_i13++) {
    c4_b_inData[c4_i13] = (*(real_T (*)[5])c4_inData)[c4_i13];
  }

  for (c4_i14 = 0; c4_i14 < 5; c4_i14++) {
    c4_u[c4_i14] = c4_b_inData[c4_i14];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_robot_diffInstanceStruct *chartInstance,
  const mxArray *c4_ro, const char_T *c4_identifier, real_T c4_y[5])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_ro), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_ro);
}

static void c4_b_emlrt_marshallIn(SFc4_robot_diffInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[5])
{
  real_T c4_dv2[5];
  int32_T c4_i15;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv2, 1, 0, 0U, 1, 0U, 1, 5);
  for (c4_i15 = 0; c4_i15 < 5; c4_i15++) {
    c4_y[c4_i15] = c4_dv2[c4_i15];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_ro;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[5];
  int32_T c4_i16;
  SFc4_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc4_robot_diffInstanceStruct *)chartInstanceVoid;
  c4_ro = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_ro), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_ro);
  for (c4_i16 = 0; c4_i16 < 5; c4_i16++) {
    (*(real_T (*)[5])c4_outData)[c4_i16] = c4_y[c4_i16];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc4_robot_diffInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_robot_diffInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d1;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d1, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d1;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc4_robot_diffInstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i17;
  real_T c4_b_inData[5];
  int32_T c4_i18;
  real_T c4_u[5];
  const mxArray *c4_y = NULL;
  SFc4_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc4_robot_diffInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i17 = 0; c4_i17 < 5; c4_i17++) {
    c4_b_inData[c4_i17] = (*(real_T (*)[5])c4_inData)[c4_i17];
  }

  for (c4_i18 = 0; c4_i18 < 5; c4_i18++) {
    c4_u[c4_i18] = c4_b_inData[c4_i18];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1, 5), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

const mxArray *sf_c4_robot_diff_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[5];
  c4_ResolvedFunctionInfo (*c4_b_info)[5];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i19;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[5])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "polyval";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/polyval.m";
  (*c4_b_info)[0].fileTimeLo = 1305343202U;
  (*c4_b_info)[0].fileTimeHi = 0U;
  (*c4_b_info)[0].mFileTimeLo = 0U;
  (*c4_b_info)[0].mFileTimeHi = 0U;
  (*c4_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/polyval.m";
  (*c4_b_info)[1].name = "eml_scalar_eg";
  (*c4_b_info)[1].dominantType = "double";
  (*c4_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c4_b_info)[1].fileTimeLo = 1286843996U;
  (*c4_b_info)[1].fileTimeHi = 0U;
  (*c4_b_info)[1].mFileTimeLo = 0U;
  (*c4_b_info)[1].mFileTimeHi = 0U;
  (*c4_b_info)[2].context = "";
  (*c4_b_info)[2].name = "eml_li_find";
  (*c4_b_info)[2].dominantType = "";
  (*c4_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  (*c4_b_info)[2].fileTimeLo = 1286843986U;
  (*c4_b_info)[2].fileTimeHi = 0U;
  (*c4_b_info)[2].mFileTimeLo = 0U;
  (*c4_b_info)[2].mFileTimeHi = 0U;
  (*c4_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  (*c4_b_info)[3].name = "eml_index_class";
  (*c4_b_info)[3].dominantType = "";
  (*c4_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c4_b_info)[3].fileTimeLo = 1286843978U;
  (*c4_b_info)[3].fileTimeHi = 0U;
  (*c4_b_info)[3].mFileTimeLo = 0U;
  (*c4_b_info)[3].mFileTimeHi = 0U;
  (*c4_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones";
  (*c4_b_info)[4].name = "eml_index_plus";
  (*c4_b_info)[4].dominantType = "int32";
  (*c4_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  (*c4_b_info)[4].fileTimeLo = 1286843978U;
  (*c4_b_info)[4].fileTimeHi = 0U;
  (*c4_b_info)[4].mFileTimeLo = 0U;
  (*c4_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5), FALSE);
  for (c4_i19 = 0; c4_i19 < 5; c4_i19++) {
    c4_r0 = &c4_info[c4_i19];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i19);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i19);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i19);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i19);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i19);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i19);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i19);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i19);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc4_robot_diffInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_d_emlrt_marshallIn(SFc4_robot_diffInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i20;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i20, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i20;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc4_robot_diffInstanceStruct *)chartInstanceVoid;
  c4_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_sfEvent), &c4_thisId);
  sf_mex_destroy(&c4_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_robot_diffInstanceStruct
  *chartInstance, const mxArray *c4_is_active_c4_robot_diff, const char_T
  *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_is_active_c4_robot_diff), &c4_thisId);
  sf_mex_destroy(&c4_is_active_c4_robot_diff);
  return c4_y;
}

static uint8_T c4_f_emlrt_marshallIn(SFc4_robot_diffInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_robot_diffInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c4_robot_diff_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3681457920U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2717861201U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(222084618U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3948223980U);
}

mxArray *sf_c4_robot_diff_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("qBQoOhwWf4NOtDz02aUgIF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
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

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c4_robot_diff(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"ro\",},{M[8],M[0],T\"is_active_c4_robot_diff\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_robot_diff_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_robot_diffInstanceStruct *chartInstance;
    chartInstance = (SFc4_robot_diffInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_robot_diffMachineNumber_,
           4,
           1,
           1,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"volt");
          _SFD_SET_DATA_PROPS(1,2,0,1,"ro");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,211);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          real_T (*c4_volt)[5];
          real_T (*c4_ro)[5];
          c4_ro = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 1);
          c4_volt = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_volt);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_ro);
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
      4, "dworkChecksum");
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

static void sf_opaque_initialize_c4_robot_diff(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc4_robot_diffInstanceStruct*) chartInstanceVar
    )->S);
  chart_debug_initialization(((SFc4_robot_diffInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c4_robot_diff((SFc4_robot_diffInstanceStruct*)
    chartInstanceVar);
  initialize_c4_robot_diff((SFc4_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_robot_diff(void *chartInstanceVar)
{
  enable_c4_robot_diff((SFc4_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_robot_diff(void *chartInstanceVar)
{
  disable_c4_robot_diff((SFc4_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_robot_diff(void *chartInstanceVar)
{
  sf_c4_robot_diff((SFc4_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c4_robot_diff(void *chartInstanceVar)
{
  ext_mode_exec_c4_robot_diff((SFc4_robot_diffInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_robot_diff(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_robot_diff
    ((SFc4_robot_diffInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_robot_diff();/* state var info */
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

extern void sf_internal_set_sim_state_c4_robot_diff(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_robot_diff();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_robot_diff((SFc4_robot_diffInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_robot_diff(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_robot_diff(S);
}

static void sf_opaque_set_sim_state_c4_robot_diff(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c4_robot_diff(S, st);
}

static void sf_opaque_terminate_c4_robot_diff(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_robot_diffInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_robot_diff((SFc4_robot_diffInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_robot_diff_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_robot_diff((SFc4_robot_diffInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_robot_diff(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_robot_diff((SFc4_robot_diffInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c4_robot_diff_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c4_robot_diff\",T\"is_active_c4_robot_diff\"}}"
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

static void mdlSetWorkWidths_c4_robot_diff(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_robot_diff_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,infoStruct,4,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1505674371U));
  ssSetChecksum1(S,(2547788183U));
  ssSetChecksum2(S,(3814327496U));
  ssSetChecksum3(S,(2890722247U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_robot_diff(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_robot_diff(SimStruct *S)
{
  SFc4_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc4_robot_diffInstanceStruct *)malloc(sizeof
    (SFc4_robot_diffInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_robot_diffInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_robot_diff;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_robot_diff;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_robot_diff;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_robot_diff;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_robot_diff;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_robot_diff;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_robot_diff;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_robot_diff;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_robot_diff;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_robot_diff;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_robot_diff;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c4_robot_diff;
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

void c4_robot_diff_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_robot_diff(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_robot_diff(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_robot_diff(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_robot_diff_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
