/* Include files */

#include "blascompat32.h"
#include "robot_diff_sfun.h"
#include "c2_robot_diff.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "robot_diff_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[20] = { "estado_target", "error", "v",
  "Kp", "L", "delta", "gamma", "gamma_hat", "d_x", "d_y", "d_theta", "nargin",
  "nargout", "clock", "X_target", "Y_target", "X", "Y", "theta", "d_estado" };

/* Function Declarations */
static void initialize_c2_robot_diff(SFc2_robot_diffInstanceStruct
  *chartInstance);
static void initialize_params_c2_robot_diff(SFc2_robot_diffInstanceStruct
  *chartInstance);
static void enable_c2_robot_diff(SFc2_robot_diffInstanceStruct *chartInstance);
static void disable_c2_robot_diff(SFc2_robot_diffInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_robot_diff(SFc2_robot_diffInstanceStruct
  *chartInstance);
static void ext_mode_exec_c2_robot_diff(SFc2_robot_diffInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_robot_diff(SFc2_robot_diffInstanceStruct *
  chartInstance);
static void set_sim_state_c2_robot_diff(SFc2_robot_diffInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_robot_diff(SFc2_robot_diffInstanceStruct *chartInstance);
static void sf_c2_robot_diff(SFc2_robot_diffInstanceStruct *chartInstance);
static void initSimStructsc2_robot_diff(SFc2_robot_diffInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_robot_diffInstanceStruct *chartInstance,
  const mxArray *c2_d_estado, const char_T *c2_identifier, real_T c2_y[3]);
static void c2_b_emlrt_marshallIn(SFc2_robot_diffInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_robot_diffInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_robot_diffInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_robot_diffInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18]);
static real_T c2_mpower(SFc2_robot_diffInstanceStruct *chartInstance, real_T
  c2_a);
static void c2_eml_error(SFc2_robot_diffInstanceStruct *chartInstance);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_f_emlrt_marshallIn(SFc2_robot_diffInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_g_emlrt_marshallIn(SFc2_robot_diffInstanceStruct
  *chartInstance, const mxArray *c2_is_active_c2_robot_diff, const char_T
  *c2_identifier);
static uint8_T c2_h_emlrt_marshallIn(SFc2_robot_diffInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_robot_diffInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_robot_diff(SFc2_robot_diffInstanceStruct
  *chartInstance)
{
  int32_T *c2_sfEvent;
  uint8_T *c2_is_active_c2_robot_diff;
  c2_is_active_c2_robot_diff = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c2_is_active_c2_robot_diff = 0U;
}

static void initialize_params_c2_robot_diff(SFc2_robot_diffInstanceStruct
  *chartInstance)
{
}

static void enable_c2_robot_diff(SFc2_robot_diffInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_robot_diff(SFc2_robot_diffInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_robot_diff(SFc2_robot_diffInstanceStruct
  *chartInstance)
{
}

static void ext_mode_exec_c2_robot_diff(SFc2_robot_diffInstanceStruct
  *chartInstance)
{
  c2_update_debugger_state_c2_robot_diff(chartInstance);
}

static const mxArray *get_sim_state_c2_robot_diff(SFc2_robot_diffInstanceStruct *
  chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[3];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T *c2_is_active_c2_robot_diff;
  real_T (*c2_d_estado)[3];
  c2_d_estado = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_is_active_c2_robot_diff = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    c2_u[c2_i0] = (*c2_d_estado)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = *c2_is_active_c2_robot_diff;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_robot_diff(SFc2_robot_diffInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[3];
  int32_T c2_i1;
  boolean_T *c2_doneDoubleBufferReInit;
  uint8_T *c2_is_active_c2_robot_diff;
  real_T (*c2_d_estado)[3];
  c2_d_estado = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_is_active_c2_robot_diff = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c2_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                      "d_estado", c2_dv0);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    (*c2_d_estado)[c2_i1] = c2_dv0[c2_i1];
  }

  *c2_is_active_c2_robot_diff = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "is_active_c2_robot_diff");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_robot_diff(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_robot_diff(SFc2_robot_diffInstanceStruct *chartInstance)
{
}

static void sf_c2_robot_diff(SFc2_robot_diffInstanceStruct *chartInstance)
{
  int32_T c2_i2;
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_clock;
  real_T c2_X_target;
  real_T c2_Y_target;
  real_T c2_X;
  real_T c2_Y;
  real_T c2_theta;
  uint32_T c2_debug_family_var_map[20];
  real_T c2_estado_target[2];
  real_T c2_error[2];
  real_T c2_v;
  real_T c2_Kp;
  real_T c2_L;
  real_T c2_delta;
  real_T c2_gamma;
  real_T c2_gamma_hat;
  real_T c2_d_x;
  real_T c2_d_y;
  real_T c2_d_theta;
  real_T c2_nargin = 6.0;
  real_T c2_nargout = 1.0;
  real_T c2_d_estado[3];
  int32_T c2_i3;
  real_T c2_A;
  real_T c2_B;
  real_T c2_x;
  real_T c2_y;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c_y;
  real_T c2_c_x;
  real_T c2_e_x;
  real_T c2_e_y;
  real_T c2_b_A;
  real_T c2_b_B;
  real_T c2_f_x;
  real_T c2_f_y;
  real_T c2_g_x;
  real_T c2_g_y;
  real_T c2_h_y;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_i_y;
  int32_T c2_i4;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_a;
  real_T c2_b;
  real_T c2_j_y;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_k_y;
  real_T c2_c_b;
  real_T c2_l_y;
  real_T c2_c_A;
  real_T c2_c_B;
  real_T c2_p_x;
  real_T c2_m_y;
  real_T c2_q_x;
  real_T c2_n_y;
  real_T c2_d_b;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_e_b;
  real_T c2_t_x;
  real_T c2_u_x;
  real_T c2_f_b;
  real_T c2_g_b;
  real_T c2_b_d_x[3];
  int32_T c2_i5;
  int32_T c2_i6;
  real_T *c2_b_theta;
  real_T *c2_b_Y;
  real_T *c2_b_X;
  real_T *c2_b_Y_target;
  real_T *c2_b_X_target;
  real_T *c2_b_clock;
  int32_T *c2_sfEvent;
  real_T (*c2_b_d_estado)[3];
  boolean_T guard1 = FALSE;
  c2_b_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_Y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_X = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_d_estado = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_Y_target = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_X_target = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_clock = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, *c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_clock, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_X_target, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_Y_target, 2U);
  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_d_estado)[c2_i2], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_b_X, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_b_Y, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_b_theta, 6U);
  *c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, *c2_sfEvent);
  c2_hoistedGlobal = *c2_b_clock;
  c2_b_hoistedGlobal = *c2_b_X_target;
  c2_c_hoistedGlobal = *c2_b_Y_target;
  c2_d_hoistedGlobal = *c2_b_X;
  c2_e_hoistedGlobal = *c2_b_Y;
  c2_f_hoistedGlobal = *c2_b_theta;
  c2_clock = c2_hoistedGlobal;
  c2_X_target = c2_b_hoistedGlobal;
  c2_Y_target = c2_c_hoistedGlobal;
  c2_X = c2_d_hoistedGlobal;
  c2_Y = c2_e_hoistedGlobal;
  c2_theta = c2_f_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 20U, 20U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c2_estado_target, 0U,
    c2_d_sf_marshallOut, c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_error, 1U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_v, 2U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Kp, 3U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_L, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_delta, 5U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_gamma, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_gamma_hat, 7U,
    c2_b_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_d_x, 8U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_d_y, 9U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_d_theta, 10U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 11U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 12U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_clock, 13U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_X_target, 14U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Y_target, 15U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_X, 16U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Y, 17U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_theta, 18U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_d_estado, 19U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c2_sfEvent, 3);
  c2_estado_target[0] = c2_X_target;
  c2_estado_target[1] = c2_Y_target;
  _SFD_EML_CALL(0U, *c2_sfEvent, 12);
  for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
    c2_error[c2_i3] = 0.0;
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 13);
  c2_A = c2_estado_target[0] - c2_X;
  c2_B = c2_X;
  c2_x = c2_A;
  c2_y = c2_B;
  c2_b_x = c2_x;
  c2_b_y = c2_y;
  c2_c_y = c2_b_x / c2_b_y;
  c2_c_x = c2_c_y;
  c2_e_x = c2_c_x;
  c2_e_y = muDoubleScalarAbs(c2_e_x);
  c2_error[0] = c2_e_y;
  _SFD_EML_CALL(0U, *c2_sfEvent, 14);
  c2_b_A = c2_estado_target[1] - c2_Y;
  c2_b_B = c2_Y;
  c2_f_x = c2_b_A;
  c2_f_y = c2_b_B;
  c2_g_x = c2_f_x;
  c2_g_y = c2_f_y;
  c2_h_y = c2_g_x / c2_g_y;
  c2_h_x = c2_h_y;
  c2_i_x = c2_h_x;
  c2_i_y = muDoubleScalarAbs(c2_i_x);
  c2_error[1] = c2_i_y;
  _SFD_EML_CALL(0U, *c2_sfEvent, 16);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 0, c2_error[0] < 0.005)) {
    if (CV_EML_COND(0, 1, 1, c2_error[1] < 0.005)) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 0, TRUE);
      _SFD_EML_CALL(0U, *c2_sfEvent, 17);
      for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
        c2_d_estado[c2_i4] = 0.0;
      }
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
    _SFD_EML_CALL(0U, *c2_sfEvent, 19);
    c2_v = 200.0;
    _SFD_EML_CALL(0U, *c2_sfEvent, 21);
    c2_Kp = 10.0;
    _SFD_EML_CALL(0U, *c2_sfEvent, 26);
    c2_j_x = c2_mpower(chartInstance, c2_estado_target[0] - c2_X) + c2_mpower
      (chartInstance, c2_estado_target[1] - c2_Y);
    c2_L = c2_j_x;
    if (c2_L < 0.0) {
      c2_eml_error(chartInstance);
    }

    c2_k_x = c2_L;
    c2_L = c2_k_x;
    c2_L = muDoubleScalarSqrt(c2_L);
    _SFD_EML_CALL(0U, *c2_sfEvent, 27);
    c2_l_x = c2_theta;
    c2_m_x = c2_l_x;
    c2_m_x = muDoubleScalarCos(c2_m_x);
    c2_a = c2_estado_target[0] - c2_X;
    c2_b = c2_m_x;
    c2_j_y = c2_a * c2_b;
    c2_n_x = c2_theta;
    c2_o_x = c2_n_x;
    c2_o_x = muDoubleScalarSin(c2_o_x);
    c2_b_a = c2_estado_target[1] - c2_Y;
    c2_b_b = c2_o_x;
    c2_k_y = c2_b_a * c2_b_b;
    c2_delta = c2_j_y + c2_k_y;
    _SFD_EML_CALL(0U, *c2_sfEvent, 30);
    c2_c_b = c2_delta;
    c2_l_y = 2.0 * c2_c_b;
    c2_c_A = -c2_l_y;
    c2_c_B = c2_mpower(chartInstance, c2_L);
    c2_p_x = c2_c_A;
    c2_m_y = c2_c_B;
    c2_q_x = c2_p_x;
    c2_n_y = c2_m_y;
    c2_gamma = c2_q_x / c2_n_y;
    _SFD_EML_CALL(0U, *c2_sfEvent, 32);
    c2_d_b = c2_gamma;
    c2_gamma_hat = 10.0 * c2_d_b;
    _SFD_EML_CALL(0U, *c2_sfEvent, 35);
    c2_r_x = c2_theta;
    c2_s_x = c2_r_x;
    c2_s_x = muDoubleScalarSin(c2_s_x);
    c2_e_b = c2_s_x;
    c2_d_x = -200.0 * c2_e_b;
    _SFD_EML_CALL(0U, *c2_sfEvent, 36);
    c2_t_x = c2_theta;
    c2_u_x = c2_t_x;
    c2_u_x = muDoubleScalarCos(c2_u_x);
    c2_f_b = c2_u_x;
    c2_d_y = 200.0 * c2_f_b;
    _SFD_EML_CALL(0U, *c2_sfEvent, 37);
    c2_g_b = c2_gamma_hat;
    c2_d_theta = 200.0 * c2_g_b;
    _SFD_EML_CALL(0U, *c2_sfEvent, 39);
    c2_b_d_x[0] = c2_d_x;
    c2_b_d_x[1] = c2_d_y;
    c2_b_d_x[2] = c2_d_theta;
    for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
      c2_d_estado[c2_i5] = c2_b_d_x[c2_i5];
    }
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, -39);
  sf_debug_symbol_scope_pop();
  for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
    (*c2_b_d_estado)[c2_i6] = c2_d_estado[c2_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c2_sfEvent);
  sf_debug_check_for_state_inconsistency(_robot_diffMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_robot_diff(SFc2_robot_diffInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i7;
  real_T c2_b_inData[3];
  int32_T c2_i8;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc2_robot_diffInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
    c2_b_inData[c2_i7] = (*(real_T (*)[3])c2_inData)[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
    c2_u[c2_i8] = c2_b_inData[c2_i8];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_robot_diffInstanceStruct *chartInstance,
  const mxArray *c2_d_estado, const char_T *c2_identifier, real_T c2_y[3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_d_estado), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_d_estado);
}

static void c2_b_emlrt_marshallIn(SFc2_robot_diffInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3])
{
  real_T c2_dv1[3];
  int32_T c2_i9;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i9 = 0; c2_i9 < 3; c2_i9++) {
    c2_y[c2_i9] = c2_dv1[c2_i9];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_d_estado;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i10;
  SFc2_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc2_robot_diffInstanceStruct *)chartInstanceVoid;
  c2_d_estado = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_d_estado), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_d_estado);
  for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
    (*(real_T (*)[3])c2_outData)[c2_i10] = c2_y[c2_i10];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc2_robot_diffInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_robot_diffInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc2_robot_diffInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i11;
  real_T c2_b_inData[2];
  int32_T c2_i12;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc2_robot_diffInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i11 = 0; c2_i11 < 2; c2_i11++) {
    c2_b_inData[c2_i11] = (*(real_T (*)[2])c2_inData)[c2_i11];
  }

  for (c2_i12 = 0; c2_i12 < 2; c2_i12++) {
    c2_u[c2_i12] = c2_b_inData[c2_i12];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_robot_diffInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2])
{
  real_T c2_dv2[2];
  int32_T c2_i13;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 1, 2);
  for (c2_i13 = 0; c2_i13 < 2; c2_i13++) {
    c2_y[c2_i13] = c2_dv2[c2_i13];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_error;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[2];
  int32_T c2_i14;
  SFc2_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc2_robot_diffInstanceStruct *)chartInstanceVoid;
  c2_error = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_error), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_error);
  for (c2_i14 = 0; c2_i14 < 2; c2_i14++) {
    (*(real_T (*)[2])c2_outData)[c2_i14] = c2_y[c2_i14];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i15;
  real_T c2_b_inData[2];
  int32_T c2_i16;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc2_robot_diffInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i15 = 0; c2_i15 < 2; c2_i15++) {
    c2_b_inData[c2_i15] = (*(real_T (*)[2])c2_inData)[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 2; c2_i16++) {
    c2_u[c2_i16] = c2_b_inData[c2_i16];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_robot_diffInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2])
{
  real_T c2_dv3[2];
  int32_T c2_i17;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv3, 1, 0, 0U, 1, 0U, 2, 1, 2);
  for (c2_i17 = 0; c2_i17 < 2; c2_i17++) {
    c2_y[c2_i17] = c2_dv3[c2_i17];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_estado_target;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[2];
  int32_T c2_i18;
  SFc2_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc2_robot_diffInstanceStruct *)chartInstanceVoid;
  c2_estado_target = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_estado_target), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_estado_target);
  for (c2_i18 = 0; c2_i18 < 2; c2_i18++) {
    (*(real_T (*)[2])c2_outData)[c2_i18] = c2_y[c2_i18];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_robot_diff_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[18];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i19;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 18), FALSE);
  for (c2_i19 = 0; c2_i19 < 18; c2_i19++) {
    c2_r0 = &c2_info[c2_i19];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i19);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i19);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i19);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i19);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i19);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i19);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i19);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i19);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18])
{
  c2_info[0].context = "";
  c2_info[0].name = "mrdivide";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[0].fileTimeLo = 1310162656U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 1289541292U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[1].name = "rdivide";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[1].fileTimeLo = 1286844044U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[2].name = "eml_div";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[2].fileTimeLo = 1305343200U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "";
  c2_info[3].name = "abs";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[3].fileTimeLo = 1286843894U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[4].name = "eml_scalar_abs";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[4].fileTimeLo = 1286843912U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "";
  c2_info[5].name = "mpower";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[5].fileTimeLo = 1286844042U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[6].name = "power";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[6].fileTimeLo = 1294089544U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[7].name = "eml_scalar_eg";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[7].fileTimeLo = 1286843996U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[8].name = "eml_scalexp_alloc";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[8].fileTimeLo = 1286843996U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[9].name = "eml_scalar_floor";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[9].fileTimeLo = 1286843926U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context = "";
  c2_info[10].name = "sqrt";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[10].fileTimeLo = 1286843952U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[11].name = "eml_error";
  c2_info[11].dominantType = "char";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[11].fileTimeLo = 1305343200U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[12].name = "eml_scalar_sqrt";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[12].fileTimeLo = 1286843938U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "";
  c2_info[13].name = "cos";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[13].fileTimeLo = 1286843906U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[14].name = "eml_scalar_cos";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[14].fileTimeLo = 1286843922U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context = "";
  c2_info[15].name = "mtimes";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[15].fileTimeLo = 1289541292U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context = "";
  c2_info[16].name = "sin";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[16].fileTimeLo = 1286843950U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[17].name = "eml_scalar_sin";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[17].fileTimeLo = 1286843936U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
}

