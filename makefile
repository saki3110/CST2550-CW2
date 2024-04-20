# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

# Define the source, object, and binary directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Define the source files, object files, and the target executable
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
TARGET = $(BINDIR)/VideoRentalSystem

# Default target
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJECTS)
	@if not exist "$(BINDIR)" mkdir $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "Compilation successful. Run the program using .\\$(TARGET)"

# Compile the source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@if not exist "$(OBJDIR)" mkdir $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target for removing compiled files
clean:
	@echo "Cleaning up..."
	@if exist "$(OBJDIR)" rmdir /s /q "$(OBJDIR)"
	@if exist "$(BINDIR)" rmdir /s /q "$(BINDIR)"
	@echo "Clean complete."

# Phony targets
.PHONY: all clean
