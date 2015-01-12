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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
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
	${OBJECTDIR}/QR_Encode.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../../Desktop/SFML-2.2/lib -lsfml-graphics-s-d -lsfml-graphics -lsfml-graphics-d -lsfml-graphics-s -lsfml-window-s -lsfml-window -lsfml-window-d -lsfml-window-s-d -lopenal32 -lfreetype -lglew -ljpeg -lsfml-audio-d -lsfml-audio-s-d -lsfml-audio-s -lsfml-audio -lsfml-main-d -lsfml-main -lsfml-network-d -lsfml-network-s-d -lsfml-network-s -lsfml-network -lsndfile -lsfml-system-d -lsfml-system-s-d -lsfml-system-s -lsfml-system

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qr_code2.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qr_code2.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qr_code2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/QR_Encode.o: QR_Encode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../Desktop/SFML-2.2/include -I../../../Desktop/SFML-2.2/include/SFML/Graphics -I../../../Desktop/SFML-2.2/include/SFML/OpenGL.hpp -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/QR_Encode.o QR_Encode.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../Desktop/SFML-2.2/include -I../../../Desktop/SFML-2.2/include/SFML/Graphics -I../../../Desktop/SFML-2.2/include/SFML/OpenGL.hpp -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/qr_code2.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
