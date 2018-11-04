/*
 * robot_diff_dt.h
 *
 * Code generation for model "robot_diff.mdl".
 *
 * Model version              : 1.170
 * Simulink Coder version : 8.1 (R2011b) 08-Jul-2011
 * C source code generated on : Thu May 12 12:37:54 2016
 *
 * Target selection: quarc_linux_verdex.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_roomba),
  sizeof(t_card)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_roomba",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&robot_diff_B.Clock), 0, 0, 22 },

  { (char_T *)(&robot_diff_B.DataTypeConversion2), 4, 0, 2 }
  ,

  { (char_T *)(&robot_diff_DWork.A), 0, 0, 1 },

  { (char_T *)(&robot_diff_DWork.RoombaInitialize_Roomba), 14, 0, 1 },

  { (char_T *)(&robot_diff_DWork.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&robot_diff_DWork.TransportDelay2_RWORK.modelTStart), 0, 0, 3 },

  { (char_T *)(&robot_diff_DWork.TransportDelay2_PWORK.TUbufferPtrs[0]), 11, 0,
    20 },

  { (char_T *)(&robot_diff_DWork.sfEvent), 6, 0, 5 },

  { (char_T *)(&robot_diff_DWork.TransportDelay2_IWORK.Tail), 10, 0, 3 },

  { (char_T *)(&robot_diff_DWork.is_active_c4_robot_diff), 3, 0, 5 },

  { (char_T *)(&robot_diff_DWork.isStable), 8, 0, 10 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  11U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&robot_diff_P.HILInitialize_OOStart), 0, 0, 17 },

  { (char_T *)(&robot_diff_P.HILInitialize_DOWatchdog), 6, 0, 5 },

  { (char_T *)(&robot_diff_P.HILInitialize_AIChannels[0]), 7, 0, 21 },

  { (char_T *)(&robot_diff_P.ids_Value[0]), 3, 0, 5 },

  { (char_T *)(&robot_diff_P.HILInitialize_Active), 8, 0, 37 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] robot_diff_dt.h */
