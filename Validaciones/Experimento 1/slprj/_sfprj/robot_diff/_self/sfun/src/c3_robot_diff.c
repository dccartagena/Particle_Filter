/* Include files */

#include "blascompat32.h"
#include "robot_diff_sfun.h"
#include "c3_robot_diff.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "robot_diff_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[13] = { "l", "J_inv", "u", "v", "w",
  "v_max", "nargin", "nargout", "clock", "d_estado", "theta", "vl", "vr" };

/* Function Declarations */
static void initialize_c3_robot_diff(SFc3_robot_diffInstanceStruct
  *chartInstance);
static void initialize_params_c3_robot_diff(SFc3_robot_diffInstanceStruct
  *chartInstance);
static void enable_c3_robot_diff(SFc3_robot_diffInstanceStruct *chartInstance);
static void disable_c3_robot_diff(SFc3_robot_diffInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_robot_diff(SFc3_robot_diffInstanceStruct
  *chartInstance);
static void ext_mode_exec_c3_robot_diff(SFc3_robot_diffInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_robot_diff(SFc3_robot_diffInstanceStruct *
  chartInstance);
static void set_sim_state_c3_robot_diff(SFc3_robot_diffInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_robot_diff(SFc3_robot_diffInstanceStruct *chartInstance);
static void sf_c3_robot_diff(SFc3_robot_diffInstanceStruct *chartInstance);
static void c3_chartstep_c3_robot_diff(SFc3_robot_diffInstanceStruct
  *chartInstance);
static void initSimStructsc3_robot_diff(SFc3_robot_diffInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_robot_diffInstanceStruct *chartInstance,
  const mxArray *c3_vr, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_robot_diffInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_robot_diffInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_emlrt_marshallIn(SFc3_robot_diffInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[18]);
static void c3_eml_scalar_eg(SFc3_robot_diffInstanceStruct *chartInstance);
static void c3_b_eml_scalar_eg(SFc3_robot_diffInstanceStruct *chartInstance);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_robot_diffInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_f_emlrt_marshallIn(SFc3_robot_diffInstanceStruct
  *chartInstance, const mxArray *c3_is_active_c3_robot_diff, const char_T
  *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn(SFc3_robot_diffInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_robot_diffInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_robot_diff(SFc3_robot_diffInstanceStruct
  *chartInstance)
{
  int32_T *c3_sfEvent;
  uint8_T *c3_is_active_c3_robot_diff;
  c3_is_active_c3_robot_diff = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c3_is_active_c3_robot_diff = 0U;
}

static void initialize_params_c3_robot_diff(SFc3_robot_diffInstanceStruct
  *chartInstance)
{
}

static void enable_c3_robot_diff(SFc3_robot_diffInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_robot_diff(SFc3_robot_diffInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_robot_diff(SFc3_robot_diffInstanceStruct
  *chartInstance)
{
}

static void ext_mode_exec_c3_robot_diff(SFc3_robot_diffInstanceStruct
  *chartInstance)
{
  c3_update_debugger_state_c3_robot_diff(chartInstance);
}

static const mxArray *get_sim_state_c3_robot_diff(SFc3_robot_diffInstanceStruct *
  chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint8_T c3_c_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T *c3_vl;
  real_T *c3_vr;
  uint8_T *c3_is_active_c3_robot_diff;
  c3_vr = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_vl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_active_c3_robot_diff = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(3), FALSE);
  c3_hoistedGlobal = *c3_vl;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_vr;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_is_active_c3_robot_diff;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_robot_diff(SFc3_robot_diffInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  boolean_T *c3_doneDoubleBufferReInit;
  real_T *c3_vl;
  real_T *c3_vr;
  uint8_T *c3_is_active_c3_robot_diff;
  c3_vr = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_vl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_active_c3_robot_diff = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_vl = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
    "vl");
  *c3_vr = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "vr");
  *c3_is_active_c3_robot_diff = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "is_active_c3_robot_diff");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_robot_diff(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_robot_diff(SFc3_robot_diffInstanceStruct *chartInstance)
{
}

static void sf_c3_robot_diff(SFc3_robot_diffInstanceStruct *chartInstance)
{
  int32_T c3_i0;
  int32_T *c3_sfEvent;
  real_T *c3_clock;
  real_T *c3_vl;
  real_T *c3_vr;
  real_T *c3_theta;
  real_T (*c3_d_estado)[3];
  c3_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_vr = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_vl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_d_estado = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c3_clock = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, *c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_clock, 0U);
  for (c3_i0 = 0; c3_i0 < 3; c3_i0++) {
    _SFD_DATA_RANGE_CHECK((*c3_d_estado)[c3_i0], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_vl, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_vr, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_theta, 4U);
  *c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_robot_diff(chartInstance);
  sf_debug_check_for_state_inconsistency(_robot_diffMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_robot_diff(SFc3_robot_diffInstanceStruct
  *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_clock;
  int32_T c3_i1;
  real_T c3_d_estado[3];
  real_T c3_theta;
  uint32_T c3_debug_family_var_map[13];
  real_T c3_l;
  real_T c3_J_inv[6];
  real_T c3_u[2];
  real_T c3_v;
  real_T c3_w;
  real_T c3_v_max;
  real_T c3_nargin = 3.0;
  real_T c3_nargout = 2.0;
  real_T c3_vl;
  real_T c3_vr;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  int32_T c3_i2;
  int32_T c3_i3;
  static real_T c3_dv0[3] = { 0.0, 0.0, 1.0 };

  int32_T c3_i4;
  real_T c3_a[6];
  int32_T c3_i5;
  real_T c3_b[3];
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  real_T c3_C[2];
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  real_T c3_b_b;
  real_T c3_y;
  real_T c3_c_b;
  real_T c3_b_y;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_c_y;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_d_y;
  real_T c3_varargin_1;
  real_T c3_varargin_2;
  real_T c3_b_varargin_2;
  real_T c3_varargin_3;
  real_T c3_i_x;
  real_T c3_e_y;
  real_T c3_j_x;
  real_T c3_f_y;
  real_T c3_xk;
  real_T c3_yk;
  real_T c3_k_x;
  real_T c3_g_y;
  real_T c3_A;
  real_T c3_B;
  real_T c3_l_x;
  real_T c3_h_y;
  real_T c3_m_x;
  real_T c3_i_y;
  real_T c3_j_y;
  real_T c3_b_a;
  real_T c3_b_A;
  real_T c3_b_B;
  real_T c3_n_x;
  real_T c3_k_y;
  real_T c3_o_x;
  real_T c3_l_y;
  real_T c3_m_y;
  real_T c3_c_a;
  real_T *c3_b_clock;
  real_T *c3_b_theta;
  real_T *c3_b_vl;
  real_T *c3_b_vr;
  real_T (*c3_b_d_estado)[3];
  int32_T *c3_sfEvent;
  c3_b_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_vr = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_vl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_d_estado = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_clock = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, *c3_sfEvent);
  c3_hoistedGlobal = *c3_b_clock;
  c3_b_hoistedGlobal = *c3_b_theta;
  c3_clock = c3_hoistedGlobal;
  for (c3_i1 = 0; c3_i1 < 3; c3_i1++) {
    c3_d_estado[c3_i1] = (*c3_b_d_estado)[c3_i1];
  }

  c3_theta = c3_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c3_l, 0U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c3_J_inv, 1U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_u, 2U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_v, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_w, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_v_max, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_clock, 8U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_d_estado, 9U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_theta, 10U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_vl, 11U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_vr, 12U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c3_sfEvent, 7);
  c3_l = 252.5;
  _SFD_EML_CALL(0U, *c3_sfEvent, 9);
  c3_x = c3_theta;
  c3_b_x = c3_x;
  c3_b_x = muDoubleScalarSin(c3_b_x);
  c3_c_x = c3_theta;
  c3_d_x = c3_c_x;
  c3_d_x = muDoubleScalarCos(c3_d_x);
  c3_J_inv[0] = -c3_b_x;
  c3_J_inv[2] = c3_d_x;
  c3_J_inv[4] = 0.0;
  c3_i2 = 0;
  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    c3_J_inv[c3_i2 + 1] = c3_dv0[c3_i3];
    c3_i2 += 2;
  }

  _SFD_EML_CALL(0U, *c3_sfEvent, 12);
  for (c3_i4 = 0; c3_i4 < 6; c3_i4++) {
    c3_a[c3_i4] = c3_J_inv[c3_i4];
  }

  for (c3_i5 = 0; c3_i5 < 3; c3_i5++) {
    c3_b[c3_i5] = c3_d_estado[c3_i5];
  }

  c3_eml_scalar_eg(chartInstance);
  c3_eml_scalar_eg(chartInstance);
  for (c3_i6 = 0; c3_i6 < 2; c3_i6++) {
    c3_u[c3_i6] = 0.0;
  }

  for (c3_i7 = 0; c3_i7 < 2; c3_i7++) {
    c3_u[c3_i7] = 0.0;
  }

  for (c3_i8 = 0; c3_i8 < 2; c3_i8++) {
    c3_C[c3_i8] = c3_u[c3_i8];
  }

  for (c3_i9 = 0; c3_i9 < 2; c3_i9++) {
    c3_u[c3_i9] = c3_C[c3_i9];
  }

  for (c3_i10 = 0; c3_i10 < 2; c3_i10++) {
    c3_C[c3_i10] = c3_u[c3_i10];
  }

  for (c3_i11 = 0; c3_i11 < 2; c3_i11++) {
    c3_u[c3_i11] = c3_C[c3_i11];
  }

  for (c3_i12 = 0; c3_i12 < 2; c3_i12++) {
    c3_u[c3_i12] = 0.0;
    c3_i13 = 0;
    for (c3_i14 = 0; c3_i14 < 3; c3_i14++) {
      c3_u[c3_i12] += c3_a[c3_i13 + c3_i12] * c3_b[c3_i14];
      c3_i13 += 2;
    }
  }

  _SFD_EML_CALL(0U, *c3_sfEvent, 14);
  c3_v = c3_u[0];
  _SFD_EML_CALL(0U, *c3_sfEvent, 15);
  c3_w = c3_u[1];
  _SFD_EML_CALL(0U, *c3_sfEvent, 17);
  c3_b_b = c3_w;
  c3_y = 126.25 * c3_b_b;
  c3_vl = c3_v - c3_y;
  _SFD_EML_CALL(0U, *c3_sfEvent, 18);
  c3_c_b = c3_w;
  c3_b_y = 126.25 * c3_c_b;
  c3_vr = c3_v + c3_b_y;
  _SFD_EML_CALL(0U, *c3_sfEvent, 20);
  c3_e_x = c3_vl;
  c3_f_x = c3_e_x;
  c3_c_y = muDoubleScalarAbs(c3_f_x);
  c3_g_x = c3_vr;
  c3_h_x = c3_g_x;
  c3_d_y = muDoubleScalarAbs(c3_h_x);
  c3_varargin_1 = c3_c_y;
  c3_varargin_2 = c3_d_y;
  c3_b_varargin_2 = c3_varargin_1;
  c3_varargin_3 = c3_varargin_2;
  c3_i_x = c3_b_varargin_2;
  c3_e_y = c3_varargin_3;
  c3_j_x = c3_i_x;
  c3_f_y = c3_e_y;
  c3_b_eml_scalar_eg(chartInstance);
  c3_xk = c3_j_x;
  c3_yk = c3_f_y;
  c3_k_x = c3_xk;
  c3_g_y = c3_yk;
  c3_b_eml_scalar_eg(chartInstance);
  c3_v_max = muDoubleScalarMax(c3_k_x, c3_g_y);
  _SFD_EML_CALL(0U, *c3_sfEvent, 22);
  if (CV_EML_IF(0, 1, 0, c3_v_max >= 450.0)) {
    _SFD_EML_CALL(0U, *c3_sfEvent, 23);
    c3_A = c3_vr;
    c3_B = c3_v_max;
    c3_l_x = c3_A;
    c3_h_y = c3_B;
    c3_m_x = c3_l_x;
    c3_i_y = c3_h_y;
    c3_j_y = c3_m_x / c3_i_y;
    c3_b_a = c3_j_y;
    c3_vr = c3_b_a * 450.0;
    _SFD_EML_CALL(0U, *c3_sfEvent, 24);
    c3_b_A = c3_vl;
    c3_b_B = c3_v_max;
    c3_n_x = c3_b_A;
    c3_k_y = c3_b_B;
    c3_o_x = c3_n_x;
    c3_l_y = c3_k_y;
    c3_m_y = c3_o_x / c3_l_y;
    c3_c_a = c3_m_y;
    c3_vl = c3_c_a * 450.0;
  }

  _SFD_EML_CALL(0U, *c3_sfEvent, -24);
  sf_debug_symbol_scope_pop();
  *c3_b_vl = c3_vl;
  *c3_b_vr = c3_vr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *c3_sfEvent);
}

static void initSimStructsc3_robot_diff(SFc3_robot_diffInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc3_robot_diffInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_robot_diffInstanceStruct *chartInstance,
  const mxArray *c3_vr, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_vr), &c3_thisId);
  sf_mex_destroy(&c3_vr);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_robot_diffInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_vr;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc3_robot_diffInstanceStruct *)chartInstanceVoid;
  c3_vr = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_vr), &c3_thisId);
  sf_mex_destroy(&c3_vr);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i15;
  real_T c3_b_inData[3];
  int32_T c3_i16;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc3_robot_diffInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i15 = 0; c3_i15 < 3; c3_i15++) {
    c3_b_inData[c3_i15] = (*(real_T (*)[3])c3_inData)[c3_i15];
  }

  for (c3_i16 = 0; c3_i16 < 3; c3_i16++) {
    c3_u[c3_i16] = c3_b_inData[c3_i16];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i17;
  real_T c3_b_inData[2];
  int32_T c3_i18;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc3_robot_diffInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i17 = 0; c3_i17 < 2; c3_i17++) {
    c3_b_inData[c3_i17] = (*(real_T (*)[2])c3_inData)[c3_i17];
  }

  for (c3_i18 = 0; c3_i18 < 2; c3_i18++) {
    c3_u[c3_i18] = c3_b_inData[c3_i18];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_robot_diffInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[2])
{
  real_T c3_dv1[2];
  int32_T c3_i19;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c3_i19 = 0; c3_i19 < 2; c3_i19++) {
    c3_y[c3_i19] = c3_dv1[c3_i19];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_u;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2];
  int32_T c3_i20;
  SFc3_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc3_robot_diffInstanceStruct *)chartInstanceVoid;
  c3_u = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_u), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_u);
  for (c3_i20 = 0; c3_i20 < 2; c3_i20++) {
    (*(real_T (*)[2])c3_outData)[c3_i20] = c3_y[c3_i20];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  real_T c3_b_inData[6];
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  real_T c3_u[6];
  const mxArray *c3_y = NULL;
  SFc3_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc3_robot_diffInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i21 = 0;
  for (c3_i22 = 0; c3_i22 < 3; c3_i22++) {
    for (c3_i23 = 0; c3_i23 < 2; c3_i23++) {
      c3_b_inData[c3_i23 + c3_i21] = (*(real_T (*)[6])c3_inData)[c3_i23 + c3_i21];
    }

    c3_i21 += 2;
  }

  c3_i24 = 0;
  for (c3_i25 = 0; c3_i25 < 3; c3_i25++) {
    for (c3_i26 = 0; c3_i26 < 2; c3_i26++) {
      c3_u[c3_i26 + c3_i24] = c3_b_inData[c3_i26 + c3_i24];
    }

    c3_i24 += 2;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 2, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_d_emlrt_marshallIn(SFc3_robot_diffInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[6])
{
  real_T c3_dv2[6];
  int32_T c3_i27;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv2, 1, 0, 0U, 1, 0U, 2, 2, 3);
  for (c3_i27 = 0; c3_i27 < 6; c3_i27++) {
    c3_y[c3_i27] = c3_dv2[c3_i27];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_J_inv;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[6];
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i30;
  SFc3_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc3_robot_diffInstanceStruct *)chartInstanceVoid;
  c3_J_inv = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_J_inv), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_J_inv);
  c3_i28 = 0;
  for (c3_i29 = 0; c3_i29 < 3; c3_i29++) {
    for (c3_i30 = 0; c3_i30 < 2; c3_i30++) {
      (*(real_T (*)[6])c3_outData)[c3_i30 + c3_i28] = c3_y[c3_i30 + c3_i28];
    }

    c3_i28 += 2;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_robot_diff_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[18];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i31;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 18), FALSE);
  for (c3_i31 = 0; c3_i31 < 18; c3_i31++) {
    c3_r0 = &c3_info[c3_i31];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i31);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i31);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i31);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i31);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i31);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i31);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i31);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i31);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[18])
{
  c3_info[0].context = "";
  c3_info[0].name = "sin";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[0].fileTimeLo = 1286843950U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[1].name = "eml_scalar_sin";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c3_info[1].fileTimeLo = 1286843936U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context = "";
  c3_info[2].name = "cos";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[2].fileTimeLo = 1286843906U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[3].name = "eml_scalar_cos";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c3_info[3].fileTimeLo = 1286843922U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context = "";
  c3_info[4].name = "mtimes";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[4].fileTimeLo = 1289541292U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[5].name = "eml_index_class";
  c3_info[5].dominantType = "";
  c3_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[5].fileTimeLo = 1286843978U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[6].name = "eml_scalar_eg";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[6].fileTimeLo = 1286843996U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[7].name = "eml_xgemm";
  c3_info[7].dominantType = "int32";
  c3_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[7].fileTimeLo = 1299098372U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[8].name = "eml_blas_inline";
  c3_info[8].dominantType = "";
  c3_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[8].fileTimeLo = 1299098368U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[9].name = "eml_refblas_xgemm";
  c3_info[9].dominantType = "int32";
  c3_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c3_info[9].fileTimeLo = 1299098374U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context = "";
  c3_info[10].name = "mrdivide";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[10].fileTimeLo = 1310162656U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 1289541292U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[11].name = "rdivide";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[11].fileTimeLo = 1286844044U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[12].name = "eml_div";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[12].fileTimeLo = 1305343200U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context = "";
  c3_info[13].name = "abs";
  c3_info[13].dominantType = "double";
  c3_info[13].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[13].fileTimeLo = 1286843894U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[14].name = "eml_scalar_abs";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c3_info[14].fileTimeLo = 1286843912U;
  c3_info[14].fileTimeHi = 0U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context = "";
  c3_info[15].name = "max";
  c3_info[15].dominantType = "double";
  c3_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c3_info[15].fileTimeLo = 1308772528U;
  c3_info[15].fileTimeHi = 0U;
  c3_info[15].mFileTimeLo = 0U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c3_info[16].name = "eml_min_or_max";
  c3_info[16].dominantType = "char";
  c3_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[16].fileTimeLo = 1303171412U;
  c3_info[16].fileTimeHi = 0U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[17].name = "eml_scalexp_alloc";
  c3_info[17].dominantType = "double";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[17].fileTimeLo = 1286843996U;
  c3_info[17].fileTimeHi = 0U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
}

