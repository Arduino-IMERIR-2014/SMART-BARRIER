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
RANLIB=avr-ranlib
CC=avr-gcc
CCC=avr-g++
CXX=avr-g++
FC=gfortran
AS=avr-as
AR=avr-ar

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
OBJECTFILES= \
	${OBJECTDIR}/_ext/389602837/WInterrupts.o \
	${OBJECTDIR}/_ext/31579608/malloc.o \
	${OBJECTDIR}/_ext/31579608/realloc.o \
	${OBJECTDIR}/_ext/389602837/wiring.o \
	${OBJECTDIR}/_ext/389602837/wiring_analog.o \
	${OBJECTDIR}/_ext/389602837/wiring_digital.o \
	${OBJECTDIR}/_ext/389602837/wiring_pulse.o \
	${OBJECTDIR}/_ext/389602837/wiring_shift.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libliibarduino.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libliibarduino.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libliibarduino.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libliibarduino.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libliibarduino.a

${OBJECTDIR}/_ext/389602837/CDC.cpp.gch: ../../../../../Arduino/hardware/arduino/cores/arduino/CDC.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o "$@" ../../../../../Arduino/hardware/arduino/cores/arduino/CDC.cpp

${OBJECTDIR}/_ext/389602837/HID.cpp.gch: ../../../../../Arduino/hardware/arduino/cores/arduino/HID.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o "$@" ../../../../../Arduino/hardware/arduino/cores/arduino/HID.cpp

${OBJECTDIR}/_ext/389602837/HardwareSerial.cpp.gch: ../../../../../Arduino/hardware/arduino/cores/arduino/HardwareSerial.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o "$@" ../../../../../Arduino/hardware/arduino/cores/arduino/HardwareSerial.cpp

${OBJECTDIR}/_ext/389602837/IPAddress.cpp.gch: ../../../../../Arduino/hardware/arduino/cores/arduino/IPAddress.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o "$@" ../../../../../Arduino/hardware/arduino/cores/arduino/IPAddress.cpp

${OBJECTDIR}/_ext/389602837/Print.cpp.gch: ../../../../../Arduino/hardware/arduino/cores/arduino/Print.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o "$@" ../../../../../Arduino/hardware/arduino/cores/arduino/Print.cpp

${OBJECTDIR}/_ext/389602837/Stream.cpp.gch: ../../../../../Arduino/hardware/arduino/cores/arduino/Stream.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o "$@" ../../../../../Arduino/hardware/arduino/cores/arduino/Stream.cpp

${OBJECTDIR}/_ext/389602837/Tone.cpp.gch: ../../../../../Arduino/hardware/arduino/cores/arduino/Tone.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o "$@" ../../../../../Arduino/hardware/arduino/cores/arduino/Tone.cpp

${OBJECTDIR}/_ext/389602837/USBCore.cpp.gch: ../../../../../Arduino/hardware/arduino/cores/arduino/USBCore.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o "$@" ../../../../../Arduino/hardware/arduino/cores/arduino/USBCore.cpp

${OBJECTDIR}/_ext/389602837/WInterrupts.o: ../../../../../Arduino/hardware/arduino/cores/arduino/WInterrupts.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/389602837/WInterrupts.o ../../../../../Arduino/hardware/arduino/cores/arduino/WInterrupts.c

${OBJECTDIR}/_ext/389602837/WMath.cpp.gch: ../../../../../Arduino/hardware/arduino/cores/arduino/WMath.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o "$@" ../../../../../Arduino/hardware/arduino/cores/arduino/WMath.cpp

${OBJECTDIR}/_ext/389602837/WString.cpp.gch: ../../../../../Arduino/hardware/arduino/cores/arduino/WString.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o "$@" ../../../../../Arduino/hardware/arduino/cores/arduino/WString.cpp

${OBJECTDIR}/_ext/31579608/malloc.o: ../../../../../Arduino/hardware/arduino/cores/arduino/avr-libc/malloc.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/31579608
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/31579608/malloc.o ../../../../../Arduino/hardware/arduino/cores/arduino/avr-libc/malloc.c

${OBJECTDIR}/_ext/31579608/realloc.o: ../../../../../Arduino/hardware/arduino/cores/arduino/avr-libc/realloc.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/31579608
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/31579608/realloc.o ../../../../../Arduino/hardware/arduino/cores/arduino/avr-libc/realloc.c

${OBJECTDIR}/_ext/389602837/main.cpp.gch: ../../../../../Arduino/hardware/arduino/cores/arduino/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o "$@" ../../../../../Arduino/hardware/arduino/cores/arduino/main.cpp

${OBJECTDIR}/_ext/389602837/new.cpp.gch: ../../../../../Arduino/hardware/arduino/cores/arduino/new.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o "$@" ../../../../../Arduino/hardware/arduino/cores/arduino/new.cpp

${OBJECTDIR}/_ext/389602837/wiring.o: ../../../../../Arduino/hardware/arduino/cores/arduino/wiring.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/389602837/wiring.o ../../../../../Arduino/hardware/arduino/cores/arduino/wiring.c

${OBJECTDIR}/_ext/389602837/wiring_analog.o: ../../../../../Arduino/hardware/arduino/cores/arduino/wiring_analog.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/389602837/wiring_analog.o ../../../../../Arduino/hardware/arduino/cores/arduino/wiring_analog.c

${OBJECTDIR}/_ext/389602837/wiring_digital.o: ../../../../../Arduino/hardware/arduino/cores/arduino/wiring_digital.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/389602837/wiring_digital.o ../../../../../Arduino/hardware/arduino/cores/arduino/wiring_digital.c

${OBJECTDIR}/_ext/389602837/wiring_pulse.o: ../../../../../Arduino/hardware/arduino/cores/arduino/wiring_pulse.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/389602837/wiring_pulse.o ../../../../../Arduino/hardware/arduino/cores/arduino/wiring_pulse.c

${OBJECTDIR}/_ext/389602837/wiring_shift.o: ../../../../../Arduino/hardware/arduino/cores/arduino/wiring_shift.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/389602837
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../../../../Arduino/hardware/arduino/cores/arduino -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/389602837/wiring_shift.o ../../../../../Arduino/hardware/arduino/cores/arduino/wiring_shift.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libliibarduino.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
