/************************************************************************************************
* MPLAB 16-Bit Device Blocks for Simulink                                                       *
*                                                                                               *
* Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892                     *
*         Forum: https://www.microchip.com/forums/f192.aspx                                     *
*         Wiki:  http://microchipdeveloper.com/simulink:start                                   *
*                                                                                               *
* Author:        Lubin Kerhuel                                                                  *
* Company:       Microchip Technology Inc                                                       * 
* Filename:      MCHP_MACRO_Saturate.h                                                          *
* Date:          16/02/2017                                                                     *
* File Version:  1.00                                                                           *
*************************************************************************************************

 SOFTWARE LICENSE AGREEMENT:
 Microchip Technology Incorporated ("Microchip") retains all ownership and 
 intellectual property rights in the code accompanying this message and in all 
 derivatives hereto.  You may use this code, and any derivatives created by 
 any person or entity by or on your behalf, exclusively with Microchip's
 proprietary products.  Your acceptance and/or use of this code constitutes 
 agreement to the terms and conditions of this notice.

 CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO 
 WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED 
 TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A 
 PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP'S 
 PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 

 YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE, WHETHER 
 IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), 
 STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, 
 PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF 
 ANY KIND WHATSOEVER RELATED TO THE CODE, HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN 
 ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT 
 ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO 
 THIS CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP SPECIFICALLY TO 
 HAVE THIS CODE DEVELOPED.

 You agree that you are solely responsible for testing the code and 
 determining its suitability.  Microchip has no obligation to modify, test, 
 certify, or support the code.

*************************************************************************************************/
#ifndef MCHP_SATURATE_FUNCTIONS_H
#define	MCHP_SATURATE_FUNCTIONS_H


#define MCHP_SATURATE_S32_TO_S16(u1)                                                                                                    		\
({                                                                                                                                      		\
long int temp32MCHP;                       /* Use 32bit variable to store the input */                                         		\
int shiftMSW, shiftLSW;                    /* Use shiftLSW and shiftMSW to extract the MSbit(sign) of MSW and LSW*/            		\
temp32MCHP = (long int)u1;                          /* Store and cast the input into 32bit signed variable */                           		\
__asm__ volatile(                                                                                                                       		\
"LSR %[tmp32MCHP],#15,%[sftLSW]         \n\t"         /* Extract MSbit of LSW */                                                          		\
"LSR %d[tmp32MCHP],#15,%[sftMSW]        \n\t"         /* Extract MSbit of MSW */                                                          		\
"ADD %d[tmp32MCHP],%[sftLSW],%[sftLSW]  \n\t"         /* Add MSW with sign-bit value of LSW. This will check if all 17 Most Significant Bits are all zeros (Z flag will be set).  Reuse sftLSW as a dummy register to store temporary result of the addition (it's value will be discarded */ \
"MOV #0x7FFF,%[sftLSW]                  \n\t"         /* Reuse sftLSW to store Maximum value for saturation. Z STATUS FLAG won't be affected*/ 	\
"BTSS SR,#1                             \n\t"         /* Check if Z flag(STATUS REGISTER). If it's set, no saturation is required  */     		\
"ADD %[sftLSW],%[sftMSW],%[tmp32MCHP]   \n\t"         /* The output result will be saturate to 0x7FFF (MAX_s16) or 0x8000 (MIN_s16) depending on sign-bit value of the 32bit signed Input (stored into sftMSW variable) */    \
: [tmp32MCHP]"+r"(temp32MCHP),[sftMSW]"=&r"(shiftMSW),[sftLSW]"=&r"(shiftLSW)                           /* Output clobber list: "r" output operand uses a general register, "+" output this operand is both read and written by the instruction*/   \
:                                                                                                                                       		\
: "cc");                                            /* Instructions can alter the flags */                                              		\
(int)temp32MCHP;                                    /* Output the result of the expression */                                           		\
})


#define MCHP_SATURATE_U32_TO_U16(u1)                                                                                                    		\
({                                                                                                                                      		\
unsigned long int tmpMCHP;                                                                                                     		\
tmpMCHP = (unsigned long int)(u1);                                                                                                      		\
__asm__ volatile(                                                                                                                       		\
"CP0    %d[tempMCHP]                \n\t"           /* Compute MSW-0x0000 and update the Z flag of the STATUS register */               		\
"BTSS   SR,#1                       \n\t"           /* Test if Z flag is set. If Z = 1, no saturation required */                       		\
"MOV    #0xFFFF, %[tempMCHP]        \n\t"           /* Saturate the output result to MAX_UINT16 if required */                          		\
: [tempMCHP] "+r"(tmpMCHP)                          /* Output clobber list: "r" output operand uses a general register, "+" output this operand is both read and written by the instruction*/ \
:                                                                                                                                       		\
: "cc");                                            /* Instructions can alter the flags */                                              		\
(unsigned int)tmpMCHP;                              /* Output the result of the expression */                                           		\
}) 


