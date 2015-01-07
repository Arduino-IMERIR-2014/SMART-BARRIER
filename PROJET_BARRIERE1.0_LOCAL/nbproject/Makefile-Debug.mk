#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=avr-gcc
CCC=avr-g++
CXX=avr-g++
FC=gfortran
AS=avr-as

# Macros
CND_PLATFORM=Arduino-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES=


# C Compiler Flags
CFLAGS=-Os -Wall -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=100

# CC Compiler Flags
CCFLAGS=-Os -Wall -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=100
CXXFLAGS=-Os -Wall -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=100

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/../../Liibarduino/dist/Debug/Arduino-Windows -lliibarduino -lm

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projet_barriere1.0.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projet_barriere1.0.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	avr-gcc -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projet_barriere1.0 ${OBJECTFILES} ${LDLIBSOPTIONS} -Os -Wl,--gc-sections -mmcu=atmega328p

${OBJECTDIR}/C_BOUTON.cpp.gch: C_BOUTON.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/../../../../../../Arduino/hardware/arduino/cores/arduino -I/../../../../../../Arduino/libraries/Servo -I/../../../../../../Arduino/libraries/Grove_LCD_RGB_Backlight_master -I/../../../../../../Arduino/libraries/Wire -I/../../../../../../Arduino/libraries/Wire/utility -I/../../../../../../Arduino/libraries/SoftwareSerial -MMD -MP -MF "$@.d" -o "$@" C_BOUTON.cpp

${OBJECTDIR}/C_BUZZER.cpp.gch: C_BUZZER.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/../../../../../../Arduino/hardware/arduino/cores/arduino -I/../../../../../../Arduino/libraries/Servo -I/../../../../../../Arduino/libraries/Grove_LCD_RGB_Backlight_master -I/../../../../../../Arduino/libraries/Wire -I/../../../../../../Arduino/libraries/Wire/utility -I/../../../../../../Arduino/libraries/SoftwareSerial -MMD -MP -MF "$@.d" -o "$@" C_BUZZER.cpp

${OBJECTDIR}/C_CAPTEUR_LUMIERE.cpp.gch: C_CAPTEUR_LUMIERE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/../../../../../../Arduino/hardware/arduino/cores/arduino -I/../../../../../../Arduino/libraries/Servo -I/../../../../../../Arduino/libraries/Grove_LCD_RGB_Backlight_master -I/../../../../../../Arduino/libraries/Wire -I/../../../../../../Arduino/libraries/Wire/utility -I/../../../../../../Arduino/libraries/SoftwareSerial -MMD -MP -MF "$@.d" -o "$@" C_CAPTEUR_LUMIERE.cpp

${OBJECTDIR}/C_CARTE.cpp.gch: C_CARTE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/../../../../../../Arduino/hardware/arduino/cores/arduino -I/../../../../../../Arduino/libraries/Servo -I/../../../../../../Arduino/libraries/Grove_LCD_RGB_Backlight_master -I/../../../../../../Arduino/libraries/Wire -I/../../../../../../Arduino/libraries/Wire/utility -I/../../../../../../Arduino/libraries/SoftwareSerial -MMD -MP -MF "$@.d" -o "$@" C_CARTE.cpp

${OBJECTDIR}/C_COMMUNICATION_USB.cpp.gch: C_COMMUNICATION_USB.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/../../../../../../Arduino/hardware/arduino/cores/arduino -I/../../../../../../Arduino/libraries/Servo -I/../../../../../../Arduino/libraries/Grove_LCD_RGB_Backlight_master -I/../../../../../../Arduino/libraries/Wire -I/../../../../../../Arduino/libraries/Wire/utility -I/../../../../../../Arduino/libraries/SoftwareSerial -MMD -MP -MF "$@.d" -o "$@" C_COMMUNICATION_USB.cpp

${OBJECTDIR}/C_ECRAN.cpp.gch: C_ECRAN.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/../../../../../../Arduino/hardware/arduino/cores/arduino -I/../../../../../../Arduino/libraries/Servo -I/../../../../../../Arduino/libraries/Grove_LCD_RGB_Backlight_master -I/../../../../../../Arduino/libraries/Wire -I/../../../../../../Arduino/libraries/Wire/utility -I/../../../../../../Arduino/libraries/SoftwareSerial -MMD -MP -MF "$@.d" -o "$@" C_ECRAN.cpp