static void c3_eml_scalar_eg(SFc3_robot_diffInstanceStruct *chartInstance)
{
}

static void c3_b_eml_scalar_eg(SFc3_robot_diffInstanceStruct *chartInstance)
{
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc3_robot_diffInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_robot_diffInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i32;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i32, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i32;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc3_robot_diffInstanceStruct *)chartInstanceVoid;
  c3_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sfEvent), &c3_thisId);
  sf_mex_destroy(&c3_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_robot_diffInstanceStruct
  *chartInstance, const mxArray *c3_is_active_c3_robot_diff, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_is_active_c3_robot_diff), &c3_thisId);
  sf_mex_destroy(&c3_is_active_c3_robot_diff);
  return c3_y;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_robot_diffInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_robot_diffInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c3_robot_diff_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(649970590U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(465212941U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2698505961U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2858599272U);
}

mxArray *sf_c3_robot_diff_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("IdAvotD264VM0gEYv6N5zC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c3_robot_diff(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"vl\",},{M[1],M[7],T\"vr\",},{M[8],M[0],T\"is_active_c3_robot_diff\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_robot_diff_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_robot_diffInstanceStruct *chartInstance;
    chartInstance = (SFc3_robot_diffInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_robot_diffMachineNumber_,
           3,
           1,
           1,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"clock");
          _SFD_SET_DATA_PROPS(1,1,1,0,"d_estado");
          _SFD_SET_DATA_PROPS(2,2,0,1,"vl");
          _SFD_SET_DATA_PROPS(3,2,0,1,"vr");
          _SFD_SET_DATA_PROPS(4,1,1,0,"theta");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,532);
        _SFD_CV_INIT_EML_IF(0,1,0,416,431,-1,509);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c3_clock;
          real_T *c3_vl;
          real_T *c3_vr;
          real_T *c3_theta;
          real_T (*c3_d_estado)[3];
          c3_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_vr = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_vl = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_d_estado = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c3_clock = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_clock);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_d_estado);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_vl);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_vr);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_theta);
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
      3, "dworkChecksum");
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

