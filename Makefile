CC := gcc
CFLAGS := -Wall -Werror -Iinclude
LDFLAGS :=

PROGNAME := miochat-server
SRC_DIR := src
BUILD_DIR := build
TARGET := $(BUILD_DIR)/$(PROGNAME)

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@
	@echo "Build complete: $(TARGET)"

install: $(TARGET)
	@mkdir -p /usr/local/bin
	@cp $(TARGET) /usr/local/bin/$(PROGNAME)
	@echo "Installed to /usr/local/bin/$(PROGNAME)"

uninstall:
	@rm -f /usr/local/bin/$(PROGNAME)
	@echo "Uninstalled from /usr/local/bin/$(PROGNAME)"

clean:
	@rm -rf $(BUILD_DIR)
	@echo "Cleaned build directory"

.PHONY: all install uninstall clean
