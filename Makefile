.SUFFIXES:
.SUFFIXES: .c .o

SRCDIR = src/main
TESTDIR = src/test
OBJDIR = build

include local.mk

OBJS = $(OBJDIR)/BlinkSignal_test.o $(OBJDIR)/BlinkSignal.o lib/libarduino_mock.a

CPLUS_INCLUDE_PATH = $(GTEST_INC):$(GMOCK_INC):$(AMOCK_DIR)/include/arduino-mock:include

CXXFLAGS += -std=c++11 -stdlib=libc++ -DGTEST_USE_OWN_TR1_TUPLE=1

clean:
	rm -rf $(OBJDIR)/*

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

# create the gtest and gmock libraries
$(OBJDIR)/gtest-all.o:
	$(CXX) -c -o $@ $< $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -I$(GTEST_HOME_DIR)/googletest/include -I$(GTEST_HOME_DIR)/googletest -c $(GTEST_HOME_DIR)/googletest/src/gtest-all.cc

$(OBJDIR)/libgtest.a: $(OBJDIR)/gtest-all.o
	ar -rv $(OBJDIR)/libgtest.a $(OBJDIR)/gtest-all.o

$(OBJDIR)/gmock-all.o:
	$(CXX) -c -o $@ $< $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -I$(GTEST_HOME_DIR)/googlemock/include -I$(GTEST_HOME_DIR)/googlemock -I$(GTEST_HOME_DIR)/googletest/include -I$(GTEST_HOME_DIR)/googletest -c $(GTEST_HOME_DIR)/googlemock/src/gmock-all.cc

$(OBJDIR)/libgmock.a: $(OBJDIR)/gmock-all.o
	ar -rv $@ $<
	