static real_T c2_mpower(SFc2_robot_diffInstanceStruct *chartInstance, real_T
  c2_a)
{
  real_T c2_b_a;
  real_T c2_ak;
  c2_b_a = c2_a;
  c2_ak = c2_b_a;
  return muDoubleScalarPower(c2_ak, 2.0);
}

static void c2_eml_error(SFc2_robot_diffInstanceStruct *chartInstance)
{
  int32_T c2_i20;
  static char_T c2_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[30];
  const mxArray *c2_y = NULL;
  for (c2_i20 = 0; c2_i20 < 30; c2_i20++) {
    c2_u[c2_i20] = c2_varargin_1[c2_i20];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc2_robot_diffInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_f_emlrt_marshallIn(SFc2_robot_diffInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i21;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i21, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i21;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc2_robot_diffInstanceStruct *)chartInstanceVoid;
  c2_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_robot_diffInstanceStruct
  *chartInstance, const mxArray *c2_is_active_c2_robot_diff, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_is_active_c2_robot_diff), &c2_thisId);
  sf_mex_destroy(&c2_is_active_c2_robot_diff);
  return c2_y;
}

static uint8_T c2_h_emlrt_marshallIn(SFc2_robot_diffInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_robot_diffInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c2_robot_diff_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1926503199U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3058871802U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3612818279U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1343897646U);
}

