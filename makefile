# ------------------------------------------------
# Inspired by : http://stackoverflow.com/questions/7004702/how-can-i-create-a-makefile-for-c-projects-with-src-obj-and-bin-subdirectories
# ------------------------------------------------

# project name (generate executable with this name)
TARGET   = Huffman


CC       = gcc
# compiling flags here
CFLAGS = -std=c99 -g -Wall

LINKER   = gcc -o
# linking flags here
LFLAGS   = -g -Wall -I. -lm

# Every important directories
SRCDIR   = src
OBJDIR   = build
INCDIR   = include
BINDIR   = bin

# all the files of the project
SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(INCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

.PHONEY: all
all : $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)
	@echo "Compiled "$<" successfully!"

.PHONEY: clean
clean:
	-rm $(OBJDIR)/*
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	-rm $(BINDIR)/*
	@echo "Executable removed!"

# Start the program after building it
run : all
	./$(BINDIR)/$(TARGET)
