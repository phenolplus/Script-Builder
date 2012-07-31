# Makefile for Script-Builder project
#

CC = g++ -Wall
GCFLAGS = `pkg-config --cflags gtk+-2.0`
GLIBS = `pkg-config --libs gtk+-2.0`
LOCAL_INCLUDE = -I ${SOURCE}

OUT = bin
OBJ = obj
SOURCE = ./source

build: script_builder

run: script_builder bin
	bin/script_builder
bin: 
	mkdir -p bin
obj:
	mkdir -p obj
script_builder: ScriptBuilder.o GraphicShell.o InterCode.o Parser.o ScriptGen.o
	${CC} ${OBJ}/ScriptBuilder.o ${OBJ}/GraphicShell.o  ${OBJ}/InterCode.o ${OBJ}/Parser.o ${OBJ}/ScriptGen.o ${GLIBS} -o ${OUT}/script_builder

ScriptBuilder.o: ${SOURCE}/ScriptBuilder.cpp InterCode.o obj
	${CC} -c ${SOURCE}/ScriptBuilder.cpp ${LOCAL_INCLUDE} ${OBJ}/InterCode.o -o ${OBJ}/ScriptBuilder.o

GraphicShell.o:  ${SOURCE}/GraphicShell.cpp ${SOURCE}/GraphicShell.h obj
	${CC} -c ${SOURCE}/GraphicShell.cpp ${GCFLAGS} -o ${OBJ}/GraphicShell.o

InterCode.o: ${SOURCE}/InterCode.cpp ${SOURCE}/InterCode.h obj
	${CC} -c ${SOURCE}/InterCode.cpp -o ${OBJ}/InterCode.o

Parser.o: ${SOURCE}/Parser.cpp ${SOURCE}/Parser.h obj
	${CC} -c ${SOURCE}/Parser.cpp -o ${OBJ}/Parser.o

ScriptGen.o: ${SOURCE}/ScriptGen.cpp ${SOURCE}/ScriptGen.h obj
	${CC} -c ${SOURCE}/ScriptGen.cpp -o ${OBJ}/ScriptGen.o

clean:
	rm -f ${obj}/*.o
