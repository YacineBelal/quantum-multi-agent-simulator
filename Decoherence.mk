###########################################################################

#----- lib a utiliser
DIRAGENTS=../../../GestionAgents
INCAGENTS=${DIRAGENTS}/LibMoRis/include
LIBAGENTS=${DIRAGENTS}/LibMoRis/lib
AGENTSLIBNAME=Agents

#-------------  Appli  --------------

TARGET=decoherenceExample

all: ${TARGET}

#---- les fichiers sources ----

FILESex= decoherenceExample.cpp \
        Prog.cpp \
		Prog1.cpp \
		Prog2.cpp \
 	QuBit.cpp \
	MessageBool.cpp \
	MessageX.cpp \
	MessageH.cpp \
	MessageG.cpp \
	MessageM.cpp \
	MessageDecoherence.cpp

###########################################################################

#---- les variables ----

CC=g++
INC=-I${INCAGENTS}
CCFLAGS=-W -Wall -Werror -pedantic ${INC}
LIBFLAGS=

LDFLAGS=\
-L${LIBAGENTS} -l${AGENTSLIBNAME} \
${LIBFLAGS}

###########################################################################

#---- les fichiers objets ----

OBJECTSex=${FILESex:.cpp=.o}

#---- librairies utilisees ----

DEPLIBS=${LIBAGENTS}/lib${AGENTSLIBNAME}.a

#--------- realisation de l'executable (edition de liens) ----



decoherenceExample: ${OBJECTSex} ${DEPLIBS}
	${CC} ${OBJECTSex} ${LDFLAGS} -o decoherenceExample

#------------------------------------

MessageBool.o : MessageBool.h MessageBool.cpp ${INCAGENTS}/MAS.h
					${CC} ${CCFLAGS} -c MessageBool.cpp

MessageG.o : MessageG.h MessageG.cpp ${INCAGENTS}/MAS.h
					${CC} ${CCFLAGS} -c MessageG.cpp

MessageDecoherence.o : MessageDecoherence.h MessageDecoherence.cpp ${INCAGENTS}/MAS.h
					${CC} ${CCFLAGS} -c MessageDecoherence.cpp
					

MessageM.o : MessageM.h MessageM.cpp ${INCAGENTS}/MAS.h
					${CC} ${CCFLAGS} -c MessageM.cpp

MessageH.o : MessageH.h MessageH.cpp ${INCAGENTS}/MAS.h
					${CC} ${CCFLAGS} -c MessageH.cpp

A.o: Donnees.h Donnees.cpp ${INCAGENTS}/MAS.h
	${CC} ${CCFLAGS} -c Donnees.cpp

decoherenceExample.o: decoherenceExample.cpp ${INCAGENTS}/MAS.h
	${CC} ${CCFLAGS} -c decoherenceExample.cpp

 

#---- la regle par defaut (.c/cpp --> .o) ----

.c.o :
	@echo
	${CC} -o $*.o -c ${CCFLAGS} $<
	@echo

.cpp.o :
	@echo
	${CC} -o $*.o -c ${CCFLAGS} $<
	@echo

#------------- clean - clear --------

CLEANING=rm -f *.o core a.out *.exe *.exe.stackdump ${TARGET}

clear:
	${CLEANING}
clean:
	${CLEANING}
