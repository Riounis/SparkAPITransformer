CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/main

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
LIB := -L lib
INC := -I include

$(TARGET):
	@echo "Linking..."
	@echo "$(CC) $^ -o $(TARGET) $(SOURCES) $(LIB)"; $(CC) $^ -o $(TARGET) $(SOURCES) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(INC) -c -o"; $(CC) $(CFLAGS) $(INC) -c -o

clean:
	@echo "Cleaning..."
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

tests:
	$(CC) $(CFLAGS) test/test_main.cpp $(INC) $(LIB) -o bin/test_main

.PHONY: clean
