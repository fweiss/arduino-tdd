.SUFFIXES:
.SUFFIXES: .c .o

SRCDIR = src/main
TESTDIR = src/test
OBJDIR = build

include local.mk

OBJS = $(OBJDIR)/BlinkSignal_test.o $(OBJDIR)/BlinkSignal.o lib/libarduino_mock.a

CPLUS_INCLUDE_PATH = $(GTEST_INC):$(GMOCK_INC):$(AMOCK_DIR)/include/arduino-mock:include

CXXFLAGS += -std=c++11 -stdlib=libc++ -DGTEST_USE_OWN_TR1_TUPLE=1

# run the tests
test: $(OBJDIR)/BlinkSignal_test
	$(OBJDIR)/BlinkSignal_test --gtest_output="xml:XML_Report.xml"

# link the tests
$(OBJDIR)/BlinkSignal_test: $(OBJS)
	$(CXX) -o $@ $^ $(GTEST_LIB) $(GMOCK_LIB)

# compile the tests
$(OBJDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -I$(CPLUS_INCLUDE_PATH) -o $@ $<

# compile the source
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -I$(CPLUS_INCLUDE_PATH) -o $@ $<
	