mxArray *sf_c2_robot_diff_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BczmfQ4ObeNZQv9ccBZmUD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(3);
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

static const mxArray *sf_get_sim_state_info_c2_robot_diff(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"d_estado\",},{M[8],M[0],T\"is_active_c2_robot_diff\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_robot_diff_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_robot_diffInstanceStruct *chartInstance;
    chartInstance = (SFc2_robot_diffInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_robot_diffMachineNumber_,
           2,
           1,
           1,
           7,
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
          _SFD_SET_DATA_PROPS(1,1,1,0,"X_target");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Y_target");
          _SFD_SET_DATA_PROPS(3,2,0,1,"d_estado");
          _SFD_SET_DATA_PROPS(4,1,1,0,"X");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Y");
          _SFD_SET_DATA_PROPS(6,1,1,0,"theta");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1279);
        _SFD_CV_INIT_EML_IF(0,1,0,530,573,615,1275);

        {
          static int condStart[] = { 534, 556 };

          static int condEnd[] = { 550, 572 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,533,573,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_clock;
          real_T *c2_X_target;
          real_T *c2_Y_target;
          real_T *c2_X;
          real_T *c2_Y;
          real_T *c2_theta;
          real_T (*c2_d_estado)[3];
          c2_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c2_Y = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_X = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_d_estado = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_Y_target = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_X_target = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_clock = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_clock);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_X_target);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_Y_target);
          _SFD_SET_DATA_VALUE_PTR(3U, *c2_d_estado);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_X);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_Y);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_theta);
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
      2, "dworkChecksum");
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

