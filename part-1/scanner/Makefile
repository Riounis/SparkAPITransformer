CC := g++
TARGET := bin/scanner
SRCDIR := src

SRCEXT := cpp
SOURCES := src/regex.cpp src/scan.cpp src/scanner.cpp src/token.cpp src/replace.cpp
LIB := -L lib
INC := -I include

$(TARGET):
	@echo "Linking..."
	@echo "$(CC) $^ -o $(TARGET) $(SOURCES) $(INC)"; $(CC) $^ -o $(TARGET) $(SOURCES) $(INC)

clean:
	@echo "Cleaning..."
	@echo " $(RM) -r $(TARGET)"; $(RM) -r $(TARGET)

.PHONY: clean
