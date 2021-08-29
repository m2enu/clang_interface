MKDIR := mkdir -p
RM := rm -rf

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

CC := gcc
LD := $(CC)

CFLAGS := -c -I$(SRC_DIR) -DNDEBUG
LDFLAGS :=

SRCS := \
	$(SRC_DIR)/ICommunication.c \
	$(SRC_DIR)/drv_can.c \
	$(SRC_DIR)/drv_spi.c \
	$(SRC_DIR)/main.c \

OBJS := $(subst $(SRC_DIR)/,$(OBJ_DIR)/,$(SRCS:.c=.o))

TARGET_BIN := $(BIN_DIR)/interface.exe

.PHONY: all
all: setup $(TARGET_BIN)

.PHONY: clean
clean:
	$(RM) $(OBJ_DIR) $(BIN_DIR)

.PHONY: setup
setup:
	$(MKDIR) $(OBJ_DIR)
	$(MKDIR) $(BIN_DIR)

$(TARGET_BIN): $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -o $@ $(CFLAGS) $<