static void sf_opaque_initialize_c2_robot_diff(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc2_robot_diffInstanceStruct*) chartInstanceVar
    )->S);
  chart_debug_initialization(((SFc2_robot_diffInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_robot_diff((SFc2_robot_diffInstanceStruct*)
    chartInstanceVar);
  initialize_c2_robot_diff((SFc2_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_robot_diff(void *chartInstanceVar)
{
  enable_c2_robot_diff((SFc2_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_robot_diff(void *chartInstanceVar)
{
  disable_c2_robot_diff((SFc2_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_robot_diff(void *chartInstanceVar)
{
  sf_c2_robot_diff((SFc2_robot_diffInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c2_robot_diff(void *chartInstanceVar)
{
  ext_mode_exec_c2_robot_diff((SFc2_robot_diffInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_robot_diff(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_robot_diff
    ((SFc2_robot_diffInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_robot_diff();/* state var info */
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

extern void sf_internal_set_sim_state_c2_robot_diff(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_robot_diff();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_robot_diff((SFc2_robot_diffInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_robot_diff(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_robot_diff(S);
}

static void sf_opaque_set_sim_state_c2_robot_diff(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_robot_diff(S, st);
}

static void sf_opaque_terminate_c2_robot_diff(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_robot_diffInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_robot_diff((SFc2_robot_diffInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_robot_diff_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_robot_diff((SFc2_robot_diffInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_robot_diff(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_robot_diff((SFc2_robot_diffInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c2_robot_diff_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c2_robot_diff\",T\"is_active_c2_robot_diff\"}}"
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

static void mdlSetWorkWidths_c2_robot_diff(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_robot_diff_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,2,6);
      sf_mark_chart_reusable_outputs(S,infoStruct,2,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(528671553U));
  ssSetChecksum1(S,(2161659944U));
  ssSetChecksum2(S,(2061758606U));
  ssSetChecksum3(S,(1464633252U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_robot_diff(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_robot_diff(SimStruct *S)
{
  SFc2_robot_diffInstanceStruct *chartInstance;
  chartInstance = (SFc2_robot_diffInstanceStruct *)malloc(sizeof
    (SFc2_robot_diffInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_robot_diffInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_robot_diff;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_robot_diff;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_robot_diff;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_robot_diff;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_robot_diff;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_robot_diff;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_robot_diff;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_robot_diff;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_robot_diff;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_robot_diff;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_robot_diff;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c2_robot_diff;
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

void c2_robot_diff_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_robot_diff(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_robot_diff(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_robot_diff(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_robot_diff_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
