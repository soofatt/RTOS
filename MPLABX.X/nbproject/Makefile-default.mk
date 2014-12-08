#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPLABX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPLABX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/PIC18/main.c ../src/PIC18/Clock.c ../src/PIC18/PreemptiveOS.c ../src/PIC18/PriorityLinkedList.c ../src/PIC18/Blinky.c ../src/PIC18/Led2.c ../src/PIC18/SevenSeg.c ../src/PIC18/UARTLoopback.c ../src/PIC18/LEDSM.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1555453033/main.o ${OBJECTDIR}/_ext/1555453033/Clock.o ${OBJECTDIR}/_ext/1555453033/PreemptiveOS.o ${OBJECTDIR}/_ext/1555453033/PriorityLinkedList.o ${OBJECTDIR}/_ext/1555453033/Blinky.o ${OBJECTDIR}/_ext/1555453033/Led2.o ${OBJECTDIR}/_ext/1555453033/SevenSeg.o ${OBJECTDIR}/_ext/1555453033/UARTLoopback.o ${OBJECTDIR}/_ext/1555453033/LEDSM.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1555453033/main.o.d ${OBJECTDIR}/_ext/1555453033/Clock.o.d ${OBJECTDIR}/_ext/1555453033/PreemptiveOS.o.d ${OBJECTDIR}/_ext/1555453033/PriorityLinkedList.o.d ${OBJECTDIR}/_ext/1555453033/Blinky.o.d ${OBJECTDIR}/_ext/1555453033/Led2.o.d ${OBJECTDIR}/_ext/1555453033/SevenSeg.o.d ${OBJECTDIR}/_ext/1555453033/UARTLoopback.o.d ${OBJECTDIR}/_ext/1555453033/LEDSM.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1555453033/main.o ${OBJECTDIR}/_ext/1555453033/Clock.o ${OBJECTDIR}/_ext/1555453033/PreemptiveOS.o ${OBJECTDIR}/_ext/1555453033/PriorityLinkedList.o ${OBJECTDIR}/_ext/1555453033/Blinky.o ${OBJECTDIR}/_ext/1555453033/Led2.o ${OBJECTDIR}/_ext/1555453033/SevenSeg.o ${OBJECTDIR}/_ext/1555453033/UARTLoopback.o ${OBJECTDIR}/_ext/1555453033/LEDSM.o

# Source Files
SOURCEFILES=../src/PIC18/main.c ../src/PIC18/Clock.c ../src/PIC18/PreemptiveOS.c ../src/PIC18/PriorityLinkedList.c ../src/PIC18/Blinky.c ../src/PIC18/Led2.c ../src/PIC18/SevenSeg.c ../src/PIC18/UARTLoopback.c ../src/PIC18/LEDSM.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/MPLABX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4520
MP_PROCESSOR_OPTION_LD=18f4520
MP_LINKER_DEBUG_OPTION=  -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1555453033/main.o: ../src/PIC18/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/main.o   ../src/PIC18/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/Clock.o: ../src/PIC18/Clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/Clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/Clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/Clock.o   ../src/PIC18/Clock.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/Clock.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/Clock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/PreemptiveOS.o: ../src/PIC18/PreemptiveOS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/PreemptiveOS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/PreemptiveOS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/PreemptiveOS.o   ../src/PIC18/PreemptiveOS.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/PreemptiveOS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/PreemptiveOS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/PriorityLinkedList.o: ../src/PIC18/PriorityLinkedList.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/PriorityLinkedList.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/PriorityLinkedList.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/PriorityLinkedList.o   ../src/PIC18/PriorityLinkedList.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/PriorityLinkedList.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/PriorityLinkedList.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/Blinky.o: ../src/PIC18/Blinky.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/Blinky.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/Blinky.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/Blinky.o   ../src/PIC18/Blinky.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/Blinky.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/Blinky.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/Led2.o: ../src/PIC18/Led2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/Led2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/Led2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/Led2.o   ../src/PIC18/Led2.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/Led2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/Led2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/SevenSeg.o: ../src/PIC18/SevenSeg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/SevenSeg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/SevenSeg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/SevenSeg.o   ../src/PIC18/SevenSeg.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/SevenSeg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/SevenSeg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/UARTLoopback.o: ../src/PIC18/UARTLoopback.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/UARTLoopback.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/UARTLoopback.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/UARTLoopback.o   ../src/PIC18/UARTLoopback.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/UARTLoopback.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/UARTLoopback.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/LEDSM.o: ../src/PIC18/LEDSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/LEDSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/LEDSM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/LEDSM.o   ../src/PIC18/LEDSM.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/LEDSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/LEDSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1555453033/main.o: ../src/PIC18/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/main.o   ../src/PIC18/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/Clock.o: ../src/PIC18/Clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/Clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/Clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/Clock.o   ../src/PIC18/Clock.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/Clock.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/Clock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/PreemptiveOS.o: ../src/PIC18/PreemptiveOS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/PreemptiveOS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/PreemptiveOS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/PreemptiveOS.o   ../src/PIC18/PreemptiveOS.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/PreemptiveOS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/PreemptiveOS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/PriorityLinkedList.o: ../src/PIC18/PriorityLinkedList.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/PriorityLinkedList.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/PriorityLinkedList.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/PriorityLinkedList.o   ../src/PIC18/PriorityLinkedList.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/PriorityLinkedList.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/PriorityLinkedList.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/Blinky.o: ../src/PIC18/Blinky.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/Blinky.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/Blinky.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/Blinky.o   ../src/PIC18/Blinky.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/Blinky.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/Blinky.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/Led2.o: ../src/PIC18/Led2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/Led2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/Led2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/Led2.o   ../src/PIC18/Led2.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/Led2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/Led2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/SevenSeg.o: ../src/PIC18/SevenSeg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/SevenSeg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/SevenSeg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/SevenSeg.o   ../src/PIC18/SevenSeg.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/SevenSeg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/SevenSeg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/UARTLoopback.o: ../src/PIC18/UARTLoopback.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/UARTLoopback.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/UARTLoopback.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/UARTLoopback.o   ../src/PIC18/UARTLoopback.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/UARTLoopback.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/UARTLoopback.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1555453033/LEDSM.o: ../src/PIC18/LEDSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1555453033 
	@${RM} ${OBJECTDIR}/_ext/1555453033/LEDSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555453033/LEDSM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1555453033/LEDSM.o   ../src/PIC18/LEDSM.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1555453033/LEDSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1555453033/LEDSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/MPLABX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLABX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/MPLABX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLABX.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
