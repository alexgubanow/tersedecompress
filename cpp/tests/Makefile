.PHONY: clean all
include ../envdef.mak

OBJ_TESTS_DIR=$(OBJ_DIR)/tests
TEST_SUITE?=$(BIN_DIR)/tersedecompress++test

default: all

SRCS += $(wildcard *.cpp)
OBJS = $(addprefix $(OBJ_TESTS_DIR)/, $(addsuffix .o, $(basename $(SRCS))))

$(OBJ_TESTS_DIR)/%.o: %.cpp | ${OBJ_TESTS_DIR}
	$(CXX) $(CXXFLAGS) -I../src -I/usr/local/include -MMD -MF $(OBJ_TESTS_DIR)/$*.d -MP -c $< -o $@
	
.PHONY: clean all

all: $(TEST_SUITE)

$(TEST_SUITE): $(OBJS) | ${BIN_DIR}
	$(LD) $(LDFLAGS) -o $(TEST_SUITE) $(OBJS) -L${BIN_DIR} -L/usr/local/lib -lgtest -ltersedecompress

${OBJ_TESTS_DIR} ${BIN_DIR}:
	-mkdir -p $@

check:
	LIBPATH=${BIN_DIR}:$(PREFIX)/lib:$$LIBPATH LD_LIBRARY_PATH=${BIN_DIR}:$(PREFIX)/lib:$$LD_LIBRARY_PATH $(TEST_SUITE) $(ROOT_DIR)../test-data/

clean:
	rm -rf $(OBJS) $(TEST_SUITE)

-include $(OBJS:%.o=%.d)