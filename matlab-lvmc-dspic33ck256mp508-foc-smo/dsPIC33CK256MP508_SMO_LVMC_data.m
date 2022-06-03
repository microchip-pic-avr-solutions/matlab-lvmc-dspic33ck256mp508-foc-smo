%% ************************************************************************
% Model         :   PMSM Field Oriented Control
% Description   :   Set Parameters for PMSM Field Oriented Control
% File name     :   mcb_pmsm_foc_qep_f28069LaunchPad_data.m
% Copyright 2020 The MathWorks, Inc.

%% Simulation Parameters

%% Set PWM Switching frequency
PWM_frequency 	= 20e3;    %Hz          // converter s/w freq
T_pwm           = 1/PWM_frequency;  %s  // PWM switching time period

%% Set Sample Times
Ts          	= T_pwm;        %sec        // simulation time step for controller
Ts_simulink     = T_pwm/2;      %sec        // simulation time step for model simulation
Ts_motor        = T_pwm/2;      %Sec        // Simulation sample time
Ts_inverter     = T_pwm/2;      %sec        // simulation time step for average value inverter
Ts_speed        = 30*Ts;        %Sec        // Sample time for speed controller
% Ts_speed        = 10e-3;      %Sec        // Sample time for speed controller

%% Set data type for controller & code-gen
dataType = fixdt(1,16,14);    % Fixed point code-generation
dataType2 = fixdt(1,16,12);    % Fixed point code-generation
% dataType = 'single';            % Floating point code-generation
% dataType2 = 'single';            % Floating point code-generation

%% System Parameters
% Set motor parameters
pmsm.model  = 'Hurst';          %           // Manufacturer Model Number
pmsm.sn     = '123456';         %           // Manufacturer Model Number
pmsm.p = 5;                     %           // Pole Pairs for the motor
pmsm.Rs = 0.4758;               %Ohm        // Stator Resistor
pmsm.Ld = 2.8698e-4;            %H          // D-axis inductance value
pmsm.Lq = 2.8470e-4;            %H          // Q-axis inductance value
pmsm.Ke = 7.3425;               %Bemf Const	// Vline_peak/krpm
pmsm.J = 2.0148e-5;             %Kg-m2      // Inertia in SI units
pmsm.B = 7.0130e-5;             %Kg-m2/s    // Friction Co-efficient
pmsm.I_rated= 3.4;              %A      	// Rated current (phase-peak)
pmsm.QEPSlits = 1000;           %           // QEP Encoder Slits
pmsm.N_base = 2800;             %rpm        // Base speed
pmsm.N_max  = 2000;             %rpm        // Max speed
pmsm.FluxPM     = (pmsm.Ke)/(sqrt(3)*2*pi*1000*pmsm.p/60); %PM flux computed from Ke
pmsm.T_rated    = (3/2)*pmsm.p*pmsm.FluxPM*pmsm.I_rated;   %Get T_rated from I_rated

%% Inverter parameters

inverter.model         = 'dsPIC33CK LVMC';               % 		// Manufacturer Model Number
inverter.sn            = 'INV_XXXX';         		% 		// Manufacturer Serial Number
inverter.V_dc          = 24;       					%V      // DC Link Voltage of the Inverter
inverter.I_max         = 4.4; 						%Amps   // Max current that can be measured
inverter.I_trip        = 3.5;                 		%Amps   // Max current for trip
inverter.Rds_on        = 1e-3;                      %Ohms   // Rds ON
inverter.Rshunt        = 0.025;                     %Ohms   // Rshunt
inverter.R_board        = inverter.Rds_on + inverter.Rshunt/3;  %Ohms
%Note: inverter.I_max = 1.65V/(Rshunt*10V/V) for 3.3V ADC with offset of 1.65V
%This is modified to match 3V ADC with 1.65V offset value for %LaunchXL-F28379D
inverter.MaxADCCnt     = 4095;      				%Counts // ADC Counts Max Value
inverter.invertingAmp  = -1;                        % 		//Non inverting current measurement amplifier

%% Derive Characteristics
pmsm.N_base = mcb_getBaseSpeed(pmsm,inverter); %rpm // Base speed of motor at given Vdc
% mcb_getCharacteristics(pmsm,inverter);

%% PU System details // Set base values for pu conversion

PU_System = mcb_SetPUSystem(pmsm,inverter);

%% Controller design // Get ballpark values!

PI_params = mcb.internal.SetControllerParameters(pmsm,inverter,PU_System,T_pwm,Ts,3*Ts_speed);

%Updating delays for simulation
PI_params.delay_Currents    = int32(Ts/Ts_simulink);
PI_params.delay_Position    = int32(Ts/Ts_simulink);
PI_params.delay_Speed       = int32(Ts_speed/Ts_simulink);
PI_params.delay_Speed1       = (PI_params.delay_IIR + 0.5*Ts)/Ts_speed;

% mcb_getControlAnalysis(pmsm,inverter,PU_System,PI_params,Ts,Ts_speed);