#define MCHP_SATURATE_U32_TO_S16(u1)                                                                                                    		\
({                                                                                                                                      		\
unsigned long int tmpMCHP;                                                                                                     		\
int shiftLSW;                                                                                                                  		\
tmpMCHP = (unsigned long int)u1;                                                                                                        		\
__asm__ volatile(                                                                                                                       		\
"LSR %[tempMCHP],#15,%[sftLSW]              \n\t"     /* Arithmetic shift: Copy MSbit of LSW on all bits. Get either 0x0000 or 0xFFFF */  		\
"IOR %d[tempMCHP],%[sftLSW],%[sftLSW]       \n\t"     /* OR, if (MSB of LSW) or any bits of MSW set, then this is non zero */             		\
"BTSS SR,#1                                 \n\t"     /* Check if Z flag(STATUS REGISTER). If it's set, no saturation is required  */     		\
"MOV #0x7FFF,%[tempMCHP]                    \n\t"     /* Saturate to MAX_INT16 if Z STATUS flag was not set by the previous operation */  		\
: [tempMCHP]"+r"(tmpMCHP), [sftLSW]"=&r"(shiftLSW)     /* Output clobber list: "r" output operand uses a general register, "+" output this operand is both read and written by the instruction*/ \
:                                                   /* Input clobber list: "r" input operand uses general register,*/                   		\
: "cc");                                            /* Instructions can alter the flags */                                              		\
(int)tmpMCHP;                                       /* Output the result of the expression */                                           		\
})


#define MCHP_SATURATE_S32_TO_U16(u1)                                                                                                    		\
({                                                                                                                                      		\
long int tmpMCHP;                                                                                                              		\
int shiftMSW;                                                                                                                  		\
int MAXIMUM_SATURATION;                                                                                                        		\
tmpMCHP = (long int)u1;                                                                                                                 		\
MAXIMUM_SATURATION = 0xFFFF;                                                                                                            		\
__asm__ volatile(                                                                                                                       		\
"LSR %d[tempMCHP],#15,%[sftMSW]             \n\t"     /* Extract MSbit of LSW */                                                          		\
"CP0 %d[tempMCHP]                           \n\t"     /* Compute MSW-0x0000 and update the Z flag of the STATUS register */               		\
"BTSS SR,#1                                 \n\t"     /* Check if Z flag(STATUS REGISTER). If it's set, no saturation is required  */     		\
"ADD %[MAX_SAT],%[sftMSW],%[tempMCHP]       \n\t"     /* The output result will be saturate to 0xFFFF (MAX_U16) or 0x0000 (MIN_U16) depending on sign-bit value of the MSW (32bit signed Input) */ \
: [tempMCHP]"+r"(tmpMCHP), [sftMSW]"=&r"(shiftMSW)      /* Output clobber list: "r" output operand uses a general register, "+" output this operand is both read and written by the instruction*/ \
: [MAX_SAT]"r"(MAXIMUM_SATURATION)                 /* Input clobber list: "r" input operand uses general register,*/                   		\
: "cc");                                            /* Instructions can alter the flags */                                              		\
(int)tmpMCHP;                                       /* Output the result of the expression */                                           		\
})


#define MCHP_SATURATE_S32_TO_U32(u1)                                                                                                    		\
({                                                                                                                                      		\
long int tmpMCHP;                                                                                                              		\
unsigned long int MINIMUM_SATURATION = 0x00000000;                                                                             		\
tmpMCHP = (long int)u1;                                                                                                                 		\
__asm__ volatile(                                                                                                                       		\
"BTSC %d[tempMCHP],#15                      \n\t"     /* if saturation is required  */                                                    		\
"MOV.D %[MIN_SAT],%[tempMCHP]               \n\t"     /* Saturate output to zero if input is negative */                                  		\
: [tempMCHP]"+r"(tmpMCHP)                           /* Output clobber list: "r" output operand uses a general register, "+" output this operand is both read and written by the instruction*/ \
: [MIN_SAT]"r"(MINIMUM_SATURATION)                  /* Input clobber list: "r" input operand uses general register,*/                   		\
: "cc");                                            /* Output the result of the expression */                                           		\
tmpMCHP;                                                                                                                                		\
})



#define MCHP_SATURATE_U32_TO_S32(u1)                                                                                                    		\
({                                                                                                                                      		\
unsigned long int tmpMCHP;                                                                                                     		\
signed long int MAXIMUM_SATURATION = 0x7FFFFFFF;                                                                               		\
tmpMCHP = (signed long int)u1;                                                                                                          		\
__asm__ volatile(                                                                                                                       		\
"BTSC %d[tempMCHP],#15                  \n\t"     /* if saturation is required  */                                                        		\
"MOV.D %[MAX_SAT],%[tempMCHP]           \n\t"     /* Saturate output to MAX_INT32 (if input is < 0x7FFFFFFF) */                           		\
:[tempMCHP]"+r"(tmpMCHP)                        /* Output clobber list: "r" output operand uses a general register, "+" output this operand is both read and written by the instruction*/ \
:[MAX_SAT]"r"(MAXIMUM_SATURATION)               /* Input clobber list: "r" input operand uses general register,*/                       		\
: "cc");                                        /* Output the result of the expression */                                               		\
tmpMCHP;                                                                                                                                		\
}) 