${OBJECTDIR}/C_ENTREE.cpp.gch: C_ENTREE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/../../../../../../Arduino/hardware/arduino/cores/arduino -I/../../../../../../Arduino/libraries/Servo -I/../../../../../../Arduino/libraries/Grove_LCD_RGB_Backlight_master -I/../../../../../../Arduino/libraries/Wire -I/../../../../../../Arduino/libraries/Wire/utility -I/../../../../../../Arduino/libraries/SoftwareSerial -MMD -MP -MF "$@.d" -o "$@" C_ENTREE.cpp

${OBJECTDIR}/C_LED.cpp.gch: C_LED.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/../../../../../../Arduino/hardware/arduino/cores/arduino -I/../../../../../../Arduino/libraries/Servo -I/../../../../../../Arduino/libraries/Grove_LCD_RGB_Backlight_master -I/../../../../../../Arduino/libraries/Wire -I/../../../../../../Arduino/libraries/Wire/utility -I/../../../../../../Arduino/libraries/SoftwareSerial -MMD -MP -MF "$@.d" -o "$@" C_LED.cpp

${OBJECTDIR}/C_MOTEUR.cpp.gch: C_MOTEUR.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/../../../../../../Arduino/hardware/arduino/cores/arduino -I/../../../../../../Arduino/libraries/Servo -I/../../../../../../Arduino/libraries/Grove_LCD_RGB_Backlight_master -I/../../../../../../Arduino/libraries/Wire -I/../../../../../../Arduino/libraries/Wire/utility -I/../../../../../../Arduino/libraries/SoftwareSerial -MMD -MP -MF "$@.d" -o "$@" C_MOTEUR.cpp

${OBJECTDIR}/C_OBJET_ENTREE.cpp.gch: C_OBJET_ENTREE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/../../../../../../Arduino/hardware/arduino/cores/arduino -I/../../../../../../Arduino/libraries/Servo -I/../../../../../../Arduino/libraries/Grove_LCD_RGB_Backlight_master -I/../../../../../../Arduino/libraries/Wire -I/../../../../../../Arduino/libraries/Wire/utility -I/../../../../../../Arduino/libraries/SoftwareSerial -MMD -MP -MF "$@.d" -o "$@" C_OBJET_ENTREE.cpp

${OBJECTDIR}/C_OBJET_SORTIE.cpp.gch: C_OBJET_SORTIE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/../../../../../../Arduino/hardware/arduino/cores/arduino -I/../../../../../../Arduino/libraries/Servo -I/../../../../../../Arduino/libraries/Grove_LCD_RGB_Backlight_master -I/../../../../../../Arduino/libraries/Wire -I/../../../../../../Arduino/libraries/Wire/utility -I/../../../../../../Arduino/libraries/SoftwareSerial -MMD -MP -MF "$@.d" -o "$@" C_OBJET_SORTIE.cpp

${OBJECTDIR}/C_POTENTIOMETRE.cpp.gch: C_POTENTIOMETRE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/../../../../../../Arduino/hardware/arduino/cores/arduino -I/../../../../../../Arduino/libraries/Servo -I/../../../../../../Arduino/libraries/Grove_LCD_RGB_Backlight_master -I/../../../../../../Arduino/libraries/Wire -I/../../../../../../Arduino/libraries/Wire/utility -I/../../../../../../Arduino/libraries/SoftwareSerial -MMD -MP -MF "$@.d" -o "$@" C_POTENTIOMETRE.cpp

${OBJECTDIR}/C_SORTIE.cpp.gch: C_SORTIE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/../../../../../../Arduino/hardware/arduino/cores/arduino -I/../../../../../../Arduino/libraries/Servo -I/../../../../../../Arduino/libraries/Grove_LCD_RGB_Backlight_master -I/../../../../../../Arduino/libraries/Wire -I/../../../../../../Arduino/libraries/Wire/utility -I/../../../../../../Arduino/libraries/SoftwareSerial -MMD -MP -MF "$@.d" -o "$@" C_SORTIE.cpp

${OBJECTDIR}/main.cpp.gch: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/../../../../../../Arduino/hardware/arduino/cores/arduino -I/../../../../../../Arduino/libraries/Servo -I/../../../../../../Arduino/libraries/Grove_LCD_RGB_Backlight_master -I/../../../../../../Arduino/libraries/Wire -I/../../../../../../Arduino/libraries/Wire/utility -I/../../../../../../Arduino/libraries/SoftwareSerial -MMD -MP -MF "$@.d" -o "$@" main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projet_barriere1.0.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
