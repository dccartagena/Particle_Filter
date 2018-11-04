  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (robot_diff_P)
    ;%
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% robot_diff_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robot_diff_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robot_diff_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robot_diff_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% robot_diff_P.HILInitialize_AOInitial
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% robot_diff_P.HILInitialize_AOFinal
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% robot_diff_P.HILInitialize_POFrequency
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% robot_diff_P.HILInitialize_POInitial
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% robot_diff_P.HILInitialize_POFinal
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% robot_diff_P.TransportDelay2_Delay
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% robot_diff_P.TransportDelay2_InitOutput
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% robot_diff_P.TransportDelay1_Delay
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% robot_diff_P.TransportDelay1_InitOutput
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% robot_diff_P.TransportDelay_Delay
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% robot_diff_P.TransportDelay_InitOutput
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% robot_diff_P.ids2_Value
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% robot_diff_P.DataStoreMemory_InitialValue
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% robot_diff_P.HILInitialize_DOWatchdog
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robot_diff_P.HILInitialize_EIInitial
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robot_diff_P.HILInitialize_POModes
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robot_diff_P.RoombaInitialize_SendBufferSize
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
	  ;% robot_diff_P.RoombaInitialize_ReceiveBufferS
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% robot_diff_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robot_diff_P.HILReadWrite_R_AnalogChannels
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 9;
	
	  ;% robot_diff_P.HILReadWrite_R_OtherChannels
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% robot_diff_P.ids_Value
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% robot_diff_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robot_diff_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robot_diff_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 28;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robot_diff_P.HILInitialize_CKStart
	  section.data(4).logicalSrcIdx = 29;
	  section.data(4).dtTransOffset = 3;
	
	  ;% robot_diff_P.HILInitialize_CKEnter
	  section.data(5).logicalSrcIdx = 30;
	  section.data(5).dtTransOffset = 4;
	
	  ;% robot_diff_P.HILInitialize_AIPStart
	  section.data(6).logicalSrcIdx = 31;
	  section.data(6).dtTransOffset = 5;
	
	  ;% robot_diff_P.HILInitialize_AIPEnter
	  section.data(7).logicalSrcIdx = 32;
	  section.data(7).dtTransOffset = 6;
	
	  ;% robot_diff_P.HILInitialize_AOPStart
	  section.data(8).logicalSrcIdx = 33;
	  section.data(8).dtTransOffset = 7;
	
	  ;% robot_diff_P.HILInitialize_AOPEnter
	  section.data(9).logicalSrcIdx = 34;
	  section.data(9).dtTransOffset = 8;
	
	  ;% robot_diff_P.HILInitialize_AOStart
	  section.data(10).logicalSrcIdx = 35;
	  section.data(10).dtTransOffset = 9;
	
	  ;% robot_diff_P.HILInitialize_AOEnter
	  section.data(11).logicalSrcIdx = 36;
	  section.data(11).dtTransOffset = 10;
	
	  ;% robot_diff_P.HILInitialize_AOTerminate
	  section.data(12).logicalSrcIdx = 37;
	  section.data(12).dtTransOffset = 11;
	
	  ;% robot_diff_P.HILInitialize_AOExit
	  section.data(13).logicalSrcIdx = 38;
	  section.data(13).dtTransOffset = 12;
	
	  ;% robot_diff_P.HILInitialize_AOReset
	  section.data(14).logicalSrcIdx = 39;
	  section.data(14).dtTransOffset = 13;
	
	  ;% robot_diff_P.HILInitialize_DOPStart
	  section.data(15).logicalSrcIdx = 40;
	  section.data(15).dtTransOffset = 14;
	
	  ;% robot_diff_P.HILInitialize_DOPEnter
	  section.data(16).logicalSrcIdx = 41;
	  section.data(16).dtTransOffset = 15;
	
	  ;% robot_diff_P.HILInitialize_DOStart
	  section.data(17).logicalSrcIdx = 42;
	  section.data(17).dtTransOffset = 16;
	
	  ;% robot_diff_P.HILInitialize_DOEnter
	  section.data(18).logicalSrcIdx = 43;
	  section.data(18).dtTransOffset = 17;
	
	  ;% robot_diff_P.HILInitialize_DOTerminate
	  section.data(19).logicalSrcIdx = 44;
	  section.data(19).dtTransOffset = 18;
	
	  ;% robot_diff_P.HILInitialize_DOExit
	  section.data(20).logicalSrcIdx = 45;
	  section.data(20).dtTransOffset = 19;
	
	  ;% robot_diff_P.HILInitialize_DOReset
	  section.data(21).logicalSrcIdx = 46;
	  section.data(21).dtTransOffset = 20;
	
	  ;% robot_diff_P.HILInitialize_EIPStart
	  section.data(22).logicalSrcIdx = 47;
	  section.data(22).dtTransOffset = 21;
	
	  ;% robot_diff_P.HILInitialize_EIPEnter
	  section.data(23).logicalSrcIdx = 48;
	  section.data(23).dtTransOffset = 22;
	
	  ;% robot_diff_P.HILInitialize_EIStart
	  section.data(24).logicalSrcIdx = 49;
	  section.data(24).dtTransOffset = 23;
	
	  ;% robot_diff_P.HILInitialize_EIEnter
	  section.data(25).logicalSrcIdx = 50;
	  section.data(25).dtTransOffset = 24;
	
	  ;% robot_diff_P.HILInitialize_POPStart
	  section.data(26).logicalSrcIdx = 51;
	  section.data(26).dtTransOffset = 25;
	
	  ;% robot_diff_P.HILInitialize_POPEnter
	  section.data(27).logicalSrcIdx = 52;
	  section.data(27).dtTransOffset = 26;
	
	  ;% robot_diff_P.HILInitialize_POStart
	  section.data(28).logicalSrcIdx = 53;
	  section.data(28).dtTransOffset = 27;
	
	  ;% robot_diff_P.HILInitialize_POEnter
	  section.data(29).logicalSrcIdx = 54;
	  section.data(29).dtTransOffset = 28;
	
	  ;% robot_diff_P.HILInitialize_POTerminate
	  section.data(30).logicalSrcIdx = 55;
	  section.data(30).dtTransOffset = 29;
	
	  ;% robot_diff_P.HILInitialize_POExit
	  section.data(31).logicalSrcIdx = 56;
	  section.data(31).dtTransOffset = 30;
	
	  ;% robot_diff_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 57;
	  section.data(32).dtTransOffset = 31;
	
	  ;% robot_diff_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 58;
	  section.data(33).dtTransOffset = 32;
	
	  ;% robot_diff_P.HILInitialize_DOInitial
	  section.data(34).logicalSrcIdx = 59;
	  section.data(34).dtTransOffset = 33;
	
	  ;% robot_diff_P.HILInitialize_DOFinal
	  section.data(35).logicalSrcIdx = 60;
	  section.data(35).dtTransOffset = 34;
	
	  ;% robot_diff_P.RoombaInitialize_Active
	  section.data(36).logicalSrcIdx = 61;
	  section.data(36).dtTransOffset = 35;
	
	  ;% robot_diff_P.HILReadWrite_Active
	  section.data(37).logicalSrcIdx = 62;
	  section.data(37).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (robot_diff_B)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% robot_diff_B.Clock
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robot_diff_B.DataTypeConversion
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robot_diff_B.ro
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% robot_diff_B.vl
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 11;
	
	  ;% robot_diff_B.vr
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 12;
	
	  ;% robot_diff_B.X
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 13;
	
	  ;% robot_diff_B.Y
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 14;
	
	  ;% robot_diff_B.theta
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 15;
	
	  ;% robot_diff_B.X_target
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 16;
	
	  ;% robot_diff_B.Y_target
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 17;
	
	  ;% robot_diff_B.K_new
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 18;
	
	  ;% robot_diff_B.d_estado
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% robot_diff_B.DataTypeConversion2
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robot_diff_B.DataTypeConversion1
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (robot_diff_DWork)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% robot_diff_DWork.A
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% robot_diff_DWork.RoombaInitialize_Roomba
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% robot_diff_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% robot_diff_DWork.TransportDelay2_RWORK.modelTStart
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robot_diff_DWork.TransportDelay1_RWORK.modelTStart
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robot_diff_DWork.TransportDelay_RWORK.modelTStart
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% robot_diff_DWork.TransportDelay2_PWORK.TUbufferPtrs
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robot_diff_DWork.TransportDelay1_PWORK.TUbufferPtrs
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 2;
	
	  ;% robot_diff_DWork.TransportDelay_PWORK.TUbufferPtrs
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 4;
	
	  ;% robot_diff_DWork.ToWorkspace_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 6;
	
	  ;% robot_diff_DWork.ToWorkspace1_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 7;
	
	  ;% robot_diff_DWork.ToWorkspace11_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 8;
	
	  ;% robot_diff_DWork.ToWorkspace12_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 9;
	
	  ;% robot_diff_DWork.ToWorkspace2_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 10;
	
	  ;% robot_diff_DWork.ToWorkspace3_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 11;
	
	  ;% robot_diff_DWork.ToWorkspace4_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 12;
	
	  ;% robot_diff_DWork.ToWorkspace5_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 16;
	  section.data(11).dtTransOffset = 13;
	
	  ;% robot_diff_DWork.HILReadWrite_PWORK
	  section.data(12).logicalSrcIdx = 17;
	  section.data(12).dtTransOffset = 14;
	
	  ;% robot_diff_DWork.ToWorkspace10_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 18;
	  section.data(13).dtTransOffset = 15;
	
	  ;% robot_diff_DWork.ToWorkspace6_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 19;
	  section.data(14).dtTransOffset = 16;
	
	  ;% robot_diff_DWork.ToWorkspace7_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 20;
	  section.data(15).dtTransOffset = 17;
	
	  ;% robot_diff_DWork.ToWorkspace8_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 21;
	  section.data(16).dtTransOffset = 18;
	
	  ;% robot_diff_DWork.ToWorkspace9_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 22;
	  section.data(17).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% robot_diff_DWork.sfEvent
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robot_diff_DWork.sfEvent_p
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robot_diff_DWork.sfEvent_g
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robot_diff_DWork.sfEvent_a
	  section.data(4).logicalSrcIdx = 26;
	  section.data(4).dtTransOffset = 3;
	
	  ;% robot_diff_DWork.sfEvent_n
	  section.data(5).logicalSrcIdx = 27;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% robot_diff_DWork.TransportDelay2_IWORK.Tail
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robot_diff_DWork.TransportDelay1_IWORK.Tail
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robot_diff_DWork.TransportDelay_IWORK.Tail
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% robot_diff_DWork.is_active_c4_robot_diff
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robot_diff_DWork.is_active_c3_robot_diff
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robot_diff_DWork.is_active_c1_robot_diff
	  section.data(3).logicalSrcIdx = 33;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robot_diff_DWork.is_active_c5_robot_diff
	  section.data(4).logicalSrcIdx = 34;
	  section.data(4).dtTransOffset = 3;
	
	  ;% robot_diff_DWork.is_active_c2_robot_diff
	  section.data(5).logicalSrcIdx = 35;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% robot_diff_DWork.isStable
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robot_diff_DWork.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robot_diff_DWork.isStable_i
	  section.data(3).logicalSrcIdx = 38;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robot_diff_DWork.doneDoubleBufferReInit_l
	  section.data(4).logicalSrcIdx = 39;
	  section.data(4).dtTransOffset = 3;
	
	  ;% robot_diff_DWork.isStable_l
	  section.data(5).logicalSrcIdx = 40;
	  section.data(5).dtTransOffset = 4;
	
	  ;% robot_diff_DWork.doneDoubleBufferReInit_l1
	  section.data(6).logicalSrcIdx = 41;
	  section.data(6).dtTransOffset = 5;
	
	  ;% robot_diff_DWork.isStable_g
	  section.data(7).logicalSrcIdx = 42;
	  section.data(7).dtTransOffset = 6;
	
	  ;% robot_diff_DWork.doneDoubleBufferReInit_f
	  section.data(8).logicalSrcIdx = 43;
	  section.data(8).dtTransOffset = 7;
	
	  ;% robot_diff_DWork.isStable_f
	  section.data(9).logicalSrcIdx = 44;
	  section.data(9).dtTransOffset = 8;
	
	  ;% robot_diff_DWork.doneDoubleBufferReInit_l5
	  section.data(10).logicalSrcIdx = 45;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1042964536;
  targMap.checksum1 = 2800824690;
  targMap.checksum2 = 4166025375;
  targMap.checksum3 = 2112424193;

