%% ************************************************************************
% Model         :   Sensorless Field Oriented Control of PMSM Using SMO
% Description   :   Set Parameters for Sensorless FOC of PMSM Using SMO
% File name     :   dsPIC33CK256MP508_SMO_LVMC_data.m
% Copyright 2022 Microchip Technology Inc.

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

%% System Parameters
% Set motor parameters

pmsm.model  = 'Hurst 300';      %           // Manufacturer Model Number
pmsm.sn     = '123456';         %           // Manufacturer Model Number
pmsm.p  = 5;                    %           // Pole Pairs for the motor
pmsm.Rs = 0.285;                %Ohm        // Stator Resistor
pmsm.Ld = 2.8698e-4;            %H          // D-axis inductance value
pmsm.Lq = 2.8698e-4;            %H          // Q-axis inductance value
pmsm.Ke = 7.3425;               %Bemf Const	// Vline_peak/krpm
pmsm.Kt = 0.274;                %Nm/A       // Torque constant
pmsm.J = 7.061551833333e-6;     %Kg-m2      // Inertia in SI units
pmsm.B = 2.636875217824e-6;     %Kg-m2/s    // Friction Co-efficient
pmsm.I_rated  = 3.42*sqrt(2);   %A      	// Rated current (phase-peak)
pmsm.N_max    = 2000;           %rpm        // Max speed
pmsm.FluxPM   = (pmsm.Ke)/(sqrt(3)*2*pi*1000*pmsm.p/60); %PM flux computed from Ke
pmsm.T_rated  = (3/2)*pmsm.p*pmsm.FluxPM*pmsm.I_rated;   %Get T_rated from I_rated

%% Inverter parameters

inverter.model         = 'dsPIC33CK_LVMC';          % 		// Manufacturer Model Number
inverter.sn            = 'INV_XXXX';         		% 		// Manufacturer Serial Number
inverter.V_dc          = 24;       					%V      // DC Link Voltage of the Inverter
inverter.ISenseMax     = 21.85; 					%Amps   // Max current that can be measured
inverter.I_trip        = 10;                  		%Amps   // Max current for trip
inverter.Rds_on        = 1e-3;                      %Ohms   // Rds ON
inverter.Rshunt        = 0.01;                      %Ohms   // Rshunt
inverter.R_board       = inverter.Rds_on + inverter.Rshunt/3;  %Ohms
inverter.MaxADCCnt     = 4095;      				%Counts // ADC Counts Max Value
inverter.invertingAmp  = -1;                        % 		// Non inverting current measurement amplifier
inverter.deadtime      = 1e-6;                      %sec    // Deadtime for the PWM 
inverter.OpampFb_Rf    = 4.02e3;                    %Ohms   // Opamp Feedback resistance for current measurement
inverter.opampInput_R  = 532;                       %Ohms   // Opamp Input resistance for current measurement
inverter.opamp_Gain    = inverter.OpampFb_Rf/inverter.opampInput_R; % // Opamp Gain used for current measurement

%% Derive Characteristics
pmsm.N_base = mcb_getBaseSpeed(pmsm,inverter); %rpm // Base speed of motor at given Vdc

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

%% Open loop reference values
T_Ref_openLoop          = 1;                    % Sec // Time for open-loop start-up
Speed_Ref_openLoop      = 500;                  % RPM // Speed referene for open-loop start-up
Iq_Ref_openLoop         = 0.75;                 % A   // Iq referene for open-loop start-up