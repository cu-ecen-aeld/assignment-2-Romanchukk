.PHONY: all clean help

# Cross-compilation support
CROSS_COMPILE ?=
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Wextra -O1

# Target
TARGET = writer

# Source
SOURCE = writer.c

# Default target
all: $(TARGET)

# Compile and link
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $@ $<

# Clean build artifacts
clean:
	rm -f $(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  all   - Build the writer executable"
	@echo "  clean - Remove the executable"
	@echo "  help  - Show this help message"
	@echo "Use CROSS_COMPILE=aarch64-none-linux-gnu- for cross-compilation"