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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES=


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projet_barriere1.0_slave.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projet_barriere1.0_slave.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projet_barriere1.0_slave ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/C_BOUTON.cpp.gch: C_BOUTON.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o "$@" C_BOUTON.cpp

${OBJECTDIR}/C_BUZZER.cpp.gch: C_BUZZER.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o "$@" C_BUZZER.cpp

${OBJECTDIR}/C_CAPTEUR_LUMIERE.cpp.gch: C_CAPTEUR_LUMIERE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o "$@" C_CAPTEUR_LUMIERE.cpp

${OBJECTDIR}/C_CARTE.cpp.gch: C_CARTE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o "$@" C_CARTE.cpp

${OBJECTDIR}/C_COMMUNICATION_USB.cpp.gch: C_COMMUNICATION_USB.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o "$@" C_COMMUNICATION_USB.cpp

${OBJECTDIR}/C_ECRAN.cpp.gch: C_ECRAN.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o "$@" C_ECRAN.cpp

${OBJECTDIR}/C_ENTREE.cpp.gch: C_ENTREE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o "$@" C_ENTREE.cpp

${OBJECTDIR}/C_ESCLAVE.cpp.gch: C_ESCLAVE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o "$@" C_ESCLAVE.cpp

${OBJECTDIR}/C_LED.cpp.gch: C_LED.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o "$@" C_LED.cpp

${OBJECTDIR}/C_MOTEUR.cpp.gch: C_MOTEUR.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o "$@" C_MOTEUR.cpp

${OBJECTDIR}/C_OBJET_ENTREE.cpp.gch: C_OBJET_ENTREE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o "$@" C_OBJET_ENTREE.cpp

${OBJECTDIR}/C_OBJET_SORTIE.cpp.gch: C_OBJET_SORTIE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o "$@" C_OBJET_SORTIE.cpp

${OBJECTDIR}/C_POTENTIOMETRE.cpp.gch: C_POTENTIOMETRE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o "$@" C_POTENTIOMETRE.cpp

${OBJECTDIR}/C_SORTIE.cpp.gch: C_SORTIE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o "$@" C_SORTIE.cpp

${OBJECTDIR}/main.cpp.gch: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o "$@" main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projet_barriere1.0_slave.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
