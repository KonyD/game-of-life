CC = g++
CFLAGS = -O2 -Wall
LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

SOURCE_FILES = $(wildcard src/*.cpp)
HEADER_FILES = $(wildcard src/*.h)
OUT = out/main.exe

all: $(OUT)

$(OUT): $(SOURCE_FILES) $(HEADER_FILES)
	$(CC) $(SOURCE_FILES) -o $(OUT) $(CFLAGS) $(LIBS)

clean:
	del /Q $(OUT)