#define MCHP_SATURATE_U16_TO_S16(u1)                                                                                                    		\
({                                                                                                                                      		\
int output;                                                                                                                    		\
output = (int) u1;                                                                                                                      		\
__asm__ volatile(                                                                                                                       		\
"BTSC %[out],#15                        \n\t"     /* if saturation is required  */                                                        		\
"MOV #0x7FFF,%[out]                     \n\t"     /* Saturate output to MAX_INT16 (if input is < 0x7FFF) */                               		\
:[out]"+r"(output)                              /* Output clobber list: "r" output operand uses a general register, "+" output this operand is both read and written by the instruction*/ \
:                                               /* Input clobber list: "r" input operand uses general register,*/                       		\
: "cc");                                        /* Output the result of the expression */                                               		\
output;                                                                                                                                 		\
})  


#define MCHP_SATURATE_S16_TO_U16(u1)                                                                                                    		\
({                                                                                                                                      		\
unsigned int output;                                                                                                           		\
output = (unsigned int)u1;                                                                                                              		\
__asm__ volatile(                                                                                                                       		\
"BTSC %[out],#15                        \n\t"     /* if saturation is required */                                                         		\
"MOV #0x0000,%[out]                     \n\t"     /* Saturate output to zero */                                                           		\
:[out]"+r"(output)                              /* Output clobber list: "r" output operand uses a general register, "+" output this operand is both read and written by the instruction*/ \
:                                                                                                                                       		\
: "cc");                                        /* Output the result of the expression */                                               		\
output;                                                                                                                                 		\
})    

#define MCHP_SATURATE_U16_TO_U8(u1)                                                                                                     		\
({                                                                                                                                      		\
unsigned int u16;                                                                                                              		\
unsigned char u8;                                                                                                              		\
u16 = (unsigned int)(u1);                                                                                                               		\
__asm__ volatile(                                                                                                                       		\
"LSR    %[in],#8,%[out]     \n\t"           /* Extract MSByte of u16 input */                                                           		\
"CP0.b  %[out]              \n\t"           /* Compute MSB-0x0000 and update the Z flag of the STATUS register */                       		\
"MOV    %[in],%[out]        \n\t"           /* Move LSByte of u16 into u8. MOV instruction won't affect SR flags */                     		\
"BTSS   SR,#1               \n\t"           /* Test if Z flag is set. If Z = 1, no saturation required */                               		\
"MOV.b  #0xFF,%[out]        \n\t"           /* Saturate the output result to MAX_UINT8 if required */                                   		\
: [out]"=&r"(u8)                             /* Output clobber list: "r" output operand uses a general register, "+" output this operand is both read and written by the instruction*/ \
: [in] "r"(u16)                                                                                                                         		\
: "cc");                                    /* Instructions can alter the flags */                                                      		\
(unsigned char)u8;                          /* Output the result of the expression */                                                   		\
}) 


#define MCHP_SATURATE_S16_TO_S8(u1)                                                                                                     		\
({                                                                                                                                      		\
int output = (int)u1;                                                                                                          		\
int MSByte,LSByte;                                                                                                             		\
int tempMCHP;                                                                                                                  		\
__asm__ volatile(                                                                                                                       		\
"LSR    %[out],#8,%[tmpMCHP]        \n\t"     /* Extract MSByte of s16 */                                                           			\
"LSR    %[out],#15,%[MSB]           \n\t"     /* Extract sign bit value of s16 */                                                     			\
"LSR    %[out],#7,%[LSB]            \n\t"     /* Prepare for sign bit extraction of LSByte */                                         			\
"AND    %[LSB],#0x01,%[LSB]         \n\t"     /* Extract sign bit value of LSByte */                                                   			\
"ADD.b  %[tmpMCHP],%[LSB],%[LSB]    \n\t"     /* Add MSByte with sign bit value of LSByte. This will check if all 8 Most Significant Bits are all zeros (Z flag will be set).  Reuse sftLSW as a dummy register to store temporary result of the addition (it's value will be discarded) */  \
"MOV.b  #0x7F,%[LSB]                \n\t"     /* Load MAX_s8 saturation value */                                                          		\
"BTSS SR,#1                         \n\t"     /* Check if Z flag(STATUS REGISTER). If it's set, no saturation is required  */             		\
"ADD.b %[LSB],%[MSB],%[out]         \n\t"     /* The output result will be saturate to 0x7F (MAX_s8) or 0x80 (MIN_s8) depending on sign-bit value of the 16bit signed Input */    \
: [MSB]"=&r"(MSByte),[LSB]"=&r"(LSByte),[tmpMCHP]"=&r"(tempMCHP),[out]"+r"(output)  /* Output clobber list: "r" output operand uses a general register, "+" output this operand is both read and written by the instruction*/ \
:                                                                                                                                       		\
: "cc");                                /* Instructions can alter the flags */                                                         			\
(signed char)output;                    /* Output the result of the expression */                                                       		\
}) 

#endif