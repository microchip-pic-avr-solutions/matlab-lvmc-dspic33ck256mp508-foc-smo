%% ************************************************************************
% Model         :   PMSM Field Oriented Control
% Description   :   Set Parameters for PMSM Field Oriented Control
% File name     :   mcb_pmsm_foc_sensorless_dsPIC33_data.m
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

%% Set data type for controller & code-gen
dataType = fixdt(1,16,14);    % Fixed point code-generation
dataType2 = fixdt(1,16,12);    % Fixed point code-generation
% dataType = 'single';            % Floating point code-generation
% dataType2 = 'single';            % Floating point code-generation

%% System Parameters
% Set motor parameters

%Long Hurst Motor (Uncomment while using this motor from line below)
pmsm.model  = 'Hurst 300';      %           // Manufacturer Model Number
pmsm.sn     = '123456';         %           // Manufacturer Model Number
pmsm.p = 5;                     %           // Pole Pairs for the motor
pmsm.Rs = 0.285;                %Ohm        // Stator Resistor
pmsm.Ld = 2.8698e-4;              %H          // D-axis inductance value
pmsm.Lq = 2.8698e-4;              %H          // Q-axis inductance value
pmsm.Ke = 7.3425;               %Bemf Const	// Vline_peak/krpm
pmsm.Kt = 0.274;                %Nm/A       // Torque constant
pmsm.J = 7.061551833333e-6;     %Kg-m2      // Inertia in SI units
pmsm.B = 2.636875217824e-6;     %Kg-m2/s    // Friction Co-efficient
pmsm.I_rated= 3.42*sqrt(2);     %A      	// Rated current (phase-peak)
pmsm.QEPSlits = 1000;           %           // QEP Encoder Slits
pmsm.N_max  = 2000;             %rpm        // Max speed
pmsm.FluxPM     = (pmsm.Ke)/(sqrt(3)*2*pi*1000*pmsm.p/60); %PM flux computed from Ke
pmsm.T_rated    = (3/2)*pmsm.p*pmsm.FluxPM*pmsm.I_rated;   %Get T_rated from I_rated

%Short Hurst Motor (Uncomment while using this motor from line below)
% pmsm.model  = 'Short Hurst';    %           // Manufacturer Model Number
% pmsm.sn     = '123456';         %           // Manufacturer Model Number
% pmsm.p = 5;                     %           // Pole Pairs for the motor
% pmsm.Rs = 2.8;                  %Ohm        // Stator Resistor
% pmsm.Ld = 0.002423;             %H          // D-axis inductance value
% pmsm.Lq = pmsm.Ld;              %H          // Q-axis inductance value
% pmsm.Ke = 7.24;                 %Bemf Const	// Vline_peak/krpm
% pmsm.Kt = 0.03;                %Nm/A       // Torque constant
% pmsm.J = 5.5e-6;     %Kg-m2      // Inertia in SI units
% pmsm.B = 2.636875217824e-6/2;     %Kg-m2/s    // Friction Co-efficient
% pmsm.I_rated= 1.2*sqrt(2);     %A      	// Rated current (phase-peak)
% pmsm.QEPSlits = 1000;           %           // QEP Encoder Slits
% pmsm.N_max  = 2000;             %rpm        // Max speed
% pmsm.FluxPM     = (pmsm.Ke)/(sqrt(3)*2*pi*1000*pmsm.p/60); %PM flux computed from Ke
% pmsm.T_rated    = (3/2)*pmsm.p*pmsm.FluxPM*pmsm.I_rated;   %Get T_rated from I_rated

%Linix Motor (Uncomment while using this motor from line below)
% pmsm.model  = 'Linix';          %           // Manufacturer Model Number
% pmsm.sn     = '45ZWN24-40';     %           // Manufacturer Model Number
% pmsm.p = 2;                     %           // Pole Pairs for the motor
% pmsm.Rs = 0.569240;             %Ohm        // Stator Resistor
% pmsm.Ld = 0.00039;              %H          // D-axis inductance value
% pmsm.Lq = 0.00039;              %H          // Q-axis inductance value
% pmsm.Ke = 2.97;               %Bemf Const	// Vline_peak/krpm
% pmsm.Kt = 0.03;                %Nm/A       // Torque constant
% pmsm.J = 3.86e-6;     %Kg-m2      // Inertia in SI units
% pmsm.B = 11.09e-6;     %Kg-m2/s    // Friction Co-efficient
% pmsm.I_rated= 2.2*sqrt(2);     %A      	// Rated current (phase-peak)
% pmsm.QEPSlits = 1000;           %           // QEP Encoder Slits
% pmsm.N_max  = 4000;             %rpm        // Max speed
% pmsm.FluxPM     = (pmsm.Ke)/(sqrt(3)*2*pi*1000*pmsm.p/60); %PM flux computed from Ke
% pmsm.T_rated    = (3/2)*pmsm.p*pmsm.FluxPM*pmsm.I_rated;   %Get T_rated from I_rated


%% Inverter parameters

inverter.model         = 'LVMC';         % 		// Manufacturer Model Number
inverter.sn            = 'INV_XXXX';         		% 		// Manufacturer Serial Number
inverter.V_dc          = 24;       					%V      // DC Link Voltage of the Inverter
inverter.ISenseMax     = 21.85; 					%Amps   // Max current that can be measured
inverter.I_trip        = 10;                  		%Amps   // Max current for trip
inverter.Rds_on        = 1e-3;                      %Ohms   // Rds ON
inverter.Rshunt        = 0.01;                     %Ohms   // Rshunt
inverter.R_board        = inverter.Rds_on + inverter.Rshunt/3;  %Ohms
%Note: inverter.I_max = 1.65V/(Rshunt*10V/V) for 3.3V ADC with offset of 1.65V
%This is modified to match 3V ADC with 1.65V offset value for %LaunchXL-F28379D
inverter.MaxADCCnt     = 4095;      				%Counts // ADC Counts Max Value
inverter.invertingAmp  = -1;                        % 		//Non inverting current measurement amplifier
inverter.deadtime      = 1e-9;

%% Derive Characteristics
pmsm.N_base = mcb_getBaseSpeed(pmsm,inverter); %rpm // Base speed of motor at given Vdc
% mcb_getCharacteristics(pmsm,inverter);

%% PU System details // Set base values for pu conversion

PU_System = mcb_SetPUSystem(pmsm,inverter);

%% Controller design // Get ballpark values!
% Get PI Gains
PI_params = mcb.internal.SetControllerParameters(pmsm,inverter,PU_System,T_pwm,Ts,Ts_speed);

%Updating delays for simulation
PI_params.delay_Currents    = int32(Ts/Ts_simulink);
PI_params.delay_Position    = int32(Ts/Ts_simulink);
PI_params.delay_Speed       = int32(Ts_speed/Ts_simulink);
PI_params.delay_Speed1       = (PI_params.delay_IIR + 0.5*Ts)/Ts_speed;

% mcb_getControlAnalysis(pmsm,inverter,PU_System,PI_params,Ts,Ts_speed);

%% Open loop reference values
T_Ref_openLoop          = 1;                    % Sec // Time for open-loop start-up
Speed_openLoop          = 500;                  % PU  // Per-Unit speed referene for open-loop start-up
%Vd_Ref_openLoop_PU      = Speed_openLoop_PU;    % Use 1.2x for Dyno setup and 1x for others