static void sf_opaque_initialize_c3_robot_diff(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc3_robot_diffInstanceStruct*) chartInstanceVar
    )->S);
  chart_debug_initialization(((SFc3_robot_diffInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c3_robot_diff((SFc3_robot_diffInstanceStruct*)
    chartInstanceVar);
  initialize_c3_robot_diff((SFc3_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_robot_diff(void *chartInstanceVar)
{
  enable_c3_robot_diff((SFc3_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_robot_diff(void *chartInstanceVar)
{
  disable_c3_robot_diff((SFc3_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_robot_diff(void *chartInstanceVar)
{
  sf_c3_robot_diff((SFc3_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c3_robot_diff(void *chartInstanceVar)
{
  ext_mode_exec_c3_robot_diff((SFc3_robot_diffInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_robot_diff(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_robot_diff
    ((SFc3_robot_diffInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_robot_diff();/* state var info */
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

extern void sf_internal_set_sim_state_c3_robot_diff(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_robot_diff();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_robot_diff((SFc3_robot_diffInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_robot_diff(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_robot_diff(S);
}

static void sf_opaque_set_sim_state_c3_robot_diff(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c3_robot_diff(S, st);
}

static void sf_opaque_terminate_c3_robot_diff(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_robot_diffInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_robot_diff((SFc3_robot_diffInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_robot_diff_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_robot_diff((SFc3_robot_diffInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_robot_diff(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_robot_diff((SFc3_robot_diffInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c3_robot_diff_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c3_robot_diff\",T\"is_active_c3_robot_diff\"}}"
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

static void mdlSetWorkWidths_c3_robot_diff(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_robot_diff_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,3,3);
      sf_mark_chart_reusable_outputs(S,infoStruct,3,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1722676031U));
  ssSetChecksum1(S,(2688488105U));
  ssSetChecksum2(S,(3561262643U));
  ssSetChecksum3(S,(1665826619U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_robot_diff(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_robot_diff(SimStruct *S)
{
  SFc3_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc3_robot_diffInstanceStruct *)malloc(sizeof
    (SFc3_robot_diffInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_robot_diffInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_robot_diff;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_robot_diff;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_robot_diff;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_robot_diff;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_robot_diff;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_robot_diff;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_robot_diff;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_robot_diff;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_robot_diff;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_robot_diff;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_robot_diff;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c3_robot_diff;
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

void c3_robot_diff_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_robot_diff(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_robot_diff(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_robot_diff(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_robot_diff_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
