@echo Compiling Secondary core Image ...
@call "E:\bitbucket_work\matlab-lvmc-dspic33ck256mp508-foc-smo\dsPIC33CK256MP508_SMO_LVMC.X\dsPIC33CK256MP508_SMO_LVMC.bat"
@if exist dsPIC33CK256MP508_SMO_LVMC.elf (
    @echo ---
    @echo Compiling Master Image ...
    @cd /d D:\MATLAB\MPLABBlocksForSimulink+MotorControlBlockset\MCLV-2\dsPIC33CH512MP508_EXT_OPAMP_QEP_FOC\mcb_pmsm_foc_qep_dsPIC33CH512MP508_Master.X
    @call mcb_pmsm_foc_qep_dsPIC33CH512MP508_Master.bat
    @cd /d E:\bitbucket_work\matlab-lvmc-dspic33ck256mp508-foc-smo\dsPIC33CK256MP508_SMO_LVMC.X
) else (
    @echo Creating Secondary core image failed.
)
