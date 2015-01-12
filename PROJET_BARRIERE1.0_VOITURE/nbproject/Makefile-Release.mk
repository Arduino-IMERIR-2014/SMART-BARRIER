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
OBJECTFILES= \
	${OBJECTDIR}/C_BOUTON.o \
	${OBJECTDIR}/C_BUZZER.o \
	${OBJECTDIR}/C_CAPTEUR_LUMIERE.o \
	${OBJECTDIR}/C_CARTE.o \
	${OBJECTDIR}/C_COMMUNICATION_USB.o \
	${OBJECTDIR}/C_ECRAN.o \
	${OBJECTDIR}/C_ENTREE.o \
	${OBJECTDIR}/C_LED.o \
	${OBJECTDIR}/C_MAITRE.o \
	${OBJECTDIR}/C_MOTEUR.o \
	${OBJECTDIR}/C_OBJET_ENTREE.o \
	${OBJECTDIR}/C_OBJET_SORTIE.o \
	${OBJECTDIR}/C_POTENTIOMETRE.o \
	${OBJECTDIR}/C_SORTIE.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projet_barriere1.0_voiture.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projet_barriere1.0_voiture.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projet_barriere1.0_voiture ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/C_BOUTON.o: C_BOUTON.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_BOUTON.o C_BOUTON.cpp

${OBJECTDIR}/C_BUZZER.o: C_BUZZER.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_BUZZER.o C_BUZZER.cpp

${OBJECTDIR}/C_CAPTEUR_LUMIERE.o: C_CAPTEUR_LUMIERE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_CAPTEUR_LUMIERE.o C_CAPTEUR_LUMIERE.cpp

${OBJECTDIR}/C_CARTE.o: C_CARTE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_CARTE.o C_CARTE.cpp

${OBJECTDIR}/C_COMMUNICATION_USB.o: C_COMMUNICATION_USB.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_COMMUNICATION_USB.o C_COMMUNICATION_USB.cpp

${OBJECTDIR}/C_ECRAN.o: C_ECRAN.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_ECRAN.o C_ECRAN.cpp

${OBJECTDIR}/C_ENTREE.o: C_ENTREE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_ENTREE.o C_ENTREE.cpp

${OBJECTDIR}/C_LED.o: C_LED.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_LED.o C_LED.cpp

${OBJECTDIR}/C_MAITRE.o: C_MAITRE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_MAITRE.o C_MAITRE.cpp

${OBJECTDIR}/C_MOTEUR.o: C_MOTEUR.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_MOTEUR.o C_MOTEUR.cpp

${OBJECTDIR}/C_OBJET_ENTREE.o: C_OBJET_ENTREE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_OBJET_ENTREE.o C_OBJET_ENTREE.cpp

${OBJECTDIR}/C_OBJET_SORTIE.o: C_OBJET_SORTIE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_OBJET_SORTIE.o C_OBJET_SORTIE.cpp

${OBJECTDIR}/C_POTENTIOMETRE.o: C_POTENTIOMETRE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_POTENTIOMETRE.o C_POTENTIOMETRE.cpp

${OBJECTDIR}/C_SORTIE.o: C_SORTIE.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_SORTIE.o C_SORTIE.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projet_barriere1.0_voiture.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
